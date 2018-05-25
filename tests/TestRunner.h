#ifndef TESTRUNNER_H
#define TESTRUNNER_H

// Qt includes
#include <QSharedPointer>
#include <QTest>
// std includes
#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>

//////////////////////////////////////////////////////////////////////////
// Test Runner allows automatic execution of tests
class TestRunner {
 public:
  static TestRunner& Instance() {
    static TestRunner instance;
    return instance;
  }

  template <typename T>
  char RegisterTest(const char* name) {
    if (std::find_if(m_tests.begin(), m_tests.begin(),
                     [&name](QSharedPointer<QObject>& elem) {
                       return elem->objectName() == name;
                     }) == end(m_tests)) {
      QSharedPointer<QObject> test(new T());
      test->setObjectName(name);
      m_tests.push_back(test);
    }
    return char(1);
  }

  int RunAll(int argc, char* argv[]) {
    int errorCode = 0;
    std::for_each(begin(m_tests), end(m_tests),
                  [&](QSharedPointer<QObject>& test) {
                    errorCode |= QTest::qExec(test.data(), argc, argv);
                    std::cout << std::endl;
                  });

    return errorCode;
  }

 private:
  std::list<QSharedPointer<QObject> > m_tests;
};

// Use this macro after your test declaration
#define DECLARE_TEST(className)  \
  static char test_##className = \
      TestRunner::Instance().RegisterTest<className>(#className);

// Use this macro to execute all tests
#define RUN_ALL_QTESTS(argc, argv) TestRunner::Instance().RunAll(argc, argv)

#endif  // TESTRUNNER_H
