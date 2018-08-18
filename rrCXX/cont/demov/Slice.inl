/// \copyright The MIT License

#pragma once
#ifndef RRCXX_SLICE_INL_
#define RRCXX_SLICE_INL_

#include <cassert>

namespace rrcxx {
namespace demov {

inline Slice::Slice(const unsigned serialNumber, const Stage stage, const std::string &path)
{
    serialNumber_ = serialNumber;
    status_ = Status::ACTIVE;
    stage_ = stage;
    stageProgress_ = 0;
    path_ = path;
}

inline Slice Slice::Original(const std::string &path)
{
    return Slice(0, Stage::ORIGINAL, path);
}

inline Slice Slice::Fragment(const unsigned serialNumber, const std::string &path)
{
    return Slice(serialNumber, Stage::TRANSCODED, path);
}

inline void Slice::resume()
{
    assert(Status::PAUSING == status_);
    status_ = Status::ACTIVE;
}

inline void Slice::retry()
{
    assert(Status::FINISHED < status_);
    status_ = Status::ACTIVE;
}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_SLICE_INL_
