#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    xSemaphoreTake(request, portMAX_DELAY);
    printf("Adding 5 to the input\n");
    data->output = data->input + 5;
    vTaskDelay(10);
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
{
    xSemaphoreGive(request);
    bool res = xSemaphoreTake(response, 100);
    printf("Giving results\n");
    return res;
}