
cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(pathToProject C:/Users/Administrator/Desktop/newFile/NdkCamera)
include_directories(C:/Boost/include/boost-1_63)
#set (CMAKE_CXX_STANDARD 11)

add_library(
             seriport
             SHARED
             src/main/cpp/Logger.hpp
             src/main/cpp/native-lib.cpp
)
add_library(boost_system STATIC IMPORTED)
set_target_properties(boost_system PROPERTIES IMPORTED_LOCATION ${pathToProject}/app/src/main/jniLibs/${ANDROID_ABI}/libboost_system.a)
find_library(log-lib
              log)

target_link_libraries(seriport
                       boost_system
                       ${log-lib}
                       )
