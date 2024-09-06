//https://www.spoj.com/problems/KGSS/

// You are given a sequence A[1], A[2], ..., A[N] ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input by a 'U' followed by space and then two integers i and x.

// U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

// This operation sets the value of A[i] to x.

// Query:
// This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

// Q x y, 1 ≤ x < y ≤ N.

// You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

// Input
// The first line of input consists of an integer N representing the length of the sequence. Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

// Output
// Output the maximum sum mentioned above, in a separate line, for each Query.

// Example
// Input:
// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5

// Output:
// 7
// 9
// 11
// 12


#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

class SegmentTree{
private:
    int n;
    vector<pair<int,int>> tree;
    
public:
    SegmentTree(vector<int> &v) {
        n = v.size();
        tree.resize(4 * n, {0, 0});
        build(0, 0, n - 1, v);
    }
    
    void build(int id, int start, int end, vector<int> &v) {
        if (start > end) return;
        if (start == end) {
            tree[id] = {v[start], LLONG_MIN}; // Initialize with second largest as negative infinity
            return;
        }
        
        int mid = start + (end - start) / 2;
        build(2 * id + 1, start, mid, v);
        build(2 * id + 2, mid + 1, end, v);
        
        vector<int> temp = {tree[2 * id + 1].first, tree[2 * id + 1].second,
                            tree[2 * id + 2].first, tree[2 * id + 2].second};
        sort(temp.rbegin(), temp.rend());
        tree[id] = {temp[0], temp[1]};
    }
    
    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }
    
    void updateTree(int id, int start, int end, int idx, int val) {
        if (start > end) return;
        if (start == end) {
            tree[id] = {val, LLONG_MIN}; // Update with new value, second largest still negative infinity
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(2 * id + 1, start, mid, idx, val);
        } else {
            updateTree(2 * id + 2, mid + 1, end, idx, val);
        }
        
        vector<int> temp = {tree[2 * id + 1].first, tree[2 * id + 1].second,
                            tree[2 * id + 2].first, tree[2 * id + 2].second};
        sort(temp.rbegin(), temp.rend());
        tree[id] = {temp[0], temp[1]};
    }
    
    pair<int,int> query(int l, int r) {
        return queryF(0, 0, n - 1, l, r);
    }
    
    pair<int,int> queryF(int idx, int start, int end, int ql, int qr) {
        if (qr < start || ql > end) return {0, LLONG_MIN}; // Return minimal values if out of range
        if (start >= ql && end <= qr) return tree[idx];
        
        int mid = start + (end - start) / 2;
        auto left = queryF(2 * idx + 1, start, mid, ql, qr);
        auto right = queryF(2 * idx + 2, mid + 1, end, ql, qr);
        
        vector<int> temp = {left.first, left.second, right.first, right.second};
        sort(temp.rbegin(), temp.rend());
        return {temp[0], temp[1]};
    }
};

signed main() {
    IOS

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int q;
    cin >> q;
    SegmentTree st(v);

    while (q--) {
        char type;
        cin >> type;

        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            auto ans = st.query(l - 1, r - 1); // Adjust to 0-based indexing
            cout << ans.first + ans.second << endl;
        } else {
            int idx, val;
            cin >> idx >> val;
            st.update(idx - 1, val); // Adjust to 0-based indexing
        }
    }

    return 0;
}
