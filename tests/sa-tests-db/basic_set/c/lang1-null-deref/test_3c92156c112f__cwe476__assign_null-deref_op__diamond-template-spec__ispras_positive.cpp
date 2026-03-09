// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 30; }

template <> unsigned int get_template<float>(float c) { return -4; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 30;

  if (local_var1 > -9) {
    pointer = NULL;
  }

  if (get_template('a') > -9) {
    *pointer = 0; // FLAW
  }
}
