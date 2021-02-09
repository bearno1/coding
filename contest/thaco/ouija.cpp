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
int n,m;
LL k[100005][205],ans[100005][205];
int main()
{
    scanf("%d %d",&n,&m);
    k[0][1]=1;
    ans[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            k[i][j]=k[i-1][j]+k[i][j-1];
            k[i][j]%=MOD;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            k[i][j]=k[i][j-1]+k[i][j];
            k[i][j]%=MOD;
            printf("%lld ",k[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=m;i++)ans[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans[i][j]=(ans[i-1][j]*k[i-1][j-1])+ans[i][j-1];
            ans[i][j]%=MOD;
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }
    printf("%lld",ans[n][m]);
}
