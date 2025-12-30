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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        if (list1 -> val < list2 -> val) return mergeTwoLists(list2, list1);
        ListNode* merging = NULL;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while (curr1 != NULL && curr2 -> next != NULL) {
            if (curr1 -> val >= curr2 -> val && curr1 -> val <= curr2 -> next -> val) {
                merging = curr1;
                curr1 = curr1 -> next;
                merging -> next = curr2 -> next;
                curr2 -> next = merging;
            }
            curr2 = curr2 -> next;
        }
        if (curr1 != NULL) curr2 -> next = curr1;
        return list2;
    }
};