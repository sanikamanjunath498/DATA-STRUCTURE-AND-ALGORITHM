/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        // Traverse through the linked list
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Duplicate found: skip the next node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory for the removed node
            } else {
                // No duplicate: move forward
                current = current->next;
            }
        }
        
        return head;
    }
};
