// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  int var;

  if (param == NULL) {
    template_flag = 62;
  }

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  *param = 0; // FLAW

  return 0;
}
