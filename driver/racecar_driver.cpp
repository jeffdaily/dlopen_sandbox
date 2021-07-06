#include <iostream>

#include "racecar_driver.h"

static int counter=0;

int racecar_driver_init()
{
    counter++;
    std::cout << "racecar_driver_init counter " << counter << std::endl;
    return 0;
}

int racecar_driver_counter(int *count)
{
    std::cout << "racecar_driver_counter" << std::endl;
    *count = counter;
    return 0;
}

int racecar_driver_close()
{
    counter--;
    std::cout << "racecar_driver_close counter " << counter << std::endl;
    return 0;
}

