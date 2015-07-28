#include <iostream>
#include <string>
using namespace std;

string int2str(int n){
    string result = "";
    while(n>0){
        char ch = (n-1)%26 + 'A';
        result.insert(result.begin(), ch);
        n -= (n-1)%26;
        n /= 26;
    } 
    return result;
}
int main(int argc, char** argv) {
    int n = 29;
    if(argc>1) {
        n = atoi(argv[1]);
    }
    cout << int2str(n) << endl;
    return 0;
}
