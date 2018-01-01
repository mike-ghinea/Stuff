#include<fstream>
using namespace std;
ifstream cin("tabela.in");
ofstream cout("tabela.out");
int l,c;
int main()
{
    cin>>l>>c;
    cout<<((l-1) xor (c-1));
    return 0;
}
