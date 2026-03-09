/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V557. Possible array overrun.
Документация: https://pvs-studio.ru/ru/docs/warnings/v557/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v557/
*/

#include <iostream>

#define  RTE_DIM(a)  (sizeof (a) / sizeof ((a)[0]))
#define RTE_DEVARGS_KEY_BUS "bus"
#define RTE_DEVARGS_KEY_CLASS "class"
#define RTE_DEVARGS_KEY_DRIVER "driver"

int rte_devargs_layers_parse_err(size_t nblayer, const char *s)
{
    struct {
        const char *key;
        const char *str;
        struct rte_kvargs *kvlist;
    } layers[] = {
        { RTE_DEVARGS_KEY_BUS "=",    NULL, NULL, },
        { RTE_DEVARGS_KEY_CLASS "=",  NULL, NULL, },
        { RTE_DEVARGS_KEY_DRIVER "=", NULL, NULL, },
    };
  
  if (nblayer > RTE_DIM(layers)) {
    return -1;
  }
  layers[nblayer].str = s; // FLAW
  return 1;
}