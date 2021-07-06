ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I ../driver -I ../../driver
AM_CXXFLAGS = -std=c++11

lib_LTLIBRARIES = libracecar_runtime.la
libracecar_runtime_la_SOURCES = racecar_runtime.cpp DynamicLibrary.cpp
include_HEADERS = racecar_runtime.h

check_PROGRAMS = test_racecar_runtime
test_racecar_runtime_SOURCES = test_racecar_runtime.cpp
test_racecar_runtime_LDADD = libracecar_runtime.la -ldl

TESTS = test_racecar_runtime
