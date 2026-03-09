// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  int var;

  if (param == NULL) {
    template_flag = 56;
  }

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    *param = 0; // FLAW
    break;
  }

  return 0;
}
