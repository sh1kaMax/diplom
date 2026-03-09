// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int buffer[20];
int *get_buffer_func() { return buffer; }

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  int local_var1 = 35;

  auto init = [&]() { local_var1 = 159; };

  if (local_var1 > 19) {
    index = 20;
  }

  init();

  if (local_var1 == 159) {
    buf_ptr = get_buffer_func();
    result = buf_ptr[index]; // FLAW
  }

  return;
}
