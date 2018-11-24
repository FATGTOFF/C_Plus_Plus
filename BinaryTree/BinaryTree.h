#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T value;	//value in the node
		TreeNode *left;	//pointer to left child node
		TreeNode *right;	//pointer to right child node
	};

	TreeNode *root;	//pointer to the root node

	//private member functions
	void insertNode(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	int treeSize(TreeNode *) const;
	int countLeafNodes(TreeNode *) const;
	int treeHeight(TreeNode *) const;

public:
	//constructor
	BinaryTree();

	//destructor
	~BinaryTree();

	//binary tree operations
	void insertNode(T);
	bool searchNode(T);
	void remove(T);	
	void displayInOrder() const;
	void displayPreOrder() const;
	void displayPostOrder() const;
	int treeSize() const;
	int countLeafNodes() const;
	int treeHeight() const;
};

//**************************************
//private member functions             *
//**************************************

//private function to insert a Node
template<class T>
void BinaryTree<T>::insertNode(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;	//insert the node
	else if (newNode->value < nodePtr->value)
		insertNode(nodePtr->left, newNode);	//serach the left branch
	else
		insertNode(nodePtr->right, newNode);	//search the right branch
}

//private function to destroy subTree
template<class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//private function to delete a node
template<class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//private function makeDeletion takes a reference to a pointer to the node
//that is to be deleted; the node is removed and the branches of the tree below the
//node are reattached
template<class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	//define a temp pointer to use in reattaching the left subtree
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		std::cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;	//reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;	//reattach the right child
		delete tempNodePtr;
	}
	//if the node has two children
	else
	{
		//move one node to the right
		tempNodePtr = nodePtr->right;
		//go to the end left node
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		//reattach the left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		//reattach the right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//private function to display tree in order
template<class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		std::cout << nodePtr->value << std::endl;
		displayInOrder(nodePtr->right);
	}
}

//private function to display the tree in pre order
template<class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->value << std::endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//private function to display the tree in post order
template<class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->value << std::endl;
	}
}

//private function to count all nodes
template<class T>
int BinaryTree<T>::treeSize(TreeNode *nodePtr) const
{
	int count{ 1 }; //count the root first as	1

	if (nodePtr->left != nullptr)
	{
		count += treeSize(nodePtr->left);
	}
	if (nodePtr->right != nullptr)
	{
		count += treeSize(nodePtr->right);
	}

	return count;
}

//private function to count leaf nodes
template<class T>
int BinaryTree<T>::countLeafNodes(TreeNode *nodePtr) const
{
	if (!nodePtr)
		return 0;
	
	if (!nodePtr->left && !nodePtr->right)
		return 1;
	else
		return (countLeafNodes(nodePtr->left) + countLeafNodes(nodePtr->right));
}

//private function to count tree size
template<class T>
int BinaryTree<T>::treeHeight(TreeNode *nodePtr) const
{
	int left{ 0 };
	int right{ 0 };

	if (!nodePtr)
		return 0;
	
	left = treeHeight(nodePtr->left);
	right = treeHeight(nodePtr->right);

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

//**********************
//constructor          *
//**********************
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

//************************
//destructor             *
//************************
template<class T>
BinaryTree<T>::~BinaryTree()
{
	destroySubTree(root);
}

//*******************************
//public functions              *
//*******************************

//public function to insert a node
template<class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode *newNode = nullptr;	//pointer to a new node
								
	newNode = new TreeNode;	//create a new node and store val in it
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	//insert the node
	insertNode(root, newNode);
}

//public function to search a node
template<class T>
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
		{
			std::cout << "\n" << nodePtr->value << std::endl;
			return true;
		}
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	
	return false;
}

//public function to remove a node
template<class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

//public function to display in order
template<class T>
void BinaryTree<T>::displayInOrder() const
{
	displayInOrder(root);
}

//public function to display in pre order
template<class T>
void BinaryTree<T>::displayPreOrder() const
{
	displayPreOrder(root);
}

//public function to display in post order
template<class T>
void BinaryTree<T>::displayPostOrder() const
{
	displayPostOrder(root);
}

//public function to count all nodes
template<class T>
int BinaryTree<T>::treeSize() const
{
	return treeSize(root);
}

//public functon to count all leaf nodes
template<class T>
int BinaryTree<T>::countLeafNodes() const
{
	return countLeafNodes(root);
}

//public function to display the tree height
template<class T>
int BinaryTree<T>::treeHeight() const
{
	return treeHeight(root);
}
#endif
