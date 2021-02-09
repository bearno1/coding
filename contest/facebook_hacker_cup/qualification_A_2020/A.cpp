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
int t,n;
char c[55][55],I[105],O[105];
int main()
{
    freopen("inA.txt","r",stdin);
    freopen("outA.txt","w",stdout);
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        scanf("%s",I+1);
        scanf("%s",O+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)c[i][j]='Y';
                else if(abs(i-j)==1&&(I[j]=='Y'&&O[i]=='Y'))c[i][j]='Y';
                else c[i][j]='N';
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(c[i][k]=='Y'&&c[k][j]=='Y')c[i][j]='Y';
                }
            }
        }
        printf("Case #%d:\n",tt);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("%c",c[i][j]);
            printf("\n");
        }
    }
}
