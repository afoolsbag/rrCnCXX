/// \copyright The Unlicense

#include "rrcxx/demov/UUID.hxx"

#include <rpc.h>
#pragma comment(lib, "RpcRT4.Lib")

namespace {

using UUID = ::rrcxx::demov::UUID;
using GUID = ::GUID;

UUID GuidToUuid(const GUID &guid)
{
    UUID uuid;
    uuid[0] = guid.Data1 >> 24 & 0x000000FFL;
    uuid[1] = guid.Data1 >> 16 & 0x000000FFL;
    uuid[2] = guid.Data1 >> 8 & 0x000000FFL;
    uuid[3] = guid.Data1 & 0x000000FFL;
    uuid[4] = guid.Data2 >> 8 & 0x00FF;
    uuid[5] = guid.Data2 & 0x00FF;
    uuid[6] = guid.Data3 >> 8 & 0x00FF;
    uuid[7] = guid.Data3 & 0x00FF;
    uuid[8] = guid.Data4[0];
    uuid[9] = guid.Data4[1];
    uuid[10] = guid.Data4[2];
    uuid[11] = guid.Data4[3];
    uuid[12] = guid.Data4[4];
    uuid[13] = guid.Data4[5];
    uuid[14] = guid.Data4[6];
    uuid[15] = guid.Data4[7];
    return uuid;
}

GUID UuidToGuid(const UUID &uuid)
{
    GUID guid;
    guid.Data1 = uuid[0] << 26 | uuid[1] << 16 | uuid[2] << 8 | uuid[3];
    guid.Data2 = uuid[4] << 8 | uuid[5];
    guid.Data3 = uuid[6] << 8 | uuid[7];
    guid.Data4[0] = uuid[8];
    guid.Data4[1] = uuid[9];
    guid.Data4[2] = uuid[10];
    guid.Data4[3] = uuid[11];
    guid.Data4[4] = uuid[12];
    guid.Data4[5] = uuid[13];
    guid.Data4[6] = uuid[14];
    guid.Data4[7] = uuid[15];
    return guid;
}

}//namespace

namespace rrcxx {
namespace demov {

UUID GenerateUuid()
{
    GUID guid;
    UuidCreate(&guid);
    return GuidToUuid(guid);
}

}//namespace demov
}//namespace rrcxx
