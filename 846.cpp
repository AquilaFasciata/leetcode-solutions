#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    int nextNotZero(int index, map<int, int>& nums) {
        if (nums.at(index) > 0) {
            return index;
        }
        if (index + 1 > nums.size()) {
            return -1
        }
        return nextNotZero(index + 1, nums);
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        map<int, int> cards(hand.begin(), hand.end());
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
                groupVec.push_back(cards[nextCard]);
                cards[nextCard]--;
            }
            groups.push_back(groupVec);
        }

        for (vector<int> const& group : groups) {

        }
        for (vector<int> const& group : groups) {

        }
    }
};