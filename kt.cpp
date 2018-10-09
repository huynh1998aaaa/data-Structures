#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a)
    {
        val= a;
        left = NULL;
        right= NULL;
    }
};
bool ktsnt(int a)
{
	if(a<2)
		return false;
	else{

		for(int i=0;i<a;i++)
		{
			if(a%i==0)
			return false;
		}
	}
	return true;
}

class tree
{
private:
	TreeNode* root;
public:
	tree();
	void insert(int value)
	{
		if(this->root==NULL)
		{
			root=new TreeNode(value);
			return;
		}
		else
		{
			queue<TreeNode*> q;
			q.push(root);
				while(!q.empty())
				{
					TreeNode* temp=q.front();
					if(temp->right==NULL && ktsnt(value)==true)
					{
						temp->right= new TreeNode(value);
						return;
					}
					else
						q.push(temp->right);
					if(temp->left==NULL && ktsnt(value)==false)
					{
						temp->left=new TreeNode(value);
						return;
					}
					else
						q.push(temp->left);
					q.pop();
				}

		}
	}
	void  Preorder(TreeNode* root1)
    {
        if(root1== NULL)
        return;
        else
        {
            cout<<root1->val<<endl;
            Preorder(root1->left);
            Preorder(root1->right);
        }
    }
	
};

int main(int argc, char const *argv[])
{
    tree myTree;
    int n, val;
    cout<<"Nhap n : ";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>> val;
        myTree.insert(val);
    }
    myTree.Preorder();
    return 0;
}


