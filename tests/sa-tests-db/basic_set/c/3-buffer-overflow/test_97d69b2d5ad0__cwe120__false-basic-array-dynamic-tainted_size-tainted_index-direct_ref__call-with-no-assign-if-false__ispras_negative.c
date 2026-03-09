// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-tainted_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

int result = 0;

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 332;
}

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int *buffer = (int *)malloc(size * sizeof(int));
  unsigned int index = 0;

  int var = 0;

  scanf("%u", &index);

  callee(&var, -9);

  if (var < 786) {
    exit(0);
  }

  result = buffer[index];

  free(buffer);
  return;
}
