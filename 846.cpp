#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int nextNotZero(int index, vector<int>& nums) {
        if (nums.at(index) > 0) {
            return index;
        }
        if (index + 1 > nums.size()) {
            return -1;
        }
        return nextNotZero(index + 1, nums);
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        vector<int> sortedHand(hand);
        sort(sortedHand.begin(), sortedHand.end());
        vector<int> cards(sortedHand.begin(), sortedHand.end());
        for (int const& card : hand) {
            cards[card]++;
        }

        int numGroups = hand.size() / groupSize;
        vector<vector<int>> groups;
        groups.reserve(numGroups);
        for (int i = 0; i < numGroups; i++) {
            vector<int> groupVec;
            groupVec.reserve(groupSize);
            for (int j = 0; j < groupSize; j++) {
                int nextCard = nextNotZero(j, cards);
                if (nextCard == -1) {
                    break;
                }
                groupVec.push_back(cards[nextCard]);
                cards[nextCard]--;
            }
            groups.push_back(groupVec);
        }

        for (vector<int> const& group : groups) {
            if (group.size() < groupSize) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol = Solution();
    vector<int> vec({1,2,3,4,5});
    bool size = sol.isNStraightHand(vec, 4);
    cout << size << '\n';
    return 0;
}