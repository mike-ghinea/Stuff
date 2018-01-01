#include <fstream>
using namespace std;
/*ifstream f ("miere.in");
ofstream g ("miere.out");*/
FILE *cin=fopen("miere.in","r"), *cout=fopen("miere.out","w");
int n,m,x,st,dr,v[50001],mij,i,j,ok;
int main()
{
    fscanf(cin,"%d",&n);
    for(i=1;i<=n;i++){
        //f>>v[i];
        fscanf(cin,"%d",&v[i]);
        v[i]=v[i]+v[i-1];
    }
//f>>m;
fscanf(cin,"%d",&m);
for(i=1;i<=m;i++){
        //f>>x;
        fscanf(cin,"%d",&x);
        st=1;
        dr=n;
        ok=1;
        while(st<=dr&&ok==1)
        {
            mij=(dr+st)/2;
            if(v[mij]+mij*(i-1)>x)
                dr=mij-1;
            else if(v[mij+1]+(mij+1)*(i-1)>x)
            {
                fprintf(cout,"%d\n",mij);
                ok=0;
            }
            else
            st=mij+1;
        }
        if(ok==1)
        fprintf(cout,"%d\n",n);
        }
    return 0;
}
