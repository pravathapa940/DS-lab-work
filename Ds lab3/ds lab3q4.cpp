#include <iostream>
using namespace std;

bool implies(bool A, bool B) { return !A || B; }
void print(bool val) { cout << (val ? "T" : "F") << "\t"; }

int main() {
    cout << "4. Mall/Jeans/Shirt Argument:\n";
    cout << "M\tJ\tS\tM?J\tJ?S\tConclusion(M?S)\tValid\n";

    for (int M = 0; M <= 1; ++M)
        for (int J = 0; J <= 1; ++J)
            for (int S = 0; S <= 1; ++S) {
                bool mImpliesJ = implies(M, J);
                bool jImpliesS = implies(J, S);
                bool conclusion = implies(M, S);
                bool valid = !(mImpliesJ && jImpliesS) || conclusion;
                print(M); print(J); print(S);
                print(mImpliesJ); print(jImpliesS); print(conclusion); print(valid);
                cout << endl;
            }
    return 0;
}

