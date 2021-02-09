#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define imx ((int)1e9)
#define all(x) ((x).begin(),((x).end())
typedef long long LL;
int mp[1505][1505][7],x,n,m;
LL rr,ans=(LL)1e16;
LL val1(int c,int a)
{
    return mp[c][a-1][1]+mp[c][a][5]+mp[c][a][6]-mp[c][a][0];
}
LL val2(int a,int c)
{
    return mp[a-1][c][2]+mp[a][c][5]+mp[a][c][6]-mp[a][c][0];
}
int dis1(int a,int b,int c)
{
    return mp[c][b-1][1]-mp[c][a][1];
}
int dis2(int a,int b,int c)
{
    return mp[b-1][c][2]-mp[a][c][2];
}
int cal1(int a,int b,int c)
{
    return mp[c][a][3]+mp[c][a][4]+mp[c][b][5]+mp[c][b][6]-mp[c][a][0]-mp[c][b][0]+dis1(a,b,c);
}
int cal2(int a,int b,int c)
{
    return mp[a][c][3]+mp[a][c][4]+mp[b][c][5]+mp[b][c][6]-mp[a][c][0]-mp[b][c][0]+dis2(a,b,c);
}
int main()
{
    scanf("%d %d",&n,&m);
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
            mp[i][j][1]=mp[i][j-1][1]+x;
            mp[i][j][2]=mp[i-1][j][2]+x;
            mp[i][j][0]=x;
            mp[i][j][3]=mp[i][j][0]+min(mp[i-1][j][3],mp[i][j-1][3]);
            //printf("%d",mp[i][j][3]);
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
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<m;j++)
    //     {
    //         for(int k=j;k<=m;k++)
    //         {
    //             if(j==k)ans=min(ans,cal1(j,k,i)-mp[i][j][0]);
    //             else ans=min(ans,cal1(j,k,i));
    //         }
    //     }
    // }
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<n;j++)
    //     {
    //         for(int k=j;k<=n;k++)
    //         {
    //             if(j==k)ans=min(ans,cal2(j,k,i)-mp[j][i][0]);
    //             else ans=min(ans,cal2(j,k,i));
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        rr=imx;
        for(int j=m;j>0;j--)
        {
            rr=min(rr,val1(i,j));
            ans=min(ans,rr-mp[i][j][1]+mp[i][j][3]+mp[i][j][4]-mp[i][j][0]);
        }
    }
    for(int j=1;j<=m;j++)
    {
        rr=imx;
        for(int i=n;i>0;i--)
        {
            rr=min(rr,val2(i,j));
            ans=min(ans,rr-mp[i][j][2]+mp[i][j][3]+mp[i][j][4]-mp[i][j][0]);
            //ans=min(ans,(LL)mp[i][j][5]+mp[i][j][3]+mp[i][j][4]+mp[i][j][6]-(3*mp[i][j][0]));
        }
    }
    printf("%lld",ans);
}
/*
5 5
1 1 1 1 1
5 5 1 5 1
1 1 1 1 1
1 5 1 5 5
1 5 1 1 1
*/
