



cmake_minimum_required(VERSION 3.24 FATAL_ERROR)


set(SSH_UTILS ssh_utils)

add_library(${SSH_UTILS}
    STATIC
    ssh_conn.cpp
)
