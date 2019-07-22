#include <data/data_thread.h>
#include <logging_base.h>
#include <fstream>
#include <iostream>

static const QString settings_file(""); //xml file path and name

class DataThreadPrivate : public logger_helper::LoggingBase {
 public:
  DataThreadPrivate(DataThread *pub);

 public:
  DataThread *_pub;
};

DataThreadPrivate::DataThreadPrivate(DataThread *pub) : _pub(pub) {
    logger->info("Data thread created");
}

////////////////////////////////////////////////////////////////////////////////
DataThread::DataThread() : _pimpl(new DataThreadPrivate(this)) {}
DataThread::~DataThread() {}
