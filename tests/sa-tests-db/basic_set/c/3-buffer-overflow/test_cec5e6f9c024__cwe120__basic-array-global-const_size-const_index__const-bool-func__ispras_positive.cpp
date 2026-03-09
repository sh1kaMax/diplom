// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// true.

#include <stdlib.h>

int buffer[38];

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return true; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 38;

  if (isTrue()) {
    result = buffer[index]; // FLAW
  }

  return;
}
