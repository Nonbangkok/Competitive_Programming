#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,A[100];

void merge(int l,int r){
    if(l>=r)return;
    int m=(l+r)>>1;

    merge(l,m);
    merge(m+1,r);

    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    forr(i,0,n1)L[i]=A[l+i];
    forr(i,0,n2)R[i]=A[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<R[j])A[k++]=L[i++];
        else A[k++]=R[j++];
    }

    while(i<n1)A[k++]=L[i++];
    while(j<n2)A[k++]=R[j++];
}

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];
    merge(0,n-1);
    forr(i,0,n)cout << A[i] << sp;

    return 0;
}