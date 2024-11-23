#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Node{
    Node *l,*r;
};

struct Nonq{
    Node *node;
    int h;
};

int main(){macos;

    queue<Nonq> q;
    Node *root= new Node;
    q.push({root,0});
    int n,mx=0;
    while(cin >> n&&n!=-2){
        auto [node,h]=q.front();
        q.pop();
        if(n==-1)continue;
        node->l=new Node;
        node->r=new Node;
        q.push({node->l,h+1});
        q.push({node->r,h+1});
        mx=max(mx,h+1);
    }
    cout << mx;

    return 0;
}