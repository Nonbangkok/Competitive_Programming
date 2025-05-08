#include <bits/stdc++.h>
#include "penguin.h"
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<pair<int,int>> ans;

void solve(int l, int r){
  if(l>r)return;
  if(!ask(0,0,l,r))return;
  if(l==r){ans.push_back({0,l});return;}
  
  int m = (l+r) >> 1;

  solve(l,m);
  solve(m+1,r);
}

vector<pair<int,int>> find_couples(int n){
  solve(1,n-1);
  // cout << "------" << endll;
  // for(auto [i,j]:ans)cout << i << sp << j << endll;
  // cout << "------" << endll;
  // forr(i,0,n){
  //   forr(j,i+1,n){
  //     if(ask(i,i,j,j))ans.push_back({i,j});
  //   }
  // }

  return ans;
}

/*
5 2
0 1
0 3
*/

/*
100 1
0 99
*/

/*
15000 1
0 14999
*/