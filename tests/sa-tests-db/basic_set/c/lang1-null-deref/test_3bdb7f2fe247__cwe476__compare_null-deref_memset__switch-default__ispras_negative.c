// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(int *param) {
  int template_flag;

  int var;

  if (param == NULL) {
    template_flag = 65;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    memset(param, 0, sizeof(int));
    use_mem_to_keep_memset(param);
    break;
  }

  return 0;
}
