// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// false.

#include <stdlib.h>

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return false; }

void SomeClass::func(void) {
  int array[41];
  int *pointer = NULL;

  pointer = array;

  if (isTrue()) {
    free(pointer);
  }
}
