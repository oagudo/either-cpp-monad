cmake_minimum_required (VERSION 2.8)
project (EitherCppMonad)

# Set compiler flags and options.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++1y") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

# Sub-directories where more CMakeLists.txt exist
find_package(Boost 1.49 COMPONENTS system thread date_time REQUIRED)

FILE(GLOB_RECURSE SOURCES "main.cpp")
FILE(GLOB_RECURSE INCLUDES "include/*.h")


# Include Directories
include_directories (./include) 
include_directories (${Boost_INCLUDE_DIR})

link_directories(${Boost_LIBRARY_DIR})

add_executable (eitherMonad ${SOURCES})

target_link_libraries(eitherMonad ${Boost_LIBRARIES})


