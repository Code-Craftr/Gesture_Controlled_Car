#include <Wire.h>
#include "ESP32_NOW.h"
#include "WiFi.h"

#include <esp_mac.h>

uint8_t broadcasting_add[] = {0x68, 0x25, 0xDD, 0x32, 0x92, 0x94};

typedef struct struct_message {
  int16_t x;
  int16_t y;
  int16_t z;
} struct_message;

struct_message mydata;
esp_now_peer_info_t peerInfo;


#define ADXL345_ADDRESS 0x53  // I2C address of ADXL345

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Wire.begin();  // SDA & SCL defaults for ESP32: GPIO 21 (SDA), GPIO 22 (SCL)

  // Enable measurement mode
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(0x2D);  // Power control register
  Wire.write(0x08);  // Set Measure bit to begin measurements
  Wire.endTransmission();

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // ✅ Peer configuration
  memcpy(peerInfo.peer_addr, broadcasting_add, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

  // ✅ Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("Peer added successfully");
}


void loop() {
  int16_t x, y, z;

  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(0x32);  // Data register starting address
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345_ADDRESS, 6, true);  // Request 6 bytes (X, Y, Z)

  x = Wire.read() | (Wire.read() << 8);
  y = Wire.read() | (Wire.read() << 8);
  z = Wire.read() | (Wire.read() << 8);

  Serial.print("X: "); Serial.print(x);
  Serial.print(" | Y: "); Serial.print(y);
  Serial.print(" | Z: "); Serial.println(z);

  mydata.x = x;
  mydata.y = y;
  mydata.z = z;

  esp_err_t result = esp_now_send(broadcasting_add, (uint8_t *)&mydata, sizeof(mydata));
  delay(100);


}
