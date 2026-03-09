// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 453; }

int func(int cond_param) {
  int result = 0;

  int var = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  callee(&var);

  if (var > 239) {
    exit(0);
  }

  result = x + 1;

  return result;
}
