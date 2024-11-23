#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int partition(int A[],int f,int l){
    int pv=A[l],i=f;
    forr(j,f,l+1){
        if(A[j]<pv){
            swap(A[i],A[j]);
            i++;
        }
    }
    swap(A[i],A[l]);
    return i;
}
int n;//for print
void quicksort(int A[],int f,int l){
    if(f<l){
        int m=partition(A,f,l);
        //forr(i,0,n)cout << A[i] << sp; cout << ": " << A[m] << endll;
        quicksort(A,f,m-1);
        quicksort(A,m+1,l);
    }
}

int main() {macos;

    //int n;
    cin >> n;
    int A[n];
    forr(i,0,n) cin >> A[i];
    quicksort(A,0,n-1);
    forr(i,0,n) cout << A[i] << sp;

    return 0;
 }
