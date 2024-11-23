/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n;
    cin >> n;

    if(n==1){
        cout << "Sunday";
    }else if(n==2){
        cout << "Monday";
    }else if(n==3){
        cout << "Tuesday";
    }else if(n==4){
        cout << "Wednesday";
    }else if(n==5){
        cout << "Thursday";
    }else if(n==6){
        cout << "Friday";
    }else if(n==7){
        cout << "Saturday";
    }else {
        cout << "Invalid number.";
    }
	
    return 0;
}