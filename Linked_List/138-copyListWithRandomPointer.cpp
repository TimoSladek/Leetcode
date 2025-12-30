/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void createCopyNodes(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }
    void copyRandomPointers(Node* head) {
        Node* temp = head;
        Node* copyTemp;
        while (temp != NULL) {
            copyTemp = temp->next;
            if (temp->random != NULL) copyTemp->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    Node* makeCopyListSeparate(Node* head) {
        Node* temp = head;
        Node* copyHead = temp->next;
        Node* copyTemp = copyHead;
        while (temp != NULL) {
            temp->next = copyTemp->next;
            if (temp->next != NULL) copyTemp->next = temp->next->next;
            temp = temp->next;
            copyTemp = copyTemp->next;
        }
        return copyHead;
    }
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        createCopyNodes(head);
        copyRandomPointers(head);
        return makeCopyListSeparate(head);
    }
};