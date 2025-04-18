#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        bool valid_string = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    valid_string = true;
                }

                if (valid_string) continue; // Pare de gerar substrings
                
                for (int j = 0; j < curr.size(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j + 1); // Cria uma substring de curr sem caracter 'j'
                    if (visited.count(next) == 0) { // Evita strings repetidas na fila da BFS
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }

            if (valid_string) break;
        }

        return result;
    }

private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                ++count;
            } else if (c == ')') {
                --count;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};

// int main() {
//     string s;
//     cin >> s;
//     Solution solve;
//     vector<string> validStrings = solve.removeInvalidParentheses(s);

//     for (const string& str : validStrings) {
//         cout << "\"" << str << "\"" << endl;
//     }
    
//     return 0;
// }
