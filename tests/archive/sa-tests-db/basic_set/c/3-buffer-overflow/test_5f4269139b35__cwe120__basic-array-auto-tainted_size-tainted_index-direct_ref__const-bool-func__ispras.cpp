// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-auto-tainted_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// true.

#include <stdio.h>

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return true; }

void SomeClass::func(void) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (isTrue()) {
    result = buffer[index]; // FLAW
  }

  return;
}
