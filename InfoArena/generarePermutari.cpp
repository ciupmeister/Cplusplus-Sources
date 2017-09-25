#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("permutari.in");
ofstream fo("permutari.out");
bool used[10];
int arr[10],p,n;
void permutation(int p)
{
    if(p==n+1)
    {
        for(int i=1;i<=n; ++i)
            fo<<arr[i]<< " ";
        fo<<"\n";
    }
    else
    {
        for(int i=1; i<=n; ++i)
        {
            if(!used[i])
            {
                used[i]=1;
                arr[p] = i;
                permutation(p+1);
                used[i] = 0;
            }
        }
    }

}

int main()
{
    fi>>n;
    permutation(1);
}
