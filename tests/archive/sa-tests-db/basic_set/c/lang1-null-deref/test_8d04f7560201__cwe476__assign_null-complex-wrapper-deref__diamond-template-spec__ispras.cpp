// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-complex-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, с
// несколькими параметрами.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

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

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 86; }

template <> unsigned int get_template<float>(float c) { return -38; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;
  struct wrap_struct_type local_struct_var;

  int local_var1 = 86;

  if (local_var1 > 85) {
    pointer = NULL;
  }

  if (get_template(0.33) > 85) {
    local_struct_var.wrap_field1 = 0;
    local_struct_var.wrap_field2 = 90;
    local_struct_var.wrap_field_ptr = pointer;
    wrapper(&local_struct_var, 23);
  }
}
