#include <stdio.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x)
		: val(x)
		, next(nullptr)
	{

	}
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
		ListNode* head  = nullptr;
		ListNode** node = &head;

		int l1Val = 0;
		int l2Val = 0;
		int sum   = 0;
		int token = 0;

		while (l1 != NULL || l2 != NULL)
		{
			if (l1) {
				l1Val = l1->val;
				l1 = l1->next;
			} else {
				l1Val = 0;
			}

			if (l2) {
				l2Val = l2->val;
				l2 = l2->next;
			} else {
				l2Val = 0;
			}

			sum   = l1Val + l2Val + token;
			token = sum / 10;

			ListNode* listNode = new ListNode(sum % 10);
			*node = listNode;
			node  = &(listNode->next);
		}

		if (token > 0)
		{
			ListNode* listNode = new ListNode(token);
			*node = listNode;
		}

		return head;
    }
};

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution solution;
	ListNode* ret = solution.addTwoNumbers(l1, l2);

	while (ret != nullptr)
	{
		printf("%d", ret->val);
		ret = ret->next;
	}
}