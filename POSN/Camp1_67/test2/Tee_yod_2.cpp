#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
unordered_map<string,int> mp;
vector<string> track;
int main(){macos;

    int n;
    cin >> n;
    while(n--){
        string cmd,s;
        cin >> cmd >> s;
        if(cmd=="book")mp[s]++,cout << "Booked successfully" << endll;
        else mp[s] = 0,cout << "Cancelled successfully" << endll;
        track.push_back(s);
    }
    for(auto i:track){
        if(mp[i])cout << i << sp;
    }

    return 0;
}