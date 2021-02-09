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
int t,dp[150005][6][4],ll,na,nb,k;
char c[150005];
int main()
{
    for(int i=0;i<6;i++)dp[0][i][1]=0,dp[0][i][2]=0;
    scanf("%d",&t);
    while(t--)
    {
        k=imx;
        scanf("%s",c+1);
        ll=strlen(c+1);
        for(int i=1;i<=ll;i++)
        {
            for(int j=0;j<6;j++)
            {
                dp[i][j][0]=dp[i-1][j][0]+1;
                dp[i][j][1]=dp[i-1][j][2];
                dp[i][j][2]=dp[i-1][j][2];
                dp[i][j][3]=j;
            }
            if(c[i]=='t')
            {
                for(int j=0;j<6;j++)
                {
                    if(dp[i][1][0]>dp[i-1][j][0])
                    {
                        dp[i][1][0]=dp[i-1][j][0];
                        dp[i][1][1]=dp[i-1][j][2];
                        dp[i][1][2]=i;
                        dp[i][1][3]=j;
                    }
                }
            }
            else if(c[i]=='w')
            {
                if(dp[i][2][0]>dp[i-1][1][0])
                {
                    dp[i][2][0]=dp[i-1][1][0];
                    dp[i][2][1]=dp[i-1][1][2];
                    dp[i][2][2]=i;
                    dp[i][2][3]=1;
                }
            }
            else if(c[i]=='o')
            {
                for(int j=0;j<6;j++)
                {
                    if(j==2)continue;
                    if(dp[i][3][0]>dp[i-1][j][0])
                    {
                        dp[i][3][0]=dp[i-1][j][0];
                        dp[i][3][1]=dp[i-1][j][2];
                        dp[i][3][2]=i;
                        dp[i][3][3]=j;
                    }
                }
            }
            else if(c[i]=='n')
            {
                if(dp[i][2][0]>dp[i-1][3][0])
                {
                    dp[i][4][0]=dp[i-1][3][0];
                    dp[i][4][1]=dp[i-1][3][2];
                    dp[i][4][2]=i;
                    dp[i][4][3]=3;
                }
            }
            else if(c[i]=='e')
            {
                for(int j=0;j<6;j++)
                {
                    if(j==4)continue;
                    if(dp[i][5][0]>dp[i-1][j][0])
                    {
                        dp[i][5][0]=dp[i-1][j][0];
                        dp[i][5][1]=dp[i-1][j][2];
                        dp[i][5][2]=i;
                        dp[i][5][3]=j;
                    }
                }
            }
            else
            {
                for(int j=0;j<6;j++)
                {
                    if(dp[i][0][0]>dp[i-1][j][0])
                    {
                        dp[i][0][0]=dp[i-1][j][0];
                        dp[i][0][1]=dp[i-1][j][2];
                        dp[i][0][2]=i;
                    }
                }
            }
        }
        for(int i=0;i<6;i++)
        {
            if(dp[ll][i][0]<k)
            {
                k=dp[ll][i][0];
                na=ll;
                nb=i;
            }
        }
        printf("%d %d %d\n",k,na,nb);
    }
}
