//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream> 

using namespace std;

//Definition of the Node
template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType> *lLink;
	binaryTreeNode<elemType> *rLink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=
		(const binaryTreeType<elemType>&);
	//Overload the assignment operator.

	bool isEmpty() const;
	//Function to determine whether the binary tree is empty.
	//Postcondition: Returns true if the binary tree is empty;
	//               otherwise, returns false.

	void inorderTraversal() const;
	//Function to do an inorder traversal of the binary tree.
	//Postcondition: Nodes are printed in inorder sequence.

	void preorderTraversal() const;
	//Function to do a preorder traversal of the binary tree.
	//Postcondition: Nodes are printed in preorder sequence.

	void postorderTraversal() const;
	//Function to do a postorder traversal of the binary tree.
	//Postcondition: Nodes are printed in postorder sequence.

	int treeHeight() const;
	//Function to determine the height of a binary tree.
	//Postcondition: Returns the height of the binary tree.

	int treeNodeCount() const;
	//Function to determine the number of nodes in a 
	//binary tree.
	//Postcondition: Returns the number of nodes in the 
	//               binary tree.

	int treeLeavesCount() const;
	//Function to determine the number of leaves in a 
	//binary tree.
	//Postcondition: Returns the number of leaves in the 
	//               binary tree.

	void destroyTree();
	//Function to destroy the binary tree.
	//Postcondition: Memory space occupied by each node 
	//               is deallocated.
	//               root = NULL;

	virtual bool search(const elemType& searchItem) const = 0;
	//Function to determine if searchItem is in the binary 
	//tree.
	//Postcondition: Returns true if searchItem is found in 
	//               the binary tree; otherwise, returns 
	//               false.

	virtual void insert(const elemType& insertItem) = 0;
	//Function to insert insertItem in the binary tree.
	//Postcondition: If there is no node in the binary tree
	//               that has the same info as insertItem, a
	//               node with the info insertItem is created
	//               and inserted in the binary search tree.

	virtual void deleteNode(const elemType& deleteItem) = 0;
	//Function to delete deleteItem from the binary tree 
	//Postcondition: If a node with the same info as 
	//               deleteItem is found, it is deleted from
	//               the binary tree.
	//               If the binary tree is empty or 
	//               deleteItem is not in the binary tree, 
	//               an appropriate message is printed.

	
	int singleParentCount();	int singleParent(binaryTreeNode<elemType> *p, int &c);	int doubleParent(binaryTreeNode<elemType> *p, int &c);	int doubleParentCount();

	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	//Copy constructor

	binaryTreeType();
	//Default constructor

	~binaryTreeType();
	//Destructor

protected:
	binaryTreeNode<elemType>  *root;
	

private:
	int c;

	void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
		binaryTreeNode<elemType>* otherTreeRoot);
	//Makes a copy of the binary tree to which 
	//otherTreeRoot points. 
	//Postcondition: The pointer copiedTreeRoot points to
	//               the root of the copied binary tree.

	void destroy(binaryTreeNode<elemType>* &p);
	//Function to destroy the binary tree to which p points. 
	//Postcondition: Memory space occupied by each node, in 
	//               the binary tree to which p points, is 
	//               deallocated.
	//               p = NULL;

	void inorder(binaryTreeNode<elemType> *p) const;
	//Function to do an inorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in inorder sequence.

	void preorder(binaryTreeNode<elemType> *p) const;
	//Function to do a preorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in preorder 
	//               sequence.

	void postorder(binaryTreeNode<elemType> *p) const;
	//Function to do a postorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in postorder 
	//               sequence.

	int height(binaryTreeNode<elemType> *p) const;
	//Function to determine the height of the binary tree
	//to which p points. 
	//Postcondition: Height of the binary tree to which 
	//               p points is returned.

	int max(int x, int y) const;
	//Function to determine the larger of x and y.
	//Postcondition: Returns the larger of x and y.

	int nodeCount(binaryTreeNode<elemType> *p) const;
	//Function to determine the number of nodes in 
	//the binary tree to which p points. 
	//Postcondition: The number of nodes in the binary 
	//               tree to which p points is returned.

	int leavesCount(binaryTreeNode<elemType> *p) const;
	//Function to determine the number of leaves in  
	//the binary tree to which p points 
	//Postcondition: The number of leaves in the binary 
	//               tree to which p points is returned.
};

//Definition of member functions







////////HOMEWORK

template <class elemType>
int binaryTreeType<elemType>::doubleParent(binaryTreeNode<elemType> *p, int &c)
{
	if(p->rLink != NULL && p->lLink != NULL)
	{
		c++;
		doubleParent(p->lLink, c);
		doubleParent(p->rLink, c);
	}
	else if(p->rLink != NULL && p->lLink == NULL)
	{
		
		doubleParent(p->rLink,c);
	}
	else if(p->rLink == NULL && p->lLink != NULL)
	{
		
		doubleParent(p->lLink,c);
	}
	return c;
}

template <class elemType>
int binaryTreeType<elemType>::doubleParentCount()
{
	c = 0;
	return	doubleParent(root,c);
}

template <class elemType>
int binaryTreeType<elemType>::singleParent(binaryTreeNode<elemType> *p, int &c)
{
		
	if(p->rLink != NULL && p->lLink != NULL)
	{
		singleParent(p->lLink, c);
		singleParent(p->rLink, c);
	}
	else if(p->rLink != NULL && p->lLink == NULL)
	{
		c++;
		singleParent(p->rLink,c);
	}
	else if(p->rLink == NULL && p->lLink != NULL)
	{
		c++;
		singleParent(p->lLink,c);
	}
	return c;
}

template <class elemType>
int binaryTreeType<elemType>::singleParentCount()
{
	c = 0;
	return singleParent(root, c);
}


////// END OF HOMEWORK








template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
(binaryTreeNode<elemType>* &copiedTreeRoot,
binaryTreeNode<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder
(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder
(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder
(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->lLink);
		postorder(p->rLink);
		cout << p->info << " ";
	}
}

//Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL)   //if the binary tree is not empty,
			//destroy the binary tree
			destroy(root);

		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else

	return *this;
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

//Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height
(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->lLink == NULL && p->rLink == NULL)
		return 1;
	else
		return leavesCount(p->lLink) + leavesCount(p->rLink);
}

#endif