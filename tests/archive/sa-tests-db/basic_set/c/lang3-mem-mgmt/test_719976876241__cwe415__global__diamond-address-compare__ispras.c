// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-address-compare.c
// Достижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <stdlib.h>

int *pointer = NULL;

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int freed_flag = 0;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    pointer = (int *)malloc(27 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (addr1 < addr2) {
    free(pointer); // FLAW
  }
}
