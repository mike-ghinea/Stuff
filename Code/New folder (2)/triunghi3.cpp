#include<stdio.h>
using namespace std;
FILE*cin=fopen("triunghi3.in","r"),*cout=fopen("triunghi3.out","w");
int n,i,x,sn,sn1,p;
int main()
{
    fscanf(cin,"%d",&n);
    sn=30;
    for(i=6;i<=n;i++)
    {
        p=sn;
        sn=sn1*2+2;
        sn1=p;
    }
   fprintf(cout,"%d",sn%2011);
}

