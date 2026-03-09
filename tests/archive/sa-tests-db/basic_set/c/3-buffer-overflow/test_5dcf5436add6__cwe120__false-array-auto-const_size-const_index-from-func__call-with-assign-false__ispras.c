// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 4; }

void callee(int *pointer_param) { *pointer_param = 238; }

void func(void) {
  int buffer[35];
  unsigned int index = 0;

  int var = 0;

  index = 35;

  callee(&var);

  if (var > 189) {
    exit(0);
  }

  index = index_change_func(index);
  result = buffer[index];

  return;
}
