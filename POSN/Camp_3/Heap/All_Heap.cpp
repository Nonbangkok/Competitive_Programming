#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
priority_queue<double> mx;
priority_queue<double,vector<double>,greater<double>> mn;
int main(){//macos;

    int n;
    double tmp;
    //cin >> n >> tmp;
    scanf("%d%lf",&n,&tmp);
    mx.push(tmp);
    //coutf(1,tmp) << endll;
    printf("%.1lf\n",tmp);
    
    forr(i,1,n){
        //cin >> tmp;
        scanf("%lf",&tmp);
        if(tmp<=mx.top())mx.push(tmp);
        else mn.push(tmp);

        while(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        while(mn.size()>mx.size()+1){
            mx.push(mn.top());
            mn.pop();
        }

        // if(i&1) coutf(1,(mn.top()+mx.top())/2.0) << endll;
        // else coutf(1,(mn.size()>mx.size()?mn.top():mx.top())) << endll;
        if(i&1) printf("%.1lf\n",(mn.top()+mx.top())/2.0);
        else printf("%.1lf\n",(mn.size()>mx.size()?mn.top():mx.top()));
    }

    return 0;
}