#include <cstdlib>
#include <fstream>
#include <iostream>

#include <avro/AvroSerialize.hh>
#include <avro/Compiler.hh>
#include <avro/DataFile.hh>
#include <avro/ValidSchema.hh>
#include "cpx.hh"

namespace {

avro::ValidSchema LoadSchema(const std::string &filename)
{
    std::ifstream schema_definition(filename);
    avro::ValidSchema schema;
    avro::compileJsonSchema(schema_definition, schema);
    return schema;
}

}//namespace

int main(int argc, char *argv[])
{
    avro::ValidSchema schema = LoadSchema("cpx.json");

    {
        avro::DataFileWriter<c::cpx> dfw("test.bin", schema);
        c::cpx c1;
        for (int i = 0; i < 100; i++) {
            c1.re = i * 100;
            c1.im = i + 100;
            dfw.write(c1);
        }
        dfw.close();
    }

    {
        avro::DataFileReader<c::cpx> dfr("test.bin", schema);
        c::cpx c2;
        while (dfr.read(c2)) {
            std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
