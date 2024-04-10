auto speedUp = []() { // The first variant of the cheat code with a lambda.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Solution() { // The second variant of the cheat code with a constructor.
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    // 125. Valid Palindrome. Time = O(n).
    bool isAlphanumeric(char letter) { // Simpler version.
        return ('a' <= letter && letter <= 'z') or ('A' <= letter && letter <= 'Z') or
			('0' <= letter && letter <= '9');
	}

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
                l++; // Skip non-alphanumeric chars.
            } else if(not isAlphanumeric(s[r])) {
                r--; // Skip non-alphanumeric chars.
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

    // 1. Two Sum. Time = O(n*log(n)) for sorting.
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

    // 11. Container With Most Water. Time = O(n) until two pointers become equal.
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

    // 875. Koko Eating Bananas. Time = O(n*log(range)), where range ~ max value in the array piles.
    long findTime(vector<int> &piles, int speed) { // O(n)
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
        while(l < r) { // log(range).
            int mid = l + (r - l) / 2;
            long time = findTime(piles, mid); // O(n).
            if(time <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

	// 206. Reverse Linked List. Time = O(n).
	// Recursive solution. Space = O(n) because of a call stack for recursive calls.
	ListNode* helper(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        }
        auto lastElem = helper(head->next);
        head->next->next = head;
        return lastElem;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        if(head->next == nullptr) {
            return head;
        }
        auto lastElem = helper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return lastElem;
    }

	// Loop solution.
	ListNode* reverseList(ListNode* head) {
        auto currentElement = head;
        ListNode* previousElement = nullptr;
        while(currentElement != nullptr) {
            auto newCurr = currentElement->next;
            currentElement->next = previousElement;
            previousElement = currentElement;
            currentElement = newCurr;
        }
        return previousElement;
    }

	// 53. Maximum Subarray.
	// Prefix sum solution. Time = O(n^2).
	int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) { // O(n).
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int maxSum = nums[0];
        for(int l = 0; l < n; l++) { // O(n).
            for(int r = l; r < n; r++) { // O(n).
                int rangeSum = prefixSum[r] - (l == 0 ? 0 : prefixSum[l - 1]); // O(1).
                if(rangeSum > maxSum) {
                    maxSum = rangeSum;
                }
            }
        }
        return maxSum;
    }

	// Kadane's algorithm or DP solution. Bottom-up. Time = O(n).
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int maxSubarraySum = 0; // S[i].
        for(int i = 0; i < n; i++) {
            if(maxSubarraySum <= 0) {
                maxSubarraySum = nums[i];
            } else {
                maxSubarraySum = maxSubarraySum + nums[i];
            }
            if(maxSubarraySum > maxSum) {
                maxSum = maxSubarraySum;
            }
        }
        return maxSum;
    }

	// 1464. Maximum Product of Two Elements in an Array. Time = O(n), Space = O(1).
	int maxProduct(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min heap.
        for(int elem : nums) {
            pq.push(elem);
            if(pq.size() > 2) {
                pq.pop();
            }
        }
        int a = pq.top();
        pq.pop();
        return (a - 1) * (pq.top() - 1);
    }

	// 1642. Furthest Building You Can Reach. Time = O(n*log(l)), Space = O(l), where l is a number of ladders.
    int furthestBuilding(vector<int> &hs, int b, int l) {
        int n = hs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> largestJmps;
        int i = 0;
        for(; i < n; i++) {
            int delta = hs[i + 1] - hs[i];
            if(delta <= 0) {
                continue;
            }
            largestJmps.push(delta);
            if(largestJmps.size() > l) {
                int minVal = largestJmps.top();
                if(minVal > b) {
                    break;
                } else {
                    b -= minVal;
                    largestJmps.pop();
                }
            }
        }
        return i;
    }

	// 215. Kth Largest Element in an Array.
	// Sorting solution (slow). Time = O(n*log(n)).
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

	// nth_element or Quick select solution. Time = O(n).
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }

	// Priority queue solution. Time = O(n*log(k)). Space = O(k). Note: 0 < k <= n.
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq; // Min heap.
        for(int elem : nums) {
            pq.push(elem);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }

	// 198. House Robber, Time = O(n)
	// Bottom-up, constant space (Space = O(1))
    int rob(vector<int> &nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        int ms0 = nums[0], ms1 = max(nums[0], nums[1]); // ms - maximum sum for current index i
        for(int i = 2; i < n; i++) {
            int newMS = max(ms1, ms0 + nums[i]);
            ms0 = ms1;
            ms1 = newMS;
        }
        return ms1;
    }

	//Recursive DP, linear space for memo (Space = O(n))
	vector<int> memo;

    int helper(vector<int> &nums, int n) {
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        if(memo[n] == -1) {
            memo[n] = max(helper(nums, n - 1), helper(nums, n - 2) + nums[n - 1]);
        }
        return memo[n];
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        memo = vector<int>(n + 1, -1);
        return helper(nums, n);
    }

	// Bottom-up, use the input vector nums as a memo, constant extra space (Space = O(1)).
	int rob(vector<int> &nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		nums[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
		}
		return nums.back();
	}

	// 70. Climbing Stairs
    vector<int> memo;

    int helper(int n) { // Memory call-stack + Memo: O(n)
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        if(memo[n] == -1) {
            memo[n] = helper(n - 2) + helper(n - 1);
        }
        return memo[n];
    }

    int climbStairs(int n) { // Recursion
		memo = vector<int>(n, -1);
		return helper(n);
    }


    int climbStairs(int n) {
        memo = vector<int>(n + 1);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i <= n; i++) {

        }
        return f0; // bottom-up, extra space, memory complexity O(n)
    }

    int climbStairs(int n) { //bottom-up, no extra memory (space), memory complexity O(1)
        long f0 = 1, f1 = 2;
        for(int i = 0; i < n - 1; i++) {
            long newF = f0 + f1;
            f0 = f1;
            f1 = newF;
        }
        return f0; // bottom-up
    }

	// 1431. Kids With the Greatest Number of Candies
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n);
        int maxElem = *max_element(candies.begin(), candies.end()); // build-in max_element find max element in a vector
        for(int i = 0; i < n; i++) {
            result[i] = (candies[i] + extraCandies) >= maxElem;
        }
        return result;
    }

	// 88. Merge Sorted Array
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> arr(m + n);
        int i = 0, j = 0;
        for(int k = 0; i < m || j < n; k++) {
            if(i >= m) {
                arr[k] = nums2[j];
                j++;
            } else if(j >= n) {
                arr[k] = nums1[i];
                i++;
            } else {
                if(nums1[i] < nums2[j]) {
                    arr[k] = nums1[i];
                    i++;
                } else {
                    arr[k] = nums2[j];
                    j++;
                }
            }
        }
        nums1 = arr;
    }

	// 69. Sqrt(x)
    int mySqrt(long x) {
        long l = 0, r = x;
        while(l < r) { // Binary search. Time = log(x).
            long mid = l + (r - l + 1) / 2;
            long sq = mid * mid;
            if(sq == x) {
                return mid;
            } else if(sq < x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

	// 94. Binary Tree Inorder Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> leftSide = inorderTraversal(root->left);
        leftSide.push_back(root->val);
        vector<int> rightSide = inorderTraversal(root->right);
        for(int elem : rightSide) {
            leftSide.push_back(elem);
        }
        return leftSide;
    }

	// 104. Maximum Depth of Binary Tree
	int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

	// 111. Minimum Depth of Binary Tree
	bool isLeaf(TreeNode* node) {
        return node->left == nullptr and node->right == nullptr;
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        if(isLeaf(root)) {
            return 1;
        }
        int leftDepth = INT_MAX, rightDepth = INT_MAX;
        if(root->left != nullptr) {
            leftDepth = minDepth(root->left);
        }
        if(root->right != nullptr) {
            rightDepth = minDepth(root->right);
        }
        return 1 + min(leftDepth, rightDepth);
    }

	//2236. Root Equals Sum of Children
    bool checkTree(TreeNode* root) {
        return (root->val == root->left->val + root->right->val);
    }

	// 100. Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == q) {
            return true;
        }
        if((p == nullptr and q != nullptr) or (p != nullptr and q == nullptr)) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

	// 700. Search in a Binary Search Tree
    TreeNode* searchBST(TreeNode* root, int val) {
        auto currNode = root;
        while(currNode != nullptr) {
            if(currNode->val == val) {
                return currNode;
            } else if(currNode->val > val) {
                currNode = currNode->left;
            } else {
                currNode = currNode->right;
            }
        }
        return nullptr;
    }

	// 701. Insert into a Binary Search Tree
    TreeNode* insertIntoBST(TreeNode *root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }
        if(root->val < val) {
            if(root->right == nullptr) {
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val);
            }
        }
        else {
            if(root->left == nullptr) {
                root->left = new TreeNode(val);
            } else {
                insertIntoBST(root->left, val);
            }
        }
        return root;
    }

	// 108. Convert Sorted Array to Binary Search Tree
    TreeNode* helper(vector<int> &nums, int l, int r) {
        if(r < l) {
            return nullptr;
        }
        int mid = (l + r) / 2;
        return new TreeNode(nums[mid], helper(nums, l, mid - 1), helper(nums, mid + 1, r));
    }

    TreeNode* sortedArrayToBST(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }

	// 202. Happy Number
	bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1) {
            if(seen.contains(n)) {
                return false;
            }
            seen.insert(n);
            int newN = 0;
            while(n != 0) {
                int digit = n % 10;
                newN += digit * digit;
                n /= 10;
            }
            n = newN;
        }
        return true;
    }

	// 771. Jewels and Stones
	int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for(char stone : stones) {
            if(jewelSet.contains(stone)) {
                count++;
            }
        }
        return count;
    }

	// 268. Missing Number
	int missingNumber(vector<int> &nums) {
        int n = nums.size();
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int i = 0; i <= n; i++) {
            if(not numSet.contains(i)) {
                return i;
            }
        }
        return -1;
    }

    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        bool present[n + 1];
        for(int i = 0; i <= n; i++) {
            present[i] = false;
        }
        for(int elem : nums) {
            present[elem] = true;
        }
        for(int i = 0; i <= n; i++) {
            if(not present[i]) {
                return i;
            }
        }
        return -1;
    }

    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int currNum = nums[i];
            while(currNum >= 0 and currNum < nums.size()) {
                int temp = nums[currNum];
                nums[currNum] = -1;
                currNum = temp;
            }
        }
        int i = 0;
        for(; i < nums.size() and nums[i] == -1; i++) {
            ;
        }
        return i;
    }

    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for(int elem : nums) {
            sum -= elem;
        }
        return sum;
    }

	// 1002. Find Common Characters
    vector<string> commonChars(vector<string> &words) {
        int n = words.size();
        int numCounts[26];
        for(char ch = 'a'; ch <= 'z'; ch++) {
            numCounts[ch - 'a'] = INT_MAX;
        }
        for(string &word : words) {
            unordered_map<char, int> table;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                table[ch] = 0;
            }
            for(char ch : word) {
                table[ch]++;
            }
            for(auto [ch, count] : table) { // structured binding
                numCounts[ch - 'a'] = min(numCounts[ch - 'a'], count);
            }
        }
        vector<string> result;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            for(int i = 0; i < numCounts[ch - 'a']; i++) {
                result.push_back(string(1, ch));
            }
        }
        return result;
    }

	// 783. Minimum Distance Between BST Nodes
    vector<int> array;

    void inorderConvert(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorderConvert(root->left);
        array.push_back(root->val);
        inorderConvert(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        array = vector<int>();
        inorderConvert(root);
        int n = array.size();
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            minDiff = min(minDiff, array[i] - array[i - 1]);
        }
        return minDiff;
    }

	// 100. Same Tree
	bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> bfsQueue1, bfsQueue2;
        bfsQueue1.push(p);
        bfsQueue2.push(q);
        while(not bfsQueue1.empty() and not bfsQueue2.empty()) {
            TreeNode *node1 = bfsQueue1.front();
            bfsQueue1.pop();

            TreeNode *node2 = bfsQueue2.front();
            bfsQueue2.pop();

            if(node1 == nullptr and node2 == nullptr) {
                ;
            } else if(node1 != nullptr and node2 == nullptr) {
                return false;
            } else if(node1 == nullptr and node2 != nullptr) {
                return false;
            } else {
                if(node1->val != node2->val) {
                    return false;
                }
                bfsQueue1.push(node1->left);
                bfsQueue1.push(node1->right);

                bfsQueue2.push(node2->left);
                bfsQueue2.push(node2->right);
            }
        }
        if(bfsQueue1.empty() and bfsQueue2.empty()) {
            return true;
        }
        return false;
    }

	// 102. Binary Tree Level Order Traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        vector<vector<int>> result;
        while(not bfsQueue.empty()) {
            int currentSize = bfsQueue.size();
            vector<int> currentLevel;
            for(int i = 0; i < currentSize; i++) {
                TreeNode* node = bfsQueue.front();
                bfsQueue.pop();
                currentLevel.push_back(node->val);
                if(node->left != nullptr) {
                    bfsQueue.push(node->left);
                }
                if(node->right != nullptr) {
                    bfsQueue.push(node->right);
                }
            }
            result.push_back(move(currentLevel));
        }
        return result;
    }

	// 200. Number of Islands
    void bfsPaint(vector<vector<char>> &grid, int rootRow, int rootColumn) {
        int m = grid.size(); // row size
        int n = grid[0].size(); // column size;
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({rootRow, rootColumn});
        while(not bfsQueue.empty()) {
            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();
            grid[row][col] = '0';
            if(row - 1 >= 0) {
                if(grid[row - 1][col] == '1') { // 1 - land, 0 - water
                    grid[row - 1][col] = '2';
                    bfsQueue.push({row - 1, col});
                }
            }
            if(col - 1 >= 0) {
                if(grid[row][col - 1] == '1') { // 1 - land, 0 - water
                    grid[row][col - 1] = '2';
                    bfsQueue.push({row, col - 1});
                }
            }
            if(row + 1 < m) {
                if(grid[row + 1][col] == '1') { // 1 - land, 0 - water
                    grid[row + 1][col] = '2';
                    bfsQueue.push({row + 1, col});
                }
            }
            if(col + 1 < n) {
                if(grid[row][col + 1] == '1') { // 1 - land, 0 - water
                    grid[row][col + 1] = '2';
                    bfsQueue.push({row, col + 1});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(); // row size
        int n = grid[0].size(); // column size;
        int countIslands = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1') {
                    bfsPaint(grid, row, col);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};
