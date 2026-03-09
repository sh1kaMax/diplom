// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-complex-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, с
// несколькими параметрами.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

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

int callee(int par1) {
  if (par1 > 40)
    return 20;

  return 10;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;
  struct wrap_struct_type local_struct_var;

  int local_var = 5;

  pointer = NULL;

  if (callee(local_var) == 10) {
    exit(0);
  }

  local_struct_var.wrap_field1 = 0;
  local_struct_var.wrap_field2 = 68;
  local_struct_var.wrap_field_ptr = pointer;
  wrapper(&local_struct_var, 76);
}
