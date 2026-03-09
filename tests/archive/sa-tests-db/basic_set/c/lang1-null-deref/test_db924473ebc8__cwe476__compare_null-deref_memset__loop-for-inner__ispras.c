// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(int *param) {
  int template_flag;

  int var, var2;

  if (param == NULL) {
    template_flag = 16;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      memset(param, 0, sizeof(int)); // FLAW
      use_mem_to_keep_memset(param);
    }
  }

  return 0;
}
