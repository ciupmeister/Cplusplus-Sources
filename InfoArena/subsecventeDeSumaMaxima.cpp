#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("ssm.in");
ofstream fo("ssm.out");

int main()
{
    int n,maxim=-1000000,stanga,dreapta,st=1,sumaCurenta=0,auxCitire;
    fi>>n;
    for(int i=1;i<=n;i++)
    {
        fi>>auxCitire;
        sumaCurenta+=auxCitire;
        if(sumaCurenta>maxim)
        {
            maxim=sumaCurenta;
            dreapta=i;
            stanga=st;
        }
        else if(sumaCurenta==maxim)
            if(dreapta-stanga>i-st)
            {
                dreapta=i;
                stanga=st;
            }
        if(sumaCurenta<0)
        {
            sumaCurenta=0;
            st=i+1;
        }

    }
    fo<<maxim<<" "<<stanga<<" "<<dreapta;
}
