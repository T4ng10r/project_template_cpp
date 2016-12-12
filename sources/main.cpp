#include <QApplication>
#include <QThread>
#include <memory>
//#include <tools/loggers.h>
#include <gui/main_window.h>
#include <data/data_thread.h>

int main(int argc, char* argv[])
{

  QApplication app(argc, argv);
  app.setApplicationName("");
  app.setOrganizationName("");
  //create_loggers();

  QThread* thread = new QThread;
  DataThread::ptr data_thread(new DataThread());
  data_thread->moveToThread(thread);
  thread->start();

  std::unique_ptr<MainWindow> main_window(new MainWindow(data_thread));
  main_window->show();

  //////////////////////////////////////////////////////////////////////////
  int iReturn = app.exec();
  main_window.release();
  thread->quit();
  return iReturn;
}
