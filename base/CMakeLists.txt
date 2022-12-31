cmake_minimum_required(VERSION 3.0)

project(tippy-base)

add_library(${PROJECT_NAME} STATIC utf8.cc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../)
target_link_libraries(${PROJECT_NAME} PUBLIC runtime::angle)

add_library(tippy::base ALIAS ${PROJECT_NAME})