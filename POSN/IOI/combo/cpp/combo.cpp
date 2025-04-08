#include <bits/stdc++.h>
#include "combo.h"
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

string guess_sequence(int N) {
  vector<char> ch = {'A','B','X','Y'};
  string p = "";
  int coins;
  coins = press("AB");
  if(coins){
      coins = press("A");
      if(coins)ch.erase(ch.begin()),p += "A";
      else ch.erase(ch.begin()+1),p += "B";
  }else{
      coins = press("X");
      if(coins)ch.erase(ch.begin()+2),p += "X";
      else ch.erase(ch.begin()+3),p += "Y";
  }
  if(N==1)return p;
  forr(i,1,N-1){
    string a = p + ch[0] + ch[0];
    string b = p + ch[0] + ch[1];
    string c = p + ch[0] + ch[2];
    string d = p + ch[1];
    coins = press(a + b + c + d);
    if(coins-i == 2)p += ch[0];
    else if(coins-i == 1)p += ch[1];
    else p += ch[2];
  }
  coins = press(p+ch[0]);
  if(coins==N)return p + ch[0];
  coins = press(p+ch[1]);
  if(coins==N)return p + ch[1];
  return p + ch[2];
}

// string guess_sequence(int N) {
//   vector<char> ch = {'A','B','X','Y'};
//   string p = "";
//   int coins;
//   forr(i,0,4){
//     p += ch[i];
//     coins = press(p);
//     if(coins==1){
//       ch.erase(ch.begin()+i);
//       break;
//     }
//     p.pop_back();
//   }
//   int prev = 1;
//   forr(i,1,N){
//     forr(j,0,3){
//       p += ch[j];
//       coins = press(p);
//       if(coins!=prev)break;
//       p.pop_back();
//     }
//     prev = coins;
//   }
//   return p;
// }