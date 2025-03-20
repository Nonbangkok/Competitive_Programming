#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

class Solution{
public:

    bool vis[31][31][1<<6];
    const int di[4] = {0,0,-1,1};
    const int dj[4] = {-1,1,0,0};
    queue<tuple<int,int,int,int>> q;

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), p = 0, bk, ans = 1e9, a, b;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(grid[i][j]=='@')q.push({a=i,b=j,0,0});
            else if(islower(grid[i][j]))p++;
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<(1<<p);k++)vis[i][j][k] = false;

        vis[a][b][0] = true;
        while(!q.empty()){
            auto [i,j,d,b] = q.front();
            q.pop();

            if(b == (1<<p)-1)return d;

            for(int k=0;k<4;k++){
                int ik = i + di[k];
                int jk = j + dj[k];

                if(ik<0||ik>=n||jk<0||jk>=m||grid[ik][jk]=='#')continue;

                if(islower(grid[ik][jk]))bk = b|(1<<(grid[ik][jk]-'a'));
                else bk = b;

                if(vis[ik][jk][bk])continue;
                if(isupper(grid[ik][jk]) && !(bk&(1<<(grid[ik][jk]-'A'))))continue;

                vis[ik][jk][bk] = true;
                q.push({ik,jk,d+1,bk});
            }
        }
        return -1;
    }
};

int main(){macos;

    // vector<string> grid = {"@.a..","###.#","b.A.B"};
    // vector<string> grid = {"@..aA","..B#.","....b"};
    // vector<string> grid = {"@Aa"};
    // vector<string> grid = {"..Ff..#..e.#...",".....#.##...#..","....#.#...#....","##.......##...#","...@#.##....#..","#........b.....","..#...#.....##.",".#....#E...#...","......A.#D.#...","...#...#..#....","...a.#B#.......",".......c.....#.","....#...C#...#.","##.#.....d..#..",".#..#......#..."};
    vector<string> grid = {"#..#.#.#..#.#.#.....#......#..",".#.......#....#A.....#.#......","#....#.....#.........#........","...#.#.........#..@....#....#.",".#.#.##...#.........##....#..#","..........#..#..###....##..#.#",".......#......#...#...#.....c#",".#...#.##......#...#.###...#..","..........##...#.......#......","#...#.........a#....#.#.##....","..#..#...#...#..#....#.....##.","..........#...#.##............","...#....#..#.........#..D.....","....#E.#....##................","...........##.#.......#.#....#","...#..#...#.#............#e...","..#####....#.#...........##..#","##......##......#.#...#..#.#..",".#F.......#..##.......#....#..","............#....#..#..#...#..",".............#...#f...#..##...","....#..#...##.........#..#..#.",".....#.....##.###..##.#......#",".#..#.#...#.....#........###..",".....#.#...#...#.....#.....#..","##.....#....B.....#..#b.......",".####....##..#.##..d.#......#.","..#.....#....##........##...##","...#...#...C..#..#....#.......","#.....##.....#.#......#......."};

    Solution sol;
    cout << sol.shortestPathAllKeys(grid);

    return 0;
}