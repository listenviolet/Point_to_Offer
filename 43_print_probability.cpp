# include <bits/stdc++.h>
using namespace std;

int g_maxValue = 6;

void printProbability(int number)
{
	if(number < 1) return;

	int *probs[2];
	probs[0] = new int[g_maxValue * number + 1];
	probs[1] = new int[g_maxValue * number + 1];

	for(int i = 0; i < g_maxValue * number + 1; ++i)
	{
		probs[0][i] = 0;
		probs[1][i] = 0;
	} 

	int flag = 0;

	for(int i = 1; i <= g_maxValue; ++i)
		probs[flag][i] = 1;

	for(int k = 2; k <= number; ++k)
	{
		for(int i = 0; i < k; ++i)
			probs[1 - flag][i] = 0;

		for(int i = k; i <= g_maxValue * k; ++i)
		{
			probs[1 - flag][i] = 0;
			for(int j = 1; j <= i && j <= g_maxValue; ++j)
				probs[1 - flag][i] += probs[flag][i - j];
		}
		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue, number);

	for(int i = number; i <= g_maxValue * number; ++i)
	{
		double ratio = (double)probs[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete [] probs[0];
	delete [] probs[1];
} 

int main()
{
	int n;
	while(cin >> n)
	{
		printProbability(n);
	}
	return 0;
}