#include <string.h>
#include <pico/stdlib.h>
#include "LoRa-RP2040.h"

int main() {

	stdio_init_all();

	while (!stdio_usb_connected()) {}

	gpio_init(10);
	gpio_set_dir(10, GPIO_OUT);
	gpio_put(10, 1);

	LoRa.setPins(21, 17, 6);
	LoRa.setRfSwitchPins(16, 13);

	if (!LoRa.begin(915E6)) {
		printf("Starting LoRa failed!\n");
		while (1);
	}

	printf("LoRa Started\n");
	uint8_t counter = 0;

	while (1) {
		printf("Sending packet: ");
		printf("%d \n",counter);
		// send packet
		LoRa.beginPacket();
		LoRa.write((uint8_t *)"hello ", 6);
		LoRa.write(&counter, 1);
		LoRa.endPacket();
		printf("end/send\n");

		counter++;
		sleep_ms(1000);
		
  }
  return 0;
}