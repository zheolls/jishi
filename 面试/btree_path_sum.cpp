#include <iostream>
using namespace std;
 
typedef int Type;
struct node
{
	Type value;
	node *left;
	node *right;
};//树结点的数据结构
node* build_tree(void);
bool find(node*,int);
 
int main()
{
	node *tree = build_tree();
	int t ;
	cout<<"请输入给定的值：";
	cin>>t;
	cout<<endl;
	cout<<find(tree,t)<<endl;
	return 0;
}
node *build_tree()//递归法建树，停止条件，结点值为0
{
	Type a;
	cin>>a;
	if (a==0)
	{
		return NULL;
	}
	node *root = new node();
	root->value = a;
	root->left = build_tree();
	root->right = build_tree();
 
	cout<<"build tree success."<<endl;
	return root;
}
 
bool find(node *root,int v)
{
	if (!root)
	{
		return 0;
	}
	if (root->value==v)
	{
		return 1;
	}
	else
	{
		find(root->left,v-root->value)||find(root->right,v-root->value);
	}
}