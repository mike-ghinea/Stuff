#include <fstream>
using namespace std;
ifstream fin ("litere.in");
ofstream fout("litere.out");
int n,i,j,nr,fr[27];
char s[10003];
int main()
{
    fin>>n;
    fin>>(s+1);
    for(i=1;i<=n;i++)
    {
        fr[s[i]-'a']++;
        for(j=s[i]-'a'+1;j<='z'-'a';j++)
        {
            nr+=fr[j];
        }
    }
    fout<<nr;
    return 0;
}
