cmake_minimum_required(VERSION 3.17)
project(SpreadSheetEs2)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(SpreadSheetEs2 main.cpp Subject.h Observer.h Values.cpp Values.h Operations.cpp Operations.h Interface.cpp Interface.h)
target_link_libraries(SpreadSheetEs2 ${CURSES_LIBRARIES})