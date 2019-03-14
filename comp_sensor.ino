//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop()
{
  //Le as informacoes do sensor, em cm 
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //Exibe informacoes no serial monitor
  //Tempo do pino echo em alta: 
  Serial.print(microsec);
  Serial.print(",");
  //Distancia calculada:
  Serial.println(((microsec)*pow(10,-6)*34000)/2);
  
  delay(1000);
}
