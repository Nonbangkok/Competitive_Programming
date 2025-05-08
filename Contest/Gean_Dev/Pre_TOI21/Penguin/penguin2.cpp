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
int cnt = 0;

void match(int l1, int r1, int l2, int r2){
  if(cnt==100)return;
  if(l1>r1||l2>r2)return;
  if(!ask(l1,r1,l2,r2))return;
  if(l1==r1&&l2==r2){ans.push_back({l1,l2});cnt++;return;}

  int m1 = (l1+r1) >> 1;
  int m2 = (l2+r2) >> 1;

  match(l1,r1,l2,m2);
  match(l1,r1,m2+1,r2);
  match(l1,m1,l2,r2);
  match(m1+1,r1,l2,r2);
}

void solve(int l, int r){
  if(cnt==100)return;
  if(l>=r)return;
  if(!ask(l,r,l,r))return;

  int m = (l+r) >> 1;
  
  solve(l,m);
  solve(m+1,r);

  match(l,m,m+1,r);
}

vector<pair<int,int>> find_couples(int n){
  solve(0,n-1);
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