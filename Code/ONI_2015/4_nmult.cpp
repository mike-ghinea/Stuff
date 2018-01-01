// sursa cu formula de recurenta + combinari recursiv
// prof. Chesca Ciprian

#include <fstream>
#include <math.h>

#define M 666013


using namespace std;

int n,k,w;
ifstream f("nmult.in");
ofstream g("nmult.out");


long long comb(int n, int k)
{
    if (k==0) return 1;
         else return (n*comb(n-1,k-1)/k)%M;

}



int nmult(int k, int n, int w)
{
    if (n<k) return 0;
        else
            if (w==1)
                    {
                    return comb(n,k);
                    }
                 else return nmult(k,n-k+1,w-1);
}


int main()
{

    f>>n>>k>>w;

    g<<nmult(k,n,w);

    f.close();
    g.close();

    return 0;
}


