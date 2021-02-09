#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int c1=0,c2=INT_MAX;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            c1=max(x,c1);
            c2=min(y,c2);
        }
        printf("%d\n",max(c1-c2,0));
    }
}
