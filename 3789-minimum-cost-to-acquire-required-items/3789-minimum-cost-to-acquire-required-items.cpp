class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long costA = (long long)need1 * cost1 + (long long)need2 * cost2;

        int maximum = max(need1, need2);
        long long costB = (long long)maximum * costBoth;

        int minimum = min(need1, need2);
        int remaining1 = need1 - minimum;
        int remaining2 = need2 - minimum;

        long long costC = (long long)minimum * costBoth;
        costC = costC + (long long)remaining1 * cost1;
        costC = costC + (long long)remaining2 * cost2;

        long long answer = min(costA, min(costB, costC));

        return answer;
    }
};