class Solution {
    public:
        unordered_map<char, vector<int>> index;
        int DFS(int i, string &key, string &ring, int j, vector<vector<int>> &memo) {
            if (i >= key.size()) return 0;
            // Salva valor da solução
            if (memo[i][j] != -1) return memo[i][j];

            char caractereAtual = key[i];
            int resposta = INT_MAX;

            for (int indice : index[caractereAtual]) {
    
                int passosEsquerda = abs(indice - j);
                int passosDireita = ring.size() - abs(indice - j);
    
                // Calcula o total de passos para alinhar e segue pro caracter seguinte
                int passosTotais = min(passosEsquerda, passosDireita) + DFS(i + 1, key, ring, indice, memo);
    
                // Atualiza a melhor resposta
                resposta = min(resposta, passosTotais);
            }
    
            // Adiciona 1 passo para selecionar o caractere
            return memo[i][j] = 1 + resposta;
        }
    
        int findRotateSteps(string ring, string key) {
    
            int m = key.size(), n = ring.size();
    
            // Matriz de memorização para armazenar os resultados das soluções
            vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    
            // Armazena os índices de cada caractere presente no anel
            for (int i = 0; i < ring.size(); i++) {
                index[ring[i]].push_back(i);
            }
    
            // Inicia busca
            return DFS(0, key, ring, 0, memo);
        }
    };
    