// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(int *param, int param2) {
  int template_flag;

  if (param == NULL) {
    template_flag = 51;
  }

  if (param2 > 8) {
    memset(param, 0, sizeof(int)); // FLAW
    use_mem_to_keep_memset(param);
  }

  return 0;
}
