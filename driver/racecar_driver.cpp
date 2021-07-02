#include "racecar_driver.h"

static int counter=0;

int racecar_driver_init() {
    counter++;
    return 0;
}

int racecar_driver_reference_counter(int *count)
{
    *count = counter;
    return 0;
}

int racecar_driver_close()
{
    counter--;
    return 0;
}

