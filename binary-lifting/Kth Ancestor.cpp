class TreeAncestor {
public:
    int dp[16][50006];

    TreeAncestor(int n, vector<int>& parent) {
        memset(dp, 0, sizeof dp);

        for (int i = 0; i < n; i++) {
            dp[0][i] = parent[i];
        }

        for (int i = 1; i < 16; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i-1][j] != -1) {  // Ensure valid ancestor
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                } else {
                    dp[i][j] = -1;  // No valid ancestor found
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int ans = node;
        for (int i = 15; i >= 0; i--) {
            if (k & (1 << i)) {
                if (dp[i][ans] == -1) return -1;  // No valid ancestor
                ans = dp[i][ans];
            }
        }
        return ans;
    }
};

//------------------------------------------CSES------------------------------------


// Company Queries I

#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 200000;
const int LOG = 18; // Since 2^18 > 200000
 
int dp[LOG][MAX_N + 1]; // dp[j][i] is the 2^j-th ancestor of employee i
 
int main() {
    int n, q;
    cin >> n >> q;
 
    memset(dp,0,sizeof dp);
 
    
    //The quetiosn gives info about parent of 2,3,4........
    for (int i = 2; i <= n; i++) {
        cin >> dp[0][i]; // The 1st ancestor (boss) of employee i
    }
    
    // Preprocessing the Binary Lifting table with reversed dimensions
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[j-1][i] != 0) {
                dp[j][i] = dp[j-1][dp[j-1][i]];
            } else {
                dp[j][i] = 0; // If there's no such ancestor
            }
        }
    }
    
    // Processing each query
    while (q--) {
        int x, k;
        cin >> x >> k;
        
        // Find the k-th ancestor
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) { // If the j-th bit is set in k
                x = dp[j][x];
                if (x == 0) break; // No such ancestor exists
            }
        }
        
        if (x == 0) {
            cout << "-1\n";
        } else {
            cout << x << "\n";
        }
    }
 
    return 0;
}