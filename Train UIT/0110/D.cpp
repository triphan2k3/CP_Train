/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[200006];
int n, k, m, par[200006][20], connect[200006], con = 0, depth[200006];

void DFS(int u) {
    connect[u] = con;
    for(int i = 1; i <= 18; ++i) par[u][i] = par[par[u][i-1]][i-1];

    for(int v: V[u])
    if (par[u][0] != v) {
        par[v][0] = u;
        depth[v] = depth[u] + 1;
        DFS(v);
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int h = depth[v] - depth[u];
    for(int i = 18; i >= 0; --i)
    if (h & (1 << i)) v = par[v][i];

    if (u == v) return u;

    for(int i = 18; i >= 0; --i)
    if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }

    return par[u][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u)
    if (par[u][0] == 0) {
        ++con;
        DFS(u);
    }

    cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;

        if (connect[u] != connect[v]) {
            cout << -1 << '\n';
            continue;
        }

        int p = LCA(u, v);
        if (depth[u] - depth[p] >= 1) {
            cout << par[u][0] << '\n';
            continue;
        }

        int h = depth[v] - depth[p] - 1;

        for(int i = 18; i >= 0; --i)
        if (h & (1 << i)) v = par[v][i];

        cout << v << '\n';
    }

    return 0;
}
