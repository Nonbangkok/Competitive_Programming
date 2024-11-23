/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define for(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define macos                \
	ios::sync_with_stdio(0); \
	cin.tie(0)
typedef long long ll;
using namespace std;
int main()
{
	macos;

	int n, p = 0, minx = 10001;
	cin >> n;
	int A[n];

	for (i, 0, n)
	{
		cin >> A[i];
	}

	for (i, 0, n)
	{
		minx = min(minx, A[i]);
		p = max(p, A[i] - minx);
	}
	cout << p;

	return 0;
}