/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V582. Consider reviewing the source code that uses the container.
Документация: https://pvs-studio.ru/ru/docs/warnings/v512/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v512/
*/

#include <iostream>
#include <array>
#include <cstring>

template<class T_, size_t numElements >
class idArray1
{
public:
  size_t size() const { return numElements; };
  inline const T_ & operator[]( size_t index ) const {
    return ptr[index];
  };
  inline T_ & operator[]( size_t index ) {
    return ptr[index];
  };
private:
  T_ ptr[numElements];
};

void UseidArrayOk1()
{
  idArray1<int, 1024> newArray;
  newArray[1023] = 1;
}