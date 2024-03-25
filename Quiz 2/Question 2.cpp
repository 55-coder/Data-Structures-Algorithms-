#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    // Phase 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break; // Cycle detected
        }
    }
    // If no cycle found
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }
    // Phase 2: Find starting point of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Return the starting point of the cycle
}

// Example usage
int main() {
    // Example 1
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;

    ListNode* cycleStart1 = detectCycle(head1);
    std::cout << "Example 1: " << cycleStart1->val << std::endl;
    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;
    ListNode* cycleStart2 = detectCycle(head2);
    std::cout << "Example 2: " << cycleStart2->val << std::endl;
    // Example 3
    ListNode* head3 = new ListNode(1);
    ListNode* cycleStart3 = detectCycle(head3);
    if (cycleStart3 != nullptr) {
        std::cout << "Example 3: " << cycleStart3->val << std::endl;
    } else {
        std::cout << "Example 3: No cycle" << std::endl;
    }
    return 0;
}
