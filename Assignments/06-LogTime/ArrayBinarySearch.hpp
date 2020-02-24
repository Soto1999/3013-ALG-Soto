///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Title:            Processing log time
// Semester:         Spring 2020
// Date:             24 Feb 2020
//
// Description:
//					 Class that hold a word and definiton
//
// Usage:
//					#include "ArrayBinarySearch.hpp"
//					insertinfo(string w, string d)
//					getword()
//					getdef()
//      
/////////////////////////////////////////////////////////////////////////////////
#include<string>

class Dictionary {
private:
	std::string word;		// word variable
	std::string definition; // definition variable
public:
	/**
	*	Dictionary
	*
	*	Description:
	*			Default constructor
	*	Params:
	*			None
	*	Returns:
	*			Void
	*/
	Dictionary() {
		word = "";
		definition = "";
	}
	/**
	*	Dictionary
	*
	*	Description:
	*			Parameterized constructer
	*	Params:
	*			string w : word being inserted
	*			string d : word being inserted
	*	Returns:
	*			Void
	*/
	Dictionary(std::string w, std::string d) {
		word = w;
		definition = d;
	}
	/**
	*	insertinfo
	*
	*	Description:
	*			Sets class variables
	*	Params:
	*			string w : word being inserted
	*			string d : word being inserted
	*	Returns:
	*			Void
	*/
	void insertinfo(std::string w, std::string d) {
		word = w;
		definition = d;
	}
	/**
	*	getword
	*
	*	Description:
	*			Returns word
	*	Params:
	*			None
	*	Returns:
	*			string word : class variable
	*/
	std::string getword() {
		return word;
	}
	/**
	*	getdef
	*
	*	Description:
	*			Returns definition
	*	Params:
	*			None
	*	Returns:
	*			string definition : class variable
	*/
	std::string getdef() {
		return definition;
	}
};
