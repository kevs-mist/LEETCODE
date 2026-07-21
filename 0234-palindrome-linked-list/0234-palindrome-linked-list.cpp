class Solution {
private:
    ListNode* startPointer; // Tracks the front of the list

    bool check(ListNode* endPointer) {
        // Base case: We reached the end of the list
        if (endPointer == nullptr) return true;

        // Move the end pointer all the way to the final node (DFS)
        bool isSubListPalindrome = check(endPointer->next);
        
        // If any deeper comparison failed, it's not a palindrome
        if (!isSubListPalindrome) return false;

        // Compare start value with end value (your "start == end" logic)
        bool valuesMatch = (startPointer->val == endPointer->val);

        // Move the start pointer forward by one step for the next comparison
        startPointer = startPointer->next;

        return valuesMatch;
    }

public:
    bool isPalindrome(ListNode* head) {
        startPointer = head;
        return check(head);
    }
};
