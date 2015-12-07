
int ledPin13 = 13; 
int sPin8 = 8;
boolean lastPress = LOW;
boolean currentState = LOW;
boolean ledOn = true;

void setup() {
  pinMode(ledPin13, OUTPUT); 
  pinMode(sPin8, INPUT);

}

boolean deb(boolean last)
{
  boolean current = digitalRead(sPin8);
  if(last != current)
  {
    delay(5);
    current = digitalRead(sPin8);
  }
  
  return current;
}


void loop() {
  
  currentState = deb(lastPress);
    if (lastPress == LOW && currentState == HIGH)
    {
      ledOn = !ledOn;
    }
    lastPress = currentState;

    digitalWrite(ledPin13, ledOn);
   
}
