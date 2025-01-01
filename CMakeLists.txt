cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

project(ssh_tools)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSSH REQUIRED libssh)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(fmt REQUIRED)

if(NOT LIBSSH_INCLUDE_DIRS OR NOT LIBSSH_LIBRARIES)

    message(FATAL_ERROR "libssh library not found!")

endif()
 
 
add_subdirectory(ssh_utils)
add_subdirectory(ssh_window)
add_executable(ssh_tools
    main.cpp 
)

message(STATUS "LIBSSH_INCLUDE_DIS: ${LIBSSH_INCLUDE_DIRS}")
message(STATUS "LIBSSH_LIBRARIES: ${LIBSSH_LIBRARIES}")


target_include_directories(ssh_tools PRIVATE ${LIBSSH_INCLUDE_DIRS})
target_link_libraries(ssh_tools PRIVATE ${LIBSSH_LIBRARIES})
target_link_libraries(ssh_tools PUBLIC Qt6::Widgets)
target_link_libraries(ssh_tools PRIVATE fmt::fmt) 
target_link_libraries(ssh_tools PRIVATE ssh_utils ssh_window)
target_include_directories(ssh_tools PUBLIC ${CMAKE_SOURCE_DIR}/ssh_utils)