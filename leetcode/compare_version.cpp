#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void split(const string &s, char delimeter, vector<int> &elems) {
	stringstream ss(s);
	string str;

	while(getline(ss, str, delimeter)) {
		elems.push_back(atoi(str.c_str()));
	}
}

void rightTrimZero(vector<int> &vec) {
	while(vec.back() == 0) {
		vec.pop_back();
	}
}

int compareVersion(string version1, string version2) {
    vector<int> vec1, vec2;
    split(version1, '.', vec1);
    split(version2, '.', vec2);

    rightTrimZero(vec1);
    rightTrimZero(vec2);

    size_t i=0;
    while(i<vec1.size() && i<vec2.size()) {
    	if(vec1[i] < vec2[i]) {
    		return -1;
    	} else if(vec1[i] > vec2[i]) {
    		return 1;
    	}

    	++i;
    }

    if(i < vec1.size() && i >= vec2.size()) {
    	return 1;
    } else if(i >= vec1.size() && i < vec2.size()) {
    	return -1;
    } 
    
    return 0;
}
int main(int argc, char** argv) {
    string ver1="1.1", ver2="1.3";
    if(argc>2){
        ver1 = argv[1];
        ver2 = argv[2];
    } 
    cout << compareVersion(ver1, ver2) << endl;
    return 0;
}
