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
int t,n,x;
char c[205];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        for(int i=1;i<=150;i++)c[i]='a';
        c[151]='\0';
        scanf("%d",&n);
        printf("%s\n",c+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(c[x+1]!='b')c[x+1]='b';
            else c[x+1]='a';
            printf("%s\n",c+1);
        }
    }
}
