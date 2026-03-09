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
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void func(void) {
  int iter_var;

  char name[1024];

  for (iter_var = 6; iter_var < 15; iter_var++) {
    scanf("%1023s", name);

    sethostname(name, sizeof(name)); // FLAW
  }
}
