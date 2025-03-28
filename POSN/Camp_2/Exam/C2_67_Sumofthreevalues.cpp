#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010;
int n,k;
vector<pair<int,int>> A,ans;

int main(){macos;

    cin >> n >> k;
    A.resize(n);
    forr(i,0,n)cin >> A[i].first,A[i].second = i+1;

    sort(A.begin(),A.end());

    forr(i,0,n-2){
        int l = i+1, r = n-1;
        while(l<r){
            if(A[i].first + A[l].first + A[r].first == k){
                cout << A[i].second << sp << A[l].second << sp << A[r].second;
                return 0;
            }else if(A[i].first + A[l].first + A[r].first > k)r--;
            else l++;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}