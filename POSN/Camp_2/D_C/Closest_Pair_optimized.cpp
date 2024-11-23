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
int chk = 0;
double Closest_Pair(vector<Point> Px, vector<Point> Py){
    int n = Px.size();
    if(n<=3){
        double mn = DBL_MAX;
        forr(i,0,n)forr(j,i+1,n)mn = min(mn,dis(Px[i],Px[j]));
        return mn;
    }

    int mid = n >> 1;
    Point midPoint = Px[mid];

    vector<Point> Pxl (Px.begin(),Px.begin()+mid);
    vector<Point> Pxr (Px.begin()+mid,Px.end());
    vector<Point> Pyl, Pyr;

    for(auto p:Py){
        if(p.x < midPoint.x)Pyl.push_back(p);
        else Pyr.push_back(p);
    }

    double dl = Closest_Pair(Pxl,Pyl);
    double dr = Closest_Pair(Pxr,Pyr);
    double d = min(dl,dr);

    n = Py.size();
    for(int i=0;i<n;i++){
        if(abs(Py[i].x-midPoint.x) < d){
            for(int j = i + 1; j < n && (Py[j].y - Py[i].y) < d; j++){
                d = min(d, dis(Py[i], Py[j]));
            }
        }
    }

    return d;
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

    vector<Point> Px = Points, Py = Points;

    sort(Px.begin(),Px.end(),[](const Point &a, const Point &b) { return a.x < b.x; });
    sort(Py.begin(),Py.end(),[](const Point &a, const Point &b) { return a.y < b.y; });

    cout << Closest_Pair(Px,Py);

    return 0;
}