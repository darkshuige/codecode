#include <iostream>
using namespace std;

int overlap(int x1, int y1, int z1, int x2, int y2, int z2) {
    int dx = min(x1 + 7, x2 + 7) - max(x1, x2);
    int dy = min(y1 + 7, y2 + 7) - max(y1, y2);
    int dz = min(z1 + 7, z2 + 7) - max(z1, z2);
    if (dx <= 0 || dy <= 0 || dz <= 0) return 0;
    return dx * dy * dz;
}


bool check(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int V1, int V2, int V3) {
    int V2_ = overlap(x1, y1, z1, x2, y2, z2) + overlap(x1, y1, z1, x3, y3, z3) + overlap(x2, y2, z2, x3, y3, z3);
    int V3_ = overlap(x1, y1, z1, x2, y2, z2);
    return V1 == 3 * 294 - 2 * V2_ - V3_ && V2 == V2_ && V3 == V3_;
}


int main() {
    int V1, V2, V3;
    cin >> V1 >> V2 >> V3;
    for (int x1 = 0; x1 <= 7; x1++) {
        for (int y1 = 0; y1 <= 7; y1++) {
            for (int z1 = 0; z1 <= 7; z1++) {
                for (int x2 = 0; x2 <= 7; x2++) {
                    for (int y2 = 0; y2 <= 7; y2++) {
                        for (int z2 = 0; z2 <= 7; z2++) {
                            for (int x3 = 0; x3 <= 7; x3++) {
                                for (int y3 = 0; y3 <= 7; y3++) {
                                    for (int z3 = 0; z3 <= 7; z3++) {
                                        if (check(x1, y1, z1, x2, y2, z2, x3, y3, z3, V1, V2, V3)) {
                                            cout << "Yes" << endl;
                                            cout << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " " << x3 << " " << y3 << " " << z3 << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
