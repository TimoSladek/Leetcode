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
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = head;
        ListNode* dummyTemp = dummyNode;
        ListNode* prev = head;
        if (temp->val != temp->next->val) {
            dummyTemp->next = temp;
            dummyTemp = dummyTemp->next;
        }
        temp = temp->next;
        while (temp->next != NULL) {
            prev->next = NULL;
            if (temp->val != prev->val && temp->val != temp->next->val) {
                dummyTemp->next = temp;
                dummyTemp = dummyTemp->next;
            }
            prev = temp;
            temp = temp->next;
        }
        if (temp->val != prev->val) {
            dummyTemp->next = temp;
        }
        return dummyNode->next;
    }
};