IF( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage ")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories($ENV{QTDIR}
                    ${Boost_INCLUDE_DIR}
                    ${Qt5Test_INCLUDE_DIRS}
                    ${tools_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/tools
                    ${log4cplus_SOURCE_DIR}/include
                    ${log4cplus_BINARY_DIR}/include)

#####################
SET ( SOURCES_MAIN
      main.cpp
      TestRunner.h )

add_executable(${PROJECT_NAME}_ut ${TEST_SRCS})
set_property(TARGET ${PROJECT_NAME}_ut PROPERTY CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME}_ut Qt5::Test ${PROJECT_NAME}_lib
                      log4cplus tools_lib)

ADD_TEST(NAME UT COMMAND ${PROJECT_NAME}_ut)
