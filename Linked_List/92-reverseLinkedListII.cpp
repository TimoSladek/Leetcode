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
    void reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;
        int cnt = right - left + 1;
        while (cnt) {
            fast = fast->next;
            cnt--;
        }
        for (int i = 0;i < left-1; ++i) {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp = fast->next;
        fast->next = NULL;
        ListNode* node = slow->next;
        reverse(node);
        slow->next = fast;
        node->next = temp;
        return dummyNode->next;
    }
};