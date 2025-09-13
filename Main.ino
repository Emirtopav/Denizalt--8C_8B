#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

// Motor A (ileri/geri)
#define IN1 25
#define IN2 26
// Motor B (sağ/sol)
#define IN3 27
#define IN4 14

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32-Denizalti"); // Bluetooth cihaz adı
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motorA_stop() { digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); }
void motorB_stop() { digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); }

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();

    // Motor A kontrol (ileri/geri)
    if (cmd == 'F') {                 // ileri
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    } else if (cmd == 'B') {          // geri
      digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
    } else if (cmd == 'S') {          // dur
      motorA_stop();
    }

    // Motor B kontrol (sağ/sol)
    if (cmd == 'R') {                 // sağ
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    } else if (cmd == 'L') {          // sol
      digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
    } else if (cmd == 'T') {          // dur
      motorB_stop();
    }
  }
}
