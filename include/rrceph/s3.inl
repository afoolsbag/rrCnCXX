/// \copyright Unlicense

#pragma once
#ifndef RRCEPH_S3_INL_
#define RRCEPH_S3_INL_

#include "s3.hxx"

#include <cstdio>
#include <condition_variable>
#include <memory>
#include <mutex>

#include <libs3.h>

namespace rrceph {

inline s3::s3(const std::string &agent, const std::string &host, const std::string &access_key, const std::string &secret_key)
    : agent_ {agent}, host_ {host}, access_key_ {access_key}, secret_key_ {secret_key}
{
    using namespace std;

    switch (S3_initialize(agent_.c_str(), S3_INIT_ALL, host.c_str())) {
    case S3StatusUriTooLong:
        throw invalid_argument {string{__func__}.append(" failed: uri too long, the max size is ").append(to_string(S3_MAX_HOSTNAME_SIZE))};
    case S3StatusInternalError:
        throw runtime_error {string{__func__}.append(" failed: s3 internal error")};
    case S3StatusOutOfMemory:
        throw bad_alloc {};
    default:
        break;
    }
}

inline s3::~s3() noexcept
{
    S3_deinitialize();
}

inline std::list<s3::bucket_info> s3::list_buckets() const
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        list<bucket_info> infos {};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        [[maybe_unused]]
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto list_service_callback = [](const char *ownerId,
                                                 const char *ownerDisplayName,
                                                 const char *bucketName,
                                                 int64_t creationDate,
                                                 void *callbackData) -> S3Status {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        bucket_info info {};
        info.owner_id = ownerId ? ownerId : "";
        info.owner_display_name = ownerDisplayName ? ownerDisplayName : "";
        info.bucket_name = bucketName ? bucketName : "";
        info.creation_date = static_cast<time_t>(creationDate);
        p_user_data->infos.emplace_back(move(info));

        return S3StatusOK;
    };

    static const S3ListServiceHandler list_service_handler {{response_properties_callback, response_complete_callback}, list_service_callback};

    // 用户数据
    user_data_t user_data;

    // 调用 API 列出桶，并等待完成
    S3_list_service(S3ProtocolHTTP, access_key_.c_str(), secret_key_.c_str(), host_.c_str(),
                    nullptr, &list_service_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_list_service failed: "}.append(S3_get_status_name(user_data.status))};

    // 返回结果
    return user_data.infos;
}

inline void s3::create_bucket(const std::string &bucket_name)
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const S3ResponseHandler response_handler {response_properties_callback, response_complete_callback};

    // 用户数据
    user_data_t user_data;

    // 调用 API 创建桶，并等待完成
    S3_create_bucket(S3ProtocolHTTP, access_key_.c_str(), secret_key_.c_str(), host_.c_str(),
                     bucket_name.c_str(), S3CannedAclPublicReadWrite, nullptr, nullptr, &response_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_create_bucket failed: "}.append(S3_get_status_name(user_data.status))};
}

inline void s3::delete_bucket(const std::string &bucket_name)
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const S3ResponseHandler response_handler {response_properties_callback, response_complete_callback};

    // 用户数据
    user_data_t user_data;

    // 调用 API 创建桶，并等待完成
    S3_delete_bucket(S3ProtocolHTTP, S3UriStylePath, access_key_.c_str(), secret_key_.c_str(), host_.c_str(),
                     bucket_name.c_str(), nullptr, &response_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string{"S3_delete_bucket failed: "}.append(S3_get_status_name(user_data.status))};
}

