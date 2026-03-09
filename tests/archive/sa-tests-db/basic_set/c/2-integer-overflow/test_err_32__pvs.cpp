/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. б) Ошибки целочисленного переполнения и некорректного совместного использования знаковых и беззнаковых чисел.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V629. Bit shifting of the 32-bit value with a subsequent expansion to the 64-bit type. Consider inspecting the expression.
Документация: https://pvs-studio.ru/ru/docs/warnings/v629/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v629/
*/

#include <iostream>
#include <cstdint>

uint64_t ErrGet52(uint8_t* ch, uint8_t sz) {
    uint64_t n = 0;
    for (uint8_t i = 0; i < sz; i++) {
        n = n | (ch[i] << (8 * i)); // FLAW
    }
    return n;
}