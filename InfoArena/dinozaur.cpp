#include <iostream>
#include <fstream>
using namespace std;
int vec[30],i;
int main()
{
    ifstream fi("dinozaur.in");
    ofstream fo("dinozaur.out");
    string s;

    fi>>s;
    for(i=0;i<s.size();i++)
    {
        vec[s[i]-96]++;
        if(vec[s[i]-96]>=2)
          {
            fo<<1;
            break;
          }
    }
    if(i>=s.size())
        fo<<0;
}
