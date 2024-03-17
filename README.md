Реализуйте на языке C функцию my_diff для выполнения построчного сравнения двух файлов с флагами -B (игнорирование пустых линий (whitespace characters)) и-i (игнорирование lowercase и uppercase).

Реализуйте функцию my_diff используя:
int my_diff(const char *a, const char *b, bool flag_i, bool flag_B)
a и b - это имена двух сравниваемых файлов, а flag_i и flag_b указывают, активен ли соответствующий флаг.
Ваша реализация должна поддерживать флаги -i и -B (и их комбинацию или отсутствие). 

Функция должна выполняться следующим образом:
1. открыть файлы
2. прочитать и сравнить их содержимое построчно
3. вывести результат сравнения
4. закрыть файлы
5. возврат с соответствующим возвращаемым значением. 

Длина строк, в данном контексте, не будет превышать 1023 символов (без учета символа новой строки \n). 

В случае, если один файл имеет больше строк, чем другой, вы должны рассматривать это так, как если бы более короткий файл имел (несколько) пустых строк в конце, чтобы соответствовать длине другого.

Программа должна пройти через 7 тестов (они сохранены как папки test1, test2, ...), в них находятся файлы а.txt и b.txt с разным содержимым, так же есть третий файл, который показывает каким должен быть результат.
Main функция уже существует и сохранена в файле a5-diff-frame. 


Моя имплементация функции my_diff сохранена в файле my_diff.с


Моя имплементация не проходит тесты полностью.


Пример, даны два файла fileA.txt и fileВ.txt:


fileA.txt:


Hi, this is a test file.


Test file 1 to be precise.

fileB.txt:


Hi, this is a test file.


Test file 2 to be precise.

Вывод вашей программы должен выглядеть следующим образом:
2c2


< Test file 1 to be precise.


---


> Test file 2 to be precise.


Вывод показывает, что строка 2 отличается между файлами (2c2 означает, что строка 2 в оригинале была изменена и стала строкой 2 в новом файле).
