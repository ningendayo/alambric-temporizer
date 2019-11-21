/**----------------------------------------------------------
   Definición de de pines digitales del receptor inalambrico
  -----------------------------------------------------------*/
const byte pinA = 7, pinB = 6, pinC = 5, pinD = 4, vtRem = 3, task1 = 1, task2 = 2;

/**------------------------------------
   Variables nùmericas que interactuan
   en el proceso de decremento númerico
   del algoritmo del temporizador
  -------------------------------------*/
int counter_pos = 1;
int minutos_1 = 8;
int minutos_2 = -1;
int segundos_1 = 0;
int segundos_2 = 0;

/**-----------------------------------------------
   Variables banderas booleanas que interactuan en
   el algoritmo del temporizador
  ------------------------------------------------*/
volatile boolean isPaused = false;
volatile boolean temporizer_flow_flag = true;

void stopCountDown();

void play_pause_stop() {
  noInterrupts();
  Serial.println("Se esta en la interrupcion");
  if (digitalRead(pinB) == HIGH) {
    temporizer_flow_flag = false;
  }
  if (digitalRead(pinA) == HIGH) {
    isPaused = !isPaused;
  }
  interrupts();
}

void countDown() {
  int minutos =  (String(minutos_1) + "" + String(minutos_2)).toInt();
  int segundos = (String(segundos_1) + "" + String(segundos_2)).toInt();
  attachInterrupt(task1, play_pause_stop, RISING);
  while (temporizer_flow_flag) {
    if (!isPaused) {

      int segundos_11;
      int segundos_22;
      int minutos_11;
      int minutos_22;

      if (String(minutos).length() == 1) {
        minutos_11 = 0;
        if (minutos_11 != minutos_1) {
          clearScreen(0);
          printNumber(0, minutos_11, false);
        }
        minutos_1 = minutos_11;
        minutos_22 = minutos;
        if (minutos_22 != minutos_2) {
          clearScreen(0);
          printNumber(0, minutos_22, false);
        }
        minutos_2 = minutos_22;
      } else {
        minutos_11 = String(String(minutos).charAt(0)).toInt();
        if (minutos_11 != minutos_1) {
          clearScreen(0);
          printNumber(0, minutos_11, false);
        }
        minutos_1 = minutos_11;
        minutos_22 = String(String(minutos).charAt(1)).toInt();
        if (minutos_22 != minutos_2) {
          clearScreen(0);
          printNumber(0, minutos_22, false);
        }
        minutos_2 = minutos_22;
      }

      if (String(segundos).length() == 1) {
        segundos_11 = 0;
        if (segundos_11 != segundos_1) {
          clearScreen(2);
          printNumber(2, segundos_11, false);
        }
        segundos_1 = segundos_11;
        segundos_22 = segundos;
        if (segundos_22 != segundos_2) {
          clearScreen(3);
          printNumber(3, segundos_22, false);
        }
        segundos_2 = segundos_22;
      } else {
        segundos_11 = String(String(segundos).charAt(0)).toInt();
        if (segundos_11 != segundos_1) {
          clearScreen(2);
          printNumber(2, segundos_11, false);
        }
        segundos_1 = segundos_11;
        segundos_22 = String(String(segundos).charAt(1)).toInt();
        if (segundos_22 != segundos_2) {
          clearScreen(3);
          printNumber(3, segundos_22, false);
        }
        segundos_2 = segundos_22;
      }

      Serial.print(minutos_11);
      Serial.print(minutos_22);
      Serial.print(":");
      Serial.print(segundos_11);
      Serial.println(segundos_22);

      if (minutos == 0 && segundos == 0) {
        printNumber(0, minutos_1, false);
        printNumber(1, -1, false);
        printNumber(2, segundos_1, false);
        printNumber(3, segundos_2, false);
        delay(1000);
        break;
      }

      if (segundos != 0) {
        segundos--;
      } else {
        segundos = 59;
        minutos--;
      }
      if (minutos_22 == 5 && segundos_11 == 0 && segundos_22 == 0) {
        five_minuts_sound();
      }
      delay(635);
    }
  }
  stopCountDown();
}

void stopCountDown() {
  detachInterrupt(task1);
  end_sound();
  isPaused = false;
  temporizer_flow_flag = true;
  clearScreen(0);
  printNumber(0, 0, false);
  clearScreen(1);
  printNumber(1, -1, false);
  clearScreen(2);
  printNumber(2, 0, false);
  clearScreen(3);
  printNumber(3, 0, false);
  Serial.print(0);
  Serial.print(":");
  Serial.print(0);
  Serial.println(0);
  counter_pos = 1;
  minutos_1 = 8;
  minutos_2 = -1;
  segundos_1 = 0;
  segundos_2 = 0;
}
