#include <vector>

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> row;
	row[0].push_back(1);
	for(size_t i=1; i<5; ++i) {
		row[i].push_back(1);
		for(size_t j=1; j<i; ++j) {
			row[i][j] = row[i-1][j-1] + row[i-1][j];
		}
		row[i].push_back(1);
	}

	return row;
}	

void printVector(vector<vector<int>> res) {
	for(vector<vector<int>>::iterator it=res.begin(); it != res.end(); ++it) {
		for(vector<int>::iterator jt=(*it).begin(); jt != (*it).end(); ++jt) {
			cout << *jt << ",";
		}
		cout <<endl;
	}
	cout <<endl;
}

int main(int argc, char** argv) {
	int numRows = 3;
	if(argc>1) {
		numRows = atoi(argv[1]);
	}
	vector<vector<int>> res = generate(numRows);
	printVector(res);

	return 0;
}