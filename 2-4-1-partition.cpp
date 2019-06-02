# include <bits/stdc++.h>
using namespace std;

int RandomInRange(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


int partition(int data[], int length, int start, int end)
{
	int index = RandomInRange(start, end);

	Swap(&data[index], &data[end]);

	int small = start - 1;
	for(index = start; index < end; ++index)
	{
		if(data[index] < data[end])
		{
			++small;
			if(small != index)
				Swap(&data[small], &data[index]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if(start == end) return;
	int index = partition(data, length, start, end);

	if(index > start) QuickSort(data, length, start, index - 1);
	if(index < end) QuickSort(data, length, index + 1, end);
}


int main()
{
	int data[] = {2, 4, 5, 1, 3};
	QuickSort(data, 5, 0, 4);
	for(int i = 0; i < 5; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}