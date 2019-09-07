#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    for (int i = 0; i < v.size()/2; ++i) {
        int temp;
        temp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = temp;
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    // numbers должен оказаться равен {2, 4, 3, 5, 1}
    return 0;
}
