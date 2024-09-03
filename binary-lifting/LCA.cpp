#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define c2 cout<<"-1\n"
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int MAX_N = 1e5 + 5;
const int LOG = 20; // Adjusted to 20 to handle large inputs

vector<int> adj[MAX_N];
int depth[MAX_N];
int dp[LOG][MAX_N]; // dp[j][i] is the 2^j-th ancestor of node i

void dfs(int node, int par, int d) {
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

void build(int n,vector<int>&parent) {
   
   dp[0][0]=-1;
   for(int i=1;i<=n;i++){
    dp[0][i]=parent[i];
   }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (dp[j-1][i] != -1) {
                dp[j][i] = dp[j-1][dp[j-1][i]];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; j--) {
        if ((1 << j) <= diff) {
            u = dp[j][u];
            diff -= (1 << j);
        }
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (dp[j][u] != dp[j][v]) {
            u = dp[j][u];
            v = dp[j][v];
        }
    }

    return dp[0][u];
}

signed main() {
    IOS
    int n;
    cin >> n;
    vector<int> parent(n+1,-1);


    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        parent[i]=p;
        
        adj[i].pb(p);
        adj[p].pb(i);
    }

    memset(dp, -1, sizeof dp);
    dfs(0, -1, 0);
    build(n,parent);

    int q;
    cin >> q;

    int x;
    cin >> x;

    for (int i = 1; i < q; i++) {
        int y;
        cin >> y;
        x = lca(x, y);
    }

    cout << x << endl;

    return 0;
}
