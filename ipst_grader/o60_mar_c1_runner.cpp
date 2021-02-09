#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,a,b,ans,l,r,po,L,R,pre[105][5005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&b,&a);
        pre[a][b]=1;
    }
    for(int i=1;i<105;i++)for(int j=1;j<5005;j++)pre[i][j]+=pre[i][j-1];
    for(int i=1;i<=m;i++)
    {
        ans=0;
        scanf("%d %d %d",&po,&L,&R);
        for(int sp=1;sp<=100;sp++)
        {
            l=L-(po/sp);
            r=R-((po+sp-1)/sp);
            l--;
            l=max(l,0);
            r=max(r,0);
            l=min(l,5004);
            r=min(r,5004);
            ans+=(pre[sp][r]-pre[sp][l]);
        }
        printf("%d\n",ans);
    }
}
/*
4 5
1 7
2 7
3 7
4 7
1 1 10
2 0 5
3 4 9
7 2 2
0 1 1
*/
