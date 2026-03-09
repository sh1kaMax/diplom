// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// true.

#include <stdlib.h>

int *pointer = NULL;

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return true; }

void SomeClass::func(void) {
  int freed_flag = 0;

  pointer = (int *)malloc(22 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (isTrue()) {
    free(pointer); // FLAW
  }
}
