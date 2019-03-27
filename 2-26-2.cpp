#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;

	getline(std::cin, str1);
	getline(std::cin, str2);

	int hashtable[256] = { 0 };
	//将str2中出现的字符在哈希表中映射出，并统计他出现的次数
	for (size_t i = 0; i < str2.size(); ++i)
	{	
		hashtable[str2[i]]++;
	}

	std::string ret;

	//遍历str1中的字符，如果没有在哈希表中出现过就将其保存在ret中
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (0 == hashtable[str1[i]])
			ret += str1[i];
	}

	std::cout << ret << std::endl;
	return 0;
}