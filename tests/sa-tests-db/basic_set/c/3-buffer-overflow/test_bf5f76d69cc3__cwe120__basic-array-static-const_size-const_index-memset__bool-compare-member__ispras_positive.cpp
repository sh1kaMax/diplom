// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: bool-compare-member.cpp
// Путь от источника до стока зависит от функции, которая сравнивает аргумент со
// значением члена класса.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[38];
void use_mem_to_keep_memset(int *);

class SomeClass {
  int member_flag;

public:
  bool isTrue(int is_true_par);

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue(int is_true_par) { return member_flag > is_true_par; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  unsigned int index = 0;

  setVal(-96);

  index = 38 + 1;

  setVal(-86);

  if (isTrue(-93)) {
    setVal(23);

    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}
