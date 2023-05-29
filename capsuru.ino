/*
プログラムを実行する前に"VarSpeedServo.h"のライブラリを導入する必要があります！
「 Arduino VarSpeedServo.h 」で検索して、ライブラリを導入してから実行してください！
*/

#include "Keyboard.h"
#include <VarSpeedServo.h>  //ライブラリのインポート
VarSpeedServo robot;        //サーボオブジェクトの作成

#define HUMANSENSOR 2
#define motorPin 3
#define LED_PIN 6

void setup() {
  Serial.begin(9600); 
  robot.attach(motorPin);
  pinMode(HUMANSENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Keyboard.begin();
}

void loop() {
  // センサが感知
  if (digitalRead(HUMANSENSOR) == HIGH) {
   // LEDの点灯
    digitalWrite(LED_PIN, HIGH);

    // caps lockのON
    Keyboard.press(KEY_CAPS_LOCK);
    
   // モータを動かし物理的にキーを押す
    robot.write(75, 50);
    delay(2000);
    robot.write(120, 50);
    delay(2000);
  }
  
  else if(digitalRead(HUMANSENSOR) == LOW) {
    // LEDの消灯
    digitalWrite(LED_PIN, LOW);

    // caps lockのOFF
    Keyboard.press(KEY_CAPS_LOCK);
  }
}