// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-auto-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 125; }

void func(void) {
  int buffer[39];
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  scanf("%u", &index);

  callee(&var);

  if (var > 113) {
    exit(0);
  }

  result = buffer[index];

  return;
}
