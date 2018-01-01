#include<fstream>
using namespace std;
FILE *cin=fopen("prieten.in","r");
FILE *cout=fopen("prieten.out","w");
int n,i,x,p,k;
unsigned long long S;
int main()
{
    fscanf(cin,"%d%d",&n,&k);
    fscanf(cin,"%u",&S);
    for(i=1;i<=k;i++)
    {
      p=i*n+i;
      fprintf(cout,"%d ",p);
    }
    for(i=1;i<=2*S;i++)
    {
        if(i*i*i-i==2*S)
           {
            fprintf(cout,"\n%d",i);
            break;
           }
    }
    return 0;
}
