



cmake_minimum_required(VERSION 3.24 FATAL_ERROR)


set(SSH_UTILS ssh_utils)

add_library(${SSH_UTILS}
    STATIC
    ssh_conn.cpp  
    ssh_utils_exception.cpp
)

target_include_directories(ssh_utils PRIVATE ${LIBSSH_INCLUDE_DIRS})
target_link_libraries(ssh_utils PRIVATE ${LIBSSH_LIBRARIES})
target_include_directories(ssh_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
