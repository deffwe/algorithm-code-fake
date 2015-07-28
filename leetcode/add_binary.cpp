#include <iostream>
#include <string>

using namespace std;

class Solution {
    public: 
    string addBinary(string a, string b) {
        string::size_type aLen = a.size();
        string::size_type bLen = b.size();
        bool carry = false;
        string result;
        while(aLen>0 || bLen>0) {
            int aBit = aLen<=0 ? 0 : a[aLen-1]-'0';
            int bBit = bLen<=0 ? 0 : b[bLen-1]-'0';
            int cBit = carry ? 1 : 0;

            result.insert(result.begin(), ((aBit+bBit+cBit) & 1) + '0');
            carry = (aBit+bBit+cBit)>1;
            if (aLen>0) {
                --aLen;
            }
            if (bLen>0) {
                --bLen;
            }
        }
        
        if(carry) {
            result.insert(result.begin(), '1');
        }

        return result;
    }
};

int tmain(int argc, char** argv) {
    string a="11", b="1";
    if(argc>2) {
        a = argv[1];
        b = argv[2];
    }
    Solution s;
    cout << s.addBinary(a, b) << endl;
    return 0;
}
