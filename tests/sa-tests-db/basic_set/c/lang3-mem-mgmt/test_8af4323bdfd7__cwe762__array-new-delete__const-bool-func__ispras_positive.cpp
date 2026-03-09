// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// true.

#include <stdlib.h>

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return true; }

void SomeClass::func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = new int[17];

  if (isTrue()) {
    delete pointer; // FLAW
  }
}
