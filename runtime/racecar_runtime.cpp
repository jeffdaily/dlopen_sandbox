#include <assert.h>
#include <stdexcept>
#include <string>

#include "DynamicLibrary.h"

#include "racecar_runtime.h"
#include "racecar_driver.h"

namespace dynamic {

DynamicLibrary getLibrary() {
    static DynamicLibrary lib("libracecar_driver.so");
    return lib;
}

int racecar_driver_init() {
    auto fn = reinterpret_cast<decltype(&racecar_driver_init)>(getLibrary().sym(__func__));
    if (!fn)
        throw std::runtime_error(std::string("Can't get ") + __func__);
    return fn();
}

int racecar_driver_counter(int *count) {
    auto fn = reinterpret_cast<decltype(&racecar_driver_counter)>(getLibrary().sym(__func__));
    if (!fn)
        throw std::runtime_error(std::string("Can't get ") + __func__);
    return fn(count);
}

int racecar_driver_close() {
    auto fn = reinterpret_cast<decltype(&racecar_driver_close)>(getLibrary().sym(__func__));
    if (!fn)
        throw std::runtime_error(std::string("Can't get ") + __func__);
    return fn();
}

}

void racecar_runtime_init()
{
    int retval = 0;
    retval = dynamic::racecar_driver_init();
    assert(retval == 0);
}

int racecar_runtime_counter()
{
    int retval = 0;
    int count = 0;

    retval = dynamic::racecar_driver_counter(&count);
    assert(retval == 0);

    return count;
}

void racecar_runtime_close()
{
    int retval = 0;
    retval = dynamic::racecar_driver_close();
    assert(retval == 0);
}

