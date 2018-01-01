#include<fstream>
using namespace std;
FILE *in=fopen("betasah.in","r"),*out=fopen("betasah.out","w");
int n,d,k,Max=-1,s,i,nr,q,w,j,v[1001],pozdama[103][3],l,c,i1,c1;
char a[1003][1003];
int main()
{
    fscanf(in,"%d%d%d",&n,&d,&k);
    for(i=1;i<=n;i++)
        v[i]=i;
    //damele notate cu 1
    for(i=1;i<=d;i++){
        fscanf(in,"%d%d",&j,&s);
        a[j][s]=1;
        pozdama[i][1]=j;pozdama[i][2]=s;
        }
    //spatiile inaccesibile notate cu 2
    for(i=1;i<=k;i++){
        fscanf(in,"%d%d",&j,&s);
        a[j][s]=2;
        v[j]--;
        }
    for(i=1;i<=n;i++)
        if(v[i]>Max)
            Max=v[i];
    fprintf(out,"%d\n",Max);
    for(i=0;i<=n+1;i++)
       a[i][0]=a[i][i+1]=a[i][i+2]=2;
    for(j=0;j<=n+2;j++)
       a[n+1][j]=2;
    nr=0;
    for(i=1;i<=d;i++)
    {
        l=pozdama[i][1]; c=pozdama[i][2];
        j=c-1;
            while(a[l][j]!=2)
            {
               if(a[l][j]==0)a[l][j]=3;
               j--;
            }
            j=c+1;
            while(a[l][j]!=2)
            {
                if(a[l][j]==0)a[l][j]=3;
                j++;
            }
          i1=l-1;
            while(a[i1][c]!=2)
            {
                if(a[i1][c]==0)a[i1][c]=3;
                i1--;
            }
            i1=l+1;
            while(a[i1][c]!=2)
            {
                if(a[i1][c]==0)a[i1][c]=3;
                i1++;
            }
        i1=l-1; j=c-1;
            while (a[i1][j]!=2)
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1--; j--;}
            i1=l+1; j=c+1;
            while (a[i1][j]!=2)
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1++; j++;}
        i1=l-1; j=c+1;
            while (a[i1][j]!=2)
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1--; j++;}
            i1=l+1; j=c-1;
            while (a[i1][j]!=2)
            { if(a[i1][j]!=1) a[i1][j]=3;
              i1++; j--;}
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            if(a[i][j]==3)
                nr++;
    fprintf(out,"%d",nr);
}
