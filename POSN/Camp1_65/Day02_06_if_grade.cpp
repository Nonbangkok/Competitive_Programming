/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x >= 80)
    {
        cout << 4;
    }
    else if (x >= 75)
    {
        cout << 3.5;
    }
    else if (x >= 70)
    {
        cout << 3;
    }
    else if (x >= 65)
    {
        cout << 2.5;
    }
    else if (x >= 60)
    {
        cout << 2;
    }
    else if (x >= 55)
    {
        cout << 1.5;
    }
    else if (x >= 50)
    {
        cout << 1;
    }
    else if (x < 50)
    {
        cout << 0;
    }
    
}