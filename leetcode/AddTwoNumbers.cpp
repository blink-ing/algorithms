class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int sum = 0;
       int carry = 0;
       ListNode* result = nullptr;
       ListNode* nextNode = nullptr;
       while ((l1 != nullptr || l2 != nullptr) || carry > 0 ) {
       	int num1 = 0, num2 = 0;
       	if (l1 != nullptr) {
       		num1 = l1->val;
       		l1 = l1->next;
       	}
       	
       	if (l2 != nullptr) {
       		num2 = l2->val;
       		l2 = l2->next;
       	}
       	
       	sum = (num1 + num2 + carry) % 10;
       	carry = (num1 + num2 + carry >= 10) ? 1 : 0;
       	
       	if (result == nullptr) {
	        	result = new ListNode(sum);
	        	nextNode = result;
	        }
	        else {
				nextNode->next = new ListNode(sum);
				nextNode = nextNode->next;
	        }
       }
       return result;
   }
};
