# include <bits/stdc++.h>
using namespace std;

class Temp
{
public:
	Temp() {++N; Sum += N;}
	static void Reset() {N = 0; Sum = 0;}
	static unsigned int GetSum() {return Sum;}

private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution(unsigned int n)
{
	Temp::Reset();
	Temp *a = new Temp[n];
	delete []a;
	a = NULL;
	return Temp::GetSum();
}

int main()
{
	int n;
	while(cin >> n)
	{
		cout << Sum_Solution(n) << endl;
	}

	return 0;
}
// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等
// 关键字及条件判断语句（A?B:C）。

// 运行时间：4ms
// 占用内存：376k