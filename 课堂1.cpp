#include <iostream>
using namespace std;

struct node 
{
    int val;
    struct node* ne;
    node(int v) : val(v), ne(NULL) {}
};
node* del(node* head, int v) 
{
    node* p = head->ne;
    while (p != NULL && p->val == v)
        p = p->ne;
    head->ne = p;
    while (p != NULL) 
	{
        node* pp = p->ne;
        if (pp != NULL && pp->val == v) 
		{
            if (pp->ne != NULL)
                p->ne = pp->ne;
            else
                p->ne = NULL;
        }
        p = p->ne;
    }
    return head;
}
void add(node* head, node* kk) 
{
    while (head->ne != NULL)
        head = head->ne;
    head->ne = kk;
}
int main() 
{
    node* head = new node(-1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
	{
        int x;
        cin >> x;
        node* kk = new node(x);
        add(head, kk);
    }
    int vv;
    cin >> vv;
    del(head, vv);
    node* p = head->ne;
    while (p != NULL) 
	{
        cout << p->val << endl;
        p = p->ne;
    }
    return 0;
}
