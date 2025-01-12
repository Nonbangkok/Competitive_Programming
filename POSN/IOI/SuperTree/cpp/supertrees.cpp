#include <bits/stdc++.h>
#include "supertrees.h"
#define forr(i, a, n) for (int i = a; i < n; i++)
#define endll "\n"
#define sp " "
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &p,vector<vector<int>> &b,vector<bool> &visited,int n,int u){
	visited[u] = true;
	forr(i,0,n){	
		if(u==i||visited[i])continue;
		if(p[u][i]){
			b[u][i] = b[i][u] = 1;
			dfs(p,b,visited,n,i);
		}
	}
}

int construct(vector<vector<int>> p) {
	int n = p.size();

	vector<vector<int>> b;
	vector<bool> visited(n,false);
	for (int i = 0; i < n; i++) {
		vector<int> row;
		row.resize(n);
		b.push_back(row);
	}

	forr(i,0,n){
		if(visited[i])continue;
		dfs(p,b,visited,n,i);
	}

	build(b);
	return 1;
}
