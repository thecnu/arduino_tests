#include<LiquidCrystal.h>
#include<dht11.h>
#define DHT 9
int motor = 10;
int nem=0;
int deger;
int suseviye = 0;
int sensorpin = A1;
LiquidCrystal lcd (8,7,6,5,4,3);
dht11 DHT11;

void setup() {
 
 lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() {

 deger = analogRead(nem);
 deger = map(deger,0,1023,100,0);
 
if (deger<=40) digitalWrite(10,LOW);
else if (deger>40 && deger<=70) digitalWrite(10,HIGH);
else if (deger>70) digitalWrite(10,HIGH);

if (deger<=40)
{
lcd.clear();
lcd.clear();
lcd.print("nem:");
lcd.print(0,0);
lcd.print("Kuru");
Serial.println("Kuru");
}
else if (deger>40 && deger<=70)
{
  lcd.clear();
  lcd.print("nem:");
  lcd.print(0,0);
  lcd.print("Normal");
  Serial.println("Normal");
}
else if (deger>70)
{
  lcd.clear();
  lcd.print("nem:");
  lcd.print(0,0);
  lcd.print("islak");
  Serial.println("islak");
}
delay(3000);

int chk = DHT11.read(DHT);

lcd.clear();
lcd.setCursor(0,0);   // there is mistake in all cursor value !! be carefull !!!
lcd.print("Sicaklik: ");
lcd.print((float)DHT11.temperature);
lcd.setCursor(0,0);
lcd.print("Derece");

delay(3000);

suseviye = analogRead(sensorpin);
//if (suseviye<=100) digitalWrite(10,LOW);
//else if (suseviye>100 && suseviye<=250) digitalWrite(10,HIGH);
//else if (suseviye>300) digitalWrite(10,HIGH);

if (suseviye<=100)
{
  lcd.clear();
  lcd.print("Su Seviyesi:");
  lcd.print(0,0);
  lcd.print("Bos");
  Serial.println("Bos");
}
else if (suseviye>100 && suseviye<=250)
{
  lcd.clear();
  lcd.print("Su Seviyesi:");
  lcd.print(0,0);
  lcd.print("Dusuk");
  Serial.println("Dusuk");  
}
else if (suseviye>250 && suseviye<=300)
{
  lcd.clear();
  lcd.print("Su Seviyesi:");
  lcd.print(0,0);
  lcd.print("Orta");
  Serial.println("Orta");
}
else if (suseviye>300)
{
  lcd.clear();
  lcd.print("Su Seviyesi:");
  lcd.print(0,0);
  lcd.print("Yuksek");
  Serial.println("Yuksek");
}
delay(3000);
}
