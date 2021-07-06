#include <iostream>

#include "racecar_driver.h"

static int counter=0;

#define COUT(addr) \
std::cout << __func__ << "\t" << (void*)(addr) \
          << "\tcounter\t" << counter \
          << "\taddr\t" << &counter \
          << std::endl

int racecar_driver_init()
{
    counter++;
    COUT(&racecar_driver_init);
    return 0;
}

int racecar_driver_counter(int *count)
{
    *count = counter;
    COUT(&racecar_driver_counter);
    return 0;
}

int racecar_driver_close()
{
    counter--;
    COUT(&racecar_driver_close);
    return 0;
}

