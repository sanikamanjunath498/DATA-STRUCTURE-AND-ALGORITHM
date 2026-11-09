struct ListNode* swapPairs(struct ListNode* head) {
    // Dummy node to handle edge cases easily (e.g., empty list or single node)
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to swap
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // Perform the swap
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move prev two nodes forward for the next pair
        prev = first;
    }

    return dummy.next;
}
