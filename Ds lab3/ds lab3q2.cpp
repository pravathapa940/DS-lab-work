#include <iostream>
using namespace std;

bool implies(bool A, bool B) { return !A || B; }
void print(bool val) { cout << (val ? "T" : "F") << "\t"; }

int main() {
    cout << "2. Argument: If hound dog then howl. Not howl. Therefore, not hound dog.\n";
    cout << "p\tq\tp?q\t¬q\tConclusion(¬p)\tValid\n";

    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q) {
            bool cond = implies(p, q);
            bool not_q = !q;
            bool conclusion = !p;
            bool valid = !(cond && not_q) || conclusion;
            print(p); print(q); print(cond); print(not_q); print(conclusion); print(valid);
            cout << endl;
        }
    return 0;
}

