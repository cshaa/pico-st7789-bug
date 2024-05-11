#include <stdio.h>
#include "pico/stdlib.h"

#ifdef PICO_W
const uint LED_PIN = CYW43_WL_GPIO_LED_PIN;
#else
const uint LED_PIN = PICO_DEFAULT_LED_PIN;
#endif

uint32_t time_ms()
{
    return (time_us_32() / 1000);
}

#ifdef PICO_W
void led_setup()
{
    cyw43_arch_init();
}
void led_on()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}
void led_off()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}
#else
void led_setup()
{
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}
void led_on()
{
    gpio_put(PICO_DEFAULT_LED_PIN, true);
}
void led_off()
{
    gpio_put(PICO_DEFAULT_LED_PIN, false);
}
#endif

int main()
{
    stdio_init_all();

    led_setup();

    while (true)
    {
        printf("Hello, world! (%i)\n", time_ms() / 1000);
        led_on();
        sleep_ms(500);
        led_off();
        sleep_ms(500);
    }
}
