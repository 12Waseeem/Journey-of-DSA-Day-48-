#include <string>
#include <unordered_map>
#include <stack>
#include <cctype>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        unordered_map<string, int> atomCount;
        stack<pair<string, int>> st;
        stack<int> multipliers;
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push({"", 0});
                i++;
            } else if (formula[i] == ')') {
                int start = ++i;
                int multiplier = 0;
                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + formula[i] - '0';
                    i++;
                }
                multiplier = max(multiplier, 1);

                unordered_map<string, int> temp;
                while (!st.empty() && st.top().second != 0) {
                    temp[st.top().first] += st.top().second * multiplier;
                    st.pop();
                }
                st.pop();

                for (const auto& kv : temp) {
                    st.push(kv);
                }
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string atom = formula.substr(start, i - start);
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + formula[i] - '0';
                    i++;
                }
                count = max(count, 1);
                st.push({atom, count});
            }
        }

        while (!st.empty()) {
            atomCount[st.top().first] += st.top().second;
            st.pop();
        }

        map<string, int> sortedAtomCount(atomCount.begin(), atomCount.end());
        string result;
        for (const auto& kv : sortedAtomCount) {
            result += kv.first;
            if (kv.second > 1) {
                result += to_string(kv.second);
            }
        }

        return result;
    }
};
