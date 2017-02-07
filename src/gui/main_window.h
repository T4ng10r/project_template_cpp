#pragma once
#include <QtWidgets/QMainWindow>
#include <memory>
#include <data/data_thread.h>
//#include <logging_base.h>

class MainWindowPrivate;

class MainWindow : public QMainWindow //, public LoggingBase
{
  Q_OBJECT

public:
  MainWindow(DataThread::ptr data_thread);
  ~MainWindow();
protected:
  std::unique_ptr<MainWindowPrivate> _pimpl;
};
