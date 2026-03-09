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
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 16; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  char name[1024];

  setVal(6);

  scanf("%1023s", name);

  setVal(32);

  if (isTrue()) {
    setVal(16);

    sethostname(name, sizeof(name)); // FLAW
  }
}
