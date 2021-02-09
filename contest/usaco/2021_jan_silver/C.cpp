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
int n,k[1005][1005],dp[1005][2],pl[1005][2],pl1[1005][2],dp1[1005][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&k[i][j]),pl[j][i%2]+=k[i][j],pl1[i][j%2]+=k[i][j];
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+pl[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+pl[i][1];
        dp1[i][0]=max(dp1[i-1][0],dp1[i-1][1])+pl1[i][0];
        dp1[i][1]=max(dp1[i-1][0],dp1[i-1][1])+pl1[i][1];
    }
    printf("%d",max(max(dp[n][0],dp[n][1]),max(dp1[n][0],dp1[n][1])));
}
