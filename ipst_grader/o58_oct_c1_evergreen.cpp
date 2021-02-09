#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
long long k,day[1000005],pl,grass[1000005],ans=LLONG_MAX,num[1000005],n,x,las1,las2,L;
vector<long long>v;
priority_queue<pair<long long,long long> >pq;
int main()
{
   scanf("%lld %lld",&n,&k);
   for(int i=1;i<=n;i++)
   {
      scanf("%lld",&x);
      v.push_back(x);
   }
   sort(v.begin(),v.end());
   day[0]=n;
   num[0]=n;
   grass[0]=n;
   for(int i=1;i<n;i++)
   {
      if(v[i]==v[i-1])
      {
         //printf("00000\n");
         grass[0]--;
         day[0]--;
      }
      //printf("+++%d\n",(-(v[i]-v[i-1]-1)));
      if((v[i]-v[i-1]-1)%2==0)pq.push({-((v[i]-v[i-1]+1)/2),0});
      else pq.push({-((v[i]-v[i-1])/2),1});
   }
   //k=((long long)100000020*(long long)100000020);
   if(!pq.empty())
   {
      while(-pq.top().F<=0)
      {
         num[0]--;
         pq.pop();
         if(pq.empty())break;
      }
   }
   //printf("%lld %lld %lld\n",day[0],grass[0],num[0]);
   //printf("%lld\n",ans);
   if(n>=k)
   {
      printf("0");
      return 0;
   }
   //printf("\\\\");
   for(int i=1;i<=1000000;i++)
   {
      int cc=0;
      num[i]=num[i-1];
      if(!pq.empty())
      {
         while(-pq.top().F<=i)
         {
            cc+=pq.top().S;
            num[i]--;
            pq.pop();
            if(pq.empty())break;
         }
      }
      grass[i]=grass[i-1]+(num[i]*2)+cc;
      day[i]=day[i-1]+grass[i];
      //if(i<=30)printf("%lld %lld %d %d\n",day[i],grass[i],num[i],cc);
      if(day[i]>=k)ans=min(ans,(long long)i);
      if(num[i]==1)
      {
         L=i;
         break;
      }
   }
   //printf("%lld %lld %lld\n",grass[L],day[L],num[L]);
   if(ans!=LLONG_MAX)
   {
      printf("%lld",ans);
      return 0;
   }
   else
   {
      long long st=L+1,ed=316227780,mid;
      while(st<=ed)
      {
         mid=(st+ed)/2;
         long long temp=mid-L;
         //printf("%lld %lld\n",mid,(day[L]+(grass[L]*temp)+(temp*(2+temp-1))));
         if(day[L]+(temp*(2+temp-1+grass[L]))>=k)
         {
            ans=min(ans,mid);
            ed=mid-1;
         }
         else
         {
            st=mid+1;
         }
      }
   }
   printf("%lld",ans);
}
/*
4 111400000000000
10 1 500000 1000000
---316227766
10554618
*/
