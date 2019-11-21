#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 8);
void printNumber(int pantalla, int numero, boolean param) {
  switch (numero) {
    case 0: {
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 6, true);
          lc.setLed(pantalla, r, 1, true);
        }
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 7, c, true);
        }

        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 6, false);
            lc.setLed(pantalla, r, 1, false);
          }
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 7, c, false);
          }

        }

        break;
      }
    case 1: {
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 4, true);
        }
        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 4, false);
          }
        }
        break;
      }
    case -1:{
      lc.setLed(pantalla,1,3,true);
      lc.setLed(pantalla,6,3,true);
      break;
    }
    case 2: {
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 4, c, true);
          lc.setLed(pantalla, 7, c, true);
        }
        for (int f = 4; f < 8; f++) {
          lc.setLed(pantalla, f, 1, true);
        }
        for (int f = 0; f < 5; f++) {
          lc.setLed(pantalla, f, 6, true);
        }

        if (param) {
          Serial.println("Se imprime");
          delay(100);
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 4, c, false);
            lc.setLed(pantalla, 7, c, false);
          }
          for (int f = 4; f < 8; f++) {
            lc.setLed(pantalla, f, 1, false);
          }
          for (int f = 0; f < 5; f++) {
            lc.setLed(pantalla, f, 6, false);
          }
        }

        break;
      }
    case 3: {
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 7, c, true);
          lc.setLed(pantalla, 4, c, true);
        }
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 6, true);
        }
        if (param) {
          delay(100);
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 7, c, false);
            lc.setLed(pantalla, 4, c, false);
          }
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 6, false);
          }
        }
        break;
      }
    case 4: {
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 5, true);
        }
        for (int r = 0; r < 5; r++) {
          lc.setLed(pantalla, r, 1, true);
        }
        for (int c = 2; c < 5; c++) {
          lc.setLed(pantalla, 4, c, true);
        }
        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 5, false);
          }
          for (int r = 0; r < 5; r++) {
            lc.setLed(pantalla, r, 1, false);
          }
          for (int c = 2; c < 5; c++) {
            lc.setLed(pantalla, 4, c, false);
          }
        }
        break;
      }
    case 5: {
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 4, c, true);
          lc.setLed(pantalla, 7, c, true);
        }
        for (int f = 0; f < 5; f++) {
          lc.setLed(pantalla, f, 1, true);
        }
        for (int f = 4; f < 8; f++) {
          lc.setLed(pantalla, f, 6, true);
        }
        if (param) {
          delay(100);
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 4, c, false);
            lc.setLed(pantalla, 7, c, false);
          }
          for (int f = 0; f < 5; f++) {
            lc.setLed(pantalla, f, 1, false);
          }
          for (int f = 4; f < 8; f++) {
            lc.setLed(pantalla, f, 6, false);
          }
        }
        break;
      }
    case 6: {
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 4, c, true);
          lc.setLed(pantalla, 7, c, true);
        }
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 1, true);
        }
        lc.setLed(pantalla, 6, 6, true);
        lc.setLed(pantalla, 5, 6, true);
        if (param) {
          delay(100);
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 4, c, false);
            lc.setLed(pantalla, 7, c, false);
          }
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 1, false);
          }
          lc.setLed(pantalla, 6, 6, false);
          lc.setLed(pantalla, 5, 6, false);
        }
        break;
      }
    case 7: {

        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 6, true);
        }
        for (int c = 1; c < 7; c++) {
          lc.setLed(pantalla, 0, c, true);
        }

        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 6, false);
          }
          for (int c = 1; c < 7; c++) {
            lc.setLed(pantalla, 0, c, false);
          }
        }

        break;
      }
    case 8: {
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 6, true);
          lc.setLed(pantalla, r, 1, true);
        }
        for (int c = 1; c < 7; c++) {
          if (c >= 1 && c <= 6) {
            lc.setLed(pantalla, 4, c, true);
          }
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 7, c, true);
        }
        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 6, false);
            lc.setLed(pantalla, r, 1, false);
          }
          for (int c = 1; c < 7; c++) {
            if (c >= 1 && c <= 6) {
              lc.setLed(pantalla, 4, c, false);
            }
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 7, c, false);
          }
        }
        break;
      }
    case 9: {
        for (int r = 0; r < 9; r++) {
          lc.setLed(pantalla, r, 6, true);
          if (r <= 4) {
            lc.setLed(pantalla, r, 1, true);
          }
        }
        for (int c = 1; c < 7; c++) {
          if (c >= 1 && c <= 6) {
            lc.setLed(pantalla, 4, c, true);
          }
          lc.setLed(pantalla, 0, c, true);
          lc.setLed(pantalla, 7, c, true);
        }
        if (param) {
          delay(100);
          for (int r = 0; r < 9; r++) {
            lc.setLed(pantalla, r, 6, false);
            if (r <= 4) {
              lc.setLed(pantalla, r, 1, false);
            }
          }
          for (int c = 1; c < 7; c++) {
            if (c >= 1 && c <= 6) {
              lc.setLed(pantalla, 4, c, false);
            }
            lc.setLed(pantalla, 0, c, false);
            lc.setLed(pantalla, 7, c, false);
          }
        }
        break;
      }
  }
}

void clearScreen(int pantalla) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(pantalla, row, col, false);
    }
  }
}
