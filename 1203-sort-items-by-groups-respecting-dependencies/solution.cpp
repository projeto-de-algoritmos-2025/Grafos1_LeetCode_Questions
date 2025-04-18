#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1)
                group[i] = groupId++;   // IDs únicos aos items com ID -1
        }
        
        // Grafos dos items e dos grupos
        vector<vector<int>> itemGraph(n);
        vector<int> itemInDegree(n, 0);
        vector<vector<int>> groupGraph(groupId);
        vector<int> groupInDegree(groupId, 0);
        unordered_map<int, vector<int>> groupItems;

        
        for (int curr = 0; curr < n; ++curr) {
            groupItems[group[curr]].push_back(curr); // Array de items que pertencem ao mesmo grupo 
            for (int prev : beforeItems[curr]) {
                itemGraph[prev].push_back(curr); // Pré-requisitos de curr
                itemInDegree[curr]++; // Vetor contador de pré-requisitos de um elemento
                if (group[prev] != group[curr]) { // Verifica se há pré-requisitos entre grupos distintos 
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupInDegree[group[curr]]++;
                }
            }
        }

        vector<int> sortedItems = topologicalSort(itemGraph, itemInDegree);
        vector<int> sortedGroups = topologicalSort(groupGraph, groupInDegree);
        if (sortedItems.empty() || sortedGroups.empty()) return {};

        // Agrupa os itens com ordem topológica correta em seus respectivos grupos
        unordered_map<int, vector<int>> orderedGroupItems;
        for (int item : sortedItems) {
            orderedGroupItems[group[item]].push_back(item);
        }
        
        // Monta o vetor final baseado na ordem de precedência dos grupos
        vector<int> result;
        for (int grp : sortedGroups) {
            for (int item : orderedGroupItems[grp]) {
                result.push_back(item);
            }
        }

        return result;
    }

private:
    vector<int> topologicalSort(const vector<vector<int>>& graph, vector<int>& inDegree) {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);
            for (int v : graph[u]) {
                if (--inDegree[v] == 0) q.push(v);
            }
        }

        return result.size() == graph.size() ? result : vector<int>();
    }   
};

// int main() {
//     Solution s;
//     int n = 8, m = 2;
//     vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
//     vector<vector<int>> beforeItems = {
//         {}, {6}, {5}, {6}, {3, 6}, {}, {}, {}
//     };
//     vector<int> result = s.sortItems(n, m, group, beforeItems);

//     for (int val : result) cout << val << " ";
//     cout << endl;

//     return 0;
// }
