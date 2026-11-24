#include <vector>
using namespace std;

class TreeAncestor {
    static constexpr int MAX_LOG = 17; // 2^16 = 65536 > 50000
    vector<vector<int>> up;

public:
    TreeAncestor(int n, vector<int>& parent) {
        up.assign(MAX_LOG, vector<int>(n, -1));

        for (int i = 0; i < n; ++i) {
            up[0][i] = parent[i];
        }

        for (int j = 1; j < MAX_LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                int mid = up[j - 1][i];
                if (mid != -1) {
                    up[j][i] = up[j - 1][mid];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < MAX_LOG && node != -1; ++j) {
            if ((k >> j) & 1) {
                node = up[j][node];
            }
        }
        return node;
    }
};