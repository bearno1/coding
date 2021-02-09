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
int n,t,x,ze;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        x=9;
        scanf("%d",&n);
        if(n<=2)
        {
            for(int i=1;i<=n;i++)
            {
                printf("%d",x);
                x--;
                if(x<0)x=9;
            }
        }
        else
        {
            printf("98");
            x=9;
            for(int i=3;i<=n;i++)
            {
                printf("%d",x);
                x++;
                if(x>9)x=0;
            }
        }
        printf("\n");
    }
}
