#include<fstream>
FILE *cin=fopen("highcard.in","r");
FILE *cout=fopen("highcard.out","w");
int N,i,x,points,j;
bool v[2*50001],b[2*50001];
int main()
{
    fscanf(cin,"%d",&N);
    for(i=1;i<=N;i++)
    {
        fscanf(cin,"%d",&x);
        v[x]=1;
        b[x]=1;
    }
    for(i=1;i<=2*N;i++)
    {
        if(v[i]==1 and b[i]==1)
        {
            for(j=i;j<=2*N;j++)
                if(v[j]==0)
                {
                    v[j]=1;
                    points++;
                    break;
                }
        }
    }
    fprintf(cout,"%d",points);
}

