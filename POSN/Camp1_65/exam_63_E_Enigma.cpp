#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
string s;
int jk = 0;
char a[4][2],b[4][2];

void spina(){
    forr(i,0,4){
        forr(j,0,2){
            if(a[i][j]=='A')a[i][j]='D';
            else if(a[i][j]=='B')a[i][j]='A';
            else if(a[i][j]=='C')a[i][j]='B';
            else if(a[i][j]=='D')a[i][j]='C';
        }
    }
    jk++;
}

void spinb(){
    forr(i,0,4){
        forr(j,0,2){
            if(b[i][j]=='A')b[i][j]='D';
            else if(b[i][j]=='B')b[i][j]='A';
            else if(b[i][j]=='C')b[i][j]='B';
            else if(b[i][j]=='D')b[i][j]='C';
        }
    }
}

void setga(int i){
    if(s[i]==a[0][0])s[i]=a[0][1];
    else if(s[i]==a[1][0])s[i]=a[1][1];
    else if(s[i]==a[2][0])s[i]=a[2][1];
    else if(s[i]==a[3][0])s[i]=a[3][1];
}

void setgb(int i){
    if(s[i]==b[0][0])s[i]=b[0][1];
    else if(s[i]==b[1][0])s[i]=b[1][1];
    else if(s[i]==b[2][0])s[i]=b[2][1];
    else if(s[i]==b[3][0])s[i]=b[3][1];
}

void setba(int i){
    if(s[i]==a[0][1])s[i]=a[0][0];
    else if(s[i]==a[1][1])s[i]=a[1][0];
    else if(s[i]==a[2][1])s[i]=a[2][0];
    else if(s[i]==a[3][1])s[i]=a[3][0];
}

void setbb(int i){
    if(s[i]==b[0][1])s[i]=b[0][0];
    else if(s[i]==b[1][1])s[i]=b[1][0];
    else if(s[i]==b[2][1])s[i]=b[2][0];
    else if(s[i]==b[3][1])s[i]=b[3][0];
}

void uturn(int i){
    if(s[i]=='A')s[i]='D';
    else if(s[i]=='B')s[i]='C';
    else if(s[i]=='C')s[i]='B';
    else if(s[i]=='D')s[i]='A';
} 

int main(){

    int bef,num;
    cin >> bef >> num >> s;

    a[0][0]='A';a[0][1]='A';
    a[1][0]='B';a[1][1]='D';
    a[2][0]='C';a[2][1]='B';
    a[3][0]='D';a[3][1]='C';

    b[0][0]='A';b[0][1]='A';
    b[1][0]='B';b[1][1]='C';
    b[2][0]='C';b[2][1]='B';
    b[3][0]='D';b[3][1]='D';

    forr(i,0,bef){
        spina();
        if(!(jk%4)&&i)spinb();
    }
    forr(i,0,num){
        setga(i);
        setgb(i);
        uturn(i);
        setbb(i);
        setba(i);
        spina();
        if(!(jk%4))spinb();
    }
    cout << s;

    return 0;
}