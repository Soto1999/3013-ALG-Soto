///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Title:            Processing linear time
// Semester:         Spring 2020
// Date:             21 Feb 2020
//
// Description:
//					 This program will read in a json dictionary, store it in a
//					 linked list and produce suggestions based on user input.
//					 The program will also time how long it takes to load 
//					 the dictionary and produce the auto suggestion.
//      
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp"           
#include "LinkedList.hpp"
#include "mygetch.hpp"
using namespace std;

int main(){
    Timer T;			   // instance of timer
	MyList Test;		   // instance of list

	char k;                // holder for character being typed
	string word = "";      // var to concatenate letters to
	string foundword = ""; // word that matches the list
	string key;			   // key variable to access json object
	string def;			   // definition included with word
	bool found = true;	   // variable that will control main loop
				

    JsonFacade J("dict_w_defs.json");   // create instance of json class
	vector<string> keys = J.getKeys();

	T.Start();
	for (int i = 0; i < keys.size(); i++) {
		key = J.getKey(i);			// gets term
		def = J.getValue(key);		// gets corresponding definition
		Test.insert(key, def);		// inserting key and definition into list
	}
	T.End();
	double s = T.Seconds();			// Setting time variable
    long m = T.MilliSeconds();		// setting time varibale

    cout <<m << " milliseconds to load dictionary" <<endl;

	cout << "Type keys and watch what happens. Type capital Z to quit." << endl;
	
	// While capital Z is not typed keep looping
	while (found == true) {
		while ((k = getch()) != 'Z') {
			word += k;          // append char to word

			if ((int)k != 10) {   // if k is not a space print it
				cout << "Key: " << k << " = " << (int)k << endl;
				cout << "Word: " << word << endl;
			}

			// Timiing how long to produce each suggestion
			T.Start();
			found = Test.search(word);
			T.End();
			
			s = T.Seconds(); // time variable

			cout << s << " seconds to produce suggestion\n";
			// hitting enter sets word back to empty
			if ((int)k == 10) {
				cout << "Enter pressed ... Word is empty\nWord: " << endl;
				word = "";
			}
		}
	}
}