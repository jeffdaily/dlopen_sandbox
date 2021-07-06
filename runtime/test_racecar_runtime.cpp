#include "racecar_runtime.h"

int main(int argc, char **argv)
{
    int count = 0;

    racecar_runtime_init();

    count = racecar_runtime_counter();

    return 0;
}
