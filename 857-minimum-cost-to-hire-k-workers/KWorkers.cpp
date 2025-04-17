class Solution {
    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
            int n = quality.size(); 
            double resultado = DBL_MAX; 
            double somaQualidade = 0;
    
            vector<pair<double, int>> razaoSalarioQualidade;
            for (int i = 0; i < n; ++i) {
                // razão de salário e qualidade de cada trabalhador
                razaoSalarioQualidade.emplace_back(
                    static_cast<double>(wage[i]) / quality[i], quality[i]);
            }

            sort(razaoSalarioQualidade.begin(), razaoSalarioQualidade.end());
    
            //max-heap para qualidades
            priority_queue<int> highQualityWorkers;
    
            for (int i = 0; i < n; ++i) {
                double ratio = razaoSalarioQualidade[i].first;  
                int qua = razaoSalarioQualidade[i].second;       
    
                somaQualidade += qua;                     
                highQualityWorkers.push(qua);             
    
                // Com mais do que k, remove o trabalhador de maior qualidade (maior custo)
                if (highQualityWorkers.size() > k) {
                    somaQualidade -= highQualityWorkers.top(); 
                    highQualityWorkers.pop();                   
                }
    
                // Com k, calcula o custo total
                if (highQualityWorkers.size() == k) {
                    resultado = min(resultado, somaQualidade * ratio);
                }
            }
            return resultado;
        }
    };
    