#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// task handle declaration
TaskHandle_t task1;

// task function declaration
void task1execute(void *pvParameters) {
    Serial.print("Task1 running on core ");
    Serial.println(xPortGetCoreID());
    
    for(;;) {
        // Task code here

        taskYIELD();
        
        // simulate some work by delaying for a short period
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }
    
    // example parameter to pass to the task
    int x = 10;

    // Create the task pinned to core 0
    xTaskCreatePinnedToCore(
        task1execute, // Function to implement the task
        "Task 1", // Task name
        5000, // Stack size in words
        &x, // Task input parameter
        1, // Priority of the task
        &task1, // Task handle
        0 // Core where the task will run
    );

    Serial.println("Setup completed");
}

void loop() {
    // Main loop code here
    // Example: Serial.println("Main loop running");
    delay(1000); // delay to avoid spamming the serial output
}
