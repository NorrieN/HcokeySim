cmake_minimum_required(VERSION 4.3)
project(HockeySim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/nathanael/Qt/6.12.0/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(HockeySim main.cpp
        player.cpp
        player.h
        Forward.cpp
        Forward.h
        Defence.cpp
        Defence.h
        Goalie.cpp
        Goalie.h
        Skater.cpp
        Skater.h)
target_link_libraries(HockeySim
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

