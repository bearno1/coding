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
int t,n,cou,cc,r;
vector<LL>v;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cc=0;
            for(int p=1;p<=i;p++)
            {
                cc*=10;
                cc+=j;
            }
            v.push_back(cc);
        }
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        r=0;
        while(r++)
        {
            if(v[r]>n)break;
        }
        printf("%d\n",r);
    }
}
