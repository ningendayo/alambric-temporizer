#include "screen_functions.h";
#include "sound_functions.h"
#include "logic_functions.h"

/*----------------------------------------------
   Variables banderas, para detección de estados
  ----------------------------------------------*/
volatile boolean isSetedOnScreen = false;
volatile boolean toInit = false;

void setup() {
  pinMode(vtRem, INPUT_PULLUP);
  pinMode(13, INPUT);
  pinMode (8, INPUT);
  Serial.begin(9600);
  int devices = lc.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    lc.shutdown(address, false);
    lc.setIntensity(address, 8);
    lc.clearDisplay(address);
  }
  printNumber(0, 0, false);
  printNumber(1, minutos_2, false);
  printNumber(2, 0, false);
  printNumber(3, 0, false);
  attachInterrupt(task1, menu, RISING);
}

void menu() {
  noInterrupts();
  /**-------------------------------------------
     1 - Esto debe ocurrir como minimo una vez
     2 - Coloca el temporizador en 8 minutos
    ---------------------------------------------*/
  if (digitalRead(pinC) == HIGH) {
    delay(500);
    if (!isSetedOnScreen) {
      Serial.println("Se preciono el Boton C (8 minutos colocados)");
      printNumber(0, 8, false);
      printNumber(2, 0, false);
      printNumber(3, 0, false);
      isSetedOnScreen = true;
    }
  }
  /**--------------------------------------------------------
     1 - Esto solo puede ocurrir una vez se haya precionado C
     2 - Inicia el temporizador
    ----------------------------------------------------------*/
  if (digitalRead(pinA) == HIGH) {
    delay(500);
    if (isSetedOnScreen) {
      Serial.println("Se preciono el Boton A (Inicio del temporizador)");
      toInit = true;
    } else {
      Serial.println("Debe primero precionar el Boton C (Colocar los 8 minutos)");
    }
  }
  interrupts();
}

void loop() {
  if (isSetedOnScreen && toInit) {
    detachInterrupt(task1);
    countDown();
    isSetedOnScreen = false;
    toInit = false;
    attachInterrupt(task1, menu, RISING);
  }
}
