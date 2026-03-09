// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int result = 0;

void callee(int *pointer_param) { *pointer_param = 374; }

void func(void) {
  int *buffer = (int *)malloc(36 * sizeof(int));
  unsigned int index = 0;

  int var = 0;

  index = 36;

  callee(&var);

  if (var > 792) {
    exit(0);
  }

  result = buffer[index]; // FLAW

  free(buffer);
  return;
}
