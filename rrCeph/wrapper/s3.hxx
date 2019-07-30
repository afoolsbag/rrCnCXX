//===-- rrS3 S3 Wrapper -----------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-30
/// \since 2019-07-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRS3_S3_HXX_
#define RRS3_S3_HXX_

#include <cstdint>
#include <ctime>
#include <list>
#include <string>
#include <vector>

namespace rrs3 {

/// \brief 桶信息
struct bucket_info {
    std::string owner_id;
    std::string owner_display_name;
    std::string bucket_name;
    std::time_t creation_date {};
};

/// \brief 对象存储
struct object_info {
    std::string key;
    std::time_t last_modified {};
    std::string e_tag;
    std::uint64_t size {};
    std::string owner_id;
    std::string owner_display_name;
};

class s3 {
public:
    inline explicit s3(const std::string &agent, const std::string &host, const std::string &access_key, const std::string &secret_key);
    inline explicit s3(const s3 &) = delete;
    inline s3 &operator=(const s3 &) = delete;
    inline explicit s3(s3 &&) noexcept = default;
    inline s3 &operator=(s3 &&) noexcept = default;
    inline virtual ~s3() noexcept;

    /// \brief 列出拥有的桶
    [[nodiscard]]
    inline std::list<bucket_info> list_buckets() const;

    /// \brief 创建桶
    inline void create_bucket(const std::string &bucket_name);

    /// \brief 删除桶
    inline void delete_bucket(const std::string &bucket_name);

    /// \brief 列出桶中的对象
    [[nodiscard]]
    inline std::list<object_info> list_objects(const std::string &bucket_name) const;

    /// \brief 上传内存数据作为对象
    inline void upload_memory_as_object(std::uint8_t *buffer, std::size_t size, const std::string &bucket_name, const std::string &key);

    /// \brief 下载对象作为内存数据
    /// \param bucket_name 桶名
    /// \param key         对象名
    /// \param buffer      本机缓存，不接受空指针
    inline void download_object_as_memory(const std::string &bucket_name, const std::string &key, std::vector<std::uint8_t> *buffer);

    /// \brief 上传文件作为对象
    inline void upload_file_as_object(const std::string &local_file_path, const std::string &bucket_name, const std::string &key);

    /// \brief 下载对象作为文件
    inline void download_object_as_file(const std::string &bucket_name, const std::string &key, const std::string &local_file_path);

    /// \brief 删除对象
    inline void delete_object(const std::string &bucket_name, const std::string &key);

    /// \brief 生成外链
    inline std::string generate_download_url(const std::string &bucket_name, const std::string &key, std::time_t expires);

private:
    const std::string agent_;
    std::string host_;
    std::string access_key_;
    std::string secret_key_;
};

}

#include "s3.inl"

#endif
