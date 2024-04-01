#include <bits/stdc++.h>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
BiTree init_Tree(BiTree T)
{
      T = (BiTree)malloc(sizeof(struct BiTNode));
      T->data = 'A';
      T->lchild = NULL;
      T->rchild = NULL;
      return T;
}
BiTree insert_Tree_left(BiTree Tree,char ch)
{
     BiTree p = (BiTree) malloc(sizeof(struct BiTNode));
     p->lchild = NULL;
     p->rchild = NULL;
     p->data = ch;
     Tree->lchild = p;
     return p;
}
BiTree insert_Tree_right(BiTree Tree,char ch)
{
    BiTree p = (BiTree) malloc(sizeof(struct BiTNode));
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = ch;
    Tree->rchild = p;
    return p;
}
void visit(BiTree tree)
{
    cout<<tree->data;
}
void preOrder(BiTree T)
{
    visit(T);
    if(T->lchild) preOrder(T->lchild);
    if(T->rchild) preOrder(T->rchild);
    return;
}
void midOrder(BiTree T)
{
    if(T->lchild) midOrder(T->lchild);
    visit(T);
    if(T->rchild) midOrder(T->rchild);
    return;
}
void lastOrder(BiTree T)
{
    if(T->lchild) lastOrder(T->lchild);
    if(T->rchild) lastOrder(T->rchild);
    visit(T);
    return;
}
int main() 
{
    BiTree T = NULL;
    T = init_Tree(T);
    BiTree B = insert_Tree_left(T,'1');
    BiTree C = insert_Tree_right(T,'3');
    BiTree D = insert_Tree_left(B,'4');
    BiTree E = insert_Tree_right(B,'5');
    insert_Tree_right(D,'6');
    insert_Tree_left(C,'7');
    preOrder(T);cout<<endl;
    midOrder(T);cout<<endl;
    lastOrder(T);cout<<endl;
    return 0;
}
