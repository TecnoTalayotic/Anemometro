/*Sensor Anemometro
En este programa configuraremos el sensor Anemometro
para leer los datos en el terminal serie. 
Creado por TecnoTalayotic
https://www.instagram.com/tecnotalayotic
https://www.thingiverse.com/TecnoTalayotic
https://github.com/TecnoTalayotic
Más información del proyecto en:
https://github.com/TecnoTalayotic/Anemometro
*/

//Variables comunes
unsigned int long conta = 0;
unsigned int long conta1 = 0;

//Variables per el anemometro
int PINclick=3;
unsigned int clicks;
const float velClick = 2.4;           //1Click en un seg son 2.4 Km/H
unsigned int vel;
bool estadoVel;


void setup() {
  Serial.begin(9600);
  inici();
  pinMode(PINclick, INPUT);
}

void loop() {
  conta++;
  anometer();
  //Serial.print(conta);
  
  if (conta<1000){}
  else{
    Serial.println();
    printVel();
    conta = 0;
  }
}


//Imprimimos Iniciando y una línea de puntos
void inici(){
  Serial.println(F("Iniciando"));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.print(F(" . "));
  delay(100);
  Serial.println(F(" . "));
  delay(100);
}

//Leemos y convertimos los valores del anemometro
void anometer(){
  while (conta1 < 2000){                                //Durante cuanto tiempo vamos ha hacer la comprobacion
    estadoVel = digitalRead(PINclick);
    conta1++;
    if (estadoVel == LOW){                              //Contador de clics
      clicks++;
      while (estadoVel == LOW){                         //Antirebot
        estadoVel = digitalRead(PINclick);
      }
    }
  }
  if (conta1 >= 2000){                                  //Salida cotador de clics, y entrada a operacion para convertirlos en Km/H
    vel = ((clicks / 2) *velClick);                     //Velocidad Km/H = Número de clics dividido entre el tiempo de ejecución en segundos, multiplicado por la velocidad de 1 clic cada segundo
  }
}

//Impresión velocidad viento
void printVel(){
  Serial.print (F("Es vent vufa a = "));
  Serial.print (vel);
  Serial.print (" Km/H ");
}
