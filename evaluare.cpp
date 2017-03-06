#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fi("evaluare.in");
ofstream fo("evaluare.out");
string expresie;
int getExpr(int &ind);
int getTerm(int &ind);
int getFactor(int &ind);
int getNumber(int &ind);

int main()
{
    fi>>expresie;
    int ind = 0;
    fo<<getExpr(ind);
}

int getExpr(int &ind)
{
    int result = getTerm(ind);
    while(expresie[ind]== '+' || expresie[ind] == '-')
    {
        ++ind;
        if(expresie[ind-1] == '+') result += getTerm(ind);
        else result -= getTerm(ind);
    }
    return result;
}

int getTerm(int &ind)
{
    int result = getFactor(ind);
    while(expresie[ind] == '*' || expresie[ind] == '/')
    {
        ++ind;
        if(expresie[ind-1] == '*') result *= getFactor(ind);
        else result /= getFactor(ind);
    }
    return result;
}

int getFactor(int &ind)
{
    if(expresie[ind] != '(') return getNumber(ind);
    else
    {
        ++ind;
        int result = getExpr(ind);
        ++ind;
        return result;
    }
}

int getNumber(int &ind)
{
    int res=0;
    while(isdigit(expresie[ind]))
    {
        res = res*10 + expresie[ind] -'0';
        ++ind;
    }
    return res;
}
