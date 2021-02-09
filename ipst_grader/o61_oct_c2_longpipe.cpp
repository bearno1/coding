#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
long long mat[3][3],a[3][3],b[3][3],fir[3][3],ans,ss,sec[3][3];
int n;
using namespace std;
void MUL(int k)
{
   if(k==1)
   {
      for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
            a[i][j]=fir[i][j];
   }
   else
   {
      MUL(k/2);
      for(int i=0;i<3;i++)
      {
         for(int j=0;j<3;j++)
         {
            long long re=0;
            for(int pp=0;pp<3;pp++)
            {
               re+=a[i][pp]*a[pp][j];
            }
            mat[i][j]=re%MOD;
         }
      }
      for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
            a[i][j]=mat[i][j];
      if(k%2==1)
      {
         for(int i=0;i<3;i++)
         {
            for(int j=0;j<3;j++)
            {
               long long re=0;
               for(int pp=0;pp<3;pp++)
               {
                  re+=a[i][pp]*fir[pp][j];
               }
               mat[i][j]=re%MOD;
            }
         }
         for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
               a[i][j]=mat[i][j];
      }
      a[0][2]+=k-1;
      a[2][0]+=k-1;
   }
   printf("===%d\n",k);
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
            printf("%d ",a[i][j]);
      }
      printf("\n");
   }
   return;
}
int main()
{
   fir[0][0]=1;
   fir[0][1]=1;
   fir[0][2]=0;
   fir[1][0]=1;
   fir[1][1]=1;
   fir[1][2]=1;
   fir[2][0]=0;
   fir[2][1]=1;
   fir[2][2]=1;
   sec[0][0]=1;
   sec[0][1]=0;
   sec[0][2]=0;
   sec[1][0]=0;
   sec[1][1]=0;
   sec[1][2]=0;
   sec[2][0]=0;
   sec[2][1]=0;
   sec[2][2]=1;
   scanf("%d",&n);
   MUL(n);
   for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
         ans+=a[i][j];
   printf("%lld",ans%MOD);
}
