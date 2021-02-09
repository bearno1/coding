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
char c[35];
int n,co,coo;
bool p=false,pp=false;
int main()
{
    gets(c+1);
    n=strlen(c+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]<='9'&&c[i]>='0')co++;
        else if(c[i]!='-')p=true;
        if(c[i]=='-')coo++;
    }
    for(int i=1;i<n;i++)
    {
        if(c[i]=='-'&&c[i+1]=='-')pp=true;
    }
    if(co<10)
    {
        printf("Invalid : too short");
        return 0;
    }
    if(co>10)
    {
        printf("Invalid : too many digits");
        return 0;
    }
    if(c[1]!='0'||(!(c[2]=='1'||c[2]=='5'||c[2]=='6'||c[2]=='8'||c[2]=='9')))
    {
        printf("Invalid : wrong prefix");
        return 0;
    }
    if(p)
    {
        printf("Invalid : alphabetic");
        return 0;
    }
    if(pp)
    {
        printf("Invalid : two dashes together");
        return 0;
    }
    if(c[1]=='-'||c[2]=='-'||c[n]=='-')
    {
        printf("Invalid : wrong dash position");
        return 0;
    }
    if(coo>2)
    {
        printf("Invalid : too many dashes");
        return 0;
    }
    printf("Valid");
}
