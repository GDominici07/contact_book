#CMAKE 3.27.7 version

cmake_minimum_required(VERSION 3.27.7)
project(contact_book VERSION 1.0)

SET(CMAKE_CXX_FLAGS  "-fpermissive")

add_executable(contact contact_book/main.cc)

