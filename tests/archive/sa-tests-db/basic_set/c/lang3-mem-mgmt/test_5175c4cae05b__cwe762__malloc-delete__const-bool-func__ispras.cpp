// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-delete.json
//
// Память выделяется с помощью стандартной функции malloc.
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

  pointer = (int *)malloc(12 * sizeof(int));

  if (isTrue()) {
    delete pointer; // FLAW
  }
}
