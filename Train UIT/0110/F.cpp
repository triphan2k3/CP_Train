/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, Next[16][100006];
string a[100006], tmp;
vector<int> S, T;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;
    for(int i = n-1; i >= 1; --i) {
        res += max(0, (int) a[i].size() - (int) a[i+1].size());
        if (a[i].size() < a[i+1].size()) continue;
        for(int c = 0; c < 10; ++c) Next[c][a[i].size()] = -1;
        for(int j = a[i].size()-1; j >= 0; --j) {
            for(int c = 0; c < 10; ++c) Next[c][j] = Next[c][j+1];
            Next[a[i][j] - '0'][j] = j;
        }
        S.clear(); int cur = 0;
        for(int j = 0; j < (int) a[i].size() && cur < (int) a[i+1].size(); ++j)
        if (a[i][j] == a[i+1][cur]) {
            S.push_back(j);
            ++cur;
        }
        if (cur >= (int) a[i+1].size()) {
            a[i] = a[i+1];
            continue;
        }
        bool ok = false;
        ++cur; S.push_back(0);
        while (!S.empty() && !ok) {
            --cur; S.pop_back();
            int point = 0;
            if (!S.empty()) point = S.back() + 1;
            for(int c = a[i+1][cur] - '1'; c >= 0 && !ok; --c)
            if (Next[c][point] != -1) {
                T.clear();
                int era = a[i].size() - Next[c][point] - a[i+1].size() + cur;
                if (era < 0) continue;
                for(int k = Next[c][point] + 1; k < (int) a[i].size(); ++k) {
                    while (era > 0 && !T.empty() && a[i][T.back()] < a[i][k]) {
                        --era;
                        T.pop_back();
                    }
                    T.push_back(k);
                }
                while (era > 0 && !T.empty()) {
                    --era;
                    T.pop_back();
                }
                if (era == 0) {
                    ok = true; tmp = "";
                    for(int j = 0; j < (int) S.size(); ++j)
                        tmp = tmp + a[i][S[j]];

                    tmp = tmp + a[i][Next[c][point]];

                    for(int j = 0; j < (int) T.size(); ++j)
                        tmp = tmp + a[i][T[j]];

                    a[i] = tmp;
                    break;
                }
            }
        }
        if (!ok) {
            if (a[i+1].size() == 1) {
                cout << "-1";
                return 0;
            }
            int era = a[i].size() - a[i+1].size() + 1;
            T.clear();
            for(int k = 0; k < (int) a[i].size(); ++k) {
                while (era > 0 && !T.empty() && a[i][T.back()] < a[i][k]) {
                    --era;
                    T.pop_back();
                }

                T.push_back(k);
            }
            while (era > 0 && !T.empty()) {
                --era;
                T.pop_back();
            }
            tmp = "";
            for(int j = 0; j < (int) T.size(); ++j)
                tmp = tmp + a[i][T[j]];
            a[i] = tmp;
            ++res;
        }
    }
    cout << res;
    return 0;
}