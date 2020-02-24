///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Title:            Processing linear time
// Semester:         Spring 2020
// Date:             24 Feb 2020
//
// Description:
//					 This program will read in a json dictionary, store it in a
//					 linked list and array and produce suggestions based on user input.
//					 The program will also time how long it takes to load 
//					 the dictionary and produce the auto suggestions for both a linear
//					 and bianry search.
//      
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp"           
#include "LinkedList.hpp"
#include "mygetch.hpp"
#include "ArrayBinarySearch.hpp"
#include <iomanip>
using namespace std;

void defaulttable(ofstream&);
void binarysearch(Dictionary*, string, JsonFacade&);
void findother(int&, int, string, JsonFacade&, Dictionary*);

int main() {
	Timer T;							// instance of timer
	MyList Test;						// instance of list
	Dictionary D;					    // instance of dictionary

	char k;								// holder for character being typed
	string word = "";					// var to concatenate letters to
	string foundword = "";				// word that matches the list
	string key;							// key variable to access json object
	string def;							// definition included with word
	bool found = true;					// variable that will control main loop
	double s;							// variable to hold seconds
	double m;							// variable to hold milliseconds
	float temp;							// varibale to hold milliseconds/1000
	double linkedaverage = 0;			// total time for all searches of linked list
	double ArrayAverage = 0;			// total time for all searches of array
	int count = 0;						// counts everytime a new word is searche for;
	ifstream infile;					// infile variable
	ofstream outfile;					// outfile vairable

	infile.open("lookups.txt");			// opens file to read in terms
	outfile.open("output.dat");			// opens file to put table into

	JsonFacade J("dict_w_defs.json");				  // create instance of json class
	vector<string> keys = J.getKeys();				  // vector to store json objects
	Dictionary* list = new Dictionary[keys.size()];	  // array of Dectionaries
	
	defaulttable(outfile);

	T.Start();
	for (int i = 0; i < keys.size(); i++) {
		key = J.getKey(i);				// gets term
		def = J.getValue(key);			// gets corresponding definition
		Test.insert(key, def);			// inserting key and definition into list
	}
	T.End();
	m = T.MilliSeconds();
	outfile << "Load Time   " << m << " ms    ";
	
	T.Start();
	for (int i = 0; i < keys.size()-1; i++) {
		key = J.getKey(i);
		def = J.getValue(key);
		list[i].insertinfo(key, def);
	}
	T.End();
	m = T.MilliSeconds();
	outfile << m<< " ms\n";
	
	
	// Timiing how long to produce each suggestion
	while (!infile.eof()) {
		infile >> word;

		// Time during the linked list search
		T.Start();
		found = Test.search(word);
		T.End();

		// Convert to seconds
		m = T.MilliSeconds();
		temp = m / 1000;
		linkedaverage += temp;

		outfile << setw(12) << left << word << setw(5) << setprecision(3) << temp << " s";

		// Time for bianry search
		T.Start();
		binarysearch(list,word, J);
		T.End();

		// Convert to seconds
		m = T.MilliSeconds();
		temp = m / 1000;
		ArrayAverage += temp;

		outfile << "    " << fixed << setprecision(3) <<  temp << " s\n";

		count++;
	}
	linkedaverage = linkedaverage / count;
	ArrayAverage = ArrayAverage / count;
	outfile << left << "AVERAGE     " << setprecision(3)<< linkedaverage << " s    " << ArrayAverage << " s\n";

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
/**
	*	defaulttable
	*
	*	Description:
	*			prints out table for output
	*	Params:
	*			ofstream&		outfile : streaming variable
	*	Returns:
	*			Void
	*/
void defaulttable(ofstream& outfile) {
		outfile << "Jose Soto\n";
		outfile << "Program 3\n\n";
		outfile << "Key         List          Array\n";
		outfile << "==================================\n";
}
/**
	*	binarysearch
	*
	*	Description:
	*			finds the key in an array by using binary
	*			search technique
	*	Params:
	*			Dicionary*		A : pointer to array of Dictionaries
	*			string		 term : key word to find
	*			JsonFacade&		J : reference to array of Json objects
	*	Returns:
	*			Void
	*/
void binarysearch(Dictionary* A, string term, JsonFacade& J) {
	int l, r, m;
	int foundwords = 0;
	bool found;
	l = 0;
	r = J.getSize() - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (A[l].getword() == term) {
			findother(foundwords, l, term, J, A);
			return;
		}
		if (A[r].getword() == term) {
			findother(foundwords, r, term, J, A);
			return;
		}
		if (A[m].getword() == term) {
			findother(foundwords, m, term, J, A);
			return;
		}
		for (int i = 0; i < term.size(); i++) {
			if (term[i] < A[m].getword()[i]) {
				r = m;
			}
			else if (term[i] > A[m].getword()[i]) {
				l = m;
			}
			if (l == r && r == m && A[m].getword() != term) {
				return;
			}
			if (i == term.size() && A[m].getword().size() > term.size()) {
				r = m;
			}
			else {
				l = m;
			}
		}
	}
}
/**
	*	findother
	*
	*	Description:
	*			does a linear search of all possible choices after
	*			binary search has been performed
	*	Params:
	*			int&			wordsfound : amounts of words found
	*			int					 index : positions variable
	*			string				  term : keyword to find
	*			JsonFacade&				 J : refernce to array of objects
	*			Dictionary*				 A : pointer to array of Dictionaries
	*	Returns:
	*			Void
	*/
void findother(int& wordsfound, int index, string term, JsonFacade& J, Dictionary* A) {
	for (int i = index; i > -1; i--) {
		size_t found = A[i].getword().find(term);
		if (found != string::npos) {
			wordsfound++;
		 }
	}
	for (int i = index; i < J.getSize() - 1; i++) {
		size_t found = A[i].getword().find(term);
		if (found != string::npos) {
			wordsfound++;
		}
	}
}