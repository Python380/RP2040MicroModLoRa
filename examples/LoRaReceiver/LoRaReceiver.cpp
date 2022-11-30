#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

// Inlude Library
#include "LoRa-RP2040.h"

int main()
{

    stdio_init_all();

    while (!stdio_usb_connected()){}

    gpio_init(10);
    gpio_set_dir(10, GPIO_OUT);
    gpio_put(10, 1);

    LoRa.setPins(21, 17, 6);
    LoRa.setRfSwitchPins(16, 13);

    if (!LoRa.begin(915E6))
    {
        printf("Starting LoRa failed!\n");
        while (1);
    }

    printf("LoRa Started\n");

    int counter = 0;

    LoRa.dumpRegisters();

    while (1)
    {
        if (LoRa.available())
        {
            // received a packet
            printf("Received packet \n'");

            // read packet
            while (LoRa.available())
            {
                printf((char *)LoRa.read());
            }

            // print RSSI of packet
            printf("' with RSSI \n");
            printf((char *)LoRa.packetRssi(), "\n");
        }
    }

    return 1;
}