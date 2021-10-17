#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MATCH1.INP"
#define out "MATCH1.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int match[N],avail[N],remind[N];
int p,q,m,sz,ok;

void dfs(int u)
{
    for (int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if (avail[v]) continue;
        avail[v]=1;
        if (match[v])
            dfs(match[v]);
        else
            ok=1;
        if (ok)
        {
            match[v]=u;
            return;
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>p>>q;
    int u,v;
    while (scanf("%d%d",&u,&v)==2)
        a[u].push_back(v);

    for (int i=1;i<=p;i++)
        remind[i]=i;
    sz=p;
    while (1)
    {
        int _sz=sz;
        for (int i=1;i<=q;i++)
            avail[i]=0;
        for (int i=sz;i>=1;i--)
        {
            ok=0;
            dfs(remind[i]);
            if (ok)
                remind[i]=remind[sz--];
        }
        if (sz==_sz) break;
    }
    cout<<p-sz<<"\n";
    for (int i=1;i<=q;i++)
        if (match[i])
            cout<<match[i]<<" "<<i<<"\n";
}
