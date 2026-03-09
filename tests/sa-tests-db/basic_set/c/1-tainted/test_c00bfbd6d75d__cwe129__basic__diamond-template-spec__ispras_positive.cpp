// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

int store;

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 69; }

template <> unsigned int get_template<float>(float c) { return -68; }

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int local_var1 = 69;

  if (local_var1 > 46) {
    scanf("%d", &index);
  }

  if (get_template('a') > 46) {
    store = array[index]; // FLAW
  }
}
