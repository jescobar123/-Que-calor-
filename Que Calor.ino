
int ThermistorPin = A5;
int LedPin = 8;
int LedVentilador = 7;
const int pinTrigger = 2;
const int pinEcho = 3;
int Vo;
int distancia;

float T;


double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = (Temp * 2.89193);        
 return Temp;
}

void setup() {
  pinMode(LedPin,OUTPUT);
  
  Serial.begin(9600);
}
void loop() {
  Vo = analogRead(ThermistorPin);
  T = Thermistor(Vo);
 // T = T - 273.15; //convert Kelvin to Celcius
 // T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit


if (T>26.75){
   digitalWrite(LedVentilador, HIGH);
}else{
  digitalWrite(LedVentilador, LOW);

}
  Serial.print("Temperature: "); 
  Serial.println(T);


  distancia = Sonar();
  Serial.println("Distancia: ");
  Serial.println(distancia); 

  if (distancia < 5){
      digitalWrite(LedPin, HIGH);
  }else{
      digitalWrite(LedPin, LOW);    
  }
  
  delay(1000);

  

}


int Sonar() {
  int time;
  int dist;

  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);

  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);

  time = pulseIn(pinEcho, HIGH);
  dist = time / 59;
  return dist;
}