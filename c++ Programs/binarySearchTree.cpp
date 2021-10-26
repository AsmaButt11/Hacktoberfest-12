/*
Name: Burhan Haroon
Username: ez-sherlock
Description: C++ implementation of a Binary Search Tree
*/

#include<iostream>
#include<conio.h>
#define SPACE 10
using namespace std;
class TreeNode {
public:
	TreeNode*left;
	int value;
	TreeNode*right;
	TreeNode() {
		value = 0;
		left = NULL;
		right = NULL;
	}
	TreeNode(int v) {
		left = NULL;
		value = v;
		right = NULL;
	}
};

class BST {
public:
	TreeNode*root;
	BST() {
		root = NULL;
	}
	bool isEmpty() {
		if (root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void insertNode(TreeNode* newNode) {
		if (root == NULL) {
			root = newNode;
			cout << "Value inserted as root node!" << endl;
		}
		else {
			TreeNode*temp = root;
			while (temp != NULL) {
				if (newNode->value == temp->value) {
					cout << "Can't insert duplicate values in BST";
					return;
				}
				else if (newNode->value < temp->value && temp->left == NULL) {
					temp->left = newNode;
					cout << "Value Inserted to the left";
					break;
				}
				else if (newNode->value < temp->value) {
					temp = temp->left;
				}

				else if ((newNode->value > temp->value) && (temp->right == NULL)) {
					temp->right = newNode;
					cout << "Value Inserted to the right";
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}

	void print2D(TreeNode*r, int space) {
		if (r == NULL)				// Base Case
			return;
		space += SPACE;				// Increse distance between levels
		print2D(r->right, space);	// Process right Child first
		cout << endl;
		for (int i = SPACE; i < space; i++)	//Print current Node after space count
			cout << " ";
		cout << r->value << "\n";
		print2D(r->left, space);	// Process Left Child
	}

	void preOrder(TreeNode*node) {
		if (node == NULL) {
			return;
		}
		else {
			cout << node->value << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	TreeNode* minValue(TreeNode*node) {
		TreeNode*current = node;
		// We are equating another node to the given node beacuse we dont want to change the value of the given node
		while (current->left!=NULL)
		{
			current = current->left;
		}
		return current;	// This will return the node having the minimum value.
	}

	void maxValue(TreeNode*newNode) {
		TreeNode*temp = root;
		while (temp->right != NULL) {
			temp = temp->right;
		}
		cout << "The maximum value is: " << temp->value << endl;

	}

	TreeNode* search(int value) {
		if (isEmpty()) {
			return root;
		}
		else {
			TreeNode*temp = root;
			while (temp != NULL)
			{
				if (temp->value == value)
					return temp;

				else if (value < temp->value)
					temp = temp->left;
				else
					temp = temp->right;
			}
		}
		return NULL;
	}

	TreeNode*deleteNode(TreeNode*node, int value) {
		if (node == NULL) {
			return NULL;
		}

		/*If the value to be deleted is smaller than the *ndoe's value,
		Then move the node to its left node*/

		else if (value < node->value) {
			node->left = deleteNode(node->left, value);
		}

		/*If the value to be deleted is greater than the *ndoe's value,
		Then move the node to its right node*/

		else if (value > node->value) {
			node->right = deleteNode(node->right, value);
		}
		else	// If the values are found!
		{
			if (node->left == NULL) {
				TreeNode*temp = node->right;
				delete node;
				return temp;
			}
			if (node->right == NULL) {
				TreeNode*temp = node->left;
				delete node;
				return temp;
			}
			else {
				// Node with the 2 children replcae the value of the (minNode) with the parent node!
				TreeNode*temp = minValue(node->right);
				// Copy the successor's content to the parent node!
				node->value = temp->value;
				// Delete the successor!
				node->right = deleteNode(node->right, temp->value);
			}
		}
		return node;
	}

};

int main() {
	BST obj;
	int option, val;

	do
	{
		cout << "What operation do you want to perform?"
			<< "Select Option number or press 0 to exit" << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Search Node" << endl;
		cout << "3. Delete Node" << endl;
		cout << "4. Print BST values" << endl;
		cout << "5. Maximum and Minimum value in the BST?" << endl;
		cout << "6. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		TreeNode*newNode = new TreeNode();
		switch (option) {
		case 0:
			break;
		case 1:
			system("CLS");
			cout << "ISNERT" << endl;
			cout << "Enter the value to insert in BST: ";
			cin >> val;
			newNode->value = val;
			obj.insertNode(newNode);
			cout << endl;
			break;
		case 2:
			cout << "SEARCH" << endl;
			cout << "Enter Value to SEARCH in BST: ";
			cin >> val;
			newNode = obj.search(val);
			if (newNode != NULL) {
				cout << "Value Found" << endl;
			}
			else {
				cout << "Value NOT Found" << endl;
			}
			cout << endl;
			obj.maxValue(newNode);
			break;
		case 3:
			cout << "DELETE" << endl;
			cout << "Enter the value to be DELETED from the BST: ";
			cin >> val;
			newNode = obj.search(val);
			if (newNode != NULL) {
				obj.deleteNode(obj.root, val);
				cout << "Value Deleted" << endl;
			}
			else {
				cout << "Value not found" << endl;
			}
			break;
		case 4:
			cout << "PRINT" << endl;
			obj.print2D(obj.root, 5);
			obj.preOrder(obj.root);
			break;
		case 5:
			obj.maxValue(obj.root);

			break;
		case 6:
			system("CLS");
			break;
		case 7:
			obj.preOrder(obj.root);
			break;
		default:
			cout << "Enter proper option number!";
		}



	} while (option != 0);
	
	return 0;
}