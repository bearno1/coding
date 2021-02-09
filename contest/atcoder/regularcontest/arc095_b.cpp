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
int n,num[100005],k,cc=MOD,k2,g;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        if(k<num[i])k=num[i],g=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==g)continue;
        if(k%2==0)
        {
            if(abs((k/2)-num[i])<cc)
            {
                cc=abs((k/2)-num[i]);
                k2=num[i];
            }
        }
        else
        {
            if(abs((k/2)-num[i])<cc)
            {
                cc=abs((k/2)-num[i]);
                k2=num[i];
            }
            if(abs(((k+1)/2)-num[i])<cc)
            {
                cc=abs(((k+1)/2)-num[i]);
                k2=num[i];
            }
        }
    }
    printf("%d %d",k,k2);
}
