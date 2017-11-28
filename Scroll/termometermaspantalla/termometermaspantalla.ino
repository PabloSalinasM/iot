#include <Servo.h>
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int contador = 0;
int a;
char entrada[14];
int tempEsperada;
int segundos;
int minutos;
int horas;
int tiempoTotalSegundos;
int lectura = 0;
float t;
int B=3975;                  //B value of the thermistor
float resistance;

void setup()
{
  pinMode(2, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
}


void loop()
{
  a=analogRead(0);
  resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
  t=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet ;
  //Serial.print("Current temperature is ");
  Serial.println(t);
  Serial.println(contador);

  if (t <=12) pos = 0;
  else if(t > 20 && t < 30)
  {
    pos = map(t,12,30,180,0);
  }
  else if (t>= 30){ pos = 180;
    digitalWrite(2, HIGH);
    delay(analogRead(0));
    digitalWrite(2, LOW);
    delay(analogRead(0));
  }
  else pos = 180;{
    myservo.write(pos);
  }
  //delay(1000);
  //Serial.println(t);
    // delay at the end of the full loop:
    //delay(1000);

  char aux[14];
  byte myByte;
    //String x = String(Serial.read());
  if(lectura == 0){
    for(int i =0; i < 14;i++) {
    //myByte = Serial.read();
    //strcat(aux,byteToStringDictionary(myByte));
    //aux[i] = byteToStringDictionary(myByte);
    //lcd.print(byteToStringDictionary(Serial.read()));
    entrada[i] = byteToStringDictionary(Serial.read());
    lcd.print(entrada[i]);

    //lcd.clear();
  }
  if(entrada[0]=='T'){
      lectura = 1;
    }
}
  //lcd.print( aux );D

  delay(1000);
  lcd.clear();
  //strcpy(aux,"");
  contador= contador + 1;
 }

  char byteToStringDictionary(int byteCode){
    char traduction;
    switch (byteCode) {
      case 48:
        traduction = '0';
        break;
      case 49:
        traduction = '1';
        break;
      case 50:
        traduction = '2';
        break;
      case 51:
        traduction = '3';
        break;
      case 52:
        traduction = '4';
        break;
      case 53:
        traduction = '5';
        break;
      case 54:
        traduction = '6';
        break;
      case 55:
        traduction = '7';
        break;
      case 56:
        traduction = '8';
        break;
      case 57:
        traduction = '9';
        break;
      case 84:
        traduction = 'T';
        break;
      case 32:
        traduction = ' ';
        break;
      default:
        traduction = 'e';
    }
    return traduction;
  }

int obtenerSegundos(char a, char b){
    int x = a - '0';
    x = x*10;
    int y = b - '0';
    return x+y;
  }

int minutosASegundos(char a, char b){
    return 60 * obtenerSegundos(a,b);
  }

int horasASegundos(char a, char b){
    return 3600 * obtenerSegundos(a,b);
  }

int calculalTiempoFinal(char a, char b, char c, char d, char e, char f){
    return horasASegundos(a,b) + minutosASegundos(c,d) + obtenerSegundos(e,f);
}