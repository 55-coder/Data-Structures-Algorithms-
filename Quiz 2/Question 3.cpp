ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr != nullptr) {
        // Store the next node
        next = curr->next;
        // Reverse the link
        curr->next = prev;
        // Move pointers one step forward
        prev = curr;
        curr = next;
    }
    // Update the head of the reversed list
    head = prev;
    return head;
}
