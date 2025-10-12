#include "stdio.h"
#include "driver/gpio.h"
#include "driver/timer.h"
#include "esp_log.h"

#define TIMER_BASE_CLK 80000000 // 80 MHz for ESP32 APB clock
#define TIMER_DIVIDER 80
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER)
#define TIMER_INTERVAL_SEC 1 // 1 second

#define PULSE_GPIO GPIO_NUM_2

static const char *TAG = "timer_pulse";

static bool IRAM_ATTR timer_isr_callback(void *args)
{
    int level = gpio_get_level(PULSE_GPIO);
    gpio_set_level(PULSE_GPIO, !level);

    return true;
}

void app_main()
{
    gpio_set_direction(PULSE_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(PULSE_GPIO, 0);

    // configure timer

    timer_config_t timer_config = {
        .divider = TIMER_DIVIDER,
        .counter_dir = TIMER_COUNT_UP,
        .counter_en = TIMER_PAUSE,
        .alarm_en = TIMER_ALARM_EN,
        .auto_reload = true,
    };

    timer_init(TIMER_GROUP_0, TIMER_0, &timer_config);
    // set alarm value
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, TIMER_INTERVAL_SEC * TIMER_SCALE);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    // register isr
    timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, timer_isr_callback, NULL, 0);
    // start timer
    timer_start(TIMER_GROUP_0, TIMER_0);
    ESP_LOGI(TAG, "1- second pulse genertion started on GPIO %d", PULSE_GPIO);
}