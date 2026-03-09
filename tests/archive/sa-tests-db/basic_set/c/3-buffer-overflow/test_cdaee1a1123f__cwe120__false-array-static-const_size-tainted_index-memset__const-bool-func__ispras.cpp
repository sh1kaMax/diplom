// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// false.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[33];
void use_mem_to_keep_memset(int *);

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return false; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (isTrue()) {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  return;
}
