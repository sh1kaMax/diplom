// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: const-bool-func-ret-member.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в true, затем в
// false.

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
  int *pointer = NULL, quantity = 15;

  member_flag = true;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  member_flag = false;

  if (isTrue()) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
