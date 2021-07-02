ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libracecar_driver.la
libracecar_driver_la_SOURCES = racecar_driver.cpp
include_HEADERS = racecar_driver.h

check_PROGRAMS = test_racecar_driver
test_racecar_driver_SOURCES = test_racecar_driver.cpp
test_racecar_driver_LDADD = libracecar_driver.la

TESTS = test_racecar_driver
