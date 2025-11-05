#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int alphaBeta(int depth, int index, bool isMax,
              const vector<int>& scores, int alpha, int beta, int maxDepth)
{
    if (depth == maxDepth)
        return scores[index];

    if (isMax) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 2; ++i) {
            int val = alphaBeta(depth + 1, index * 2 + i, false, scores, alpha, beta, maxDepth);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha) break; // prune
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 2; ++i) {
            int val = alphaBeta(depth + 1, index * 2 + i, true, scores, alpha, beta, maxDepth);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha) break; // prune
        }
        return best;
    }
}

int main() {
    int n;
    cout << "Enter number of leaf nodes (must be power of 2): ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter " << n << " leaf node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // depth = log2(n)
    int maxDepth = 0, temp = n;
    while (temp > 1) {
        maxDepth++;
        temp /= 2;
    }

    int bestValue = alphaBeta(0, 0, true, scores,
                              numeric_limits<int>::min(),
                              numeric_limits<int>::max(),
                              maxDepth);

    cout << "Best value: " << bestValue << endl;
    return 0;
}

