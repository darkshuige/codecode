#include <bits/stdc++.h>
using namespace std;
struct node
{
	char date;
	node *l,*r;
};
node *creat()
{
	node *t=new node;
	char c;
	cin>>c;
	if(c=='#')
	 t=NULL;
	else
	{
		t->date=c;
		t->l=creat();
		t->r=creat();
	}
	return t;
}
void post(node *root)
{
	if(root)
	{
		post(root->l);
		post(root->r);
		cout<<root->date;
	}
}
int main()
{
    node *root=creat();
    post(root);
    return 0;
}
