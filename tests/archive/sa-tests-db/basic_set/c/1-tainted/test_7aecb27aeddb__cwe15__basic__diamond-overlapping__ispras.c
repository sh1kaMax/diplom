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
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void func(int param) {
  char name[1024];

  if (param > 25) {
    scanf("%1023s", name);
  }

  if (param < 34) {
    sethostname(name, sizeof(name)); // FLAW
  }
}
