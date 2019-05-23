/// \copyright Unlicense

#define _CRT_SECURE_NO_WARNINGS

#include "instance.hxx"

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

byte8_parray_t rrdllx_t::alloc_byte8_array(const vector<uint8_t> &value)
{
    const auto size = value.size();
    auto owner = make_unique<uint8_t[]>(value.size());
    const auto data = owner.get();

    auto data_pair = make_pair(size, move(owner));
    auto map_pair = make_pair(data, move(data_pair));
    byte8_array_owner_.insert(move(map_pair));

    memcpy(data, value.data(), value.size() * sizeof(uint8_t));

    return make_pair(size, data);
}

void rrdllx_t::free_byte8_array(byte8_rarray_t byte8_rarray)
{
    if (!byte8_array_owner_.count(byte8_rarray))
        throw exception_t(rrdllx_instance_byte8_array_not_found);
    byte8_array_owner_.erase(byte8_rarray);
}

char_parray_t rrdllx_t::alloc_char_array(const vector<char> &value)
{
    const auto size = value.size();
    auto owner = make_unique<char[]>(value.size());
    const auto data = owner.get();

    auto data_pair = make_pair(size, move(owner));
    auto map_pair = make_pair(data, move(data_pair));
    char_array_owner_.insert(move(map_pair));

    memcpy(data, value.data(), value.size() * sizeof(char));

    return make_pair(size, data);
}

void rrdllx_t::free_char_array(char_rarray_t char_rarray)
{
    if (!char_array_owner_.count(char_rarray))
        throw exception_t(rrdllx_instance_char_array_not_found);
    char_array_owner_.erase(char_rarray);
}

zstring_t rrdllx_t::alloc_zstring(const string &value)
{
    return alloc_char_array({value.data(), value.data() + value.size() + 1}).second;
}

zstring_t rrdllx_t::alloc_last_internal_error_zstring()
{
    return alloc_zstring(last_internal_error());
}

void rrdllx_t::free_zstring(zstring_t zstring)
{
    free_char_array(zstring);
}

zstring_parray_t rrdllx_t::alloc_zstring_array(const vector<string> &value)
{
    const auto size = value.size();
    auto owner = make_unique<zstring_t[]>(value.size());
    const auto data = owner.get();

    auto data_pair = make_pair(size, move(owner));
    auto map_pair = make_pair(data, move(data_pair));
    zstring_array_owner_.insert(move(map_pair));

    for (size_t i = 0; i < value.size(); ++i)
        data[i] = alloc_zstring(value.at(i));

    return make_pair(size, data);
}

void rrdllx_t::free_zstring_array(zstring_rarray_t zstring_rarray)
{
    if (!zstring_array_owner_.count(zstring_rarray))
        throw exception_t(rrdllx_instance_zstring_array_not_found);
    const auto &oarray = zstring_array_owner_.at(zstring_rarray);
    for (size_t i = 0; i < oarray.first; ++i)
        free_zstring(oarray.second[i]);
    zstring_array_owner_.erase(zstring_rarray);
}

void rrdllx_t::free_all()
{
    byte8_array_owner_.clear();
    char_array_owner_.clear();
    zstring_array_owner_.clear();
}

void rrdllx_t::last_internal_error(const std::string &txt)
{
    const auto tid = this_thread::get_id();
    last_internal_error_[tid] = txt;
}

std::string rrdllx_t::last_internal_error()
{
    const auto tid = this_thread::get_id();
    return last_internal_error_[tid];
}

}//namespace rrdllx
