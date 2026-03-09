// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdio.h>
#include <stdlib.h>

void func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r");

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    if (f != NULL) {
      fclose(f);
    }
    break;
  }
}
