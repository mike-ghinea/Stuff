#include<stdio.h>
#include<algorithm>
using namespace std;
FILE *cin=fopen("joker.in","r"), *cout=fopen("joker.out","w");
int n,k,v[50001],v1[60001],i,x,nr=1,j,q,w;
int main()
{
    fscanf(cin,"%d%d",&n,&k);
    for(i=1;i<=k;i++)
    fscanf(cin,"%d",&v[i]);
    sort(v+1,v+k+1);
    for(i=1;i<=k;i++)
    {
        if(v[i]==x+1)
        nr++;
        else if(v[i]!=x+1)
        {
            if(nr>w)
            w=nr;
            nr=1;
        }
        x=v[i];
    }
    if(nr>=w)
    fprintf(cout,"%d",nr);
    else
    fprintf(cout,"%d",w);
    return 0;

}
