int role = 6; 
void setup() {
Serial.begin(9600);
 pinMode(6, OUTPUT); 
  pinMode(role, OUTPUT);
 }

void loop() {
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading data from bt module
      switch(data)
      {
        
        case 'a': digitalWrite(6, LOW); delay(2000); // click a in app 
     
        case 'd': digitalWrite(6, HIGH);break;  delay(2000); // click d in app 
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
