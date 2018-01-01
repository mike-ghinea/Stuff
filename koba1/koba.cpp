#include <fstream>
using namespace std;
ifstream cin("koba.in");
ofstream cout("koba.out");
unsigned long long s,s1,t1,t2,t3,nr,n,a[1000001],v[1001],k,q,i,t,ok;
int main()
{
   cin>>n>>t1>>t2>>t3;
   a[1]=t1;
   a[2]=t2;
   a[3]=t3;
   s=t1%10+t2%10+t3%10;
   for(i=4;i<=n-1;i++)
   {
       a[i]=a[i-1]+a[i-2]*a[i-3];
       s=s+a[i]%10;
   }
   cout<<s;
   return 0;
}

