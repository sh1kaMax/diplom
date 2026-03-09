// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(int *param) {
  int template_flag;

  if (param == NULL) {
    template_flag = 48;
  }

  if (!(template_flag > 0)) {
    param = &template_flag;
  } else {
    memset(param, 0, sizeof(int)); // FLAW
    use_mem_to_keep_memset(param);
  }

  return 0;
}
