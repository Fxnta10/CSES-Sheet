#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26);
    for (char c : s) {
        freq[c - 'A']++;
    }

    string ans = "";
    while (ans.size() < n) {
        for (int i = 0; i < 26; i++) {
            char c = i + 'A';
            if (freq[i] > 0 && (ans.empty() || ans.back() != c)) {
                freq[i]--;
                int mx = 0;
                int remaining = n - ans.size() - 1;

                for (int j = 0; j < 26; j++) {
                    mx = max(mx, freq[j]);
                }

                if (mx <= (remaining + 1) / 2) {
                    ans += c;
                    break;
                }
                freq[i]++;
            }
        }
    }
    cout << ans << endl;
}