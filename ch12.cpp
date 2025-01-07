#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct vector_hash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash = hash * 31 + i;
        }
        return hash;
    }
};

class Solution {
private:
    unordered_map<vector<int>, int, vector_hash> memo;

    // Helper function to calculate the direct cost without special offers
    int directCost(const vector<int>& needs, const vector<int>& price) {
        int total = 0;
        for (size_t i = 0; i < needs.size(); ++i) {
            total += needs[i] * price[i];
        }
        return total;
    }

    // Recursive function to calculate the minimum cost
    int dfs(const vector<int>& price, const vector<vector<int>>& special, vector<int> needs) {
        if (memo.count(needs)) return memo[needs];

        // Start with the direct cost as the base case
        int minCost = directCost(needs, price);

        // Try applying each special offer
        for (const auto& offer : special) {
            vector<int> nextNeeds(needs);
            bool valid = true;

            for (size_t i = 0; i < needs.size(); ++i) {
                if (needs[i] < offer[i]) {
                    valid = false;
                    break;
                }
                nextNeeds[i] -= offer[i];
            }

            if (valid) {
                minCost = min(minCost, offer.back() + dfs(price, special, nextNeeds));
            }
        }

        memo[needs] = minCost;
        return minCost;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};

