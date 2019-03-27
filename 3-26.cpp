#include <iostream>

int main()
{
	int bare = 0;
	
	while (std::cin >> bare && bare)
	{
		//drank = bare/3;
		//std::cout << drank << std::endl;
		int drank = 0;
		while (bare >= 2)
		{
			int drank1 = 0;
			drank1 += bare / 3;
			if (2 == bare)
			{
				drank++;
				break;
			}

			bare = drank1 + bare % 3;
			drank += drank1;
		}
		std::cout << drank << std::endl;
	}
	return 0;
}