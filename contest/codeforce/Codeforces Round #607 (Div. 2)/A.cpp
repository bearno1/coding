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
int t,ll;
char c[10005];
int main()
{
    inI(t);
    while(t--)
    {
        scanf("%s",c+1);
        ll=strlen(c+1);
        if(c[ll]=='o')printf("FILIPINO\n");
        else if(c[ll]=='u')printf("JAPANESE\n");
        else printf("KOREAN\n");
    }
}
