#include <fstream>

using namespace std;
ifstream fin("paint.in");
ofstream fout("paint.out");
int a,b,c,d;
int main()
{
    fin>>a>>b>>c>>d;
    if(c<a)
    {
        swap(a,c);
        swap(b,d);
    }
    if(c<b)
        fout<<max(d,b)-min(a,c);
    else
        fout<<d-c+b-a;
    return 0;
}
