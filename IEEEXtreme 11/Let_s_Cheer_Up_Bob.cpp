#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int fewest = 12;
vector<ii> finalans,res;
int a[4][4];
int board[4][4];
int point[10];

int checkboard() {
    FOR(i,1,3) {
        int r = 0, c = 0;
        FOR(j,1,3) {
            r+=board[i][j];
            c+=board[j][i];
        }
        if (r==3) return 1;
        if (r==12) return 4;
        if (c==3) return 1;
        if (c==12) return 4;
    }
    int r = board[1][1]+board[2][2]+board[3][3];
    int c = board[1][3]+board[2][2]+board[3][1];
    if (r==3) return 1;
    if (r==12) return 4;
    if (c==3) return 1;
    if (c==12) return 4;
    return 0;
}
void backtrack(int turn) {
    if (turn %2) {
        FOR(x,1,9) if (point[x]==0) {
            FOR(i,1,3) FOR(j,1,3)
                if (a[i][j]==x) {
                    board[i][j] = 1;
                    point[x] = 1;
                    backtrack(turn+1);
                    board[i][j] = 0;
                    point[x] = 0;
                }
            break;
        }
        return;
    }
    if (turn > fewest) return;
    if (checkboard()==1) {
        if (turn < fewest) {
            fewest = turn;
            finalans = res;
            return;
        }
        finalans = min(finalans,res);
        return;
    }
    FOR(i,1,3) FOR(j,1,3)
        if (!board[i][j]) {
            board[i][j] = 4;
            point[a[i][j]] = 1;
            int flag = checkboard();
            res.pb({i,j});
            if (flag == 0) 
                backtrack(turn+1);
            res.pop_back();
            board[i][j] = 0;
            point[a[i][j]] = 0;
        }
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    FOR(i,1,9) {
        int x,y;
        cin >> x >> y;
        a[x][y] = i;
    }
    backtrack(1);
    for(ii x:finalans) 
        cout << x.F << " " << x.S << "\n";
    
}