// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>

int func(int *param) {
  int template_flag = 0;

  int var, var2;

  if (param == NULL) {
    template_flag = 93;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      *param = 0; // FLAW
    }
  }

  return 0;
}
