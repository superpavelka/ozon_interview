#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_map>

/*
���� ����� ������������� ����� "target". ����� ���� ������������������ 
�� ����� ������������� �����. ���������� �������� � �������� ���� "1", 
���� � ������������������ ���� ��� ����� �����, ������� ����� �������� 
"target" ��� "0" ���� ����� ���.*/

int checkSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> temp;

	for (int i = 0; i < nums.size(); i++)
	{
		int v = target - nums.at(i);

		if (temp.find(v) != temp.end())
			return 1;

		temp[nums[i]] = i;
	}

	return 0;
}

int main()
{
	std::vector<int> nums = { 3, 7, 11, 15 };
	int target = 9;
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = checkSum(nums, target);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer = " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}