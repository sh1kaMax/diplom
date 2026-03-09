// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int model_external_func(int external_param);

void callee(int *pointer_param) { *pointer_param = 230; }

int func(void) {
  int result = 0;

  int var = 0;

  int x;

  callee(&var);

  if (var > 32) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
