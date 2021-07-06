ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I ../driver -I ../../driver
AM_CXXFLAGS = -std=c++11

lib_LTLIBRARIES = libracecar_runtime_one.la
libracecar_runtime_one_la_SOURCES = racecar_runtime_one.cpp DynamicLibrary.cpp
include_HEADERS = racecar_runtime_one.h

check_PROGRAMS = test_racecar_runtime_one
test_racecar_runtime_one_SOURCES = test_racecar_runtime_one.cpp
test_racecar_runtime_one_LDADD = libracecar_runtime_one.la -ldl

TESTS = test_racecar_runtime_one
