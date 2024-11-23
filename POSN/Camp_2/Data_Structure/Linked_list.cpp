#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

typedef struct name{
    int num;
    char ch;
    string s;
    name* ptr;
}Non;

// You can use like this instead above
// struct Non{
//     int num;
//     char ch;
//     string s;
//     Non* ptr;
// };

Non* crenode(int n){
    Non* node = new Non;
    node->num = n;
    node->ptr = NULL;
    return node;
}

bool isempty(Non *head){
    return head==NULL;
}

int main() {macos;

    Non* nod1,*nod2;
    nod1 = crenode(23);
    //nod1->num=23;

    nod2= crenode(20);
    //nod2->num=20;
    nod2->ptr=nod1;
    nod1=nod2;

    cout << nod1->num;

    return 0;
 }
