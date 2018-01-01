#include<fstream>
using namespace std;
ifstream cin("text.in");
ofstream cout("text.out");
unsigned int nrl,nrc,ok;
char k;
int main()
{
    while(cin.get(k))
    {
        if(ok==0&&((k>='a'&&k<='z')||(k>='A'&&k<='Z')))
            ok=1;
        if(ok==1&&((k>='a'&&k<='z')||(k>='A'&&k<='Z')))
            nrl++;
        else if(ok==1)
        nrc++,ok=0;
    }
    cout<<nrl/nrc;
    return 0;
}
