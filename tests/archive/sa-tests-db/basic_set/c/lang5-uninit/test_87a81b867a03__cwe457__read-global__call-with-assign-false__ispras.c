// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int x;

void callee(int *pointer_param) { *pointer_param = 284; }

int func(void) {
  int result = 0;

  int var = 0;

  callee(&var);

  if (var > 84) {
    exit(0);
  }

  result = x + 1;

  return result;
}
