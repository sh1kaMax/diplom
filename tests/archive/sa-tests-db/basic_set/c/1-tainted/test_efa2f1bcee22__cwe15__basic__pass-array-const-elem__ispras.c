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
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void func(int param) {
  char name[1024];

  int arr[100];
  arr[50] = param;
  arr[75] = 7;

  if (param) {
    scanf("%1023s", name);
  }

  param = arr[50];

  if (param) {
    sethostname(name, sizeof(name)); // FLAW
  }
}
