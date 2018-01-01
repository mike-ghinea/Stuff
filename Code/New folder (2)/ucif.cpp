#include<fstream>
using namespace std;
FILE *cin=fopen("ucif.in","r"), *cout=fopen("ucif.out","w");
int n,i,j,m,x=1,s;
int main()
{
 	fscanf(cin,"%d",&n);
 	s=0;
 	for(i=1;i<=n;i++)
    {
        x=1;
        for(j=1;j<=i;j++)
        x=x*i%10;
        s=(s+x)%10;
    }
    fprintf(cout,"%d",s);
	return 0;
}
