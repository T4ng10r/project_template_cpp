#pragma once
#include <QObject>
#include <memory>

class DataThreadPrivate;

class DataThread : public QObject
{
  Q_OBJECT
public:
    typedef std::shared_ptr<DataThread> ptr;

    DataThread();
    ~DataThread();
private:
    friend class DataThreadPrivate;
    std::unique_ptr<DataThreadPrivate> _pimpl;
};
