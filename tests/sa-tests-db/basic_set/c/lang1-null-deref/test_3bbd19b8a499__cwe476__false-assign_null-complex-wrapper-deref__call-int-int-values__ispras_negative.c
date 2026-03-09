// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-complex-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, с
// несколькими параметрами.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

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

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;
  struct wrap_struct_type local_struct_var;

  int local_var = 34;

  pointer = NULL;

  if (callee(local_var, 155) > 0) {
    exit(0);
  }

  local_struct_var.wrap_field1 = 0;
  local_struct_var.wrap_field2 = -82;
  local_struct_var.wrap_field_ptr = pointer;
  wrapper(&local_struct_var, 82);
}
