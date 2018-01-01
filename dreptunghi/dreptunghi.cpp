#include <fstream>
#include <cmath>
using namespace std;
ifstream f("dreptunghi.in");
ofstream g ("dreptunghi.out");
 int x,y,s;
int main()
{f>>x>>y;
while (x!=0&&y!=0){
    if (x<y){
            s=s+x*(y/x);
            y=y%x;}
 else
    {
    s=s+y*(x/y);
    x=x%y;
    }
 }
g<<s;
return 0;
}
