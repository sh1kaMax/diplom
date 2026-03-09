// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: const-bool-func-ret-member2.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true. Но установка в true происходит после проверки. Поэтому путь недостижим.

#include <stdlib.h>

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int array[14];
  int *pointer = NULL;

  member_flag = false;

  pointer = array;

  if (isTrue()) {
    member_flag = true;
    free(pointer);
  }
}
