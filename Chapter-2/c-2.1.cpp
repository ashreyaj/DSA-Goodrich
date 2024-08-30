// This code prints out the code. This is called a "quine".
#include<iostream>
char* s = "// This code prints out the code. This is called a \"quine\".\n#include<iostream>%cchar* s = %c%s%c;%cint main(){printf(s,10,34,s,34,10,10); return 0;}%c";
int main(){printf(s,10,34,s,34,10,10); return 0;}