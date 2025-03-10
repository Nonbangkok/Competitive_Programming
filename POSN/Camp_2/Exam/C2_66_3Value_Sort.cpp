//3ValSort : Greedy + Math
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int na[4];
    int table[4][4]; //table[X][Y] : number X in zone Y
    memset(na, 0, sizeof(na));
    memset(table, 0, sizeof(table));
    cin >> n;
    int s[n+1];
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        na[s[i]]++;
    }
    for (int i = 1; i <= n; i++){
        if (i <= na[1])
            table[s[i]][1]++;
        else if (i <= na[1] + na[2])
            table[s[i]][2]++;
        else table[s[i]][3]++;
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++)cout << table[i][j] << ' ';
        cout << "\n";
    }
    int ans = min(table[1][2], table[2][1])
            + min(table[1][3], table[3][1])
            + min(table[2][3], table[3][2])
            + 2 * abs(table[1][2] - table[2][1]);
            
    // int ans = min(table[1][2], table[2][1])
    //     + min(table[1][3], table[3][1])
    //     + min(table[2][3], table[3][2])
    //     + 2 * (abs(table[1][2] - table[2][1]) + abs(table[1][3] - table[3][1]) + abs(table[2][3] - table[3][2])) / 3;

    cout << ans;
    return 0;
}