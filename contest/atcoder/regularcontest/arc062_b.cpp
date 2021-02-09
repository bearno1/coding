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
char c[100005];
int sc,pp,n;
int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    for(int i=1;i<=n;i++)
    {
        if(pp==0)
        {
            if(c[i]=='p')sc--;
            pp++;
        }
        else
        {
            if(c[i]=='g')sc++;
            pp--;
        }
        //printf("%d %d %d\n",i,sc,pp);
    }
    printf("%d",sc);
}
