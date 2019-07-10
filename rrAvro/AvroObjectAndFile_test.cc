//===-- Avro Object and File ------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Avro 对象和文件。
///
/// \version 2019-07-10
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <fstream>

#include <avro/Compiler.hh>
#include <avro/DataFile.hh>
#include <avro/ValidSchema.hh>

#include <boost/dll.hpp>

#include <gtest/gtest.h>

#include "RecordType.hh"

using namespace std;

namespace rravro {

namespace {
const auto schemaPath = boost::dll::program_location().parent_path() / "RecordType.json";
const auto binPath = boost::dll::program_location().parent_path() / "RecordType.bin";
}

TEST(AvroObjectAndFile, WriteToFile)
{
    std::ifstream schemaIfstream(schemaPath.string());
    ASSERT_TRUE(schemaIfstream.is_open());

    avro::ValidSchema schema;
    compileJsonSchema(schemaIfstream, schema);

    RecordType data {};
    data.enumValue = EnumType::BLUE;

    avro::DataFileWriter<RecordType> writer(binPath.string().c_str(), schema);
    writer.write(data);
    //writer.write(data2);
    //writer.write(data3);
    writer.close();
}

TEST(AvroObjectAndFile, ReadFromFile)
{
    std::ifstream schemaIfstream(schemaPath.string());
    ASSERT_TRUE(schemaIfstream.is_open());

    avro::ValidSchema schema;
    compileJsonSchema(schemaIfstream, schema);

    avro::DataFileReader<RecordType> reader(binPath.string().c_str(), schema);
    RecordType data;
    while (reader.read(data)) {
        ASSERT_EQ(EnumType::BLUE, data.enumValue);
    }
    reader.close();
}

}
