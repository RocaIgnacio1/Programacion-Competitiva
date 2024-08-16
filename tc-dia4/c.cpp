#include <iostream>
#include <algorithm>
using namespace std;

int countZeroesInBitPosition(int l, int r, int bit) {
    int cycleLength = 1 << (bit + 1); // 2^(bit + 1)
    int halfCycleLength = cycleLength >> 1; // 2^bit

    int totalNumbers = r - l + 1;
    int startCycle = l / cycleLength;
    int endCycle = r / cycleLength;

    int zeroesInCompleteCycles = (endCycle - startCycle) * halfCycleLength;

    int zeroesAtStart = 0;
    int startRemainder = l % cycleLength;
    int endRemainder = r % cycleLength;

    if (startRemainder < halfCycleLength) {
        zeroesAtStart += min(halfCycleLength - startRemainder, totalNumbers);
    }

    int zeroesAtEnd = 0;
    if (endRemainder < halfCycleLength) {
        zeroesAtEnd += (endRemainder + 1);
    } else {
        zeroesAtEnd += halfCycleLength;
    }

    return zeroesInCompleteCycles + zeroesAtStart + zeroesAtEnd;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int min_deletions = r - l + 1;

        for (int bit = 0; bit < 18; ++bit) {
            int zeroes = countZeroesInBitPosition(l, r, bit);
            min_deletions = min(min_deletions, zeroes);
        }

        cout << min_deletions << endl;
    }

    return 0;
}
