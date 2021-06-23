#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

/*
Даны два неотрицательных числа A и B (числа могут содержать до 1000 цифр). 
Вам нужно вычислить их сумму. Тут проверяется умение работать с стандартной библиотекой вывода.

Формат ввода
Первая строка ввода содержит числа A и B, разделенные пробелом
Формат вывода
Результат сложения двух чисел нужно вывести на отдельной строке.*/

std::string getSum(std::string sin)
{
	std::string s1 = sin.substr(0, sin.find(" "));
	std::string s2 = sin.substr(sin.find(" "), sin.size()- 1);

	int size = s1.size() >= s2.size() ? s1.size() : s2.size();

	int sum = 0;

	std::string sout;
	for (int i = 0; i < size; i++)
	{
		if (((int)s1.size() - i - 1) >= 0)
			sum += (int)(s1[s1.size() - i - 1] - '0');

		if (((int)s2.size() - i - 1) >= 0)
			sum += (int)(s2[s2.size() - i - 1] - '0');

		if (sum > 9)
			sout += ((sum % 10) + '0');
		else
			sout += (sum + '0');
		sum /= 10;
	}
	std::reverse(sout.begin(), sout.end());
	return sout;
}

int main()
{
	//std::string s("12345 654321");
	std::string s("9873276128376 89891828374981");
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = getSum(s);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer = " << answer.c_str() << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}