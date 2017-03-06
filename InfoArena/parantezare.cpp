#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
ifstream fi("parantezare.in");
ofstream fo("parantezare.out");



int main()
{
    stack<int> stiva;
    int vect[100000];
    int n,a;
    string ecuatie;
    getline(fi,ecuatie);
    fi>>n;
    for(int i=0;i<ecuatie.size();i++)
    {
        if(ecuatie[i]=='(')
        {
            stiva.push(i);
        }
        if(ecuatie[i]==')')
        {
            vect[stiva.top()]=i;
            stiva.pop();
        }
    }

    for(int i=1;i<=n;i++)
    {
        fi>>a;
        fo<<vect[a]<<" ";
    }
}
