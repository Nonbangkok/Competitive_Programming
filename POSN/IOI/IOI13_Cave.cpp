#include <bits/stdc++.h>
#include "cave.h"
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010;
int S[N],D[N],test[N],k;
bool fix[N];

void exploreCave(int n){
    forr(i,0,n){
        k = (tryCombination(S)==i);
        int l = 0, r = n - 1, m;
        while(l<r){
            m = (l+r) >> 1;
            forr(j,0,n){
                if(fix[j])test[j] = S[j];
                else if(l<=j&&j<=m)test[j] = k;
                else test[j] = !k;
            }
            if(tryCombination(test)==i)l = m + 1;
            else r = m;
        }
        S[l] = k;
        D[l] = i;
        fix[l] = true;
    }
    answer(S,D);
}