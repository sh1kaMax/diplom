// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-static.json
//
// Чтение значения неинициализированной статической переменной для использования
// при вычислении выражения.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 223; }

int func(void) {
  int result = 0;

  int var = 0;

  static int x;

  callee(&var);

  if (var > 120) {
    exit(0);
  }

  result = x + 1;

  return result;
}
