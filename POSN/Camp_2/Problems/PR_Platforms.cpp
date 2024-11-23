#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    vector<int> vec;
    Non* next;
};

Non* Create(){
    Non* node = new Non;
    node->next=NULL;
    return node;
}

Non* A[100002];
int chk[100002];

int main() {macos;

    char ch;
    int n,a,b;
    cin >> n;

    forr(i,0,n){
        cin >> ch >> a >> b;
        if(ch=='N'){
            if(!chk[b])A[b]=new Non;chk[b]=1;
            A[b]->vec.push_back(a);
        }else{
            A[a]->next=A[b];
        }
    }

    for(auto node : A){
        for(auto i : node->vec){
            cout << i << endll;
        }
    }
    //not finish

    return 0;
}