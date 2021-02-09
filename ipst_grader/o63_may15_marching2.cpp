#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define imx ((int)1e9)
#define all(x) ((x).begin(),((x).end())
typedef long long LL;
int n,m,mp[1505][1505][7],x,rr;
LL ans=imx;
bool p=false;
int main()
{
    scanf("%d %d",&n,&m);
    if(n>m)swap(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int o=3;o<7;o++)mp[i][0][o]=imx,mp[i][m+1][o]=imx;
    }
    for(int j=1;j<=m;j++)
    {
        for(int o=3;o<7;o++)mp[0][j][o]=imx,mp[n+1][j][o]=imx;
    }
    mp[1][0][3]=0;
    mp[n][0][4]=0;
    mp[0][m][5]=0;
    mp[n+1][m][6]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&x);
            if(p)
            {
                mp[j][i][1]=mp[j-1][i][1]+x;
                mp[j][i][2]=mp[j][i-1][2]+x;
                mp[j][i][0]=x;
                mp[j][i][3]=mp[j][i][0]+min(mp[j][i-1][3],mp[j-1][i][3]);
            }
            else
            {
                mp[i][j][1]=mp[i][j-1][1]+x;
                mp[i][j][2]=mp[i-1][j][2]+x;
                mp[i][j][0]=x;
                mp[i][j][3]=mp[i][j][0]+min(mp[i-1][j][3],mp[i][j-1][3]);
            }
            //printf("%d ",mp[i][j][3]);
        }
        //printf("\n");
    }
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=m;j++)
        {
            mp[i][j][4]=mp[i][j][0]+min(mp[i+1][j][4],mp[i][j-1][4]);
            // printf("%d ",mp[i][j][4]);
        }
        // printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>0;j--)
        {
            mp[i][j][5]=mp[i][j][0]+min(mp[i-1][j][5],mp[i][j+1][5]);
            // printf("%d ",mp[i][j][5]);
        }
        // printf("\n");
    }
    for(int i=n;i>0;i--)
    {
        for(int j=m;j>0;j--)
        {
            mp[i][j][6]=mp[i][j][0]+min(mp[i+1][j][6],mp[i][j+1][6]);
            // printf("%d ",mp[i][j][6]);
        }
        // printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        rr=imx;
        for(int j=m;j>0;j--)
        {
            ans=min(ans,(LL)rr-mp[i][j][1]+mp[i][j][3]+mp[i][j][4]-mp[i][j][0]);
            ans=min(ans,(LL)mp[i][j][3]+mp[i][j][4]-(mp[i][j][0]*3)+mp[i][j][5]+mp[i][j][6]);
            rr=min(rr,mp[i][j][5]+mp[i][j][6]+mp[i][j-1][1]-mp[i][j][0]);
        }
    }
    for(int j=1;j<=m;j++)
    {
        rr=imx;
        for(int i=n;i>0;i--)
        {
            ans=min(ans,(LL)rr-mp[i][j][2]+mp[i][j][3]+mp[i][j][4]-mp[i][j][0]);
            ans=min(ans,(LL)mp[i][j][3]+mp[i][j][4]-(mp[i][j][0]*3)+mp[i][j][5]+mp[i][j][6]);
            rr=min(rr,mp[i][j][5]+mp[i][j][6]+mp[i-1][j][2]-mp[i][j][0]);
        }
    }
    printf("%lld",ans);
}
