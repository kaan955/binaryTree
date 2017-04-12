
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	bSearchTreeType<int> tree1;
	bSearchTreeType<int> tree2;

	int arr[10] = { 50, 30, 83, 14, 41, 57, 104, 38, 44, 5 };

	for (int i = 0; i < 10; i++)
		tree1.insert(arr[i]);

	tree2 = tree1;

	cout << "Height of Tree1: " << tree1.treeHeight() << endl;

	cout << endl;

	cout << "Preorder Traversal: ";
	tree1.preorderTraversal();
	cout << endl;

	cout << "Postorder Traversal: ";
	tree1.postorderTraversal();
	cout << endl;

	cout << "Inorder Traversal: ";
	tree1.inorderTraversal();
	cout << endl;

	cout << endl;

	tree2.insert(47);
	cout << "Height of Tree2: " << tree2.treeHeight() << endl;

	cout << "Number of nodes in Tree1: " << tree1.treeNodeCount() << endl;
	cout << "Number of nodes in Tree2: " << tree2.treeNodeCount() << endl;

	cout << endl;

	cout << "Number of leaves in Tree1: " << tree1.treeLeavesCount() << endl;
	cout << "Number of leaves in Tree2: " << tree2.treeLeavesCount() << endl;


	/// HOMEWORK TEST SECTİON

	tree1.insert(11);
	tree1.insert(4);
	cout << "single parent sayisi for tree1 " << tree1.singleParentCount() << endl;
	cout << "double parent sayisi for tree1 "  << tree1.doubleParentCount() << endl;


	cout << "single parent sayisi for tree2 " << tree2.singleParentCount() << endl;
	cout << "double parent sayisi for tree2 "  << tree2.doubleParentCount() << endl;

	/// END OF HOMEWORK TEST SECTION


	system("PAUSE");
	return 0;
}