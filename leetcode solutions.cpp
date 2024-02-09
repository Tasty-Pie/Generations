auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    // 125. Valid Palindrome
    bool isAlphanumeric(char letter) {
        if('a' <= letter && letter <= 'z') {
            return true;
        }
        if('A' <= letter && letter <= 'Z') {
            return true;
        }
        if('0' <= letter && letter <= '9') {
            return true;
        }
        return false;
    }

    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(not isAlphanumeric(s[l])) {
                l++;
            } else if(not isAlphanumeric(s[r])) {
                r--;
            } else {
                if(tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }

    // 1. Two Sum
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<vector<int>> pairs(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int sum = pairs[i][0] + pairs[j][0];
            if(sum == target) {
                return {pairs[i][1], pairs[j][1]};
            } else if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }

    // 11. Container With Most Water
	int maxArea(vector<int> &height) {
		int i = 0, j = height.size() - 1;
		int maxWater = 0;
		while (i != j) {
			if (height[i] < height[j]) {
				auto temp = height[i] * (j - i);
				if (temp > maxWater) {
					maxWater = temp;
				}
				i++;
			} else {
				auto temp = height[j] * (j - i);
				if (temp > maxWater) {
					maxWater = temp;
				}
				j--;
			}
		}
		return maxWater;
	}
    // 875. Koko Eating Bananas
    long findTime(vector<int> &piles, int speed) {
        long hours = 0;
        for(int bananas : piles) {
            hours += bananas / speed;
            if(bananas % speed != 0) {
                hours++;
            }
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, long h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int mid = l + (r - l) / 2;
            long time = findTime(piles, mid);
            if(time <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

};
