// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(int *param) {
  int template_flag;

  int flag = 0;

  if (param == NULL) {
    template_flag = 21;
  }

  if (template_flag > 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  memset(param, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(param);

  return 0;
}
