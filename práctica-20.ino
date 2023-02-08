# xanela-do-coche-automatizada
Programa para simular a función dunha ventana de un automovil, da maneira  simplificada. O pulsador acciona o motor de subida o ser premido. unha  segunda pulsación fai que se accione o motor de baixada. O percorrido do  motor dura 7 segundos.

Entradas: Pulsador (dixital)
Saídas: Relé (2x dixital)

Autor: Marcos Antonio Mariño Mota
Data: Febreiro de 2023
*/

#define motorArriba 11
#define motorAbaixo 12
#define pulsador     7

bool estado = 0;
int contador = 100; // Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);
  
  Serial.begin(9600);
  int estado;
  
  Serial.println(estado);
}

void loop() {
  // Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado = !estado; 
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  // Fin da lectura do pulador
  
  Serial.print("valor do contador: ");
  Serial.println(contador);
  
  // Accionamiento dos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
      contador--;
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70);
      contador--;
    }
  }
  else {             // Se non está o motor accionado, lee botón 10 veces/s
    delay(100);
  }
  // Fin de accionamentos dos motores
  delay(7);
  if (contador ==0) {
    digitalWrite(motorArriba, LOW);
    digitalWrite(motorAbaixo, LOW);
  }
}

