class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        stack<int> myStack; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                myStack.push(nums[i]);
            }
        } // <-- Added missing closing brace for the first 'for' loop

        int validCount = myStack.size(); 

        for (int i = validCount - 1; i >= 0; i--) {
            nums[i] = myStack.top(); 
            myStack.pop();           
        }

        return validCount;
    } 
};