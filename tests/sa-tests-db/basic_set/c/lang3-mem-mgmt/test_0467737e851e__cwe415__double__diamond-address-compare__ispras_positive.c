// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: diamond-address-compare.c
// Достижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <stdlib.h>

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    pointer1 = (int *)malloc(12 * sizeof(int));
    pointer2 = (int *)malloc(12 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  }

  if (addr1 < addr2) {
    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
  }

  free(pointer1);
}
