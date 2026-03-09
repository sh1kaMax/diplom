// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <stdlib.h>
#include <string.h>

int result = 0;
void use_mem_to_keep_memset(int *);

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 19; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int *buffer = (int *)malloc(22 * sizeof(int));
  unsigned int index = 0;

  setVal(1);

  index = 22 + 1;

  setVal(8);

  if (isTrue()) {
    setVal(-1);

    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  free(buffer);
  return;
}
