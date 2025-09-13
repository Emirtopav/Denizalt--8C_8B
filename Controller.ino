#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

#define BTN_F 32
#define BTN_B 33
#define BTN_R 34
#define BTN_L 35

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32-Controller", true); // Master
  Serial.println("Bağlanıyor...");
  if (SerialBT.connect("ESP32-Submarine")) Serial.println("Bağlandı!");
  else Serial.println("Bağlantı yok!");

  pinMode(BTN_F, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  // 34 ve 35 sadece giriş; harici pull-up ekleyin
}

void loop() {
  // Motor A (ileri/geri)
  if (!digitalRead(BTN_F))      SerialBT.write('F');
  else if (!digitalRead(BTN_B)) SerialBT.write('B');
  else                          SerialBT.write('S');

  // Motor B (sağ/sol)
  if (!digitalRead(BTN_R))      SerialBT.write('R');
  else if (!digitalRead(BTN_L)) SerialBT.write('L');
  else                          SerialBT.write('T');

  delay(100); // titreşim önleme
}
