/*
プログラムを実行する前に"VarSpeedServo.h"のライブラリを導入する必要があります！
「 Arduino VarSpeedServo.h 」で検索して、ライブラリを導入してから実行してください！
*/

// #define HID_CUSTOM_LAYOUT
// #define LAYOUT_GERMAN

// #include <HID-Project.h>
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
  if (digitalRead(HUMANSENSOR) == HIGH) {
    robot.write(0, 50);
    delay(500);
    robot.write(135, 50);
    delay(500);
  }
  
  else if(digitalRead(HUMANSENSOR) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);

    // Keyboard.press(lllmmkkk
    Keyboard.write(KEY_CAPS_LOCK);

    delay(10);                   
    // Keyboard.releaseAll();
  }
    // robot.write(0, 50)
    // delay(200);
    // robot.write(135, 50)
    // delay(200);

  // // センサが感知 (ボタンが押されている)
  // if (digitalRead(HUMANSENSOR) == HIGH) {
  //   // LEDの点灯
  //   Serial.println("High");
  //   digitalWrite(LED_PIN, HIGH);
  
  //   // caps lockのON
  //   Keyboard.press(KEY_CAPS_LOCK);

  //   // モータを動かして顔を出す
  //   robot.write(0, 50)
  //   delay(200);
  // } 

  // //センサが感知していない
  // else if (digitalRead(HUMANSENSOR) == LOW) {
  //   // LEDの消灯
  //   Serial.println("Low");
  //   digitalWrite(LED_PIN, LOW);
  
  //   // caps lockのOFF
  //   Keyboard.press(KEY_CAPS_LOCK);

  //   // モータを動かして顔をしまう
  //   robot.write(0, 50)
  //   delay(200);
  // }
}