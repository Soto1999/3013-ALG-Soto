/////////////////////////////////////////////////////////////////////
//
// Author:			Jose Soto
// Email:			josesoto56@icloud.com
// Label:			02
// Title:			Commented Code
// Course:			3013 ALG
// Semester:		Spring 2020
//
// Description:
//			This program will push values into two different list.
//			Addition will be performed by combining the elements from
//			both list into one. Overloaded functions can be used to out-
//			put the contents of any list.
//
// Usage:
//
// Files:
//		A02-CommentedCode.cpp			: driver program
//////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int A[100];
/** 
* Node
*
* Description:
*		This struct holds a pointer with a value.
*
* Public Methods:
*						Node()
*
* Private Methods:
*						None
* Usage:
*     *Usage through list*
*/
struct Node {
	int x;			//Value to that is contained within node
	Node* next;		//Node pointer to next node
	Node() {
		x = -1;
		next = NULL;
	}
	Node(int n) {
		x = n;
		next = NULL;
	}
};

/**
* List
*
* Description:
*		This class hold a node. Two special nodes, Head and Tail, are
*		created to keep track of both ends of the list. The list can
*		remove, instert, traverse, and give imediate feedback on the 
*		status of the class.
*
* Public Methods:
*						List()
*		void			Push(int val)
*		void			Insert(int val)
*		void			PrintTail()
*		string			Print()
*		int				Pop()
*		List			operator+(List&)
*		int				operator[](int)
*		ostream			operator<<(ostream& os, List L)
*		
* Private Methods:
*						None
* Usage:
*     *Usage through list*
*/
class List {
private:
	Node* Head;		//Node at the front of the list
	Node* Tail;		//Node at the tail of the list
	int Size;		//Size of the list

public:
	List() {
		Head = Tail = NULL;
		Size = 0;
	}

	/**
		* Public : Push
		*
		* Description:
		*		Adds node to linked list.
		*
		* Params:
		*	int		: value to be inserted
		*
		* Returns:
		*		Nothing
	*/
	void Push(int val) {
		// allocate new memory and init node
		Node* Temp = new Node(val);

		if (!Head && !Tail) {
			Head = Tail = Temp;
		}
		else {
			Tail->next = Temp;
			Tail = Temp;
		}
		Size++;
	}
	
	/**
		* Public : Insert
		*
		* Description:
		*		Adds node to linked list.
		*
		* Params:
		*	int		: value to be inserted
		*
		* Returns:
		*		Nothing
	*/
	void Insert(int val) {
		// allocate new memory and init node
		Node* Temp = new Node(val);

		// figure out where it goes in the list

		Temp->next = Head;
		Head = Temp;
		if (!Tail) {
			Tail = Head;
		}
		Size++;
	}

	/**
		* Public : PrintTali
		*
		* Description:
		*		Prints last node in list
		*
		* Params:
		*		No params
		*
		* Returns:
		*		Nothing
	*/
	void PrintTail() {
		cout << Tail->x << endl;
	}

	/**
		* Public : Print
		*
		* Description:
		*		Prints entire list
		*
		* Params:
		*		No params
		*
		* Returns:
		*		Nothing
	*/
	string Print() {
		Node* Temp = Head;
		string list;

		while (Temp != NULL) {
			list += to_string(Temp->x) + "->";
			Temp = Temp->next;
		}

		return list;
	}

	/**
		* Public : Pop
		*
		* Description:
		*		Will remove a node from the list
		*
		* Params:
		*		No params
		*
		* Returns:
		*		0

	*/
	// not implemented
	int Pop() {
		Size--;
		return 0; //
	}
	
	/**
		* Public : operator+
		*
		* Description:
		*		Adds the nodes of two list together
		*
		* Params:
		*		List&		: List by reference
		*
		* Returns:
		*		List		: List that contains both
		*					  list					
	*/
	List operator+(const List& Rhs) {
		// Create a new list that will contain both when done
		List NewList;

		// Get a reference to beginning of local list
		Node* Temp = Head;

		// Loop through local list and Push values onto new list
		while (Temp != NULL) {
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Get a reference to head of Rhs
		Temp = Rhs.Head;

		// Same as above, loop and push
		while (Temp != NULL) {
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Return new concatenated version of lists
		return NewList;
	}

	/**
		* Public : Operator[]
		*
		* Description:
		*		Retutns a value of a node from a 
		*		specific position
		*
		* Params:
		*		int			: position in the list
		*
		* Returns:
		*		int			: value of the selected node
	*/
	// Implementation of [] operator.  This function returns an
	// int value as if the list were an array.
	int operator[](int index) {
		Node* Temp = Head;

		if (index >= Size) {
			cout << "Index out of bounds, exiting";
			exit(0);
		}
		else {

			for (int i = 0; i < index; i++) {
				Temp = Temp->next;
			}
			return Temp->x;
		}
	}
	/**
		* Public : operator<<
		*
		* Description:
		*		Will display the contents of the all nodes
		*		within the list, os is a friend of L
		*
		* Params:
		*		ostream&		: streaming variable
		*		list			: list instance
		* Returns:
		*		ostream&		: streaming variable
		*
	*/
	friend ostream& operator<<(ostream& os, List L) {
		os << L.Print();
		return os;
	}
};

int main(int argc, char** argv) {
	List L1;	//Instance of List 1
	List L2;	//Instance of List 2

	for (int i = 0; i < 25; i++) {
		L1.Push(i);
	}

	for (int i = 50; i < 100; i++) {
		L2.Push(i);
	}

	//cout << L1 << endl;
	L1.PrintTail();
	L2.PrintTail();

	List L3 = L1 + L2;
	cout << L3 << endl;

	cout << L3[5] << endl;
	return 0;
}