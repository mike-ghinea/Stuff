#include<stdio.h>
using namespace std;
FILE *cin=fopen("culori3.in","r");
FILE *cout=fopen("culori3.out","w");
short int k[1501],a1[2][1501],a2[2][1501],a3[2][1501],a4[2][1501],a5[2][1501],s[1501],ss[1501],sss[1501],a[1501];
int n,i;
void suma(short int a[],short int b[],short int c[])
    {
        int i, t=0;
        for(i=1;i<=b[0]||i<=a[0];i++)
            {
                t=b[i]+a[i]+t;
                c[i]=t%10;
                t=t/10;
            }
        c[0]=i-1;
        if(t>0)
            {
                c[i]=t;
                c[0]++;
            }
    }
int main()
{
    fscanf(cin,"%d",&n);
    a1[0][0]=a2[0][0]=a3[0][0]=a4[0][0]=a5[0][0]=1;
    a1[1][0]=a2[1][0]=a3[1][0]=a4[1][0]=a5[1][0]=1;
    a1[0][1]=a2[0][1]=a3[0][1]=a4[0][1]=a5[0][1]=1;
    a1[1][1]=a2[1][1]=a3[1][1]=a4[1][1]=a5[1][1]=1;
    for(i=2;i<=n;i++)
    {
        suma(k,a2[1-i%2],a1[i%2]);
        suma(a1[1-i%2],a3[1-i%2],a2[i%2]);
        suma(a2[1-i%2],a4[1-i%2],a3[i%2]);
        suma(a3[1-i%2],a5[1-i%2],a4[i%2]);
        suma(k,a4[1-i%2],a5[i%2]);
    }
    suma(a1[n%2],a2[n%2],s);
    suma(a3[n%2],a4[n%2],ss);
    suma(s,ss,sss);
    suma(sss,a5[n%2],a);
    for(i=a[0];i>=1;i--)
        fprintf(cout,"%d",a[i]);
}
