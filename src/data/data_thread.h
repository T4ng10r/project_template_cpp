#pragma once
#include <QObject>
#include <memory>
#include <boost/property_tree/ptree.hpp>

class DataThreadPrivate;

class DataThread : public QObject
{
  Q_OBJECT
public:
    typedef std::shared_ptr<DataThread> ptr;

    DataThread();
    ~DataThread();
    boost::property_tree::ptree get_settings();
private:
    friend class DataThreadPrivate;
    std::unique_ptr<DataThreadPrivate> _pimpl;
};
