#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <string>

#include "racecar_runtime_one.h"
#include "racecar_driver.h"

void racecar_runtime_one_init()
{
    int retval = 0;
    retval = racecar_driver_init();
    assert(retval == 0);
}

int racecar_runtime_one_counter()
{
    int retval = 0;
    int count = 0;

    retval = racecar_driver_counter(&count);
    assert(retval == 0);

    return count;
}

void racecar_runtime_one_close()
{
    int retval = 0;
    retval = racecar_driver_close();
    assert(retval == 0);
}

