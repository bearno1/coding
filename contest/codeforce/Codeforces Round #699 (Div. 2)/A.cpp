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
int n,t,a,b,c,d,x,y,k;
char cc[100005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        a=0,b=0,c=0,d=0;
        scanf("%d %d",&x,&y);
        scanf("%s",cc+1);
        k=strlen(cc+1);
        for(int i=1;i<=k;i++)
        {
            if(cc[i]=='U')a++;
            if(cc[i]=='D')b--;
            if(cc[i]=='R')c++;
            if(cc[i]=='L')d--;
        }
        if(y<=a&&y>=b&&x<=c&&x>=d)printf("YES\n");
        else printf("NO\n");
    }
}
