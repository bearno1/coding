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
int t;
unsigned long long a,b,op;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        op=0;
        scanf("%llu %llu",&a,&b);
        if(a==b)printf("0\n");
        else if(a>b)
        {
            while(1)
            {
                op++;
                if(a%8==0&&a/8>=b)
                {
                    a=a/8;
                }
                else if(a%4==0&&a/4>=b)
                {
                    a=a/4;
                }
                else if(a%2==0&&a/2>=b)
                {
                    a=a/2;
                }
                else
                {
                    printf("-1\n");
                    break;
                }
                if(a==b)
                {
                    printf("%llu\n",op);
                    break;
                }
                if(a<b)
                {
                    printf("-1\n",op);
                    break;
                }
            }
        }
        else
        {
            while(1)
            {
                op++;
                if(a*8<=b)
                {
                    a=a*8;
                }
                else if(a*4<=b)
                {
                    a=a*4;
                }
                else if(a*2<=b)
                {
                    a=a*2;
                }
                else
                {
                    printf("-1\n");
                    break;
                }
                if(a==b)
                {
                    printf("%llu\n",op);
                    break;
                }
                if(a>b)
                {
                    printf("-1\n",op);
                    break;
                }
            }
        }
    }
}
