class Solution {
public:
    int m, n;
    const array<array<int, 2>, 4> directions = {{{0,1}, {1,0}, {0,-1}, {-1,0}}};

    int dfs(int i, int j, const vector<vector<int>>& matrix, vector<int>& cache) {
        int idx = i * n + j; // traduz posicao da matriz para o vetor cache
        if (cache[idx] != 0) return cache[idx];

        int maxLength = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + directions[k][0], y = j + directions[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxLength = max(maxLength, 1 + dfs(x, y, matrix, cache)); // maior caminho a partir de uma direcao
            }
        }

        return cache[idx] = maxLength; // salva na cache o maior caminho partindo dessa posicao
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        m = matrix.size();
        n = matrix[0].size();
        vector<int> cache(m * n, 0);
        int result = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result = max(result, dfs(i, j, matrix, cache));

        return result;
    }
};

