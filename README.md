# Исследование статических анализаторов для языка C

Данный проект содержит набор бесплатных и открытых статических анализаторов кода для языка **C**, а также инструкции по их установке, запуску и обработке результатов.  
Цель — провести сравнительное исследование качества анализа, числа ошибок, уникальности находок и ложных срабатываний.

## Используемые анализаторы

1. **Cppcheck**  
2. **Clang Static Analyzer (scan-build)**  
3. **clang-tidy**  
4. **Splint**  
5. **Frama-C**  
6. **Flawfinder**  
7. **Sparse**  
8. **RATS (Rough Auditing Tool for Security)**  
9. **Infer (Meta/Facebook)**  
10. **CodeChecker**

---

# 1. Cppcheck

### Установка
```bash
sudo apt install -y cppcheck
```
### Простой запуск на файле
```bash
cppcheck --enable=all --std=c11 file.c
```
### Опции для машинного/разбираемого вывода
```bash
cppcheck --enable=all --std=c11 --xml --xml-version=2 file.c 2> cppcheck.xml
```

---

# 2. Clang Static Analyzer

### Установка
```bash
sudo apt install -y clang clang-tools
```
### Простой запуск на файле
```bash
scan-build --use-analyzer=/usr/bin/clang clang -c file.c -o file.o
```
### Запуск со сборкой
```bash
scan-build make
```

---

# 3. Clang-tidy

### Установка
```bash
sudo apt install -y clang-tidy
```
### Запуск на файле
```bash
clang-tidy file.c -- -std=c11 -Iinclude
```
### Опции для машинного вывода
```bash
clang-tidy file.c -checks='*' -export-fixes=fixes.yaml -- -std=c11
```

---

# 4. Splint

### Установка
```bash
sudo apt install -y splint
```
### Простой запуск на файле
```bash
splint file.c
```
### Машинный вывод (сниженный шум)
```bash
splint -weak file.c > splint.txt
```

---

# 5. Frama-C

### Установка
```bash
sudo apt install -y frama-c
```
# Простой запуск
```bash
frama-c file.c
```
# Запуск с анализом Value
```bash
frama-c -val file.c
```
### Сохранение отчёта
```bash
frama-c -val file.c > frama_output.txt
```

---

# 6. Flawfinder

### Установка
```bash
sudo apt install -y flawfinder
```
### Запуск
```bash
flawfinder file.c
```
### Вывод в файл, разбираемый формат
```bash
flawfinder --context --columns --html file.c > flawfinder_report.html
```

---

# 7. Sparse

### Установка
```bash
sudo apt install -y sparse
```
### Простой запуск
```bash
sparse file.c
```
### Типичный сценарий с флагами компиляции
```bash
sparse -Wbitwise -Wptr-subtraction -Wsparse-error file.c
```

---

# 8. RATS (Rough Auditing Tool for Security)

### Установка
```bash
sudo apt install -y rats
```
### Запуск
```bash
rats -w 3 file.c
```
### Машинный вывод (XML)
```bash
rats -w 3 --xml file.c > rats.xml
```

---

# 9. Infer (Meta/Facebook)

### Установка
```bash
sudo apt install -y infer
```

### Запуск анализа
```bash
infer -- gcc -c file.c
```
### Результат сохраняется в папку
```bash
infer-out/
```

---
