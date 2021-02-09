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
char cc[105];
int len,ans,d1,d2;
bool del;
int main()
{
    cc[0]='1';
    scanf("%d",&len);
    scanf("%s",cc+1);
    while(1)
    {
        d1=-1,d2=0;
        for(int i=1;i<=len;i++)
        {
            if((cc[i]==cc[i-1]+1)||(cc[i]==cc[i+1]+1))
            {
                if(cc[i]>d1)
                {
                    d1=cc[i];
                    d2=i;
                }
            }
        }
        if(d1==-1)break;
        for(int i=d2;i<=len;i++)
        {
            cc[i]=cc[i+1];
        }
        ans++;
        len--;
    }
    printf("%d",ans);
}
