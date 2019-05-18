/// \copyright Unlicense

#define _CRT_SECURE_NO_WARNINGS

#include "instance.hxx"

#include <cassert>
#include <cstring>

using namespace std;

namespace rrdllx {

/*==============================================================================
 *  _____ _____ ___ _____ _____ _____   ___  ___ ________  _________ ___________
 * /  ___|_   _/ _ \_   _|_   _/  __ \  |  \/  ||  ___|  \/  || ___ \  ___| ___ \
 * \ `--.  | |/ /_\ \| |   | | | /  \/  | .  . || |__ | .  . || |_/ / |__ | |_/ /
 *  `--. \ | ||  _  || |   | | | |      | |\/| ||  __|| |\/| || ___ \  __||    /
 * /\__/ / | || | | || |  _| |_| \__/\  | |  | || |___| |  | || |_/ / |___| |\ \
 * \____/  \_/\_| |_/\_/  \___/ \____/  \_|  |_/\____/\_|  |_/\____/\____/\_| \_|
 */

rrdllx_handle_t rrdllx_t::alloc_instance()
{
    auto mov_ptr = make_unique<rrdllx_t>();
    const auto handle = mov_ptr.get();
    instance_owner_.insert(make_pair(handle, move(mov_ptr)));
    return handle;
}

rrdllx_t &rrdllx_t::instance(handle_t handle)
{
    if (!instance_owner_.count(handle))
        throw exception_t(rrdllx_instance_not_found);
    return *instance_owner_.at(handle);
}

void rrdllx_t::free_instance(handle_t handle)
{
    if (!instance_owner_.count(handle))
        throw exception_t(rrdllx_instance_not_found);
    instance_owner_.erase(handle);
}

map<handle_t, unique_ptr<rrdllx_t>> rrdllx_t::instance_owner_;

/*==============================================================================
 *  _____ _   _  _____ _____ ___   _   _ _____  _____   ___  ___ ________  _________ ___________
 * |_   _| \ | |/  ___|_   _/ _ \ | \ | /  __ \|  ___|  |  \/  ||  ___|  \/  || ___ \  ___| ___ \
 *   | | |  \| |\ `--.  | |/ /_\ \|  \| | /  \/| |__    | .  . || |__ | .  . || |_/ / |__ | |_/ /
 *   | | | . ` | `--. \ | ||  _  || . ` | |    |  __|   | |\/| ||  __|| |\/| || ___ \  __||    /
 *  _| |_| |\  |/\__/ / | || | | || |\  | \__/\| |___   | |  | || |___| |  | || |_/ / |___| |\ \
 *  \___/\_| \_/\____/  \_/\_| |_/\_| \_/\____/\____/   \_|  |_/\____/\_|  |_/\____/\____/\_| \_|
 */

zstring_t rrdllx_t::alloc_zstring(const string &value)
{
    auto mov_ptr = make_unique<char[]>(value.length() + 1);
    const auto raw_ptr = mov_ptr.get();
    zstring_owner_.insert(make_pair(raw_ptr, move(mov_ptr)));
    strcpy(raw_ptr, value.c_str());
    return raw_ptr;
}

void rrdllx_t::free_zstring(zstring_t zstring)
{
    assert(zstring);
    if (!zstring_owner_.count(zstring))
        throw exception_t(rrdllx_instance_zstring_not_found);
    zstring_owner_.erase(zstring);
}

zstring_array_t rrdllx_t::alloc_zstring_array(const vector<string> &value)
{
    auto vector_mov_ptr = make_unique<zstring_t[]>(value.size());
    const auto vector_raw_ptr = vector_mov_ptr.get();
    zstring_array_vector_owner_.insert(make_pair(vector_raw_ptr, move(vector_mov_ptr)));
    for (size_t i = 0; i < value.size(); ++i)
        vector_raw_ptr[i] = alloc_zstring(value.at(i));

    auto array_mov_ptr = make_unique<zstring_array_deref_t>(zstring_array_deref_t{value.size(), vector_raw_ptr});
    const auto array_raw_ptr = array_mov_ptr.get();
    zstring_array_owner_.insert(make_pair(array_raw_ptr, move(array_mov_ptr)));
    return array_raw_ptr;
}

void rrdllx_t::free_zstring_array(zstring_array_t array)
{
    assert(array);
    if (!zstring_array_owner_.count(array))
        throw exception_t(rrdllx_instance_zstring_array_not_found);
    if (!zstring_array_vector_owner_.count(array->vector))
        throw exception_t(rrdllx_instance_zstring_array_not_found);
    for (size_t i = 0; i < array->count; ++i)
        free_zstring(array->vector[i]);
    zstring_array_vector_owner_.erase(array->vector);
    zstring_array_owner_.erase(array);
}

binary_t rrdllx_t::alloc_binary(const vector<uint8_t> &value)
{
    auto data_mov_ptr = make_unique<uint8_t[]>(value.size());
    const auto data_raw_ptr = data_mov_ptr.get();
    binary_data_owner_.insert(make_pair(data_raw_ptr, move(data_mov_ptr)));
    memcpy(data_raw_ptr, value.data(), value.size());

    auto binary_mov_ptr = make_unique<binary_deref_t>(binary_deref_t{value.size(), data_raw_ptr});
    const auto binary_raw_ptr = binary_mov_ptr.get();
    binary_owner_.insert(make_pair(binary_raw_ptr, move(binary_mov_ptr)));
    return binary_raw_ptr;
}

void rrdllx_t::free_binary(binary_t binary)
{
    assert(binary);
    if (!binary_owner_.count(binary))
        throw exception_t(rrdllx_instance_binary_not_found);
    if (!binary_data_owner_.count(binary->data))
        throw exception_t(rrdllx_instance_binary_not_found);
    binary_data_owner_.erase(binary->data);
    binary_owner_.erase(binary);
}

void rrdllx_t::free_all()
{
    zstring_owner_.clear();
    zstring_array_owner_.clear();
    zstring_array_vector_owner_.clear();
    binary_owner_.clear();
    binary_data_owner_.clear();
}

}//namespace rrdllx
