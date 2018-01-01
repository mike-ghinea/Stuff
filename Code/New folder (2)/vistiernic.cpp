#include<stdio.h>
using namespace std;
FILE*cin=fopen("vistiernic.in","r"),*cout=fopen("vistiernic.out","w");
int n,i,x,nr1,nr2;
int main()
{
    fscanf(cin,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(cin,"%d",&x);
        while(x%2==0&&x!=0)
        {
            x=x/2;
            nr1++;
        }
        while(x%5==0&&x!=0)
        {
            x=x/5;
            nr2++;
        }
    }
    if(nr1<nr2)
    fprintf(cout,"%d",nr1);
    else
    fprintf(cout,"%d",nr2);
}
