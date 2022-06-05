#include <SharpIR.h>

#define ON_SENSOR A0
#define model 1080

int onMesafe, ikaz=13;

SharpIR onIR(ON_SENSOR, model);

void setup() {
  
 Serial.begin(9600);
 pinMode(ikaz, OUTPUT);
 
}

void loop() {
  
  delay(1000);

  onMesafe = onIR.distance();
  
  if (onMesafe > 80 || onMesafe < 10) 
  {
    Serial.print("1,");
    Serial.println(" Out of range ");
    digitalWrite(ikaz, HIGH);
  }
  else 
  {
    Serial.print("0,");
    Serial.print(" ON: ");
    Serial.print(onMesafe);
    Serial.print("cm");
    digitalWrite(ikaz, LOW);
  }
 

}
