#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define button_pin GPIO_NUM_13
#define led_pin GPIO_NUM_2

void app_main(void)
{
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(button_pin, GPIO_MODE_INPUT);

    int led_state = 0;
    int last_state = 1;

    while (1)
    {
        int button_state = gpio_get_level(button_pin);
        if ((button_state == 0) && (last_state == 1))
        {
            led_state = !led_state;
            gpio_set_level(led_pin, led_state);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
        last_state = button_state;
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}