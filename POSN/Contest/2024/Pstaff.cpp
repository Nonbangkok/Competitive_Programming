#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
bool cmp(pair<int,int> a , pair<int,int>b){
    return a.second < b.second;
}
int main(){macos;

    vector<int> A;
    vector<pair<int,int>> B;
    int n,m,a,b;
    cin >> n >> m;
    forr(i,0,n){
        cin >> a;
        A.push_back(a);
    }

    forr(i,0,m){
        cin >> a >> b;
        B.push_back({a,b});
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),cmp);

    int cnt=0;
    forr(i,0,n){
        forr(j,0,m){
            if(B[j].first<=A[i]&&A[i]<=B[j].second){
                cnt++;
                B[j].first=-1;
                B[j].second=-1;
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}