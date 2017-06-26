boolean boton1=0;
boolean boton2=0;
boolean boton3=0;
byte segmentos[]={B00111111,B00000110,B01011011,B01001111, B01100110, B01101101,B01111101, B00000111,B01111111,B01100111};
int sensor=13;
volatile int credito;
void setup() { 
  Serial.begin(9600);
 DDRD=B11111111;
 pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(sensor,INPUT);
 
}
boolean Sensor()
{
  return(digitalRead(sensor));
  delay(500);
}

void loop() {
  boton1= digitalRead(10);
  boton2= digitalRead(11);
  boton3= digitalRead(12); 
  
  if(Sensor()==true)
  {
    credito+=1;
  }
   
    if(credito>0)
    {
      credito=constrain(credito,0,99);
   
    if(credito==1)
    {
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      PORTD=B00000110; 
      Serial.println(credito);
      delay(1000);
      }
      
     if (credito==2)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[credito];
      Serial.println(credito);
      delay(1000);}
     
     if(credito==3)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[credito];
      Serial.println(credito);
      delay(1000);}
     
     if(credito==4)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[credito];
      Serial.println(credito);
      delay(1000);}
      
     if(credito==5)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[5];
      Serial.println(credito);
      delay(1000);}
     
     if(credito==6)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[6];
      Serial.println(credito);
      delay(1000);}
    
     if(credito==7)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[7];
      Serial.println(credito);
      delay(1000);}
     
     if(credito==8)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[8];
      Serial.println(credito);
      delay(1000);}
      
     if(credito==9)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      PORTD=segmentos[9];
      Serial.println(credito);
      delay(1000);
    }
      
      if(boton1)
  {
    do
    {
    credito=(credito-2);
    PORTD=segmentos[credito];
    }
    while(credito>=2);
  }
    if(boton2)
  {
    do
    {
    credito=(credito-5);
    PORTD=segmentos[credito];
    }
    while(credito>=5);
  }
    if(boton3)
  {
    do
    {
    credito=(credito-7);
    PORTD=segmentos[credito];
    }
    while(credito>=7);
  }   

   Serial.print("credito: ");
   Serial.println(credito); 
 
    }
  
else
if(credito==0)
 {
  Serial.println("Credito insuficiente");
  PORTD=B00111111;
 }
 
 
}
