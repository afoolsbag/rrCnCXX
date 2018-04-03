//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Avro™入门
///
/// \version 2018-04-03
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <fstream>
#include <iostream>

#include <avro/Compiler.hh>
#include <avro/DataFile.hh>
#include <avro/ValidSchema.hh>
#include "schema.hh"

int main(int argc, char *argv[])
{
    avro::ValidSchema schema;

    {
        const std::string schema_def_fname {"schema.json"};  // schema definition file name
        std::ifstream schema_def(schema_def_fname);  // schema definition
        if (!schema_def.is_open()) {
            std::cerr << "Failed to open \"" << schema_def_fname << "\"." << std::endl;
            return EXIT_FAILURE;
        }
        avro::compileJsonSchema(schema_def, schema);
    }

    {
        avro::DataFileWriter<rrAvro::record_type> dfwriter("test.bin", schema);
        rrAvro::record_type data;
        for (int i = 0; i < 100; i++) {
            data.null_value.set_null();
            data.boolean_value = true;
            dfwriter.write(data);
        }
        dfwriter.close();
    }

    {
        avro::DataFileReader<rrAvro::record_type> dfreader("test.bin", schema);
        rrAvro::record_type data;
        while (dfreader.read(data)) {
            std::cout << '(' << data.boolean_value << ')' << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
