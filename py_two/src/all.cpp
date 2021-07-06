#include <pybind11/pybind11.h>

#include "racecar_runtime_two.h"

PYBIND11_MODULE(two_caller, m) {
	m.doc() = "pybind11 example";
	m.def("init", &racecar_runtime_two_init, "Calls racecar runtime two init");
	m.def("counter", &racecar_runtime_two_counter, "Calls racecar runtime two counter");
}
