// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>
#include <string.h>

int result = 0;
void use_mem_to_keep_memset(int *);

void callee(int *pointer_param) { *pointer_param = 247; }

void func(void) {
  int buffer[31];
  unsigned int index = 0;

  int var = 0;

  index = 31 + 1;

  callee(&var);

  if (var > 243) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return;
}
