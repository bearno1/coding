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
int n,m,h,st,ed,mid,ans;
char c[10];
int main()
{
    st=0,ed=1000;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        cout<<"? "<<mid<<" 0"<<endl;
        scanf("%s",c);
        if(c[0]=='Y')n=max(n,mid),st=mid+1;
        else ed=mid-1;
    }
    st=0,ed=1000;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        cout<<"? "<<mid<<" "<<(n*2)<<endl;
        scanf("%s",c);
        if(c[0]=='Y')m=max(m,mid),st=mid+1;
        else ed=mid-1;
    }
    st=0,ed=1000;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        cout<<"? "<<"0 "<<mid<<endl;
        scanf("%s",c);
        if(c[0]=='Y')h=max(h,mid),st=mid+1;
        else ed=mid-1;
    }
    n*=2;
    ans=(n*n)+((h-n)*m);
    cout<<"! "<<ans<<endl;
    //printf("%d %d %d",n,m,h);
}
