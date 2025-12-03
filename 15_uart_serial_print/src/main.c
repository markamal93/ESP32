#include "driver/uart.h"
#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"


void app_main() {
    const char *msg = "hello world from uart\n";


    uart_write_bytes(UART_NUM_0 , msg , strlen(msg));
    vTaskDelay(pdMS_TO_TICKS(1000));

}