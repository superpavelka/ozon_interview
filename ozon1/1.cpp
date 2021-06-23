#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/*
На вход подается большое кол-во целых чисел, все числа кроме одного имеют пару. 
Найдите единственное непарное число. Эта задача задумывалась как разминка для 
решения контеста. Существует несколько вариантов ее решения разной оптимальности, 
как “в лоб” с помощью стандартных средств любого языка программирования, так и 
более творческие варианты.*/

int getNum(std::vector<int>& nums, int& err) {
	int res = 0;
	if (!nums.size())
	{
		err = -1;
		return res;
	}
	res = nums[0];
	for (int i = 1; i < nums.size(); ++i)
		res ^= nums[i];
	if (!res)
		err = -1;
	return res;
}
int main()
{
	std::vector<int> nums = { 2, 7, 11, 15, 7, 15 , 2 };
	int err = 0;
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = getNum(nums, err);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	if (err == 0)
		std::cout << "Answer = " << answer << "\n";
	else
		std::cout << "Error" << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}