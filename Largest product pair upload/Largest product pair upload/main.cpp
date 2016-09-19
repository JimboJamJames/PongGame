#include <iostream>

int main()
{
	int numbers[4];
	printf("give me 4 numbers \n");

	int largest = 0;
	int large = 0;
	int total = 0;

	for (int i = 0; i < 4; ++i)
	{
		scanf_s("%d", &numbers[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (numbers[i] >= largest)
		{
			large = largest;
			largest = numbers[i];
		}
		else if (numbers[i] >= large)
		{
			large = numbers[i];
		}

	}
	total = large * largest;

	printf("%d\n", total);

	system("pause");

}
