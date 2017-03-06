#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fi("text.in");
    ofstream fo("text.out");
    string s;
    int lit=0,cuv=0,i;
    while(getline(fi,s))
    {
        for(i=0;i<=s.size();i++)
        {
            if(isalpha(s[i]) && i==0)
            {
                cuv++;
                lit++;
                continue;
            }
            if(isalpha(s[i]) && !isalpha(s[i-1]))
            {
                cuv++;
                lit++;
            }
            if(isalpha(s[i]) && isalpha(s[i-1]))
                lit++;
        }
    }
    fo<<int(lit/cuv);
}
