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
    int deadline,profit;

    bool operator < (const Non &rhs)const{
        return profit > rhs.profit;
    }
};

const int N = 110;
vector<bool> slot(N,false);
vector<Non> jobs;
int t,n,a,b,c,cnt,ans;

int main(){macos;

    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> a >> b >> c;
            jobs.push_back({b,c});
        }

        sort(jobs.begin(),jobs.end());

        for(auto job:jobs){
            forl(t,job.deadline,0){
                if(slot[t])continue;
                slot[t] = true;
                ans += job.profit;
                cnt++;
                break;
            }
        }
        
        cout << cnt << sp << ans << endll;

        jobs.clear();
        forr(i,0,N)slot[i] = false;
        cnt = 0, ans = 0;
    }

    return 0;
}