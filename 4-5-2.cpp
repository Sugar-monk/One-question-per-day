////#include <iostream>
////
////using namespace std;
////
////#define ADD(x,y) ((x)+(y))
////#define SUB(x,y) ((x)>(y))
////
////int main()
////{
////	long a, b, c;            //���������߳�
////
////	while (cin >> a >> b >> c)
////	{
////		if (SUB(ADD(a, b), c) && SUB(ADD(a, c), b) && SUB(ADD(c, b), a))
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//#define ADD(x,y) ((x)+(y))
//#define SUB(x,y) ((x)-(y))
//
//int main()
//{
//	string arr;
//	long a, b, c;            //���������߳�
//	int i = 0;
//	while (cin >> a >> b >> c)
//	{
//		if (SUB(ADD(a, b), c) && SUB(ADD(a, c), b) && SUB(ADD(c, b), a))
//			arr[i] = 'Yes';
//		else
//			arr[i] = 'No';
//		i++;
//	}
//	for (auto a = 0; a < arr.size(); ++a)
//	{
//		cout << arr[a] << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <utility>

using namespace std;

int main()
{
	int arr[] = { 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*int p1 = 0;
	while (p1 < len)
	{
		if (arr[p1] % 2 != p1 % 2)
		{
			int p2 = p1 + 1;
			while (p2 < len && arr[p2] % 2 != p1 % 2)
				p2++;
			if (p2 < len)
				swap(arr[p2], arr[p1]);
		}
		p1++;
	}*/
	int i = 0;
	int j = 1;
	while (i<len && j<len)
	{
		if (arr[len - 1] % 2 == 0)
		{
			swap(arr[len - 1], arr[i]);
			i += 2;
		}
		else
		{
			swap(arr[len - 1], arr[j]);
			j += 2;
		}
	}

	return 0;
}
//#include <iostream>
//#include <vector>
//
//	using namespace std;
//
//	int Answer(const long num, const int n)
//	{
//		long tmp = num;
//		int count = 0;
//		while (1 == tmp % 5)
//		{
//			count++;
//			tmp -= (tmp / 5) + 1;
//		}
//		if (count == n)
//			return n + tmp;
//		else
//			return 1;
//	}
//
//	int main()
//	{
//		int n = 0;
//		vector<int> arr;
//		while (cin >> n && n != 0)
//		{
//			arr.push_back(n);
//		}
//		for (auto a = 0; a < arr.size(); ++a)
//		{
//			long num = 0;
//			int tmp = 0;
//			while (tmp = Answer(num, arr[a]) && tmp == 1)        //�ҳ�����Ҫ�����Сnum
//				num++;
//			cout << num << " " << tmp << endl;
//		}
//
//		return 0;
//	}
//	return 0;
//}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int answer(const long num, const int n)
//{
//	long tmp = num;
//	int count = 0;
//	while (1 == tmp % 5)
//	{
//		count++;
//		tmp -= (tmp / 5) + 1;
//	}
//	if (count == n)
//		return n + tmp;
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	vector<int> arr;
//	while (cin >> n && n != 0)
//	{
//		arr.push_back(n);
//	}
//	for (auto a = 0; a < arr.size(); ++a)
//	{
//		long num = 0;
//		int tmp = 0;
//		while (tmp = answer(num, arr[a]) && tmp == 1)        //�ҳ�����Ҫ�����Сnum
//			num++;
//		cout << num << " " << tmp << endl;
//	}
//
//	return 0;
//}


template<class T>
class SmartPtr{
public:
	SmartPtr(T* ptr = nullptr) :_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	//SmartPtrд�����ﻹ��������һ������ָ�룬���ָ�������Ƿ�����RAII���ƣ�
	//���ǻ�������ָ�����Ϊ����Ҫ��*��->���زſ���

	T& operator*()
	{
		return *_ptr;
	}
	T& operator->()
	{
		return _ptr
	}

private:
	T* _ptr;
};

template<class T>
class Auto_Ptr
{
public:
	AutoPtr(T* ptr = nullptr) :_ptr(ptr)
	{}
	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	//һ�������˿������ͽ�sp�е���Դת�Ƶ���ǰ�����У�Ȼ��sp�������������Դ�Ͽ���ϰ
	//�����ͽ����һ��ռ䱻�������ʹ����ɵĳ���������⡣
	AutoPtr(AutoPtr<T>& sp)
	{
		//����ǲ����Լ����Լ���ֵ
		if (this != &sp)
		{
			//�ͷŵ�ǰ�����е���Դ
			if (_ptr)
				delete _ptr;
			//ת��sp����Դ����ǰ����
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}

		return *this;
	}

private:
	T* _ptr;
};

template<class T>
class Uni