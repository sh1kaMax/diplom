// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-array-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete[].
//
// Поточный вариант: const-bool-func-ret-member.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true.

#include <stdlib.h>

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  member_flag = false;

  pointer = new int[26];

  member_flag = true;

  if (isTrue()) {
    delete[] pointer;
  }
}
