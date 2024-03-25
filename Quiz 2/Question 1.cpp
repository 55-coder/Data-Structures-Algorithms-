#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false; // No cycle found
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true; // Cycle found
}

// Example usage
int main() {
    // Example 1
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;

    std::cout << "Example 1: " << std::boolalpha << hasCycle(head1) << std::endl;
    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;
    std::cout << "Example 2: " << std::boolalpha << hasCycle(head2) << std::endl;
    // Example 3
    ListNode* head3 = new ListNode(1);
    std::cout << "Example 3: " << std::boolalpha << hasCycle(head3) << std::endl;
    return 0;
}
