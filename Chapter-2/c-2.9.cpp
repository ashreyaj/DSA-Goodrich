#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

long term_derivative(string term, long val) 
{
    string coeff_str = "";
    int i;
    for (i = 0; term[i] != 'x'; i++)
    {
        coeff_str.push_back(term[i]);
    }
    long coeff = atol(coeff_str.c_str());

    string pow_str = "";
    for (i = i + 2; i != term.size(); i++)
    {
        pow_str.push_back(term[i]);
    }
    long power = atol(pow_str.c_str());

    return coeff * power * pow(val, power - 1);
}

long derivative(string& str, int val) 
{
    long ans = 0;
    istringstream is(str);
    string term;
    while (is >> term) 
    {
        if (term == "+")
            continue;
        else
            ans = (ans + term_derivative(term, val));
    }
    return ans;
}

int main() 
{
    string str = "8x^3 + 9x^2 + 4x^1";
    int val = 2;
    cout << derivative(str, val);
    return 0;
}