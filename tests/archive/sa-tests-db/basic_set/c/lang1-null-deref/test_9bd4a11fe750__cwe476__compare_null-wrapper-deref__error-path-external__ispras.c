// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 22;
  }

  if (external_func())
    goto error_label;

  param = &template_flag;

  exit(0);

error_label:
  wrapper(param); // FLAW

  return 0;
}
