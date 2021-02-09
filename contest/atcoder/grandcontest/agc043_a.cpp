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
int n,m,k[105][105],a,b,ii,jj,ni,nj,di[]={0,1},dj[]={1,0};
char c[105][105];
priority_queue<pair<pii,pii> >pq;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)k[i][j]=imx;
    }
    pq.push({{0,'.'},{0,1}});
    while(!pq.empty())
    {
        a=-pq.top().F.F;
        b=pq.top().F.S;
        ii=pq.top().S.F;
        jj=pq.top().S.S;
        //printf("[%d %d]",ii,jj);
        pq.pop();
        for(int i=0;i<2;i++)
        {
            ni=ii+di[i];
            nj=jj+dj[i];
            if(ni<1||nj<1||ni>n||nj>m)continue;
            if(b=='.'&&c[ni][nj]=='#')
            {
                if(a+1<k[ni][nj])
                {
                    k[ni][nj]=a+1;
                    pq.push({{-k[ni][nj],c[ni][nj]},{ni,nj}});
                }
            }
            else
            {
                if(a<k[ni][nj])
                {
                    k[ni][nj]=a;
                    pq.push({{-k[ni][nj],c[ni][nj]},{ni,nj}});
                }
            }
        }
    }
    printf("%d",k[n][m]);
}
