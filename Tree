#include <iostream>
using namespace std;
#include <queue>
class Node
{public:
	int data;
	Node* left;
	Node* right;
	

	Node(int a)
	{
		data = a;
		left = NULL;
		right = NULL;
	}	
};

bool sNT(int a)
{
	if(a<=1) return false;
	for(unsigned int i =2; i<a; i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}

class Tree
{
	private:
		Node* root;
		
		void _preOrder(Node* temp)
		{
			if(temp==NULL)
				return;
			else
			{
				cout<<temp->data<<" ";
				_preOrder(temp->left);
				_preOrder(temp->right);
			}		
		}
		void _inOrder(Node* temp)
		{
			if(temp==NULL)
				return;
			else
			{
				_preOrder(temp->left);
				cout<<temp->data<<" ";
				_preOrder(temp->right);
			}		
		}
	public:
		Tree()
		{
			root = NULL;
		}
		void Insert(int a)
		{
			if(root== NULL)
				root = new Node(a);
			else
			{		
			queue<Node*> q;
			q.push(root);
			
			while(!q.empty())
			{
				Node* temp = q.front();
				//cout<<temp->data<<" "; 
				if((!sNT(a)) && temp->left == NULL )
				{
					temp->left = new Node(a);
					//cout<<temp->left->data<<" ";
					return;
				}
				//else q.push(root->left);
				
				if((sNT(a)) && temp->right == NULL )
				{
					temp->right = new Node(a);
					//cout<<temp->right->data<<" ";
					return;
				}
				//else q.push(root->right);
				if(sNT(a))
				{
					if(temp -> right != NULL)
					q.push(temp->right);
					if(temp -> left != NULL)
					q.push(temp->left);
				}
				else
				{
					if(temp -> left != NULL)
					q.push(temp->left);
					if(temp -> right != NULL)
					q.push(temp->right);
				}
				
				q.pop();

			}
			}
		}
		
		void preOrder()
		{
			_preOrder(root);
		}
		void inOrder()
		{
			_inOrder(root);
		}
		
		
};

int main()
{

	int n;
	cin>>n;
	Tree myTree;
	for(unsigned int i =0; i<n;i++)
	{
		int temp;
		cin>>temp;
		myTree.Insert(temp);
	}
	myTree.preOrder();cout<<endl;
	myTree.inOrder();cout<<endl;
	return 0;
}
