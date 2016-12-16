#include <data/data_thread.h>
//#include <logging_base.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <fstream>
#include <iostream>

static const QString settings_file(""); //xml file path and name

class DataThreadPrivate { //: public LoggingBase {
 public:
  DataThreadPrivate(DataThread *pub);
  void load_settings(QString file = settings_file);

 public:
  DataThread *_pub;
  boost::property_tree::ptree settings_tree;
};

DataThreadPrivate::DataThreadPrivate(DataThread *pub) : _pub(pub) {
  load_settings();
//  logger.log(log4cplus::INFO_LOG_LEVEL,
//             str(boost::format("Data thread created")));
}

void DataThreadPrivate::load_settings(QString file) {
  logger.log(
      log4cplus::INFO_LOG_LEVEL,
      str(boost::format("Loading properties file (%1%)") % file.toStdString()));
  using boost::property_tree::ptree;

  try {
    std::basic_ifstream<char> stream(file.toLatin1());
    read_xml(stream, settings_tree);
  } catch (boost::property_tree::xml_parser::xml_parser_error const & /*ex*/) {
    //logger.log(log4cplus::ERROR_LOG_LEVEL, "Lack of properties file");
  }
  //logger.log(log4cplus::DEBUG_LOG_LEVEL,
  //           "Settings: loading settings from file finished");
}

////////////////////////////////////////////////////////////////////////////////
DataThread::DataThread() : _pimpl(new DataThreadPrivate(this)) {}
DataThread::~DataThread() {}

boost::property_tree::ptree DataThread::get_settings() {
  return _pimpl->settings_tree;
}
