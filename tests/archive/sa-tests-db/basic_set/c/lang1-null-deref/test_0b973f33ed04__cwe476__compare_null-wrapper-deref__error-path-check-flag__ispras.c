// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param) {
  int template_flag = 0;

  int flag = 0;

  if (param == NULL) {
    template_flag = 5;
  }

  if (template_flag > 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  wrapper(param); // FLAW

  return 0;
}
