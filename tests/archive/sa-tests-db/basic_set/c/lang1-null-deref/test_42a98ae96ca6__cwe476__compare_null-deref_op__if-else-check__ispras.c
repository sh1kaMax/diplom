// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 4;
  }

  if (template_flag > 0) {
    exit(0);
  } else {
    *param = 0;
  }

  return 0;
}
