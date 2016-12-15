## Use compiler debugging flags per default
INCLUDE(CxxFlags)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories($ENV{QTDIR}
                    ${Boost_INCLUDE_DIR}
                    ${tools_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/tools/tools
                    ${log4cplus_SOURCE_DIR}/include
                    ${log4cplus_BINARY_DIR}/include)


list(REMOVE_ITEM PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(${PROJECT_NAME}_lib STATIC ${PROJECT_SRCS} )
#set(${PROJECT_NAME}_lib ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)

target_link_libraries(${PROJECT_NAME}_lib log4cplus
                      Qt5::Core gcov)


add_executable(${PROJECT_NAME}
               main.cpp )
target_link_libraries(${PROJECT_NAME}
      ${Boost_SYSTEM_LIBRARY} log4cplus tools_lib ${PROJECT_NAME}_lib )


