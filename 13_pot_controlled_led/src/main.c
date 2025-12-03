#include <stdio.h>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "pot_led" ;

//config

//ADC configs
#define POT_ADC_UNIT    ADC_UNIT_1
#define POT_ADC_CHANNEL ADC1_CHANNEL_6              //gpio34
#define POT_ATTEN       ADC_ATTEN_DB_11             //full range 0-3.3V
#define POT_WIDTH       ADC_WIDTH_BIT_12            //12 bit ADC 0-4095


//pwm config
#define LED_GPIO    5               //led pin
#define LEDC_TIMER  LEDC_TIMER_0
#define LEDC_MODE   LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEl    LEDC_CHANNEL_0
#define LEDC_FREQ       5000
#define LEDC_DUTY_RES   14

static void ADCInit(){
    adc1_config_width(POT_WIDTH);
    adc1_config_channel_atten(POT_ADC_CHANNEL , POT_ATTEN);

}
static void LEDCInit(){
        ledc_timer_config_t ledc_timer = {
        .speed_mode         = LEDC_MODE,
        .timer_num          = LEDC_TIMER,
        .duty_resolution    = LEDC_DUTY_RES,
        .freq_hz            = LEDC_FREQ,
        .clk_cfg            = LEDC_AUTO_CLK,

    };
    ledc_timer_config(&ledc_timer);
    ledc_channel_config_t ledc_channel = {
        .speed_mode         = LEDC_MODE,
        .channel            = LEDC_CHANNEl,
        .timer_sel          = LEDC_TIMER,
        .intr_type          = LEDC_INTR_DISABLE,
        .gpio_num           = LED_GPIO,
        .duty               = 0,
        .hpoint             = 0,
    };
    ledc_channel_config(&ledc_channel);
}

void app_main() {

    ADCInit();
    LEDCInit();

    const int max_adc = 4095;
    const int max_duty = (1 << LEDC_DUTY_RES ) -1 ;

    while (1)
    {
        int raw = adc1_get_raw(POT_ADC_CHANNEL);

        //map the adc raw value to a duty cycle
        uint32_t duty = (uint32_t)(((uint64_t)raw * (uint64_t)max_duty)/(uint64_t)max_adc);
        ledc_set_duty(LEDC_MODE , LEDC_CHANNEl , duty);
        ledc_update_duty(LEDC_MODE , LEDC_CHANNEl);
        ESP_LOGI(TAG,"ADC_raw = %d -> duty = %u", raw , duty);

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}