#include <iostream>
#include <string>
using namespace std;

string v = "aeiouAEIOU";
int vowels_tot = 0;

int recursive_vowels(string s)
{
    int s_size = s.size();
    int c = 0;
    if (s_size == 0) return c;
    else if (v.find(s[0]) != string::npos) c++;
    s = s.substr(1);
    vowels_tot = c + recursive_vowels(s);
    return vowels_tot;
}

bool vowel_cons(string x)
{
    int vowels = recursive_vowels(x);
    return (x.size()/2) < vowels;
}

int main()
{
    string x = "daaa";
    cout << "Does \"" << x << "\" have more vowels than consonants? " << endl << ((vowel_cons(x)==1)?"Yes":"No") << endl;
    return EXIT_SUCCESS;
}