#include "racecar_runtime_one.h"

int main(int argc, char **argv)
{
    int count = 0;

    racecar_runtime_one_init();

    count = racecar_runtime_one_counter();

    return 0;
}
