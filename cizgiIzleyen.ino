#include <SoftwareSerial.h>
#define rxPin 13
#define txPin 12
String string;
SoftwareSerial mySerial(txPin,rxPin);//RX, TX

#define SensorSol 8
#define SensorOrta 9
#define SensorSag 10

#define MotorR1 5
#define MotorR2 6 // Sensör ve Motorların Arduino'ya bağladığımız pinlerini tanımlıyoruz.
#define MotorRE 7

#define MotorL1 3
#define MotorL2 4
#define MotorLE 2

void setup() {
 

mySerial.begin(9600);

  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);

  pinMode(MotorR1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(MotorR2, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);

  string.reserve(200); 

}

void loop() {

if(mySerial.available()>0){
    
    string = mySerial.readString(); 
  }
  
  
  if(string == "ileri"){
    ileri();
    delay(500);
    string="";
  }
  if(string == "sag"){
    sag();
    delay(500);
    string="";
  }
  if(string == "sol"){
    sol();
    delay(500);
    string="";
  }
  if(string == "geri"){
    geri();
    delay(500);
    string="";
  }
  if(string == "dur"){
    dur();
    delay(500);
    string="";
    
  }
  

  if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
    ileri();
    delay(25);
  }

  if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
    sag();
    delay(25);
  }

  if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    sol();
    delay(25);
  }

}


void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 85); // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 85); // Sol motorun hızı 150

}

void geri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 85); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 85); // Sol motorun hızı 150

}


void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 0); // Sağ motorun hızı 0 (Motor duruyor)

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 85); // Sol motorun hızı 150


}

void sol(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 85); // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 0); // Sol motorun hızı 0 (Motor duruyor)

}

void dur(){ // Robotun durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);

}
