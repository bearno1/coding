#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,a,b,c,t,ww;
char cc[105],pp[105];
bitset<105>ss;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      ww=0;
      for(int i=0;i<105;i++)ss[i]=false;
      scanf("%d %d %d %d",&n,&a,&b,&c);
      scanf("%s",cc);
      for(int i=0;i<n;i++)
      {
         if(cc[i]=='R')
         {
            if(b>0)
            {
               pp[i]='P';
               ww++;
               ss[i]=true;
               b--;
            }
         }
         else if(cc[i]=='P')
         {
            if(c>0)
            {
               pp[i]='S';
               ww++;
               ss[i]=true;
               c--;
            }
         }
         else
         {
            if(a>0)
            {
               pp[i]='R';
               ww++;
               ss[i]=true;
               a--;
            }
         }
      }
      for(int i=0;i<n;i++)
      {
         if(!ss[i])
         {
            if(a>0)
            {
               pp[i]='R';
               a--;
            }
            else if(b>0)
            {
               pp[i]='P';
               b--;
            }
            else
            {
               pp[i]='S';
               c--;
            }
         }
      }
      if(ww>=(n+1)/2)
      {
         printf("YES\n");
         for(int i=0;i<n;i++)printf("%c",pp[i]);
         printf("\n");
      }
      else
      {
         printf("NO\n");
      }
   }
}
