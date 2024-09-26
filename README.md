# Римские цифры
Перевести натуральное число (<4000), заданное в десятичной системе счисления в систему римского счёта, а число, заданное в системе римского счёта, в десятичную систему счисления.

Число, которое необходимо преобразовать, задаётся в командной строке. 

Система римских цифр использует особые знаки для десятичных разрядов `I=1`, `X=10`, `C=100`, `M=1000` и их половин `V=5`, `L=50`, `D=500`.

Натуральные числа записываются при помощи повторения этих цифр. При этом, если большая цифра стоит перед меньшей, то они складываются, если же меньшая перед большей, то меньшая вычитается из большей. 
Последнее правило применяется во избежание четырехкратного повторения одной и той же цифры. Например, `XL=50-10=40` вместо `XXXX`.

Максимально возможное число, записанное по правилам в римской системе счисления 3999.

Страница на Википедии: [Римские цифры](https://ru.wikipedia.org/wiki/Римские_цифры)

## Требования
Программа не должна использовать контейнеры STL (std::vector, std::string и т. д.). 

## Вход
Аргумент командной строки содержит число, записанное в десятичной системе счисления или в системе римского счета.

## Выход
Если на входе было число, записанное в десятичной системе счисления, то вывести в консоль число, записанное римскими цифрами.

Если на входе было число в системе римского счёта, то вывести в консоль число в десятичной системе счисления.

Если на входе было число в неправильном формате или число, которое не может быть записано в римской системе счисления, вывести `wrong integer`.

## Пример 1
Для перевода числа `MMXXIII` в десятичную систему счисления, командная строка будет иметь вид:
```
   ./roman MMXXIII
```
Вывод на экран: `2023`

## Пример 2
Для перевода числа `540` в систему римского счета, командная строка будет иметь вид:
```
   ./roman 540
```
Вывод на экран: `DXL`

## Пример 3
```
   ./roman 5432
```
Вывод на экран: `wrong integer`
