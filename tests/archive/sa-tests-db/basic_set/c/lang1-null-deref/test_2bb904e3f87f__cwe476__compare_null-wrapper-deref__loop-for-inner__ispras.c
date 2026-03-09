// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param) {
  int template_flag = 0;

  int var, var2;

  if (param == NULL) {
    template_flag = 18;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      wrapper(param); // FLAW
    }
  }

  return 0;
}
