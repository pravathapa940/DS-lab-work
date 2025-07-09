#include <iostream>
using namespace std;

bool implies(bool A, bool B) { return !A || B; }
bool biconditional(bool A, bool B) { return A == B; }
void print(bool val) { cout << (val ? "T" : "F") << "\t"; }

int main() {
    cout << "1a. (p ? 段 ? r) ? (殆 ? r)\n";
    cout << "p\tq\tr\t段\t殆\t(p?段)\t(p?段?r)\t(殆?r)\t?\n";
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r) {
                bool not_q = !q, not_p = !p;
                bool p_and_not_q = p && not_q;
                bool left = p_and_not_q || r;
                bool right = not_p || r;
                bool result = implies(left, right);
                print(p); print(q); print(r); print(not_q); print(not_p);
                print(p_and_not_q); print(left); print(right); print(result);
                cout << endl;
            }

    cout << "\n1b. (p ? 段 ? r) ? (殆 ? r)\n";
    cout << "p\tq\tr\t(p?段?r)\t(殆?r)\t?\n";
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r) {
                bool expr1 = (p && !q) || r;
                bool expr2 = (!p) || r;
                bool result = biconditional(expr1, expr2);
                print(p); print(q); print(r); print(expr1); print(expr2); print(result);
                cout << endl;
            }
    return 0;
}

