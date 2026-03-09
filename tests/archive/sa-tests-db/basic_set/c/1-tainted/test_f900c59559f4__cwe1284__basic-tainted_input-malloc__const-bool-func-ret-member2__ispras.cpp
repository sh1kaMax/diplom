// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: const-bool-func-ret-member2.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true. Но установка в true происходит после проверки. Поэтому путь недостижим.

#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int *pointer = NULL, quantity = 13;

  member_flag = false;

  scanf("%d", &quantity);

  if (isTrue()) {
    member_flag = true;
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
