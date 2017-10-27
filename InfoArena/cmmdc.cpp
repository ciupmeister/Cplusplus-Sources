#include <fstream>

using namespace std;
ifstream fi("cmmdc.in");
ofstream fo("cmmdc.out");

int euclid(int a, int b) /// I don't think you need explanations.
{
    int c;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int a,b; ///declaring the two numbers
    fi>>a>>b; ///reading them
    fi.close(); ///closing the input stream
    int k = euclid(a,b); ///determining the result
    if(k == 1) fo<<0; ///checking if it's 1, then we write 0
    else fo<<k; /// else we write the result
    fo.close(); ///we close the output stream

}
