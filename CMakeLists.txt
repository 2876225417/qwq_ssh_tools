cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)


project(qwq_ssh_tools)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSSH REQUIRED libssh)

if(NOT LIBSSH_INCLUDE_DIRS OR NOT LIBSSH_LIBRARIES)

    message(FATAL_ERROR "libssh library not found!")

endif()

add_executable(ssh_tools
    main.cpp
)

message(STATUS "LIBSSH_INCLUDE_DIS: ${LIBSSH_INCLUDE_DIRS}")
message(STATUS "LIBSSH_LIBRARIES: ${LIBSSH_LIBRARIES}")

target_include_directories(ssh_tools PRIVATE ${LIBSSH_INCLUDE_DIRS})
target_link_libraries(ssh_tools PRIVATE ${LIBSSH_LIBRARIES})
