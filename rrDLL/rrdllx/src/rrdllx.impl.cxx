/// \copyright Unlicense

#define _CRT_SECURE_NO_WARNINGS

#include "rrdllx.impl.hxx"

#include <cstring>

using namespace std;

namespace rrdllx {

//==============================================================================
//  _____ _____ ___ _____ _____ _____   ___  ___ ________  _________ ___________
// /  ___|_   _/ _ \_   _|_   _/  __ \  |  \/  ||  ___|  \/  || ___ \  ___| ___ \
// \ `--.  | |/ /_\ \| |   | | | /  \/  | .  . || |__ | .  . || |_/ / |__ | |_/ /
//  `--. \ | ||  _  || |   | | | |      | |\/| ||  __|| |\/| || ___ \  __||    /
// /\__/ / | || | | || |  _| |_| \__/\  | |  | || |___| |  | || |_/ / |___| |\ \
// \____/  \_/\_| |_/\_/  \___/ \____/  \_|  |_/\____/\_|  |_/\____/\____/\_| \_|

rrdllx_handle_t rrdllx_t::alloc_instance()
{
    auto mov_ptr = make_unique<rrdllx_t>();
    const auto handle = mov_ptr.get();
    instance_map_.insert(make_pair(handle, move(mov_ptr)));
    return handle;
}

rrdllx_t &rrdllx_t::instance(handle_t handle)
{
    if (!handle)
        throw exception_t(rrdllx_invalid_argument_nullptr);
    if (!instance_map_.count(handle))
        throw exception_t(rrdllx_out_of_range_handle);
    return *instance_map_.at(handle);
}

void rrdllx_t::free_instance(handle_t handle)
{
    if (!handle)
        throw exception_t(rrdllx_invalid_argument_nullptr);
    if (!instance_map_.count(handle))
        throw exception_t(rrdllx_out_of_range_handle);
    instance_map_.erase(handle);
}

map<handle_t, unique_ptr<rrdllx_t>> rrdllx_t::instance_map_;

//==============================================================================
//  _____ _   _  _____ _____ ___   _   _ _____  _____   ___  ___ ________  _________ ___________
// |_   _| \ | |/  ___|_   _/ _ \ | \ | /  __ \|  ___|  |  \/  ||  ___|  \/  || ___ \  ___| ___ \
//   | | |  \| |\ `--.  | |/ /_\ \|  \| | /  \/| |__    | .  . || |__ | .  . || |_/ / |__ | |_/ /
//   | | | . ` | `--. \ | ||  _  || . ` | |    |  __|   | |\/| ||  __|| |\/| || ___ \  __||    /
//  _| |_| |\  |/\__/ / | || | | || |\  | \__/\| |___   | |  | || |___| |  | || |_/ / |___| |\ \
//  \___/\_| \_/\____/  \_/\_| |_/\_| \_/\____/\____/   \_|  |_/\____/\_|  |_/\____/\____/\_| \_|

zstring_t rrdllx_t::alloc_zstring(const string &value)
{
    auto mov_ptr = make_unique<char[]>(value.length() + 1);
    const auto raw_ptr = mov_ptr.get();
    zstring_map_.insert(make_pair(raw_ptr, move(mov_ptr)));
    strcpy(raw_ptr, value.c_str());
    return raw_ptr;
}

void rrdllx_t::free_zstring(zstring_t string)
{
    if (!string)
        throw exception_t(rrdllx_invalid_argument_nullptr);
    if (!zstring_map_.count(string))
        throw exception_t(rrdllx_out_of_range_instance_zstring);
    zstring_map_.erase(string);
}

zstring_array_t rrdllx_t::alloc_zstring_array(const vector<string> &value)
{
    auto vector_mov_ptr = make_unique<zstring_t[]>(value.size());
    const auto vector_raw_ptr = vector_mov_ptr.get();
    zstring_array_vector_map_.insert(make_pair(vector_raw_ptr, move(vector_mov_ptr)));
    for (size_t i = 0; i < value.size(); ++i)
        vector_raw_ptr[i] = alloc_zstring(value.at(i));

    auto array_mov_ptr = make_unique<zstring_array_deref_t>(zstring_array_deref_t {value.size(), vector_raw_ptr});
    const auto array_raw_ptr = array_mov_ptr.get();
    zstring_array_map_.insert(make_pair(array_raw_ptr, move(array_mov_ptr)));
    return array_raw_ptr;
}

void rrdllx_t::free_zstring_array(zstring_array_t array)
{
    if (!array)
        throw exception_t(rrdllx_invalid_argument_nullptr);
    if (!zstring_array_map_.count(array))
        throw exception_t(rrdllx_out_of_range_instance_zstring_array);
    if (!zstring_array_vector_map_.count(array->vector))
        throw exception_t(rrdllx_out_of_range_instance_zstring_array_vector);
    for (size_t i = 0; i < array->count; ++i)
        free_zstring(array->vector[i]);
    zstring_array_vector_map_.erase(array->vector);
    zstring_array_map_.erase(array);
}

binary_t rrdllx_t::alloc_binary(const vector<uint8_t> &value)
{
    auto data_mov_ptr = make_unique<uint8_t[]>(value.size());
    const auto data_raw_ptr = data_mov_ptr.get();
    binary_data_map_.insert(make_pair(data_raw_ptr, move(data_mov_ptr)));
    memcpy(data_raw_ptr, value.data(), value.size());

    auto binary_mov_ptr = make_unique<binary_deref_t>(binary_deref_t {value.size(), data_raw_ptr});
    const auto binary_raw_ptr = binary_mov_ptr.get();
    binary_map_.insert(make_pair(binary_raw_ptr, move(binary_mov_ptr)));
    return binary_raw_ptr;
}

void rrdllx_t::free_binary(binary_t binary)
{
    if (!binary)
        throw exception_t(rrdllx_invalid_argument_nullptr);
    if (!binary_map_.count(binary))
        throw exception_t(rrdllx_out_of_range_instance_binary);
    if (!binary_data_map_.count(binary->data))
        throw exception_t(rrdllx_out_of_range_instance_binary_data);
    binary_data_map_.erase(binary->data);
    binary_map_.erase(binary);
}

void rrdllx_t::free_all()
{
    zstring_map_.clear();
    zstring_array_map_.clear();
    zstring_array_vector_map_.clear();
    binary_map_.clear();
    binary_data_map_.clear();
}

}//namespace rrdllx
