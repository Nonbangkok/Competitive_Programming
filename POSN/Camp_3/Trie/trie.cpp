#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct TrieNode{
    TrieNode* child[62] = {};
    bool isEnd = false;
};

TrieNode root;
int n;
string s;

int getIndex(char c){
    if(isdigit(c))return c - '0';
    else if(isupper(c))return c - 'A' + 10;
    else return c - 'a' + 36;
}

bool insert(const string& s){
    TrieNode* node = &root;
    for(char c:s){
        int idx = getIndex(c);
        if(!node->child[idx])node->child[idx] = new TrieNode();
        node = node->child[idx];
    }
    if(node->isEnd) return true;
    node->isEnd = true;
    return false;
}

int main(){macos;

    cin >> n;

    while(n--){
        cin >> s;
        if(insert(s))cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}