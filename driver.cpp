#include "driver.h"

static int counter=0;

int driver_init() {
    counter++;
    return 0;
}

int driver_reference_counter(int *count)
{
    *count = counter;
    return 0;
}

int driver_close()
{
    counter--;
    return 0;
}

