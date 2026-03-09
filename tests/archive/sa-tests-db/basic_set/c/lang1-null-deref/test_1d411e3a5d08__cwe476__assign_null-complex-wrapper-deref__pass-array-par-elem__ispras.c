// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-complex-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, с
// несколькими параметрами.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

struct wrap_struct_type {
  int wrap_field1;
  int wrap_field2;
  int *wrap_field_ptr;
};

void inner_wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}
void wrapper(struct wrap_struct_type *struct_ptr, int other_par) {
  if (other_par > 0) {
    int *st_ptr = struct_ptr->wrap_field_ptr;
    inner_wrapper(st_ptr, struct_ptr->wrap_field2);
  }
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;
  struct wrap_struct_type local_struct_var;

  int arr[100];
  int some_var = 42;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[55] = 7;

  if (some_var) {
    pointer = NULL;
  }

  if (arr[param]) {
    local_struct_var.wrap_field1 = 0;
    local_struct_var.wrap_field2 = 82;
    local_struct_var.wrap_field_ptr = pointer;
    wrapper(&local_struct_var, 31); // FLAW
  }
}
