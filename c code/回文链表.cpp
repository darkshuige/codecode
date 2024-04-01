#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool isPalindrome(ListNode* head) 
{
    if (head == NULL || head->next == NULL) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) 
	{
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *prev = NULL, *curr = slow->next;
    while (curr != NULL)
	{
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    ListNode *p1 = head, *p2 = prev;
    bool isPalin = true;
    while (p2 != NULL) 
	{
        if (p1->val != p2->val) 
		{
            isPalin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    curr = prev;
    prev = NULL;
    while (curr != NULL) 
	{
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    slow->next = prev;
    return isPalin;
}
ListNode* init() 
{
    int n, value;
    cin >> n;
    if (n <= 0) return NULL;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) 
	{
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }
    return head;
}

signed main() 
{
	int n;
	ListNode * head=init();
    cout << (isPalindrome(head) ? "true" : "false") << endl;
    while (head != NULL) 
	{
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
