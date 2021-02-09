#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
vector<int>v[100005];
int n,m,num[100005],gr[100005],x,y,k,ans;
bitset<100005>go;
queue<int>q;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!go[i])
        {
            q.push(i);
            while(!q.empty())
            {
                k=q.front();
                go[k]=true;
                gr[k]=i;
                q.pop();
                for(int j=0;j<v[k].size();j++)
                {
                    if(!go[v[k][j]])
                    {
                        q.push(v[k][j]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(gr[i]==gr[num[i]])ans++;
    }
    printf("%d",ans);
}
