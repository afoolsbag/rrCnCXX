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


#ifndef SCHEMA_HH_3078970193__H_
#define SCHEMA_HH_3078970193__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace rrAvro {
struct record_type;
struct _schema_json_Union__0__ {
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
    record_type get_record_type() const;
    void set_record_type(const record_type& v);
    _schema_json_Union__0__();
};

enum enum_type {
    ABC,
    IJK,
    XYZ,
};

struct record_type {
    typedef _schema_json_Union__0__ null_value_t;
    null_value_t null_value;
    bool boolean_value;
    int32_t int_value;
    int64_t long_value;
    float float_value;
    double double_value;
    std::vector<uint8_t> bytes_value;
    std::string string_value;
    enum_type enum_value;
    std::vector<std::string > array_value;
    std::map<std::string, std::string > map_value;
    boost::array<uint8_t, 1> fixed_value;
    record_type() :
        null_value(null_value_t()),
        boolean_value(bool()),
        int_value(int32_t()),
        long_value(int64_t()),
        float_value(float()),
        double_value(double()),
        bytes_value(std::vector<uint8_t>()),
        string_value(std::string()),
        enum_value(enum_type()),
        array_value(std::vector<std::string >()),
        map_value(std::map<std::string, std::string >()),
        fixed_value(boost::array<uint8_t, 1>())
        { }
};

inline
record_type _schema_json_Union__0__::get_record_type() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<record_type >(value_);
}

inline
void _schema_json_Union__0__::set_record_type(const record_type& v) {
    idx_ = 1;
    value_ = v;
}

inline _schema_json_Union__0__::_schema_json_Union__0__() : idx_(0) { }
}
namespace avro {
template<> struct codec_traits<rrAvro::_schema_json_Union__0__> {
    static void encode(Encoder& e, rrAvro::_schema_json_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_record_type());
            break;
        }
    }
    static void decode(Decoder& d, rrAvro::_schema_json_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                rrAvro::record_type vv;
                avro::decode(d, vv);
                v.set_record_type(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<rrAvro::enum_type> {
    static void encode(Encoder& e, rrAvro::enum_type v) {
		if (v < rrAvro::ABC || v > rrAvro::XYZ)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for rrAvro::enum_type and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, rrAvro::enum_type& v) {
		size_t index = d.decodeEnum();
		if (index < rrAvro::ABC || index > rrAvro::XYZ)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for rrAvro::enum_type and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<rrAvro::enum_type>(index);
    }
};

template<> struct codec_traits<rrAvro::record_type> {
    static void encode(Encoder& e, const rrAvro::record_type& v) {
        avro::encode(e, v.null_value);
        avro::encode(e, v.boolean_value);
        avro::encode(e, v.int_value);
        avro::encode(e, v.long_value);
        avro::encode(e, v.float_value);
        avro::encode(e, v.double_value);
        avro::encode(e, v.bytes_value);
        avro::encode(e, v.string_value);
        avro::encode(e, v.enum_value);
        avro::encode(e, v.array_value);
        avro::encode(e, v.map_value);
        avro::encode(e, v.fixed_value);
    }
    static void decode(Decoder& d, rrAvro::record_type& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.null_value);
                    break;
                case 1:
                    avro::decode(d, v.boolean_value);
                    break;
                case 2:
                    avro::decode(d, v.int_value);
                    break;
                case 3:
                    avro::decode(d, v.long_value);
                    break;
                case 4:
                    avro::decode(d, v.float_value);
                    break;
                case 5:
                    avro::decode(d, v.double_value);
                    break;
                case 6:
                    avro::decode(d, v.bytes_value);
                    break;
                case 7:
                    avro::decode(d, v.string_value);
                    break;
                case 8:
                    avro::decode(d, v.enum_value);
                    break;
                case 9:
                    avro::decode(d, v.array_value);
                    break;
                case 10:
                    avro::decode(d, v.map_value);
                    break;
                case 11:
                    avro::decode(d, v.fixed_value);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.null_value);
            avro::decode(d, v.boolean_value);
            avro::decode(d, v.int_value);
            avro::decode(d, v.long_value);
            avro::decode(d, v.float_value);
            avro::decode(d, v.double_value);
            avro::decode(d, v.bytes_value);
            avro::decode(d, v.string_value);
            avro::decode(d, v.enum_value);
            avro::decode(d, v.array_value);
            avro::decode(d, v.map_value);
            avro::decode(d, v.fixed_value);
        }
    }
};

}
#endif
