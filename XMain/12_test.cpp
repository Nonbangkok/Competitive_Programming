#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5;
int A[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> A[i];

    int mx=0, l=0, zeros=0;
    for(int r = 0; r < n; r++){
        if(A[r]==0)zeros++;
        while(zeros>k){
            if (A[l]==0)zeros--;
            l++;
        }
        mx=max(mx,r-l+1);
    }

    cout << mx;

    return 0;
}