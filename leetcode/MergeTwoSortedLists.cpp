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
        void addNode(ListNode* head, int value) {
            bool findBiggerNumber = false;

            while (true) {
                if (value < head->val) {
                    ListNode* newNode = new ListNode(head->val);
                    head->val = value;
                    newNode->next = head->next;
                    head->next = newNode;
                    break;
                }

                if (head->next == nullptr) {
                    ListNode* newNode = new ListNode(value);
                    head->next = newNode;
                    break;
                }
                head = head->next;
            }
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            vector<int> valList;
            while (l1 != nullptr || l2 != nullptr) {
                if (l1 != nullptr) {
                    valList.push_back(l1->val);
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    valList.push_back(l2->val);
                    l2 = l2->next;
                }
            }

            const int valListSize = valList.size();
            ListNode* result = nullptr;
            if (valListSize) {
                result = new ListNode(valList[0]);
                for (int i = 1; i < valListSize; i++) {
                    addNode(result, valList[i]);    
                }
            }

            return result;
        }
};