inline std::list<s3::object_info> s3::list_objects(const std::string &bucket_name) const
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        list<object_info> infos {};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        [[maybe_unused]]
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto list_bucket_callback = [](int isTruncated,
                                                const char *nextMarker,
                                                int contentsCount,
                                                const S3ListBucketContent *contents,
                                                int commonPrefixesCount,
                                                const char **commonPrefixes,
                                                void *callbackData) -> S3Status {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        for (int i {0}; i < contentsCount; ++i) {
            const auto &content = contents[i];
            object_info info {};
            info.key = content.key ? content.key : "";
            info.last_modified = static_cast<time_t>(content.lastModified);
            info.e_tag = content.eTag ? content.eTag : "";
            info.size = content.size;
            info.owner_id = content.ownerId ? content.ownerId : "";
            info.owner_display_name = content.ownerDisplayName ? content.ownerDisplayName : "";
            p_user_data->infos.emplace_back(move(info));
        }

        return S3StatusOK;
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3ListBucketHandler list_bucket_handler {{response_properties_callback, response_complete_callback}, list_bucket_callback};

    // 用户数据
    user_data_t user_data;

    // 调用 API 列出对象，并等待完成
    S3_list_bucket(&bucket_context, nullptr, nullptr, nullptr, 0, nullptr, &list_bucket_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_list_bucket failed: "}.append(S3_get_status_name(user_data.status))};

    // 返回结果
    return user_data.infos;
}

inline void s3::upload_memory_as_object(std::uint8_t *buffer, std::size_t size, const std::string &bucket_name, const std::string &key)
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        uint8_t *cur {};
        size_t left {};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto put_object_data_callback = [](int bufferSize,
                                                    char *buffer,
                                                    void *callbackData) -> int {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);
        const auto size = min(p_user_data->left, static_cast<size_t>(bufferSize));
        if (size == 0)
            return size;
        memcpy(buffer, p_user_data->cur, size);
        p_user_data->cur += size;
        p_user_data->left -= size;
        return size;
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3PutObjectHandler put_object_handler {{response_properties_callback, response_complete_callback}, put_object_data_callback};

    // 用户数据
    user_data_t user_data;
    user_data.cur = buffer;
    user_data.left = size;

    // 调用 API 上传对象，并等待完成
    S3_put_object(&bucket_context, key.c_str(), size, nullptr, nullptr, &put_object_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_put_object failed: "}.append(S3_get_status_name(user_data.status))};
}

inline void s3::download_object_as_memory(const std::string &bucket_name, const std::string &key, std::vector<std::uint8_t> *buffer)
{
    using namespace std;

    if (!buffer)
        throw invalid_argument {string {__func__}.append("'s argument \"buffer\" cannot be nullptr")};

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        vector<uint8_t> *buffer {nullptr};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto get_object_data_callback = [](int bufferSize,
                                                    const char *buffer,
                                                    void *callbackData) -> S3Status {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);
        try {
            p_user_data->buffer->insert(p_user_data->buffer->cend(), buffer, buffer + bufferSize);
            return S3StatusOK;
        } catch (...) {
            return S3StatusAbortedByCallback;
        }
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3GetObjectHandler put_object_handler {{response_properties_callback, response_complete_callback}, get_object_data_callback};

    // 用户数据
    user_data_t user_data;
    user_data.buffer = buffer;

    // 调用 API 下载对象，并等待完成
    S3_get_object(&bucket_context, key.c_str(), nullptr, 0, 0, nullptr, &put_object_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_get_object failed: "}.append(S3_get_status_name(user_data.status))};
}

inline void s3::upload_file_as_object(const std::string &local_file_path, const std::string &bucket_name, const std::string &key)
{
    using namespace std;

    unique_ptr<FILE, decltype(&fclose)> fp {fopen(local_file_path.c_str(), "rb"), &fclose};
    if (!fp)
        throw runtime_error {string {"open file failed: "}.append(local_file_path)};

    fseek(fp.get(), 0L, SEEK_END);
    const long size {ftell(fp.get())};
    fseek(fp.get(), 0L, SEEK_SET);

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        FILE *fp {};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto put_object_data_callback = [](int bufferSize,
                                                    char *buffer,
                                                    void *callbackData) -> int {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);
        return fread(buffer, sizeof(char), bufferSize, p_user_data->fp);
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3PutObjectHandler put_object_handler {{response_properties_callback, response_complete_callback}, put_object_data_callback};

    // 用户数据
    user_data_t user_data;
    user_data.fp = fp.get();

    // 调用 API 上传对象，并等待完成
    S3_put_object(&bucket_context, key.c_str(), size, nullptr, nullptr, &put_object_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_put_object failed: "}.append(S3_get_status_name(user_data.status))};
}

inline void s3::download_object_as_file(const std::string &bucket_name, const std::string &key, const std::string &local_file_path)
{
    using namespace std;

    unique_ptr<FILE, decltype(&fclose)> fp {fopen(local_file_path.c_str(), "wb"), &fclose};
    if (!fp)
        throw runtime_error {string {"open file failed: "}.append(local_file_path)};

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
        FILE *fp {};
    };

    static const auto response_properties_callback = [](const S3ResponseProperties *properties,
                                                        void *callbackData) -> S3Status {
        return S3StatusOK;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    static const auto get_object_data_callback = [](int bufferSize,
                                                    const char *buffer,
                                                    void *callbackData) -> S3Status {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);
        return fwrite(buffer, sizeof(char), bufferSize, p_user_data->fp) < static_cast<size_t>(bufferSize) ? S3StatusAbortedByCallback : S3StatusOK;
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3GetObjectHandler put_object_handler {{response_properties_callback, response_complete_callback}, get_object_data_callback};

    // 用户数据
    user_data_t user_data;
    user_data.fp = fp.get();

    // 调用 API 下载对象，并等待完成
    S3_get_object(&bucket_context, key.c_str(), nullptr, 0, 0, nullptr, &put_object_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_get_object failed: "}.append(S3_get_status_name(user_data.status))};
}

inline void s3::delete_object(const std::string &bucket_name, const std::string &key)
{
    using namespace std;

    struct user_data_t {
        S3Status status {S3StatusOK};
        string message;
        string resource;
        string further_details;
    };

    static const auto response_complete_callback = [](S3Status status,
                                                      const S3ErrorDetails *error,
                                                      void *callbackData) -> void {
        auto *p_user_data = reinterpret_cast<user_data_t *>(callbackData);

        p_user_data->status = status;
        if (status != S3StatusOK) {
            p_user_data->message = error && error->message ? error->message : "";
            p_user_data->resource = error && error->resource ? error->resource : "";
            p_user_data->further_details = error && error->furtherDetails ? error->furtherDetails : "";
        }
    };

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    static const S3ResponseHandler delete_response_handler {nullptr, response_complete_callback};

    // 用户数据
    user_data_t user_data;

    // 调用 API 删除对象，并等待完成
    S3_delete_object(&bucket_context, key.c_str(), nullptr, &delete_response_handler, &user_data);

    // 检查异常
    if (user_data.status != S3StatusOK)
        throw runtime_error {string {"S3_delete_object failed: "}.append(S3_get_status_name(user_data.status))};

}

inline std::string s3::generate_download_url(const std::string &bucket_name, const std::string &key, std::time_t expires)
{
    using namespace std;

    S3BucketContext bucket_context {
        host_.c_str(),
        bucket_name.c_str(),
        S3ProtocolHTTP,
        S3UriStylePath,
        access_key_.c_str(),
        secret_key_.c_str()
    };

    char buffer[S3_MAX_AUTHENTICATED_QUERY_STRING_SIZE] {};

    // 调用 API 生成外链，并等待完成
    const auto status = S3_generate_authenticated_query_string(buffer, &bucket_context, key.c_str(), static_cast<int64_t>(expires), nullptr);

    // 检查异常
    if (status != S3StatusOK)
        throw runtime_error {string {"S3_generate_authenticated_query_string failed: "}.append(S3_get_status_name(status))};

    return buffer;
}


}

#endif
