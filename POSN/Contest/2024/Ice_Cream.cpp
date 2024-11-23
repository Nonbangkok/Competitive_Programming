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
    int n,sum;
    vector<int> A;
};

int main() {macos;

    int n,mar,t,tmp;
    cin >> n >> mar;
    int ans[mar+1];
    Non market[mar+1];
    forr(i,1,mar+1){market[i].n=0;market[i].sum=0;}
    forr(i,1,n+1){
        cin >> tmp;
        int o;
        if(i%3==0)o=mar;else o=i%3;
        market[o].A.push_back(tmp);
        market[o].n++;
        market[o].sum+=tmp;
    }

    cin >> t;
    int num,stop;
    forr(i,1,t+1){
        cin >> num >> stop;
        int k=market[num].n-stop;
        while(k--){
            if(num==mar||market[num-1].n<=market[num+1].n){
                market[num-1].A.push_back(market[num].A.back());
                market[num-1].n++;
                market[num-1].sum+=market[num].A.back();

                market[num].n--;
                market[num].sum-=market[num].A.back();
                market[num].A.pop_back();
            }else{
                market[num+1].A.push_back(market[num].A.back());
                market[num+1].n++;
                market[num+1].sum+=market[num].A.back();

                market[num].n--;
                market[num].sum-=market[num].A.back();
                market[num].A.pop_back();
            }
        }
    }
    forr(i,1,mar+1){
        cout << market[i].sum << endll;
    }
    //not finish

    return 0;
}