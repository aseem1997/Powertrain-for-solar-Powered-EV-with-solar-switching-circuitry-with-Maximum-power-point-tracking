int mot=2;
int bat=3;
int sol=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mot,OUTPUT);
  pinMode(bat,OUTPUT);
  pinMode(sol,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensol=(5.0/1023.0)*analogRead(A1);
  float senbat=(5.0/1023.0)*analogRead(A0);
  
  Serial.print(sensol);
  Serial.print('\t');
  Serial.println(senbat);
 // Serial.println();



  if((sensol>4.9||sensol<4.35) && senbat>4.35 && senbat<4.72)
    {
      digitalWrite(sol,LOW);
      digitalWrite(mot,HIGH);
      digitalWrite(bat,HIGH);
    }
  else if(sensol<4.9 && sensol>4.35)
    {
      digitalWrite(bat,LOW);
      digitalWrite(sol,HIGH);
      digitalWrite(mot,HIGH);
    }
  else if(senbat<4.18 && sensol>4.35)
    {
      digitalWrite(bat,HIGH);
      digitalWrite(sol,HIGH);
      digitalWrite(mot,LOW);
      Serial.println("Entered charging phase with battery voltage:");
      float senbat1=senbat;

      while(senbat<4.55) 
      {         
        digitalWrite(mot,LOW);
        digitalWrite(sol,HIGH);
        digitalWrite(bat,HIGH);
        delay(5000);
        digitalWrite(sol,LOW);
        digitalWrite(bat,LOW);
        delay(3000);
        
        float senbat=analogRead(A0)*5.0/1023;
        Serial.println(senbat);
        if(senbat>4.55)
        {
        Serial.println("comparison positive");
        break;
        }
        
        
      }
      Serial.println("chsrging Over");
    }
}



