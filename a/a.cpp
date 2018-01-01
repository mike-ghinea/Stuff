#include<fstream>
#include<cstring>

using namespace std;
ofstream cout("a.out");
int i,j;
int main()
{
char c[21]="tamara",*p;
for(i=0;i<strlen(c);i=i+1)
{ p=strchr(c,'a');
 cout<<p-c;}
}
