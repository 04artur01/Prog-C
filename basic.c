// Комментарий для описания программы
#include <stdio.h> // Подключение заголовочного файла для использования функции printf()
int main() // Главная функция - точка входа в любую программу на C
{
printf("Hello, World!"); // Функция для вывода текста
return 0; // Значение, возвращаемое главной функцией
}

// Объявление переменных
тип_данных имя_переменной;
тип_данных имя_переменной = начальное_значение;

// Типы данных
char // Для представления символов
int // Для представления целых чисел
float // Для представления десятичных чисел с точностью до 6-7 знаков
double // Для представления десятичных чисел с точностью до 15 знаков
void // Для представления пустого значения

// Модификаторы типов данных
short // Для уменьшения размера целочисленных типов
long // Для увеличения размера целочисленных или дробных типов
signed // Для указания знака целочисленных типов
unsigned // Для указания отсутствия знака целочисленных типов

// Производные типы данных
массив // Для хранения нескольких значений одного типа
указатель // Для хранения адреса другой переменной
структура // Для группировки разных типов данных под одним именем
объединение // Для хранения разных типов данных в одной области памяти
перечисление // Для определения набора именованных констант

// Операторы
+ // Сложение
-  // Вычитание

* // Умножение
/ // Деление
% // Остаток от деления
++ // Инкремент (увеличение на 1)
-- // Декремент (уменьшение на 1)
= // Присваивание
+= // Сложение и присваивание
-= // Вычитание и присваивание
*= // Умножение и присваивание
/= // Деление и присваивание
%= // Остаток от деления и присваивание
== // Равенство
!= // Неравенство
> // Больше
< // Меньше
>= // Больше или равно
<= // Меньше или равно
&& // Логическое И
|| // Логическое ИЛИ
! // Логическое НЕ
& // Побитовое И
| // Побитовое ИЛИ
^ // Побитовое ИСКЛЮЧАЮЩЕЕ ИЛИ
~ // Побитовое НЕ
<< // Сдвиг влево
>> // Сдвиг вправо

// Условные конструкции
if (условие) // Если условие истинно, выполнить блок кода
{
// Код
}
else if (другое_условие) // Иначе, если другое условие истинно, выполнить другой блок кода
{
// Другой код
}
else // Иначе, выполнить третий блок кода
{
// Третий код
}

switch (выражение) // В зависимости от значения выражения, выполнить соответствующий блок кода
{
case константа1: // Если выражение равно константе1, выполнить блок кода
// Код
break; // Прервать выполнение switch
case константа2: // Если выражение равно константе2, выполнить другой блок кода
// Другой код
break; // Прервать выполнение switch
default: // Если выражение не равно ни одной из констант, выполнить третий блок кода
// Третий код
break; // Прервать выполнение switch
}

// Циклы
while (условие) // Пока условие истинно, повторять блок кода
{
// Код
}

do // Выполнить блок кода, а затем проверить условие
{
// Код
}
while (условие); // Пока условие истинно, повторять блок кода

for (инициализация; условие; обновление) // Для выполнения блока кода с заданными параметрами
{
// Код
}

// Функции
тип_возвращаемого_значения имя_функции (тип_параметра1 имя_параметра1, тип_параметра2 имя_параметра2, ...) // Объявление функции с указанием типа возвращаемого значения, имени функции и параметров
{
// Код функции
return возвращаемое_значение; // Возврат значения из функции
}

// Пример функции для перевода температуры из Фаренгейта в Цельсий
int celsius(int fahr) // Объявление функции с типом int и одним параметром типа int
{
int cel; // Объявление локальной переменной типа int
cel = (fahr - 32) * 5 / 9; // Вычисление значения переменной cel
return cel; // Возврат значения переменной cel из функции
}

// Вызов функции
имя_функции (значение_параметра1, значение_параметра2, ...); // Вызов функции с передачей значений параметров

// Пример вызова функции celsius
int temp; // Объявление переменной типа int
temp = celsius(100); // Вызов функции celsius с передачей значения 100 и присваивание возвращаемого значения переменной temp
printf("%d\n", temp); // Вывод значения переменной temp