#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    char ch;
    int n,t;
    cin >> n >> t;
    int A[n],B[n];
    forr(i,0,n)cin >> A[i];
    forr(i,0,n)cin >> B[i];
    int ia=0,ib=0,rema=A[0],remb=B[0],sca=0,scb=0;
    forr(i,0,t){
        cin >> ch;
        if(ch=='A'){
            if(rema>remb){
                rema-=remb;
                if(ib+1==n)ib=0;
                remb=B[++ib];
                sca++;
            }else if(rema<remb){
                remb-=rema;
                if(ia+1==n)ia=0;
                rema=A[++ia];
                scb++;
            }else{
                if(ia+1==n)ia=0;
                if(ib+1==n)ib=0;
                rema=A[++ia];
                remb=B[++ib];
                sca++;
                scb++;
            }
        }else{
            int sava=ia,savb=ib;
            cout << rema << sp;
            forr(i,1,3){
                if(ia+i==n)ia=0;
                cout << A[ia+i] << sp;
            }
            cout << endll << remb << sp;
            forr(i,1,3){
                if(ib+i==n)ib=0;
                cout << B[ib+i] << sp;
            }
            cout << endll;
            ia=sava;ib=savb;
        }
    }
    cout << sca << sp << scb;

    return 0;
}