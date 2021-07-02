#include <assert.h>

#include "racecar_driver.h"

int main(int argc, char **argv)
{
    int retval = 0;
    int count = 0;

    retval = racecar_driver_init();
    assert(retval == 0);

    retval = racecar_driver_counter(&count);
    assert(retval == 0);
    assert(count == 1);

    retval = racecar_driver_close();
    assert(retval == 0);

    return 0;
}
