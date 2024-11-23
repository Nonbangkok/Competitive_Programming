#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

struct Marble{
    int weight;
    int id;

    bool operator<(const Marble& other) const {
        if (weight != other.weight)
            return weight < other.weight;
        else
            return id < other.id;
    }
};

typedef tree<Marble,null_type,less<Marble>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    int a, b;
    scanf("%d %d", &a, &b);

    ordered_set marbles;
    int id_counter = 0;

    for (int i = 0; i < N; ++i) {
        int w;
        scanf("%d", &w);
        marbles.insert({w, id_counter++});
    }

    for (int round = 0; round < L; ++round) {
        auto it_a = marbles.find_by_order(a - 1);
        auto it_b = marbles.find_by_order(b - 1);

        Marble marble_a = *it_a;
        Marble marble_b = *it_b;

        int x = marble_a.weight;
        int y = marble_b.weight;

        marbles.erase(it_a);
        marbles.erase(it_b);

        marbles.insert({y - x, id_counter++});
        marbles.insert({(x + y) / 2, id_counter++});
    }

    for (auto it = marbles.begin(); it != marbles.end(); ++it) {
        printf("%d", it->weight);
        if (next(it) != marbles.end())
            printf(" ");
    }
    printf("\n");

    return 0;
}