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

bool com (pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

int main() {macos;

    vector<pair<int,int> > A;
    int t,temp;
    cin >> t;

    forr(i,0,t){
        cin >> temp;
        A.push_back(make_pair(temp,i));
    }
    sort(A.begin(),A.end());

    forr(i,0,t){
        if(i==0){
            if(A[i].first==A[i+1].first){
                A[i].second=999;
            }
        }else if(A[i].first==A[i+1].first || A[i].first==A[i-1].first){
            A[i].second=999;
        }
    }
    sort(A.begin(),A.end(),com);

    forr(i,0,t){
        if(A[i].second!=999){
            cout << A[i].first << ' ';
        }
    }

    return 0;
}