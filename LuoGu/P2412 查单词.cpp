#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<string> words;
vector<string> low;          // 每个单词的小写形式
vector<vector<int>> st;      // st[k][i] 表示从 i 开始，长度 2^k 的区间内最优单词的下标
vector<int> lg;              // lg[x] = floor(log2(x))

// 返回 i, j 中更优的下标（忽略大小写字典序最大；相等时取下标大的）
int better(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    if (low[i] != low[j]) return low[i] > low[j] ? i : j;
    return max(i, j);   // 相等取靠后的
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    words.resize(N);
    low.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        low[i] = words[i];
        for (char& c : low[i]) c = tolower(c);
    }

    // 预处理 log2
    lg.assign(N + 1, 0);
    for (int i = 2; i <= N; ++i) lg[i] = lg[i >> 1] + 1;

    // 构建 ST 表
    int K = lg[N] + 1;
    st.assign(K, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) st[0][i] = i;
    for (int k = 1; k < K; ++k) {
        int len = 1 << k;
        int half = len >> 1;
        for (int i = 0; i + len <= N; ++i) {
            st[k][i] = better(st[k - 1][i], st[k - 1][i + half]);
        }
    }

    // 回答查询
    while (M--) {
        int x, y;
        cin >> x >> y;
        --x; --y;                  // 转 0-based 闭区间
        int k = lg[y - x + 1];
        int ans = better(st[k][x], st[k][y - (1 << k) + 1]);
        cout << words[ans] << '\n';
    }

    return 0;
}