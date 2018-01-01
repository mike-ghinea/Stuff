#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int B[30000];
unsigned long long sum;
int main()
{
    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    for (int i = 0; i < N; i++) {
        cin>>B[i];
        sum+=B[i];
    }
    if(sum<C)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(B,B+N);
    double x=(double)C/N;
    for(int i=0;i<N;i++)
    {
        if(sum<=C or B[i]<x)
        {
            C-=B[i];
            cout<<B[i]<<"\n";
            sum-=B[i];
            x=(double)C/(N-i-1);
        }
        else
        {
            if(C-((int)x)==1 and i==N-1)
                cout<<(int)x+1<<"\n";
            else
                cout<<(int)x<<"\n";
            C-=(int)x;
            x=(double)C/(N-i-1);
        }
    }
}
