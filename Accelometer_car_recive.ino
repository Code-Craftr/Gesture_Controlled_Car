/*
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/  
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/

#include <esp_now.h>
#include <WiFi.h>
#define RightForeward 26
#define RightBackward 19
#define LeftForeward 27
#define LeftBackward 17

int speed2 = 32;
int speed3 = 33;   // Choose any PWM-capable pin
int pwmChannel = 0;
int pwmChannel2 = 0;
int freq = 5000;
int resolution = 8;
int dutycycle = 0;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int16_t x;
  int16_t y;
  int16_t z;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("X: ");
  Serial.println(myData.x);
  Serial.print(" y: ");
  Serial.println(myData.y);
  Serial.print(" z: ");
  Serial.println(myData.z);


  if (myData.x >= 50){
    digitalWrite(RightForeward, HIGH);
    digitalWrite(LeftForeward, HIGH);
    Serial.println("moving foreward");
    dutycycle = map(myData.x, 0, 250, 60, 255);
    ledcWrite(pwmChannel, dutycycle);
    ledcWrite(pwmChannel2, dutycycle);

  }
  else if(myData.x <= -50){
    digitalWrite(RightBackward, HIGH);
    digitalWrite(LeftBackward, HIGH);
    Serial.println("Moving Backward");
    dutycycle = map(-myData.x, 0, 250, 60, 255);
    ledcWrite(pwmChannel, dutycycle);
    ledcWrite(pwmChannel2, dutycycle);
  }
  else if(myData.y >= 50){
    digitalWrite(RightForeward, HIGH);
    digitalWrite(LeftBackward, HIGH);
    Serial.println("Turning Right");
    dutycycle = map(myData.y, 0, 200, 60, 255);
    ledcWrite(pwmChannel, dutycycle);
    ledcWrite(pwmChannel2, dutycycle);
  }
  else if(myData.y <= -50){
    digitalWrite(RightBackward, HIGH);
    digitalWrite(LeftForeward, HIGH);
    dutycycle = map(-myData.y, 0, 200, 60, 255);
    ledcWrite(pwmChannel, dutycycle);
    ledcWrite(pwmChannel2, dutycycle);
  }
  else {
    digitalWrite(RightForeward, LOW);
    digitalWrite(RightBackward, LOW);
    digitalWrite(LeftForeward, LOW);
    digitalWrite(LeftBackward, LOW);
    dutycycle = 0;
    ledcWrite(pwmChannel, dutycycle);
    ledcWrite(pwmChannel2, dutycycle);
  }
}
 

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(RightForeward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForeward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(speed2, pwmChannel);

  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(speed3, pwmChannel2);
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}
 
void loop() {

}