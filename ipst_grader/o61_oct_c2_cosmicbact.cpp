#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define X(i) pos[i].F
#define Y(i) pos[i].S.F
#define Bac(i) pos[i].S.S
const long long MX ((long long)((1e18)*4));
using namespace std;
int n,cc,k,kc;
long long mn1[100005][2],mn2[100005][2],L,p[100005],las,st,ed,mid,a,b,ans;
vector<pair<long long,pair<long long,int> > >pos;
int main()
{
   scanf("%d %lld",&n,&L);
   mn2[0][0]=MX;
   mn1[n+1][0]=MX;
   pos.push_back({-1,{-1,-1}});
   for(int i=1;i<=n;i++)
   {
      scanf("%lld %lld",&a,&b);
      pos.push_back({a,{b,i}});
   }
   pos.push_back({MX,{MX,MX}});
   sort(pos.begin(),pos.end());
   for(int i=n;i>0;i--)
   {
      if(mn1[i+1][0]>Y(i)+X(i)+Bac(i))
      {
         mn1[i][0]=Y(i)+X(i)+Bac(i);
         mn1[i][1]=Bac(i);
      }
      else if(mn1[i+1][0]==Y(i)+X(i)+Bac(i))
      {
         mn1[i][0]=Y(i)+X(i)+Bac(i);
         mn1[i][1]=min((long long)Bac(i),mn1[i+1][1]);
      }
      else
      {
         mn1[i][0]=mn1[i+1][0];
         mn1[i][1]=mn1[i+1][1];
      }
      //printf("\\%lld %lld %d\n",mn1[i][1],mn1[i][0],i);
   }
   for(int i=1;i<=n;i++)
   {
      if(mn2[i-1][0]>Y(i)-X(i)+Bac(i))
      {
         mn2[i][0]=Y(i)-X(i)+Bac(i);
         mn2[i][1]=Bac(i);
      }
      else if(mn2[i-1][0]==Y(i)-X(i)+Bac(i))
      {
         mn2[i][0]=Y(i)-X(i)+Bac(i);
         mn2[i][1]=min((long long)Bac(i),mn2[i-1][1]);
      }
      else
      {
         mn2[i][0]=mn2[i-1][0];
         mn2[i][1]=mn2[i-1][1];
      }
      //printf("//%lld %lld %d\n",mn2[i][1],mn2[i][0],i);
   }
   /*cc=1;
   for(int i=0;i<=L;i++)
   {
      while(X(cc)<i)
      {
         cc++;
      }
      if(mn2[cc-1][0]+i<mn1[cc][0]-i)k=mn2[cc-1][1];
      else if(mn2[cc-1][0]+i==mn1[cc][0]-i)k=min(mn2[cc-1][1],mn1[cc][1]);
      else k=mn1[cc][1];
      //printf("|%d %d|\n",k,cc);
   }*/
   las=0;
   cc=1;
   while(las<=L)
   {
      while(X(cc)<las)
      {
         cc++;
      }
      if(mn2[cc-1][0]+las<mn1[cc][0]-las)k=mn2[cc-1][1];
      else if(mn2[cc-1][0]+las==mn1[cc][0]-las)k=min(mn2[cc-1][1],mn1[cc][1]);
      else k=mn1[cc][1];
      //printf("--%d\n",k);
      st=las,ed=L,ans=las;
      while(st<=ed)
      {
         mid=(st+ed)/2;
         int l=cc,r=n+1,mm,CC=cc;
         while(l<=r)
         {
            mm=(l+r)/2;
            if(X(mm)<mid)
            {
               l=mm+1;
            }
            else
            {
               CC=max(CC,mm);
               r=mm-1;
            }
            //printf("[[[]]]%lld %d %lld\n",X(mm),mm,mid);
         }
         //printf(">>%d %lld\n",CC,mid);
         if(mn2[CC-1][0]+mid<mn1[CC][0]-mid)kc=mn2[CC-1][1];
         else if(mn2[CC-1][0]+mid==mn1[CC][0]-mid)kc=min(mn2[CC-1][1],mn1[CC][1]);
         else kc=mn1[CC][1];
         if(k==kc)
         {
            //printf("-------------%d %d\n",k,kc);
            ans=max(ans,mid);
            st=mid+1;
         }
         else
         {
            ed=mid-1;
         }
         //printf("_{%lld %d %d %d}\n",mid,k,kc,CC);
      }
      p[k]+=ans-las+1;
      //printf("===%lld %lld %d\n",ans,las,k);
      las=ans+1;
   }
   for(int i=1;i<=n;i++)
   {
      printf("%lld\n",p[i]);
   }
}
/*
3 1000000
4 0
7 0
5 0
*/
