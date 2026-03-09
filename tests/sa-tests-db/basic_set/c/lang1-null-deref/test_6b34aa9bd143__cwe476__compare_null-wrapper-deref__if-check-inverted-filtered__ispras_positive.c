// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 9;
  }

  if (!(template_flag > 0)) {
    param = &template_flag;
  }

  wrapper(param); // FLAW

  return 0;
}
