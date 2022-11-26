#include <stdio.h>
#include <iostream>

#include "pico/stdlib.h"
#include "pico/multicore.h"

int main()
{
    set_sys_clock_khz(250000, true);
    setSystemPowerHigh();

    stdio_init_all();
    DEBUG &&std::cout.precision(4);
    sleep_ms(7500);
}
