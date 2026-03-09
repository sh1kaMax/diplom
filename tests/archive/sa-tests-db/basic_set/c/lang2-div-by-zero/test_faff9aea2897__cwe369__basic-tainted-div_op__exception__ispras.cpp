// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 38, divisor = 4, result;

  try {
    scanf("%d", &divisor);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor; // FLAW
  }
}
