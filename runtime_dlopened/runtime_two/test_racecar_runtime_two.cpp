#include "racecar_runtime_two.h"

int main(int argc, char **argv)
{
    int count = 0;

    racecar_runtime_two_init();

    count = racecar_runtime_two_counter();

    return 0;
}
