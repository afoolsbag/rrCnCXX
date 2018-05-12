//===-- Avro Object and File ------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对象和文件。
///
/// \version 2018-05-12
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <fstream>

#include <avro/Compiler.hh>
#include <avro/DataFile.hh>
#include <avro/ValidSchema.hh>

#include "schema/RecordType.hxx"

int main(int argc, char *argv[])
{
    // schema
    avro::ValidSchema schema;
    std::ifstream schemaIfs("RecordType.json");
    assert(schemaIfs.is_open());
    avro::compileJsonSchema(schemaIfs, schema);

    // output
    rravro::RecordType odata;
    odata.enumValue = rravro::BLUE;

    avro::DataFileWriter<rravro::RecordType> writer("rt.bin", schema);
    do {
        writer.write(odata);
    } while (false);
    writer.close();

    // input
    avro::DataFileReader<rravro::RecordType> reader("rt.bin", schema);
    rravro::RecordType idata;
    while (reader.read(idata)) {
        reader.read(idata);
    }
    reader.close();

    return EXIT_SUCCESS;
}
