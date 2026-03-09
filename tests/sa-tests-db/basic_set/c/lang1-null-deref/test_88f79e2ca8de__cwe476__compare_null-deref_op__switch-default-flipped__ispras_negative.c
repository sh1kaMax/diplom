// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  int var;

  if (param == NULL) {
    template_flag = 61;
  }

  var = 0;

  switch (var) {
  default:
    *param = 0;
    break;
  case 0:
    exit(0);
    break;
  }

  return 0;
}
