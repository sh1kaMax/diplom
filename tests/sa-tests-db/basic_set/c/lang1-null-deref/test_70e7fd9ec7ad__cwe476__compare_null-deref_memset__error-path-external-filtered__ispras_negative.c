// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>
#include <string.h>

int external_func(void);

void use_mem_to_keep_memset(int *);

int func(int *param) {
  int template_flag;

  if (param == NULL) {
    template_flag = 1;
  }

  if (external_func()) {

    param = &template_flag;

    goto error_label;
  }

  exit(0);

error_label:
  memset(param, 0, sizeof(int));
  use_mem_to_keep_memset(param);

  return 0;
}
