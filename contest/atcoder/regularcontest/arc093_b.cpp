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
char c[105][105];
bool p=false,ll=false;
int a,b,aa,bb,mid,k,ri=2,rj=2;
int main()
{
    scanf("%d %d",&a,&b);
    if(b==1&&a!=1)ll=true;
    for(int i=1;i<=99;i++)
    {
        for(int j=1;j<=99;j++)
        {
            c[i][j]='.';
        }
    }
    a--;
    b--;
    k=3;
    while(b--)
    {
        c[ri][rj]='#';
        rj+=k;
        if(rj>99)rj=98,ri+=3,k*=-1;
        if(rj<1)rj=2,ri+=3,k*=-1;
    }
    if(a==0)c[99][99]='#',p=true;
    while(a--)
    {
        c[ri+1][rj+1]='#';
        c[ri+1][rj-1]='#';
        c[ri-1][rj+1]='#';
        c[ri-1][rj-1]='#';
        c[ri+1][rj]='#';
        c[ri-1][rj]='#';
        c[ri][rj-1]='#';
        c[ri][rj+1]='#';
        rj+=k;
        if(rj>99)rj=98,ri+=3,k*=-1;
        if(rj<1)rj=2,ri+=3,k*=-1;
    }
    if(!p)
    {
        while(1)
        {
            c[ri+1][rj+1]='#';
            c[ri+1][rj-1]='#';
            c[ri-1][rj+1]='#';
            c[ri-1][rj-1]='#';
            c[ri+1][rj]='#';
            c[ri-1][rj]='#';
            c[ri][rj-1]='#';
            c[ri][rj+1]='#';
            c[ri][rj]='#';
            if(ri==98&&rj==98)break;
            rj+=k;
            if(rj>99)rj=98,ri+=3,k*=-1;
            if(rj<1)rj=2,ri+=3,k*=-1;
        }
    }
    if(ll)c[99][99]='.';
    printf("99 99\n");
    for(int i=1;i<=99;i++)
    {
        for(int j=1;j<=99;j++)
        {
            printf("%c",c[i][j]);
        }
        printf("\n");
    }
}
