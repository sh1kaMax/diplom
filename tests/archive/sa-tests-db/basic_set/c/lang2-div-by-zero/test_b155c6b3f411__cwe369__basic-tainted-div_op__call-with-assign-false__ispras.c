// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 423; }

void func(void) {
  int divident = 57, divisor = 8, result;

  int var = 0;

  scanf("%d", &divisor);

  callee(&var);

  if (var > 74) {
    exit(0);
  }

  result = divident / divisor;
}
