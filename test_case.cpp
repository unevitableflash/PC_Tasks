// gen.cpp
#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1); // Enable testlib random

    int m = atoi(argv[1]); // number of rows
    int n = atoi(argv[2]); // number of columns

    println(m, n); // Output the dimensions

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = rnd.next(0, 1); // Random 0 or 1
            cout << val << " ";
        }
        cout << '\n';
    }

    return 0;
}
