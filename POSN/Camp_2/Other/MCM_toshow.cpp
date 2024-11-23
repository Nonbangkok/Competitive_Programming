#include <bits/stdc++.h>
#include <unistd.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n=5;

    // forr(l,0,n)forr(r,l+1,n)forr(k,l,r){

    //     forr(i,0,n){
    //         forr(j,0,n){
    //             if(i==l&&j==r)cout << "n" << sp;
    //             else if(i==l&&j==k)cout << "a" << sp;
    //             else if(i==k+1&&j==r)cout << "b" << sp;
    //             else if(i==j)cout << "0" << sp;
    //             else cout << "-" << sp;
    //         }
    //         cout << endll;
    //     }
    //     usleep(1000000);
    //     system("clear");

    // }

    forr(sz,1,n)forr(l,0,n-sz){
        int r=l+sz;
        forr(k,l,r){

            forr(i,0,n){
                forr(j,0,n){
                    if(i==l&&j==r)cout << "n" << sp;
                    else if(i==l&&j==k)cout << "a" << sp;
                    else if(i==k+1&&j==r)cout << "b" << sp;
                    else if(i==j)cout << "0" << sp;
                    else cout << "-" << sp;
                }
                cout << endll;
            }
            usleep(1000000);
            system("clear");

        }
    }

    return 0;
}