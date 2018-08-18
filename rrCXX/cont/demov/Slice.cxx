/// \copyright The MIT License

#include "Slice.hxx"

#include <cassert>

namespace rrcxx {
namespace demov {

void Slice::pause()
{
    assert(Status::ACTIVE == status_);
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
}

void Slice::fail(const Status failedStatus)
{
    assert(status_ < Status::FINISHED);
    assert(Status::FINISHED < failedStatus);
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
}

}//namespace demov
}//namespace rrcxx
