# include <bits/stdc++.h>
using namespace std;

template <unsigned int n> struct Sum_Solution_tp
{
    enum Value {N = Sum_Solution_tp<n - 1>::N + n};
};
template <> struct Sum_Solution_tp<1>
{
    enum Value {N = 1};
};

int main()
{
	cout << Sum_Solution_tp<100>::N << endl;;
	return 0;
}

// 求1+2+3+...+n，要求不能使用乘除法、
// for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
// Notice:
// can only use static number,
// cannot use input number
// cause templete will be generate when compile
// =========Example=============================
// Sum_Solution_tp<100>::N => corrent
// ------------------------------------
// cin >> n;
// Sum_Solution_tp<n>::N   => wrong