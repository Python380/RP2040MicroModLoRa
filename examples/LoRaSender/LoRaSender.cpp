#include <string.h>
#include <pico/stdlib.h>
#include "LoRa-RP2040.h"

int main() {

	stdio_init_all();

   while (!stdio_usb_connected()) {}

   LoRa.setPins(21, 17, 6);

	printf("Starting LoRa\n");

	if (!LoRa.begin(915E6)) {
		printf("Starting LoRa failed!\n");
		while (1);
	}
	uint8_t counter = 0;

	while (1) {
		printf("Sending packet: ");
		printf("%d \n",counter);
		// send packet
		LoRa.beginPacket();
		LoRa.print("hello ");
		LoRa.print(counter);
		LoRa.endPacket();

		counter++;
		sleep_ms(5000);
		
  }
  return 0;
}