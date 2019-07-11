//===-- Service Implement ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief rrIce 服务实现。
///
/// \author zhengrr
/// \version 2019-07-11
/// \since 2017-12-13
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRICE_SERVICEIMPL_H_
#define RRICE_SERVICEIMPL_H_

#include "Service.h"

namespace rrIce {

class ServiceImpl : public virtual Service {
public:
    bool        echoBool(bool value, const Ice::Current &current) override;
    Ice::Byte   echoByte(Ice::Byte value, const Ice::Current &current) override;
    short       echoShort(short value, const Ice::Current &current) override;
    int         echoInt(int value, const Ice::Current &current) override;
    long long   echoLong(long long value, const Ice::Current &current) override;
    float       echoFloat(float value, const Ice::Current &current) override;
    double      echoDouble(double value, const Ice::Current &current) override;
    std::string echoString(std::string value, const Ice::Current &current) override;

    CustomEnum echoEnum(CustomEnum value, const Ice::Current &current) override;
    CustomStruct echoStruct(CustomStruct value, const Ice::Current &current) override;
    CustomSequence echoSequence(CustomSequence value, const Ice::Current &current) override;
    CustomDictionary echoDictionary(CustomDictionary value, const Ice::Current &current) override;

    void getNumber(int &outValue, const Ice::Current &current) override;
    Ice::optional<int> optNumber(Ice::optional<int> inValue, Ice::optional<int> &outValue, const Ice::Current &current) override;
    void setNumber(int inValue, const Ice::Current &current) override;

    void throwException(const Ice::Current &current) override;
};

}

#endif
