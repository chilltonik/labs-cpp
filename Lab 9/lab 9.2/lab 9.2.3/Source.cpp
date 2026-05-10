/*
9.2. СПИСКИ
Реализовать решение задачи с использованием параметризированных классов vector и list (указать лучший и объяснить почему).

3. Реализовать вариант заданий 7.6, используя объявление и методы соответствующего параметризированного класса из стандартной библиотеки шаблонов STL

3. Даны натуральное число n, действительные числа x1, x2, ... xn. Разработать про-
грамму вычисления значения выражения следующего вида:
(x1 + x2 + nxn ) + (x2 + x3 + (n −1)xn−1 ) + ...+ (xn−1 + xn + 2x2 ) .

3. Даны натуральное число n, действительные числа x1, x2, ... xn. Разработать про-
грамму вычисления значения выражения следующего вида:
(x1 + x2 + nxn ) + (x2 + x3 + (n −1)xn−1 ) + ...+ (xn−1 + xn + 2x2 ) .
*/
#include"Functions.h"

int main()
{
	srand(time(NULL));

	cout << "Enter count_values: ";
	int values_count = Input_value(max_for_values);
	vector<int> arr(values_count);

	fill_vector(arr);
	print_vector(arr);

	int result_vector = -1;
	result_vector = calculate_result_vector(arr);
	cout << "Result: " << result_vector << endl;

	list<int> lst(values_count);
	fill_list(lst);
	print_list(lst);

	int result_list = -1;
	result_list = calculate_result_list(lst);
	cout << "Result: " << result_list << endl; 

	return 0;
}