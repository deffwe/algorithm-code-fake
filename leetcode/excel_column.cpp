#include <iostream>
#include <string>
using namespace std;

size_t excelStr2Int(string str) {
    size_t result=0, n=0;

    for(size_t i=0; i<str.size(); ++i) {
        n = str[i] - 'A' + 1;
        result = 26*i + n;
    }
    return result;
}
int main(int argc, char** argv) {
    string s= "AA";
    if(argc>1) {
        s = argv[1];
    }
    cout << excelStr2Int(s) << endl;
    return 0;
}
