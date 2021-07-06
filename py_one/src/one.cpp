#include <pybind11/pybind11.h>

#include "racecar_runtime.h"

PYBIND11_MODULE(one_caller, m) {
	m.doc() = "pybind11 example";
	m.def("init", &racecar_runtime_init, "Calls racecar runtime init");
	m.def("counter", &racecar_runtime_counter, "Calls racecar runtime counter");
}
