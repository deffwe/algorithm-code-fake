#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    string str = "";
    for(size_t i=0; i<s.size(); ++i) {
        if(isdigit(s[i]) || isalpha(s[i])) {
           str.push_back(tolower(s[i])); 
        }
    }            
    if(!str.size()) {
        return true;
    }

    size_t i=0, j=str.size() - 1;

    while(i <= j) {
        if(str[i] != str[j]) {
            return false;
        }
        ++i;
        if(j>0){
            --j;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    string s = "a";
    if(argc>1) {
        s = argv[1];
    }
    cout << isPalindrome(s) << endl;

    return 0;
}
