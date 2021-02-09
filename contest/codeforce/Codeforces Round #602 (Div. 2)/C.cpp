#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,k,cc;
queue<pair<int,int> >q;
queue<int>dd;
char c[2005],cor[2005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",c+1);
        int d=(k-1)*2,ck=(n/2)-k+1;
        for(int i=1;i<=n;i++)
        {
            if(i<=d)
            {
                if(i%2==1)cor[i]='(';
                else cor[i]=')';
            }
            else if(i<=d+ck)
            {
                cor[i]='(';
            }
            else
            {
                cor[i]=')';
            }
            //printf("%c",cor[i]);
        }
        //printf("\n");
        for(int i=1;i<=n;i++)
        {
            if(c[i]==cor[i])continue;
            else
            {
                //printf("--%d\n",i);
                int r=i+1;
                while(c[r]!=cor[i])r++;
                for(int j=i;j<=r;j++)dd.push(c[j]);
                for(int j=r;j>=i;j--)c[j]=dd.front(),dd.pop();
                q.push({i,r});
                //for(int j=1;j<=n;j++)printf("%c",c[j]);
                //printf("\n");
            }
        }
        printf("%d\n",q.size());
        while(!q.empty())
        {
            printf("%d %d\n",q.front().F,q.front().S);
            q.pop();
        }
    }
}
