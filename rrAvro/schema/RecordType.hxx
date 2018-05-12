/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef RECORDTYPE_HXX_3506892715__H_
#define RECORDTYPE_HXX_3506892715__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace rravro {
struct RecordType;
struct RecordType_json_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    RecordType get_RecordType() const;
    void set_RecordType(const RecordType& v);
    RecordType_json_Union__0__();
};

enum EnumType {
    RED,
    GREEN,
    BLUE,
};

struct RecordType {
    typedef RecordType_json_Union__0__ nullValue_t;
    nullValue_t nullValue;
    bool booleanValue;
    int32_t intValue;
    int64_t longValue;
    float floatValue;
    double doubleValue;
    std::vector<uint8_t> bytesValue;
    std::string stringValue;
    EnumType enumValue;
    std::vector<std::string > arrayValue;
    std::map<std::string, std::string > mapValue;
    boost::array<uint8_t, 1> fixedValue;
    RecordType() :
        nullValue(nullValue_t()),
        booleanValue(bool()),
        intValue(int32_t()),
        longValue(int64_t()),
        floatValue(float()),
        doubleValue(double()),
        bytesValue(std::vector<uint8_t>()),
        stringValue(std::string()),
        enumValue(EnumType()),
        arrayValue(std::vector<std::string >()),
        mapValue(std::map<std::string, std::string >()),
        fixedValue(boost::array<uint8_t, 1>())
        { }
};

inline
RecordType RecordType_json_Union__0__::get_RecordType() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<RecordType >(value_);
}

inline
void RecordType_json_Union__0__::set_RecordType(const RecordType& v) {
    idx_ = 1;
    value_ = v;
}

inline RecordType_json_Union__0__::RecordType_json_Union__0__() : idx_(0) { }
}
namespace avro {
template<> struct codec_traits<rravro::RecordType_json_Union__0__> {
    static void encode(Encoder& e, rravro::RecordType_json_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_RecordType());
            break;
        }
    }
    static void decode(Decoder& d, rravro::RecordType_json_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                rravro::RecordType vv;
                avro::decode(d, vv);
                v.set_RecordType(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<rravro::EnumType> {
    static void encode(Encoder& e, rravro::EnumType v) {
		if (v < rravro::RED || v > rravro::BLUE)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for rravro::EnumType and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, rravro::EnumType& v) {
		size_t index = d.decodeEnum();
		if (index < rravro::RED || index > rravro::BLUE)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for rravro::EnumType and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<rravro::EnumType>(index);
    }
};

template<> struct codec_traits<rravro::RecordType> {
    static void encode(Encoder& e, const rravro::RecordType& v) {
        avro::encode(e, v.nullValue);
        avro::encode(e, v.booleanValue);
        avro::encode(e, v.intValue);
        avro::encode(e, v.longValue);
        avro::encode(e, v.floatValue);
        avro::encode(e, v.doubleValue);
        avro::encode(e, v.bytesValue);
        avro::encode(e, v.stringValue);
        avro::encode(e, v.enumValue);
        avro::encode(e, v.arrayValue);
        avro::encode(e, v.mapValue);
        avro::encode(e, v.fixedValue);
    }
    static void decode(Decoder& d, rravro::RecordType& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.nullValue);
                    break;
                case 1:
                    avro::decode(d, v.booleanValue);
                    break;
                case 2:
                    avro::decode(d, v.intValue);
                    break;
                case 3:
                    avro::decode(d, v.longValue);
                    break;
                case 4:
                    avro::decode(d, v.floatValue);
                    break;
                case 5:
                    avro::decode(d, v.doubleValue);
                    break;
                case 6:
                    avro::decode(d, v.bytesValue);
                    break;
                case 7:
                    avro::decode(d, v.stringValue);
                    break;
                case 8:
                    avro::decode(d, v.enumValue);
                    break;
                case 9:
                    avro::decode(d, v.arrayValue);
                    break;
                case 10:
                    avro::decode(d, v.mapValue);
                    break;
                case 11:
                    avro::decode(d, v.fixedValue);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.nullValue);
            avro::decode(d, v.booleanValue);
            avro::decode(d, v.intValue);
            avro::decode(d, v.longValue);
            avro::decode(d, v.floatValue);
            avro::decode(d, v.doubleValue);
            avro::decode(d, v.bytesValue);
            avro::decode(d, v.stringValue);
            avro::decode(d, v.enumValue);
            avro::decode(d, v.arrayValue);
            avro::decode(d, v.mapValue);
            avro::decode(d, v.fixedValue);
        }
    }
};

}
#endif
