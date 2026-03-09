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
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int external_func(void);

void func(void) {
  char name[1024];

  scanf("%1023s", name);

  if (external_func())
    goto error_label;

  strncpy(name, "myhost", 6);

  exit(0);

error_label:
  sethostname(name, sizeof(name)); // FLAW
}
