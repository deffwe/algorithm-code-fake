#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void printVec(const vector<long> &);
vector<int> getRow(long);

vector<int> getRow(long rowIndex) {
    rowIndex += 1;
	vector<long> row, tmp;
    vector<int> result;
    if(rowIndex<=1) {
        result.push_back(1);
        return result;
    }
    row.push_back(0);
    row.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
	for(long i=2; i<=rowIndex/2; ++i) {
        long x = (row[i-1]*(rowIndex-i+1)) / (i==1 ? 1 : (i-1));
        tmp.push_back(x-tmp[i-1]);
        row.push_back(x);
	}
    
    row.erase(row.begin());

    vector<long> res(row);
    if(rowIndex & 1) {
        res.push_back(tmp.back()*2);
	}
    reverse(row.begin(), row.end());
    res.insert(res.end(), row.begin(), row.end());
    for(vector<long>::iterator it=res.begin(); it != res.end(); ++it) {
        result.push_back((int)(*it));
    }

	return result;
}
void prlongVec(const vector<int>& res) {
    for(size_t i=0; i<res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}
int main(int argc, char** argv) {
    long rowIndex = 3;
    if(argc>1) {
        rowIndex = atoi(argv[1]);
    }
    vector<int> res = getRow(rowIndex);
    prlongVec(res); 
    return 0;
}
