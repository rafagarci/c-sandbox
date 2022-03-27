// Compiled with:
// g++-11 -fPIC -shared -o main.so main.cpp
// x86_64 i386

#include <iostream>
#include <string>

using namespace std;

// Check token
bool check(const char *token){
    string token_s = string(token);
    if(token_s.compare("password") == 0)
        return true;
    else
        return false;
}

// Changed signature to make the python
// script find the function name easily
int main(const char *argv){
    if(check(argv))
        cout << "token checked\n";
    else
        cout << "invalid token\n";
    return 0;
}
