#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

class Solution{
    public:
        int size;
        vector<pair<int,int>> data;

        Solution(int n){
            size = n;
            data.resize(n);
        }

        void sort_data(){
            sort(data.begin(),data.end());
        }

        int query(int x){
            int idx = lower_bound(data.begin(),data.end(),make_pair(x,0))-data.begin();
            if(data[idx].first==x)return data[idx].second;
            return -1;
        }
};

int main(){macos;

    int n,q,x;
    cin >> n;

    Solution sol(n);

    forr(i,0,n)cin >> sol.data[i].first, sol.data[i].second = i;

    sol.sort_data();

    cin >> q;
    while(q--){
        cin >> x;
        cout << sol.query(x) << sp;
    }

    return 0;
}