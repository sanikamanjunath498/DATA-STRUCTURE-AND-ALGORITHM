struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy node simplifies edge cases like removing the head node
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // 1. Advance fast pointer n + 1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // 2. Move fast and slow together until fast reaches NULL
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 3. Skip the Nth node from the end
    struct ListNode *toDelete = slow->next;
    slow->next = slow->next->next;

    return dummy.next;
}
