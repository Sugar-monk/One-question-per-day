#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;

	getline(std::cin, str1);
	getline(std::cin, str2);

	int hashtable[256] = { 0 };
	//��str2�г��ֵ��ַ��ڹ�ϣ����ӳ�������ͳ�������ֵĴ���
	for (size_t i = 0; i < str2.size(); ++i)
	{	
		hashtable[str2[i]]++;
	}

	std::string ret;

	//����str1�е��ַ������û���ڹ�ϣ���г��ֹ��ͽ��䱣����ret��
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (0 == hashtable[str1[i]])
			ret += str1[i];
	}

	std::cout << ret << std::endl;
	return 0;
}