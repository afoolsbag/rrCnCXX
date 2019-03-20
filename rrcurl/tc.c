/**
 * \copyright Unlicense
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <check.h>
#include <curl/curl.h>
#include <curl/easy.h>

#include "ts.h"

static int progress_callback(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    (void)clientp;
    static unsigned int cnt = 0;
    if ((++cnt & 0xFF) == 0) {
        if (dltotal || dlnow)
            printf("Download progress: %.0lf bytes / %.0lf bytes\n", dlnow, dltotal);
        if (ultotal || ulnow)
            printf("Upload progress: %.0lf bytes / %.0lf bytes\n", ulnow, ultotal);
    }
    return 0;
}

static size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata)
{
    FILE *fp = userdata;
    return fread(buffer, size, nitems, fp);
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = userdata;
    return fwrite(ptr, size, nmemb, fp);
}

START_TEST(tf_https_download)
{
    CURLcode ec = CURLE_OK;

    FILE *fp = fopen("1mb_from_apache.img", "wb");
    ck_assert(fp);

    /* 初始 */
    CURL *curl = curl_easy_init();
    ck_assert(curl);

    /* 配置 */
    ec = curl_easy_setopt(curl, CURLOPT_URL, "https://mirrors.tuna.tsinghua.edu.cn/apache/zzz/mirror-tests/1mb.img");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 执行 */
    ec = curl_easy_perform(curl);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 清理 */
    curl_easy_cleanup(curl);
    fclose(fp);
}
END_TEST;

START_TEST(tf_fpt_upload)
{
    CURLcode ec = CURLE_OK;

    FILE *fp = fopen("1mb_from_apache.img", "rb");
    ck_assert(fp);

    fseek(fp, 0L, SEEK_END);
    const long sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    /* 初始 */
    CURL *curl = curl_easy_init();
    ck_assert(curl);

    /* 配置 */
    ec = curl_easy_setopt(curl, CURLOPT_URL, "ftp://localhost/1mb.img");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_USERNAME, "username");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_UPLOAD, true);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_READDATA, fp);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)sz);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 执行 */
    ec = curl_easy_perform(curl);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 清理 */
    curl_easy_cleanup(curl);
    fclose(fp);
}
END_TEST;

START_TEST(tf_fpt_download)
{
    CURLcode ec = CURLE_OK;

    FILE *fp = fopen("1mb_from_ftp.img", "wb");
    ck_assert(fp);

    /* 初始 */
    CURL *curl = curl_easy_init();
    ck_assert(curl);

    /* 配置 */
    ec = curl_easy_setopt(curl, CURLOPT_URL, "ftp://localhost/1mb.img");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_USERNAME, "username");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    ec = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));
    ec = curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 执行 */
    ec = curl_easy_perform(curl);
    ck_assert_msg(ec == CURLE_OK, curl_easy_strerror(ec));

    /* 清理 */
    curl_easy_cleanup(curl);
    fclose(fp);
}
END_TEST;

TCase *tc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_set_timeout(tc, 0);
    tcase_add_test(tc, tf_https_download);
    tcase_add_test(tc, tf_fpt_upload);
    tcase_add_test(tc, tf_fpt_download);
    return tc;
}
