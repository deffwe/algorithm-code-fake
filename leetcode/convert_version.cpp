#include <iostream>
#include <string>
#include <vector>
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
    while(i<vec1.size() && j<vec2.size()) {
    	if(vec1[i] < vec2[i]) {
    		return -1;
    	} else if(vec1[i] > vec2[i]) {
    		return 1;
    	}

    	++;
    }

    if(i < vec1.size() && i >= vec2.size()) {
    	return 1;
    } else if(i >= vec1.size() && i < vec2.size()) {
    	return -1;
    } 
    
    return 0;
}