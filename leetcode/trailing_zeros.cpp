#include <iostream>
using namespace std;

int getTrailingZeros(int n) {
    int result = 0;

    for(size_t i=5; i<=n; i*=5) {
        result += n/i;
    }
    return result;
}
int main() {
    int n=INT_MAX;
    cout << getTrailingZeros(n) << endl;
    return 0;
}
