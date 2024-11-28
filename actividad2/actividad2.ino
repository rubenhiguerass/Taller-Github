#include <Arduino.h>

void cristianos(void * parameter) {
  Serial.println("cristianos!");
  vTaskDelete(NULL); // esto es para borrar la tarea cuando se complete
}

void moros(void * parameter) {
  Serial.print("¡Moros y ");
  vTaskDelete(NULL); 
}

void setup() {
  Serial.begin(115200);
  
  // creamos la primera tarea
  xTaskCreate(cristianos, "TareaCristianos", 1000, NULL, 1, NULL);
  
  // metemos un pequeño delay para que la funcion cristianos se ejecute primero
  delay(200); // Ajusta el tiempo según sea necesario
  
  // creamos la segunda parea
  xTaskCreate(moros, "TareaMoros", 1000, NULL, 1, NULL);
}

void loop() {
  // se queda vacío
}