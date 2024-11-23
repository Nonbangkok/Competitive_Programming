#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Point{
    double x,y;
};

double dis(Point a, Point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int main(){macos;

    vector<Point> Points;

    int n;
    cin >> n;

    forr(i,0,n){
        double a,b;
        cin >> a >> b;
        Points.push_back({a,b});
    }

    double d = DBL_MAX;
    forr(i,0,n)forr(j,i+1,n)d = min(d, dis(Points[i],Points[j]));
    cout << d;

    return 0;
}