# CMakeList.txt: проект CMake для Rational; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (rational)

add_executable(testRat testRat.cpp)

add_library(rational rational.cpp rational.h)

target_link_libraries(testRat rational)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET rational PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
