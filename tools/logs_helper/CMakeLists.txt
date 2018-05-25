project(LogsHelper)
include_directories(${Qt5Core_INCLUDE_DIRS})

include_directories(${Boost_INCLUDE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/include
                    ${log4cplus_SOURCE_DIR}/include
                    ${log4cplus_BINARY_DIR}/include)

SET ( TOOLS_SRC
  qtTools.cpp
  loggers.cpp
  qtTools.h
  loggers.h  )

IF (WIN32)
  SOURCE_GROUP(tools FILES ${TOOLS_SRC})
endif(WIN32)

add_library(logs_helper_lib STATIC ${TOOLS_SRC} )
target_link_libraries(logs_helper_lib ${LOGGER_LIBRARY} ${Boost_LIBRARIES} )
