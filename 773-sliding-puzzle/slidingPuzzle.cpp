class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            // Movimentos possíveis (esquerda, baixo, direita, cima)
            int dr[] = {0, 1, 0, -1}; 
            int dc[] = {-1, 0, 1, 0};
    
            // Estado final desejado do tabuleiro
            vector<vector<int>> res(2, vector<int>(3));
            res[0][0] = 1;
            res[0][1] = 2;
            res[0][2] = 3;
            res[1][0] = 4;
            res[1][1] = 5;
            res[1][2] = 0;
    
            // Procurar a posição inicial do 0
            int r, c;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == 0) {
                        r = i;
                        c = j;
                        break;
                    }
                }
            }
    
            // Fila para a BFS
            queue<pair<pair<int, int>, pair<vector<vector<int>>, int>>> q;
            q.push({{r, c}, {board, 0}}); // Adiciona o estado inicial na fila
    
            // Mapa para registrar quais estados já foram visitados
            map<vector<vector<int>>, int> mp;
            mp[board]++;
    
            // Início da BFS
            while(!q.empty()) {
                // Estado atual da fila
                int row = q.front().first.first;
                int col = q.front().first.second;
                vector<vector<int>> v = q.front().second.first;
                int steps = q.front().second.second;
                q.pop();
    
                // Verifica a solução
                if(v == res) return steps;
    
                // Tenta mover o 0 para as 4 direções
                for(int i = 0; i < 4; i++) {
                    int nr = row + dr[i]; // nova linha
                    int nc = col + dc[i]; // nova coluna
    
                    if(nc < 3 && nr < 2 && nr >= 0 && nc >= 0) {
                        // Troca o 0 com o número vizinho
                        swap(v[nr][nc], v[row][col]);
    
                        // Se o novo estado ainda não foi visitado
                        if(mp.find(v) == mp.end()) {
                            // Adiciona o novo estado à fila 
                            q.push({{nr, nc}, {v, steps + 1}});
                            mp[v]++; // Marca como visitado
                        }
    
                        // Desfaz a troca 
                        swap(v[nr][nc], v[row][col]);
                    }
                }
            }
    
            // Se não houver solução
            return -1;
        }
    };
    