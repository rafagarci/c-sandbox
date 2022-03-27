// Compiled with:
// g++-11 -fPIC -shared -o main.so main.cpp
// x86_64 i386

#include <iostream>
#include <string>

using namespace std;

bool check(const char *token){
    string token_s = string(token);
    if(token_s.compare("password") == 0)
        return true;
    else
        return false;
}

int main(const int argc, const char *argv[]){

    if(check(argv[0]))
        cout << "token checked\n";
    else
        cout << "invalid token\n";

    if(check(argv[1]))
        cout << "token checked\n";
    else
        cout << "invalid token\n";

    return 0;
}
