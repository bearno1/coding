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
int a,b,c,n,x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x%4==0)a++;
        else if(x%2==0)b++;
        else c++;
    }
    if(c==0)printf("Yes");
    else if(b==0)
    {
        c-=a;
        if(c>1)printf("No");
        else printf("Yes");
    }
    else if(a==0)
    {
        if(c!=0)printf("No");
        else printf("Yes");
    }
    else
    {
        c-=a;
        if(c==0)printf("Yes");
        else
        {
            if(b==0)printf("Yes");
            else printf("No");
        }
    }
}
