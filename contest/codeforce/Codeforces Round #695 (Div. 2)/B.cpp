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
int t,n,num[300005],k,mx,tp,cc,tp1,tp2;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        k=0,mx=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i=2;i<n;i++)
        {
            if(num[i]>num[i-1]&&num[i]>num[i+1])k++;
            if(num[i]<num[i-1]&&num[i]<num[i+1])k++;
        }
        for(int i=2;i<n;i++)
        {
            tp=0,tp1=0,tp2=0;
            cc=num[i];
            if(num[i]>num[i-1]&&num[i]>num[i+1])tp++;
            if(num[i]<num[i-1]&&num[i]<num[i+1])tp++;
            if(i!=2)
            {
                if(num[i-1]>num[i-2]&&num[i-1]>num[i])tp++;
                if(num[i-1]<num[i-2]&&num[i-1]<num[i])tp++;
            }
            if(i!=n-1)
            {
                if(num[i+1]>num[i+2]&&num[i+1]>num[i])tp++;
                if(num[i+1]<num[i+2]&&num[i+1]<num[i])tp++;
            }
            num[i]=num[i-1];
            if(num[i]>num[i-1]&&num[i]>num[i+1])tp1++;
            if(num[i]<num[i-1]&&num[i]<num[i+1])tp1++;
            if(i!=2)
            {
                if(num[i-1]>num[i-2]&&num[i-1]>num[i])tp1++;
                if(num[i-1]<num[i-2]&&num[i-1]<num[i])tp1++;
            }
            if(i!=n-1)
            {
                if(num[i+1]>num[i+2]&&num[i+1]>num[i])tp1++;
                if(num[i+1]<num[i+2]&&num[i+1]<num[i])tp1++;
            }
            num[i]=num[i+1];
            if(num[i]>num[i-1]&&num[i]>num[i+1])tp2++;
            if(num[i]<num[i-1]&&num[i]<num[i+1])tp2++;
            if(i!=2)
            {
                if(num[i-1]>num[i-2]&&num[i-1]>num[i])tp2++;
                if(num[i-1]<num[i-2]&&num[i-1]<num[i])tp2++;
            }
            if(i!=n-1)
            {
                if(num[i+1]>num[i+2]&&num[i+1]>num[i])tp2++;
                if(num[i+1]<num[i+2]&&num[i+1]<num[i])tp2++;
            }
            mx=max(tp-tp1,mx);
            mx=max(tp-tp2,mx);
            num[i]=cc;
        }
        printf("%d\n",k-mx);
    }
}
