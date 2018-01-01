#include<fstream>
using namespace std;
ifstream cin("case1.in");
ofstream cout("case1.out");
int i,n,r1,r2,r3,x,b,f,c;
int main()
{
   cin>>n;
   for(i=1;i<=n;i++)
   {
      cin>>x;
      if(x/1000==1)
        {r1++;r2=r2;r3=r3;}
      else if(x/1000==2)
        {r2++;r1=r1;r3=r3;}
      else if(x/1000==3)
        {r3++;r1=r1;r2=r2;}
      b=b+x/100%10;
      f=f+x/10%10;
      c=c+x%10;
   }
   cout<<r1<<'\n'<<r2<<'\n'<<r3<<'\n'<<b<<'\n'<<f<<'\n'<<c;
   return 0;
}
