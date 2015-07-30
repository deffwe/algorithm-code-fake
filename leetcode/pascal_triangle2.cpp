#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> row{1};
	for(int i=2; i<rowIndex/2; ++i) {
		row.push_back((row[i-1]*(rowIndex-i+1)) / (i-1));
	}

	if(rowIndex & 1) {
		row.push_back((row[rowIndex/2]*(rowIndex-rowIndex/2+2)) / (rowIndex/2));
	}

	return row;
}