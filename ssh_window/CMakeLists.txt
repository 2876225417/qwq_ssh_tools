cmake_minimum_required(VERSION 3.24 FATAL_ERROR)



find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(ssh_window
    STATIC
    mainwindow.cpp
    ssh_config.cpp
    ssh_config_panel.cpp
    ssh_cmd_panel.cpp
)

target_link_libraries(ssh_window PRIVATE Qt6::Widgets)
target_link_libraries(ssh_window PRIVATE ssh_utils)