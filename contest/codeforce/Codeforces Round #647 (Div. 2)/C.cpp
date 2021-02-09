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
unsigned long long n,ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%llu",&n);
        while(n>0)
        {
            ans+=n;
            n/=2;
        }
        printf("%llu\n",ans);
    }
}
// int n,k[105][10],ans,r,cc,p;
// int main()
// {
//     for(int i=1;i<=100;i++)
//     {
//         cc=i;
//         r=0;
//         p=0;
//         while(cc>0)
//         {
//             k[i][r]=cc%2;
//             r++;
//             cc/=2;
//         }
//         for(int j=0;j<10;j++)
//         {
//             if(k[i][j]!=k[i-1][j])p++;
//         }
//         ans+=p;
//         printf("%d %d %d\n",ans,p,i);
//     }
// }
