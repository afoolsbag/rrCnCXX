//===-- S3 Test -------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-11-20
/// \since 2019-07-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <fstream>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "rrceph/s3.hxx"

using namespace std;

namespace rrceph {

constexpr char host[] {"127.0.0.1:7480"};
constexpr char access_key[] {"access_key"};
constexpr char secret_key[] {"secret_key"};
constexpr char sample_bucket[] = "s3cpp_sample";
constexpr char sample_key[] = "s3cpp_sample.txt";
constexpr char sample_upload_file[] = "s3cpp_sample_raw.txt";
constexpr char sample_download_file[] = "s3cpp_sample_ceph.txt";

class s3_test : public testing::Test {
protected:
    static s3 client;
    static void SetUpTestCase()
    {
        std::remove(sample_upload_file);
        std::remove(sample_download_file);
        ofstream file {sample_upload_file};
        file << "hello, world";
    }
    static void TearDownTestCase()
    {}
};
s3 s3_test::client {"s3cpp", host, access_key, secret_key};

TEST_F(s3_test, list_buckets)
{
    const auto infos = client.list_buckets();
    cout << "buckets:\n";
    for (const auto &info : infos)
        cout << info.bucket_name << '\n';
}

TEST_F(s3_test, create_bucket)
{
    client.create_bucket(sample_bucket);
}

TEST_F(s3_test, upload_file)
{
    client.upload_file_as_object(sample_upload_file, sample_bucket, sample_key);
}

TEST_F(s3_test, generate_download_url)
{
    const auto expires = time(nullptr) + 15 * 60;
    const auto url = client.generate_download_url(sample_bucket, sample_key, expires);
    cout << "url: " << url << '\n';
}

TEST_F(s3_test, download_object_as_file)
{
    client.download_object_as_file(sample_bucket, sample_key, sample_download_file);
}

TEST_F(s3_test, download_object_as_memory)
{
    vector<uint8_t> buffer;
    client.download_object_as_memory(sample_bucket, sample_key, &buffer);
    cout << "object:\n"
        "size: " << buffer.size() << '\n';
}

TEST_F(s3_test, list_object)
{
    const auto infos = client.list_objects(sample_bucket);
    cout << "objects:\n";
    for (const auto &info : infos)
        cout << info.key << '\n';
}

TEST_F(s3_test, delete_object)
{
    client.delete_object(sample_bucket, sample_key);
}

TEST_F(s3_test, delete_bucket)
{
    client.delete_bucket(sample_bucket);
}

TEST_F(s3_test, list_buckets_again)
{
    const auto infos = client.list_buckets();
    cout << "buckets:\n";
    for (const auto &info : infos)
        cout << info.bucket_name << '\n';
}

}
