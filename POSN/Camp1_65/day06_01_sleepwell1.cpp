/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

void sleep(int x,int lower,int upper){
    if(lower>x){
        cout << "Sleep more" <<endll;
    }else if(upper<x){
        cout << "Sleep too much" <<endll;
    }else{
        cout << "Sleep Well" <<endll;
    }
}

int main() {macos;

    int t,age,h1,m1,h2,m2,summ,x;
    cin >> t;

    while(t--){
        cin >> age >> h1 >> m1 >> h2 >> m2;
        summ=(((h2+24)*60)+m2)-((h1*60)+m1);
        cout << summ/60 << space << summ%60 <<endll;
        x=summ/60;

        if(age<=13){
            sleep(x,9,11);
        }else if(age<=17){
            sleep(x,9,10);
        }else if(age<=25){
            sleep(x,7,9);
        }else if(age<=64){
            sleep(x,7,9);
        }else{
            sleep(x,7,8);
        }
    }

    return 0;
}