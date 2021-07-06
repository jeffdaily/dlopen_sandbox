#include <pybind11/pybind11.h>

#include "racecar_runtime_one.h"

PYBIND11_MODULE(one_caller, m) {
	m.doc() = "pybind11 example";
	m.def("init", &racecar_runtime_one_init, "Calls racecar runtime one init");
	m.def("counter", &racecar_runtime_one_counter, "Calls racecar runtime one counter");
}
