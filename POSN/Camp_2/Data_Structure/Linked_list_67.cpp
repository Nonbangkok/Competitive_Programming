#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Listnode{
    int val;
    Listnode* next;
};

int main() {macos;

    Listnode* numlist = NULL;
    numlist = new Listnode;

    numlist->val=10;

    cout << numlist->val;

    return 0;
}