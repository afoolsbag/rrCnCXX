/// \copyright The MIT License

#include "Slice.hxx"

#include <cassert>

namespace rrcxx {
namespace demov {

bool Slice::pause()
{
    if (Status::ACTIVE != status_)
        return false;
    status_ = Status::PAUSING;
    switch (stage_) {
    case Stage::UPLOADING:   stage_ = Stage::ORIGINAL;   break;
    case Stage::TRANSCODING: stage_ = Stage::UPLOADED;   break;
    case Stage::EXTRACTING:  stage_ = Stage::TRANSCODED; break;
    case Stage::DETECTING:   stage_ = Stage::TRANSCODED; break;
    case Stage::RECOGNIZING: stage_ = Stage::TRANSCODED; break;
    default:                                             break;
    }
    stageProgress_ = 0;
    return true;
}

bool Slice::resume()
{
    if (Status::PAUSING != status_)
        return false;
    status_ = Status::ACTIVE;
    return true;
}

bool Slice::fail(const Status failedStatus)
{
    assert(Status::FINISHED < failedStatus);
    if (Status::FINISHED <= status_)
        return false;
    status_ = failedStatus;
    switch (stage_) {
    case Stage::UPLOADING:   stage_ = Stage::ORIGINAL;   break;
    case Stage::TRANSCODING: stage_ = Stage::UPLOADED;   break;
    case Stage::EXTRACTING:  stage_ = Stage::TRANSCODED; break;
    case Stage::DETECTING:   stage_ = Stage::TRANSCODED; break;
    case Stage::RECOGNIZING: stage_ = Stage::TRANSCODED; break;
    default:                                             break;
    }
    stageProgress_ = 0;
    return true;
}

bool Slice::retry()
{
    if (status_ <= Status::FINISHED)
        return false;
    status_ = Status::ACTIVE;
    return true;
}

bool Slice::upload(const double progress, const bool finished, const std::string &newPath)
{
    if (Status::ACTIVE != status_)
        return false;
    if (Stage::ORIGINAL == stage_)
        stage_ = Stage::UPLOADING;
    if (Stage::UPLOADING != stage_)
        return false;
    stageProgress_ = progress;
    if (finished) {
        stage_ = Stage::UPLOADED;
        if (!newPath.empty())
            path_ = newPath;
    }
    return true;
}

bool Slice::transcode(const double progress, const bool finished)
{
    if (Status::ACTIVE != status_)
        return false;
    if (Stage::UPLOADED == stage_)
        stage_ = Stage::TRANSCODING;
    if (Stage::TRANSCODING != stage_)
        return false;
    stageProgress_ = progress;
    if (finished)
        stage_ = Stage::TRANSCODED;
    return true;
}

bool Slice::extract(const double progress, const bool finished)
{
    if (Status::ACTIVE != status_)
        return false;
    if (Stage::TRANSCODED == stage_)
        stage_ = Stage::EXTRACTING;
    if (Stage::EXTRACTING != stage_)
        return false;
    stageProgress_ = progress;
    if (finished)
        stage_ = Stage::EXTRACTED;
    return true;
}

bool Slice::detect(const double progress, const bool finished)
{
    if (Status::ACTIVE != status_)
        return false;
    if (Stage::EXTRACTED == stage_)
        stage_ = Stage::DETECTING;
    if (Stage::DETECTING != stage_)
        return false;
    stageProgress_ = progress;
    if (finished)
        stage_ = Stage::DETECTED;
    return true;
}

bool Slice::recognize(const double progress, const bool finished)
{
    if (Status::ACTIVE != status_)
        return false;
    if (Stage::DETECTED == stage_)
        stage_ = Stage::RECOGNIZING;
    if (Stage::RECOGNIZING != stage_)
        return false;
    stageProgress_ = progress;
    if (finished) {
        status_ = Status::FINISHED;
        stage_ = Stage::RECOGNIZED;
    }
    return true;
}

}//namespace demov
}//namespace rrcxx
