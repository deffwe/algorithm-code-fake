#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX_LEN = 10;

vector<string> findRepeatedDnaSequenes(string s) {
    unordered_map<size_t, int> stat;
    hash<string> hash_func;

    vector<string> result;
    for(size_t i=0; i+MAX_LEN<=s.size(); ++i) {
        string word = s.substr(i, MAX_LEN);
        size_t hash_code = hash_func(word);
        stat[hash_code]++;
        if(stat[hash_code] == 2) {
            result.push_back(word);
        }
    } 
    return result;
}
void printVector(vector<string> v) {
    cout << "[";
    for(size_t i=0; i<v.size(); ++i) {
        cout << v[i] << (i<v.size()-1 ? ", " : "");
    }
    cout << "]" << endl;
}

int tmain() {
    string s =  "AAAAAAAAAAA";
    printVector(findRepeatedDnaSequenes(s));
    return 0;
}
