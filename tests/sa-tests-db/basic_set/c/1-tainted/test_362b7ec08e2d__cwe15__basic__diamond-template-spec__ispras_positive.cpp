// Авторы теста: ИСП РАН
// CWE: 15
// Название: External control of system or configuration settings
// Модельный вариант: basic.json
//
// Источник загрязненного значения - пользовательский ввод
// Ошибка реализуется путем передачи загрязненного значения в вызов функции
// sethostname. (Ошибка может устраняться путем проверки загрязненного значения
// на соответствие безопасному значению или переопредением его на безопасное
// значение.)
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 53; }

template <> unsigned int get_template<float>(float c) { return -89; }

void func(void) {
  char name[1024];

  int local_var1 = 53;

  if (local_var1 > 50) {
    scanf("%1023s", name);
  }

  if (get_template('a') > 50) {
    sethostname(name, sizeof(name)); // FLAW
  }
}
