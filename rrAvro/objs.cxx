//===-- Avro Object and Stream ----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对象和流。
///
/// \version 2018-05-12
/// \since 2018-05-12
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <array>
#include <fstream>

#include <avro/AvroParse.hh>
#include <avro/Compiler.hh>
#include <avro/DataFile.hh>
#include <avro/Stream.hh>
#include <avro/ValidSchema.hh>

#include "avro/DataStream.hxx"
#include "schema/RecordType.hxx"

int main(int argc, char *argv[])
{
    // schema
    avro::ValidSchema schema;
    std::ifstream schemaIfs("RecordType.json");
    assert(schemaIfs.is_open());
    avro::compileJsonSchema(schemaIfs, schema);

    rravro::RecordType data;

    // input
    std::ifstream ifs("rt.bin", std::ios::binary);
    avro::DataStreamReader<rravro::RecordType> reader(ifs, schema);
    while (reader.read(data)) {
        ;
    }
    reader.close();
    ifs.close();

    // output
    std::stringstream ss;
    avro::DataStreamWriter<rravro::RecordType> writer(ss, schema);
    {
        writer.write(data);
    }
    writer.close();

    const std::size_t len = ss.tellp();
    char *bytes = new char[len];
    ss.read(bytes, len);
    delete[] bytes;

    return EXIT_SUCCESS;
}
