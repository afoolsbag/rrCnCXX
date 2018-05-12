#pragma once
#ifndef DATASTREAM_HXX_
#define DATASTREAM_HXX_

#include <map>
#include <string>
#include <vector>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/array.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/utility.hpp>

#include <avro/buffer/Buffer.hh>
#include <avro/Config.hh>
#include <avro/DataFile.hh>
#include <avro/Encoder.hh>
#include <avro/ValidSchema.hh>
#include <avro/Specific.hh>
#include <avro/Stream.hh>

namespace avro {

class DataStreamWriterBase : boost::noncopyable {
    const ValidSchema schema_;
    const EncoderPtr encoderPtr_;
    const size_t syncInterval_;
    Codec codec_;

    std::unique_ptr<OutputStream> stream_;
    std::unique_ptr<OutputStream> buffer_;
    const DataFileSync sync_;
    int64_t objectCount_;

    typedef std::map<std::string, std::vector<uint8_t> > Metadata;

    Metadata metadata_;

    static DataFileSync makeSync();

    void writeHeader();
    void setMetadata(const std::string& key, const std::string& value);

    void sync();

public:
    Encoder& encoder() const { return *encoderPtr_; }

    void syncIfNeeded();

    void incr() {
        ++objectCount_;
    }
    DataStreamWriterBase(std::ostream &os, const ValidSchema& schema,
        size_t syncInterval, Codec codec = NULL_CODEC);

    ~DataStreamWriterBase();
    void close();

    const ValidSchema& schema() const { return schema_; }

    void flush();
};

template <typename T>
class DataStreamWriter : boost::noncopyable {
    std::unique_ptr<DataStreamWriterBase> base_;
public:
    DataStreamWriter(std::ostream &os, const ValidSchema& schema,
        size_t syncInterval = 16 * 1024, Codec codec = NULL_CODEC) :
        base_(new DataStreamWriterBase(os, schema, syncInterval, codec)) { }

    void write(const T& datum) {
        base_->syncIfNeeded();
        avro::encode(base_->encoder(), datum);
        base_->incr();
    }

    void close() { base_->close(); }

    const ValidSchema& schema() const { return base_->schema(); }

    void flush() { base_->flush(); }
};

class DataStreamReaderBase : boost::noncopyable {
    const std::unique_ptr<InputStream> stream_;
    const DecoderPtr decoder_;
    int64_t objectCount_;
    bool eof_;
    Codec codec_;

    ValidSchema readerSchema_;
    ValidSchema dataSchema_;
    DecoderPtr dataDecoder_;
    std::unique_ptr<InputStream> dataStream_;
    typedef std::map<std::string, std::vector<uint8_t> > Metadata;

    Metadata metadata_;
    DataFileSync sync_;

    boost::scoped_ptr<boost::iostreams::filtering_istream> os_;
    std::vector<char> compressed_;

    void readHeader();

    bool readDataBlock();
public:
    Decoder& decoder() { return *dataDecoder_; }

    bool hasMore();

    void decr() { --objectCount_; }

    DataStreamReaderBase(std::istream &is);

    void init();

    void init(const ValidSchema& readerSchema);

    const ValidSchema& readerSchema() { return readerSchema_; }

    const ValidSchema& dataSchema() { return dataSchema_; }

    void close();
};

template <typename T>
class DataStreamReader : boost::noncopyable {
    std::unique_ptr<DataStreamReaderBase> base_;
public:
    DataStreamReader(std::istream &is, const ValidSchema& readerSchema) :
        base_(new DataStreamReaderBase(is)) {
        base_->init(readerSchema);
    }

    DataStreamReader(std::istream &is) :
        base_(new DataStreamReaderBase(is)) {
        base_->init();
    }

    DataStreamReader(std::unique_ptr<DataStreamReaderBase> base) : base_(base) {
        base_->init();
    }

    DataStreamReader(std::unique_ptr<DataStreamReaderBase> base,
        const ValidSchema& readerSchema) : base_(base) {
        base_->init(readerSchema);
    }

    bool read(T& datum) {
        if (base_->hasMore()) {
            base_->decr();
            avro::decode(base_->decoder(), datum);
            return true;
        }
        return false;
    }

    const ValidSchema& readerSchema() { return base_->readerSchema(); }

    const ValidSchema& dataSchema() { return base_->dataSchema(); }

    void close() { return base_->close(); }
};

}// namespace avro

#endif//DATASTREAM_HXX_
