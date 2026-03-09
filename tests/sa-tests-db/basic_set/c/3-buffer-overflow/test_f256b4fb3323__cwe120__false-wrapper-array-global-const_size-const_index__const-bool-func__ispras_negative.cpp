// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// false.

#include <stdlib.h>

int buffer[24];
int *get_buffer_func() { return buffer; }

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return false; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  index = 24;

  if (isTrue()) {
    buf_ptr = get_buffer_func();
    result = buf_ptr[index];
  }

  return;
}
