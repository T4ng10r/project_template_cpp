cmake_minimum_required(VERSION 3.0.0)
ENABLE_TESTING()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1 ) #generate compile commands for YCM
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(functions)
include(options)

add_definitions(-D_VARIADIC_MAX=10)
add_subdirectory(docs)
add_subdirectory(tests)
add_subdirectory(sources)
