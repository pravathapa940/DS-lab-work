#include <iostream>
using namespace std;

int modInverse(int a, int m) {
    int m0 = m, x0 = 0, x1 = 1;
    while (a > 1) {
        int q = a / m, t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    return (x1 + m0) % m0;
}

int chineseRemainder(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) prod *= num[i];

    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num) / sizeof(num[0]);
    cout << "x = " << chineseRemainder(num, rem, k) << endl;
    return 0;
}
