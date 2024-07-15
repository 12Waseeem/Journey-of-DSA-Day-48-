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
        if (!head || !head->next) {
            return head; // Return if the list is empty or has only one node
        }

        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr && curr->val == duplicateVal) {
                    curr = curr->next; // Move curr to skip duplicates
                }
                prev->next = curr; // Link previous node to the non-duplicate node
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next; // Return the head of the updated list
    }
};
