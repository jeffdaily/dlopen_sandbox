ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I ../driver -I ../../driver
AM_CXXFLAGS = -std=c++11

lib_LTLIBRARIES = libracecar_runtime_two.la
libracecar_runtime_two_la_SOURCES = racecar_runtime_two.cpp DynamicLibrary.cpp
include_HEADERS = racecar_runtime_two.h

check_PROGRAMS = test_racecar_runtime_two
test_racecar_runtime_two_SOURCES = test_racecar_runtime_two.cpp
test_racecar_runtime_two_LDADD = libracecar_runtime_two.la -ldl

TESTS = test_racecar_runtime_two
