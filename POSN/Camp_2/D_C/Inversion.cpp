#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll ans=0;

void merge(int A[],int f,int l){
    int m=(l+f)/2;
    int n1=m-f+1;
    int n2=l-m;
    int L[n1],R[n2];
    forr(i,0,n1)L[i]=A[i+f];
    forr(i,0,n2)R[i]=A[i+m+1];

    int i=0,j=0,k=f;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            ans+=(n1-i);n
            j++;
        }
        k++;
    }

    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}
int n; //for print
void mergesort(int A[],int f,int l){
    if(f>=l)return ;
    int m=(l+f)/2;
    mergesort(A,f,m);
    mergesort(A,m+1,l);
    merge(A,f,l);
    //forr(i,0,n)cout << A[i] << sp; cout << endll;
}

int main() {macos;

    //int n;
    cin >> n;
    int A[n];
    forr(i,0,n)cin >> A[i];
    mergesort(A,0,n-1);
    //forr(i,0,n)cout << A[i] << sp;
    cout << ans;

    return 0;
 }
