//===-- cURL Test -----------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-22
/// \since 2019-03-20
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <memory>

#include <curl/curl.h>
#include <curl/easy.h>
#include <gtest/gtest.h>

using namespace std;

namespace rrcurl {

static int progress_callback(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    (void)clientp;
    static unsigned int cnt = 0;
    if ((++cnt & 0xFF) == 0) {
        if (0 < dltotal || 0 < dlnow)
            printf("Download progress: %.0lf bytes / %.0lf bytes\n", dlnow, dltotal);
        if (0 < ultotal || 0 < ulnow)
            printf("Upload progress: %.0lf bytes / %.0lf bytes\n", ulnow, ultotal);
    }
    return 0;
}

static size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata)
{
    const auto img = reinterpret_cast<FILE *>(userdata);
    return fread(buffer, size, nitems, img);
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    const auto img = reinterpret_cast<FILE *>(userdata);
    return fwrite(ptr, size, nmemb, img);
}

TEST(test, https_download)
{
    CURLcode ec {CURLE_OK};

    // 考虑到效率，采用 C 风格文件 IO 而非 C++ 风格，下同
    const unique_ptr<FILE, decltype(&fclose)> up_img {fopen("1mb_from_apache.img", "wb"), &fclose};

    // 初始化
    const unique_ptr<CURL, decltype(&curl_easy_cleanup)> up_curl {curl_easy_init(), &curl_easy_cleanup};
    ASSERT_TRUE(up_curl);

    // 配置
    ec = curl_easy_setopt(up_curl.get(), CURLOPT_URL, "https://mirrors.tuna.tsinghua.edu.cn/apache/zzz/mirror-tests/1mb.img");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(up_curl.get(), CURLOPT_SSL_VERIFYPEER, false);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(up_curl.get(), CURLOPT_WRITEFUNCTION, write_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(up_curl.get(), CURLOPT_WRITEDATA, up_img.get());
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(up_curl.get(), CURLOPT_NOPROGRESS, false);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(up_curl.get(), CURLOPT_PROGRESSFUNCTION, progress_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    // 执行
    ec = curl_easy_perform(up_curl.get());
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
}

TEST(test, fpt_upload)
{
    CURLcode ec {CURLE_OK};

    const unique_ptr<FILE, decltype(&fclose)> up_img {fopen("1mb_from_apache.img", "rb"), &fclose};
    fseek(up_img.get(), 0L, SEEK_END);
    const curl_off_t img_size {ftell(up_img.get())};
    fseek(up_img.get(), 0L, SEEK_SET);

    // 初始化
    const unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl {curl_easy_init(), &curl_easy_cleanup};
    ASSERT_TRUE(curl);

    // 配置
    ec = curl_easy_setopt(curl.get(), CURLOPT_URL, "ftp://localhost/1mb.img");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_USERNAME, "username");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_PASSWORD, "password");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(curl.get(), CURLOPT_UPLOAD, true);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_READFUNCTION, read_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_READDATA, up_img.get());
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(curl.get(), CURLOPT_INFILESIZE_LARGE, img_size);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_NOPROGRESS, false);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_PROGRESSFUNCTION, progress_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    // 执行
    ec = curl_easy_perform(curl.get());
    switch (ec) {
    case CURLE_OK:
    case CURLE_COULDNT_CONNECT:
    case CURLE_UPLOAD_FAILED:
        break;
    default:
        FAIL() << curl_easy_strerror(ec);
    }
}

TEST(test, fpt_download)
{
    CURLcode ec {CURLE_OK};

    const unique_ptr<FILE, decltype(&fclose)> up_img {fopen("1mb_from_ftp.img", "wb"), &fclose};

    // 初始化
    const unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl {curl_easy_init(), &curl_easy_cleanup};
    ASSERT_TRUE(curl);

    // 配置
    ec = curl_easy_setopt(curl.get(), CURLOPT_URL, "ftp://localhost/1mb.img");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_USERNAME, "username");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_PASSWORD, "password");
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, write_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, up_img.get());
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    ec = curl_easy_setopt(curl.get(), CURLOPT_NOPROGRESS, false);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);
    ec = curl_easy_setopt(curl.get(), CURLOPT_PROGRESSFUNCTION, progress_callback);
    ASSERT_EQ(CURLE_OK, ec) << curl_easy_strerror(ec);

    // 执行
    ec = curl_easy_perform(curl.get());
    switch (ec) {
    case CURLE_OK:
    case CURLE_COULDNT_CONNECT:
        break;
    default:
        FAIL() << curl_easy_strerror(ec);
    }
}

}
