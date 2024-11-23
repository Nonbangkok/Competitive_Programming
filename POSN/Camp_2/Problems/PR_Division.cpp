#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n;
bool chk[9];
vector<int> vec;

bool cal(){
    int n1=0,n2=0;
    forr(i,0,5)n1+=vec[i]*pow(10,4-i);
    forr(i,5,10)n2+=vec[i]*pow(10,9-i);
    if(n1/n2!=double(n1)/double(n2))return false;
    return n1/n2==n;
}

void sSearch(){
    if(vec.size()==10){
        if(cal()){
            forr(k,0,vec.size()){
                if(k==5)cout << " / ";
                cout << vec[k];
            }
            cout << "= " << n << endll;
        }
    }else{
        forr(i,0,10){
            if(chk[i])continue;
            chk[i]=true;
            vec.push_back(i);
            sSearch();
            chk[i]=false;
            vec.pop_back();
        }
    }
}

int main() {macos;

    cin >> n;
    sSearch();

    return 0;
}