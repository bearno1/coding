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
int n,m,ans[100005][2],a,b;
bool dp[100005][30];
char c[100005];
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)c[i]-='A';
    for(int i=0;i<100005;i++)for(int j=0;j<30;j++)dp[i][j]=false;
    for(int i=1;i<=n;i++)
    {
        ans[i][0]=ans[i-1][0];
        for(int j=c[i];j>-1;j--)
        {
            if(dp[i-1][j])
            {
                dp[i][j]=true;
            }
        }
        if(!dp[i][c[i]])
        {
            dp[i][c[i]]=true;
            ans[i][0]++;
        }
    }
    for(int i=0;i<100005;i++)for(int j=0;j<30;j++)dp[i][j]=false;
    for(int i=n;i>0;i--)
    {
        ans[i][1]=ans[i+1][1];
        for(int j=c[i];j>-1;j--)
        {
            if(dp[i+1][j])
            {
                dp[i][j]=true;
            }
        }
        if(!dp[i][c[i]])
        {
            dp[i][c[i]]=true;
            ans[i][1]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",ans[a-1][0]+ans[b+1][1]);
    }
}
