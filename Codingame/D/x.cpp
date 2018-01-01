#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
ifstream cin("x.in");
ofstream cout("x.out");
int i,j,x,y;
char matrix[41][41];
char c;
int main()
{
    int width;
    cin >> width;
    int height;
    cin >> height;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
        {
            cin>>matrix[i][j];
        }
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
        {
            if(matrix[i][j]=='0')
            {
                cout<<j<<" "<<i<<" ";
                int ok=0;
                for(x=j+1;x<width;x++)
                    if(matrix[i][x]=='0'){
                        break;
                    }
                        cout<<x<<" "<<i<<" ",ok=1;¦¦
                if(ok==0)
                    cout<<"-1 -1 ";
                ok=0;
                for(x=i+1;x<width;x++)
                    if(matrix[x][j]=='0'){
                        cout<<j<<" "<<x<<"\n",ok=1;
                        break;
                    }
                if(ok==0)
                    cout<<"-1 -1\n";
                ok=0;
            }
        }
}
