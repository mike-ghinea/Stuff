#include<fstream>
using namespace std;
FILE *cin=fopen("miere.in","r"), *cout=fopen("miere.out","w");
long long v[50001],Inceput,Final,mij,n,m,x,i,j,ok;
int main()
{
 	fscanf(cin,"%lld",&n);
 	for(i=1;i<=n;i++)
        {
            fscanf(cin,"%lld",&v[i]);
            v[i]=v[i]+v[i-1];
        }
    fscanf(cin,"%lld",&m);
    for(i=1;i<=m;i++)
    {
        fscanf(cin,"%lld",&x);
        Inceput=1;
        Final=n;
        ok=1;
        while(Inceput<=Final&&ok==1)
        {
            mij=(Final+Inceput)/2;
            if(v[mij]+mij*1ll*(i-1)>x)
                Final=mij-1;
            else if(v[mij+1]+(mij+1)*1ll*(i-1)>x)
            {
                fprintf(cout,"%lld\n",mij);
                ok=0;
            }
            else
            Inceput=mij+1;
        }
        if(ok==1)
        fprintf(cout,"%lld\n",n);
        }
	return 0;
}

