#include <iostream>
using namespace std;

bool implies(bool A, bool B) { return !A || B; }
void print(bool val) { cout << (val ? "T" : "F") << "\t"; }

int main() {
    cout << "3. Goat/Yugo Argument:\n";
    cout << "G\tY\tL\t(G?Y)?L\t¬L\tY?¬L\tConclusion(¬G)\tValid\n";

    for (int G = 0; G <= 1; ++G)
        for (int Y = 0; Y <= 1; ++Y)
            for (int L = 0; L <= 1; ++L) {
                bool premise2 = implies(G && Y, L);
                bool not_L = !L;
                bool premise3 = Y && not_L;
                bool conclusion = !G;
                bool premise1 = G || Y;
                bool valid = !(premise1 && premise2 && premise3) || conclusion;
                print(G); print(Y); print(L);
                print(premise2); print(not_L); print(premise3); print(conclusion); print(valid);
                cout << endl;
            }
    return 0;
}

