#include<fstream>
using namespace std;
ifstream cin("spion.in");
ofstream cout("spion.out");
char c;
int p,nr,knr;
int main()
{
  cin>>p;
  while(cin>>c)
  {
      if(c=='E')
        nr++;
      knr++;
  }
  if(p==1)
    cout<<nr+1;
  if(p==2)
    cout<<combinari(nr,knr);
  return 0;
}
