#include <iostream>
#include <string>
#include <vector>
using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    // b должно стать равно 4
    return 0;
}
