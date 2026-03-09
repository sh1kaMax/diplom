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
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void func(void) {
  char name[1024];

  scanf("%1023s", name);

  sethostname(name, sizeof(name)); // FLAW
}
