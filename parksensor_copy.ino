
#include <LiquidCrystal.h>
int trigPin=8, echoPin=9, buzzer=10, led= 11;

LiquidCrystal lcd(6,7,5,4,3,2);

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16,2);
  

}

void loop() {
  
    long time, distance;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    time=pulseIn(echoPin,HIGH);
    distance=(time/2)/29.1;
    Serial.println(distance);

    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Distance:");
    lcd.setCursor(9, 1);
    lcd.print(distance);

      if(distance<10){
        lcd.setCursor(11, 1);
        lcd.print("cm");
      }
      else if(distance<100){
        lcd.setCursor(12, 1);
        lcd.print("cm");
      }
      else if(distance<1000){
        lcd.setCursor(13, 1); //Distance:115 cm
        lcd.print("cm");
    }
    
    if(distance<=5){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);  
      delay(50);    
    }
    else if(distance<=10){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(75);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);  
      delay(75);    
    }
    else if(distance<=15){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);  
      delay(100);    
    }
    else if(distance<=20){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(125);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);  
      delay(125);    
    }
    else if(distance<=30){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(150);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);  
      delay(150);    
    }
  // put your main code here, to run repeatedly:

}
