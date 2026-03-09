// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int func(int param, int param2) {
  int divident = 48, result;

  if (param == 0) {
    divident = 84;
  }

  if (param2 > 5 && param2 < 25) {
    result = divident / param; // FLAW
  }

  return result;
}
