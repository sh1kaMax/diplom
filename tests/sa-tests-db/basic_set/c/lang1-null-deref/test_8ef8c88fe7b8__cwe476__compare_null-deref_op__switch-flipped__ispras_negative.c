// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  int var;

  if (param == NULL) {
    template_flag = 14;
  }

  var = 0;

  switch (var) {
  case 1:
    *param = 0;
    break;
  case 0:
    exit(0);
    break;
  }

  return 0;
}
