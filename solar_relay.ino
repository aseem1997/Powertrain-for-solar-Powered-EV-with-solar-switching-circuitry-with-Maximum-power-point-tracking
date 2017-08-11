int mco=13;
int bat=9;
int sol=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(mco,OUTPUT);
  pinMode(bat,OUTPUT);
  pinMode(sol,OUTPUT);
  digitalWrite(mco,LOW);
  digitalWrite(bat,LOW);
  digitalWrite(sol,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
float sen_sol=analogRead(A1)*5.0/1023;
float sen_bat=analogRead(A2)*5.0/1023;

if(sen_sol<4.33 && sen_sol>=4.0)
  {
    digitalWrite(bat,LOW);
    digitalWrite(sol, HIGH);
    digitalWrite(mco,HIGH);
  
  }
 else
  {
    if(sen_bat<4.33 && sen_bat>=3.83)
    {
      digitalWrite(sol,LOW);
      digitalWrite(bat,HIGH);
      digitalWrite(mco,HIGH);
      
    }
    else
    {
      while(sen_bat<4.17) 
      {      
        digitalWrite(mco,LOW);
        digitalWrite(sol,HIGH);
        digitalWrite(bat,HIGH);
        delay(300000);
        digitalWrite(sol,LOW);
        digitalWrite(bat,LOW);
        delay(30000);
        
        float sen_bat=analogRead(A2)*5.0/1023;
      }
      
    }

   }
 }
