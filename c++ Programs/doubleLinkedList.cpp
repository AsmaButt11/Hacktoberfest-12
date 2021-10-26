/*
Name: Burhan Haroon
Username: ez-sherlock
Description: C++ implementation of a Double Linked List
*/

#include<iostream>
using namespace std;
class DNode {
private:
public:
	DNode*next;
	int value;
	DNode*pre;
};
class DList {
private:
	DNode*head;
	DNode*tail;
public:
	DList() {
		head = new DNode();
		tail = new DNode();
		head->next = tail;
		tail->pre = head;
	}
	void insertInEmptyList(DNode*newNode) {
		if (head->next == tail) {				
			newNode->next = tail;
			newNode->pre = head;
			head->next = newNode;
			tail->pre = newNode;
		}
	}
	DNode* insertAtStart(int x) {
		DNode*newNode = new DNode();
		newNode->value = x;
		newNode->next = head->next;
		newNode->pre = head;
		head->next = newNode;
		newNode->next->pre = newNode;
		//cout << newNode;
		return newNode;
	}
	DNode* insertAtMiddle(int x, int index) {
		DNode*currNode = head->next;
		DNode*newNode = new DNode();
		int currIndex = 0;
		while (currNode->next != tail && currIndex != index - 1)
		{
			currNode = currNode->next;
			currIndex++;
		}
		if (currIndex == (index - 1)) {
			newNode->value = x;
			newNode->next = currNode->next;
			newNode->pre = currNode;
			currNode->next->pre = newNode;
			currNode->next = newNode;

			return newNode;
		}
	}
	DNode* insertBeforeAValue(int x, int y) {
		DNode*currNode = head;
		DNode*prevNode = NULL;
		while (currNode->next != tail && currNode->value != y) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		DNode*newNode = new DNode();
		newNode->value = x;
		prevNode->next = newNode;
		newNode->pre = prevNode;
		newNode->next = currNode;
		currNode->pre = newNode;
		return newNode;
	}

	DNode* insertAtTail(int x) {
		DNode*currNode = head;
		while (currNode->next!=tail)
		{
			currNode = currNode->next;
		}
		DNode*newNode = new DNode();
		newNode->value = x;
		newNode->next = currNode->next;
		newNode->pre = currNode;
		currNode->next->pre = newNode;
		currNode->next = newNode;
		return newNode;
	}
	void displayList(DNode*node) {
		cout << "Displaying List:\n";
		DNode*newNode = node;
		newNode = head->next;
		int currIndex = 0;
		while (newNode->next != NULL)
		{
			cout << newNode->value << endl;
			newNode = newNode->next;
			currIndex++;
		}
		cout << "The total number of elements in the List are: " << currIndex << endl;
	}
	void removeAllButKey(int key){
		cout << "\nDeleting every element in the List except " << key << "\n\n";
		DNode*currNode = head->next;
		do
		{
			if (currNode->value != key) {
				DNode*temp = currNode;
				temp->next->pre = temp->pre;
				temp->pre->next = temp->next;
				currNode = currNode->next;
				delete temp;
			}
			else
			{
				currNode = currNode->next;
			}
		} while (currNode != tail);
	}
	DNode* concatenate(int val1, int val2) {
		DNode*currNode = head;
		DNode*newNode = new DNode;
		while (currNode->next != tail) {
			currNode = currNode->next;
		}
		if (currNode->next==tail)
		{
			newNode->value = val2;
			newNode->next = currNode->next;
			newNode->pre = currNode;
			currNode->next->pre = newNode;
			currNode->next = newNode;
			return newNode;
		}
	}
};

int main() {
	DList d1;
	int option, val;
	do
	{
		cout << "What operation do you want to perform?"
			<< "Select Option number or press 0 to exit" << endl;
		cout << "1. Insert Node in an Empty List" << endl;
		cout << "2. Display All Values" << endl;

		cin >> option;
		DNode*newNode = new DNode();
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "ISNERT" << endl;
			cout << "Enter the value to be inserted in the List: ";
			cin >> val;
			newNode->value = val;
			d1.insertInEmptyList(newNode);
			cout << endl;
			break;
		case 2:
			cout << "PRINT"<<endl;
			d1.displayList(newNode);
		default:
			cout << "Enter proper option number!";
		}
	} while (option!=0);

	return 0;
}