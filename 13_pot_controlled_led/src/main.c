#include <stdio.h>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "pot_led" ;

//config

//ADC config
#define POT_ADC_UNIT    ADC_UNIT_1
#define POT_ADC_CHANNEL ADC1_CHANNEL_6              //gpio34
#define POT_ATTEN       ADC_ATTEN_DB_11             //full range 0-3.3V
#define POT_WIDTH       ADC_WIDTH_BIT_12            //12 bit ADC 0-4095


//pwm config
#define LED_GPIO    2               //led pin
#define LEDC_TIMER  LEDC_TIMER_0
#define LEDC_MODE   LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEl    LEDC_CHANNEL_0
#define LEDC_FREQ       5000
void app_main() {}