#include <stdlib.h>
#include <stdint.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "systick.h"
#include "usb.h"

void main(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	init_systick();
	init_usb();

	// configure status LED
	rcc_periph_clock_enable(RCC_GPIOC);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

	// TODO: ADD INITIALIZATION HERE

	while(1) {
		usb_poll();

		// TODO: OTHER LOOP CODE HERE
	}
}
