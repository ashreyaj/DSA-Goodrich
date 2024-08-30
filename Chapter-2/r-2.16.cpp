#include<iostream>
using namespace std;

string removePunctuations(string &s)
{
    string ss = "";
    string punc = ".,?'";
    for (auto x:s)
    {
        if (punc.find(x) == string::npos) ss += x;
    }
    return ss;
}

int main()
{
    string s = "Let's try, Mike.";
    cout << s << " without punctuations is " << removePunctuations(s) << endl;
    return 0;
}