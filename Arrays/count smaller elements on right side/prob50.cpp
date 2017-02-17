#include<iostream>
using namespace std;

struct tree{
	int key,height,size;
	struct tree *left,*right;
};

class avl_trees
{
        private:
                int size1;
                int *arr,*countsmaller;
	public:
                void get()
              {
                cout<<"Enter the array size"<<endl;
                cin>>size1;
                arr=new int[size1];
                countsmaller=new int[size1];
                cout<<"Enter the values"<<endl;
                for(int i=0;i<size1;i++)
                cin>>arr[i];
              }
		tree *new_node(int );
		tree *insert(tree *,int,int *);
		int height(tree *);
                int size(tree *);
		tree *ll(tree *);
		tree *rr(tree *);
		//void inorder(tree *);
		int get_difference(tree *);
                void count_smaller();
                void display()
             {
                cout<<"The required array is:"<<endl;
                for(int i=0;i<size1;i++)
                cout<<countsmaller[i]<<" ";
             }
};

int avl_trees::height(tree *root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;
}

int avl_trees::size(tree *root)
{
        if(root==NULL)
                return 0;
        else
                return root->size;
}

tree *avl_trees::new_node(int val)
{
	tree *node=new tree;
	node->key=val;
	node->left=node->right=NULL;
	node->height=1;
        node->size=1;
	return node;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

tree *avl_trees::rr(tree *root)
{
	tree *x=root->left;
	tree *y=x->right;

	x->right=root;
	root->left=y;

	root->height=1+max(height(root->left),height(root->right));
	x->height=1+max(height(x->left),height(x->right));

        root->size=1+size(root->left)+size(root->right);
        x->size=1+size(x->left)+size(x->right);
	return x;
}

tree *avl_trees::ll(tree *root)
{
	tree *x=root->right;
	tree *y=x->left;

	x->left=root;
	root->right=y;

	root->height=1+max(height(root->left),height(root->right));
	x->height=1+max(height(x->left),height(x->right));

        root->size=1+size(root->left)+size(root->right);
        x->size=1+size(x->left)+size(x->right);
	return x;
}

int avl_trees::get_difference(tree *root)
{
	if(root==NULL)
		return 0;
	else
		return height(root->left)-height(root->right);
}

tree *avl_trees::insert(tree *root,int key,int *count)
{
	int diff;
	if(root==NULL)
		return (new_node(key));
	else if(key>root->key)
        {
                *count=*count+size(root->left)+1;
		root->right=insert(root->right,key,count);
        }
	else
		root->left=insert(root->left,key,count);

	root->height=1+max(height(root->left),height(root->right));
        root->size=1+size(root->left)+size(root->right);
	diff=get_difference(root);
	if(diff>1)
	{
		if(key<root->left->key)
			return rr(root);
		else
		{
			root->left=ll(root->left);
			return rr(root);
		}
	}
	else if(diff<-1)
	{
		if(key>root->right->key)
			return ll(root);
		else
		{
			root->right=rr(root->right);
			return ll(root);
		}
	}
	return root;
}

void avl_trees::count_smaller()
{
int i;
tree *root=NULL;
for(i=0;i<size1;i++)
countsmaller[i]=0;
for(i=size1-1;i>=0;i--)
{
root=insert(root,arr[i],&countsmaller[i]);
}
}

int main(void)
{
	avl_trees avl;
        avl.get();
        avl.count_smaller();
        avl.display();
}
