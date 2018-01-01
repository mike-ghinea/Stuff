#include<iostream>
using namespace std;
bool stop;
unsigned int g1,g2,g3,l,c,d;
void f(unsigned short l, unsigned short c, unsigned short d)
{
    static bool m[6][6];
    //validate
    if(d==0&&l==0||d==1&&c==5||d==2&&l==5||d==3&&c==0||m[l][c]){cout<<"Jucatorul "<<(g1%2?"B":"A")<<" mutare invalida";return;}
    //execute

}
int main()
{
    while(!stop)
    {
        cin>>l>>c>>d;
        f(l,c,d);
    }
    return 0;
}
