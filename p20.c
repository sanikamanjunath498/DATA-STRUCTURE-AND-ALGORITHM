class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases like removing the head node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n + 1 steps ahead so slow stops right before the target node
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end (nullptr)
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Bypass and delete the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node to prevent memory leaks
        
        return newHead;
    }
};
