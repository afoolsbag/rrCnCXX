/// \copyright Unlicense

#include "ServiceImpl.h"

#include <Ice/Ice.h>

#ifdef NDEBUG
# define dprintf(...) ((void)0)
#else
# include <cstdio>
# define dprintf(...) std::fprintf(stderr, __VA_ARGS__)
#endif

using namespace std;

namespace rrIce {

bool ServiceImpl::echoBool(bool value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %s\n", value ? "true" : "false");
    return value;
}

Ice::Byte ServiceImpl::echoByte(Ice::Byte value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %hhu\n", value);
    return value;
}

short ServiceImpl::echoShort(short value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %hd\n", value);
    return value;
}

int ServiceImpl::echoInt(int value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %d\n", value);
    return value;
}

long long ServiceImpl::echoLong(long long value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %lld\n", value);
    return value;
}

float ServiceImpl::echoFloat(float value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %f\n", value);
    return value;
}

double ServiceImpl::echoDouble(double value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %lf\n", value);
    return value;
}

string ServiceImpl::echoString(string value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %s\n", value.c_str());
    return value;
}

CustomEnum ServiceImpl::echoEnum(CustomEnum value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = %s\n", [&]() -> string {
        switch (value) {
        case CustomEnum::SMT: return "SMT";
        case CustomEnum::ZL: return "ZL";
        case CustomEnum::JT: return "JT";
        default: return "Unexpected CustomEnum";
        }
    }().c_str());
    return value;
}

CustomStruct ServiceImpl::echoStruct(CustomStruct value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value = {smt=%s, zl=%s, jt=%s}\n", value.smt ? "true" : "false", value.zl ? "true" : "false", value.jt ? "true" : "false");
    return value;
}

CustomSequence ServiceImpl::echoSequence(CustomSequence value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value.size = %zd\n", value.size());
    return value;
}

CustomDictionary ServiceImpl::echoDictionary(CustomDictionary value, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("value.size = %zd\n", value.size());
    return value;
}

namespace {
namespace static_global {
int number {};
}
}

void ServiceImpl::getNumber(int &outValue, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("outValue = %d\n", outValue);
    outValue = static_global::number;
}

Ice::optional<int> ServiceImpl::optNumber(Ice::optional<int> inValue, Ice::optional<int> &outValue, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("inValue = %s\n", [&]()->string {
        if (!inValue.has_value())
            return "nullopt";
        return to_string(inValue.value());
    }().c_str());
    dprintf("outValue = %s\n", [&]()->string {
        if (!outValue.has_value())
            return "nullopt";
        return to_string(outValue.value());
    }().c_str());
    if (inValue.has_value()) {
        if (outValue.has_value())
            outValue = inValue;
        return inValue;
    }
    return Ice::nullopt;
}

void ServiceImpl::setNumber(int inValue, [[maybe_unused]] const Ice::Current &current)
{
    dprintf("SERVER DEBUG INFORMATION:\n");
    dprintf("service = %s\n", __func__);
    dprintf("%s\n", current.con->toString().c_str());
    dprintf("inValue = %d\n", inValue);
    static_global::number = inValue;
}

void ServiceImpl::throwException([[maybe_unused]] const Ice::Current &current)
{
    throw Exception("kkrj");
}

}
