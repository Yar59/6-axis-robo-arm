// подключаем библиотеку серво
#define AMOUNT 6
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriverSmooth.h>
#include <ServoSmooth.h>
#include <smoothUtil.h>

 ServoSmooth serv[AMOUNT]; 
uint32_t myTimer;
void setup() {
  //подключаем серво к пинам
serv[0].attach(2, 600, 2400);
serv[0].smoothStart();
serv[0].setAccel(0.1);
serv[1].attach(3, 600, 2400);
serv[1].smoothStart();
serv[1].setAccel(0.1);
serv[2].attach(4, 600, 2400);
serv[2].smoothStart();
serv[2].setAccel(0.1);
serv[3].attach(5, 600, 2400);
serv[3].smoothStart();
serv[3].setAccel(0.1);
serv[4].attach(6, 600, 2400);
serv[4].smoothStart();
serv[4].setAccel(0.1);
serv[5].attach(7, 600, 2400);
serv[5].smoothStart();
serv[5].setAccel(0.1);

}

void loop() {
boolean state = serv[AMOUNT].tick();  
if (millis() - myTimer >= 40) {
myTimer = millis();
serv[0].setTarget(map(analogRead(A0),0,1023,600, 2400));  
serv[1].setTarget(map(analogRead(A1),0,1023,600, 2400));  
serv[2].setTarget(map(analogRead(A2),0,1023,600, 2400));  
serv[3].setTarget(map(analogRead(A3),0,1023,600, 2400));  
serv[4].setTarget(map(analogRead(A4),0,1023,600, 2400));  
serv[5].setTarget(map(analogRead(A5),0,1023,600, 2400));  //считываем данные с потенциометров, переводим в угол и отправляем на серво
}
}
