## Use compiler debugging flags per default
INCLUDE(CxxFlags)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE PROJECT_SRCS *.cpp *.h *.ui *.qml)
list(REMOVE_ITEM PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(${PROJECT_NAME}_lib STATIC ${PROJECT_SRCS} )
set_property(TARGET ${PROJECT_NAME}_lib PROPERTY CXX_STANDARD 14)

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${logs_helper_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_lib logs_helper_lib
                      Qt5::Core Qt5::Widgets Qt5::Gui
                     # ${GCOV_LIBRARY}
                     )

add_executable(${PROJECT_NAME}
    main.cpp )

target_link_libraries(${PROJECT_NAME}
      ${PROJECT_NAME}_lib )

    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    #        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Mingw_Path}/libgcc_s_seh-1.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
    #        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Mingw_Path}/libstdc++-6.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
    #        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Mingw_Path}/libwinpthread-1.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}>/logs
    )


