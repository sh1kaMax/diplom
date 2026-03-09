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
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void func(void) {
  char name[1024];

  int var, var2;

  scanf("%1023s", name);

  for (var = 0; var < 13; var++) {
    for (var2 = var; var2 < 12; var2++) {
      sethostname(name, sizeof(name)); // FLAW
    }
  }
}
