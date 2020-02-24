///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Title:            Processing log time
// Semester:         Spring 2020
// Date:             21 Feb 2020
//
// Description:
//				   	 Simple singley linked list that will hold a word and 
//					 definition. The program can search for a word a produce
//				     'auto' suggestions list of at most 10 words.
//
// Usage:
//					 #include "LinkedList.hpp"
//				   	 insert(string word, string definiton)
//      
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
using namespace std;


struct wordnode {
	std::string word;		// word
	std::string definition; // definition
	wordnode* next;			// node pointer to next
};


class MyList {
	wordnode* head;				//Head Pointer
	wordnode* current;			//Current node pointer
	wordnode* end;				//Tail node pointer
	string suggested[10];	//Stores suggested word
public:
	/**
	*	Mylist
	*
	*	Description:
	*			Constructor
	*	Params:
	*			None
	*	Returns:
	*			Void
	*/
	MyList() {
		head = NULL;
		current = head;
		end = head;
		resetsuggested();
	}
	/**
	*	Insert
	*
	*	Description:
	*			Insert item and definition into the list
	*	Params:
	*			string		w : word
	*			string		d : definition
	*	Returns:
	*			Void
	*/
	void insert(std::string w, std::string d) {
		resetcursor();
		if (head == NULL) {
			head = new wordnode;
			head->word = w;
			head->definition = d;
			end = head;
			end->next = head->next;
		}
		else {
			wordnode* temp = new wordnode;
			end->next = temp;
			temp->next = NULL;
			end = temp;
			end->word = w;
			end->definition = d;
		}
	}
	/**
	*	resetcursor
	*
	*	Description:
	*			assigns current to head
	*	Params:
	*			None
	*	Returns:
	*			Void
	*/
	void resetcursor() {
		current = head;
	}
	/**
	*	Print
	*
	*	Description:
	*			Prints list
	*	Params:
	*			None
	*	Returns:
	*			Void
	*/
	void print() {
		resetcursor();
		while (current != NULL) {
			cout << current->word;
			if (current->next == NULL) {
				return;
			}
			cout << "->";
			current = current->next;
		}
	}
	/**
	*	search
	*
	*	Description:
	*			finds all words that include a substring
	*			of passed in string
	*	Params:
	*			String		term : word tyoed by user
	*	Returns:
	*			bool		foundword : is word is found, true
	*									is returned 
	*/
	bool search(std::string term) {
		resetcursor();
		bool foundword = false;
		int count = 0;
		int i = 0;
		while (current != NULL) {
			size_t found = current->word.find(term);
			
			if (found != string::npos) {
				if (i < 10) {
					suggested[i] = current->word;
					i++;
				}
				count++;
			}
			current = current->next;
		}

		//cout << count << " words found\n";

		//printsuggested(foundword);
		resetsuggested();          
		return foundword;
	}
	bool linearsearch(std::string term) {
		while (current != NULL) {
			if (current->word != term) {
				current = current -> next;
			}
			else {
				return true;
			}
		}
		return false;
	}
	/**
	*	printsuggested
	*
	*	Description:
	*			prints suggested list
	*	Params:
	*			bool		flag : variable for emoty list
	*	Returns:
	*			Void
	*/
	void printsuggested(bool flag) {
		if (suggested[0] == "NULL99") {
			cout << "No matches found\n";
			flag = false;
			return;
		}
		for (int i = 0; i < 10; i++) {
			if (suggested[i] != "NULL99") {
				cout << suggested[i] << " ";
			}
		}
		cout << "\n";
		flag = true;
	}
	/**
	*	resetsuggested
	*
	*	Description:
	*			reset the suggested list to default
	*			values
	*	Params:
	*			None
	*	Returns:
	*			Void
	*/
	void resetsuggested() {
		for (int i = 0; i < 10; i++) {
			suggested[i] = "NULL99";
		}
	}
};