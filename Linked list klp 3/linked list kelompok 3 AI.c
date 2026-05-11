#include <stdio.h>
#include <stdlib.h>

// LeetCode ListNode structure
struct ListNode {
    int val;
    struct ListNode *next;
};

// Fungsi utama detectCycle sesuai LeetCode signature
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next) return NULL;
    
    // Phase 1: Detect cycle dengan slow (1 step) dan fast (2 steps)
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Phase 2: Cari entry point cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Return node dimana cycle dimulai
        }
    }
    return NULL;  // No cycle
}

// Helper functions untuk testing
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    printf("List: ");
    while (curr) {
        printf("%d", curr->val);
        if (curr->next) printf(" -> ");
        curr = curr->next;
    }
    printf("");
}

// Test case 1: List dengan cycle (3 -> 4 -> 0 -> 2 -> cycle ke 2)
int main() {
    // Buat list: 3 -> 4 -> 0 -> 2 -> (cycle ke 2)
    struct ListNode* head = createNode(3);
    head->next = createNode(4);
    head->next->next = createNode(0);
    head->next->next->next = createNode(2);
    
    // Buat cycle: node 2 -> node 2
    struct ListNode* cycleNode = head->next->next->next;
    cycleNode->next = head->next->next->next;  // 2 -> 2 (self-loop)
    
    printList(head);
    
    struct ListNode* result = detectCycle(head);
    if (result) {
        printf("Cycle starts at node dengan nilai: %d", result->val);
    } else {
        printf("No cycle detected");
    }
    
    return 0;
}