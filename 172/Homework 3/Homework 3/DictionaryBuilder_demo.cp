// ----------------------------------------------------------------------------
//
// ---------------------------- Dictionary Builder ----------------------------
// 
// ----------------------------------------------------------------------------
//
//  Program Name: Dictionary Builder 
//
//  This program reads an electronic book, converts all words to lower case,
//  trims all leading and trailing non-alpha characters, counts the number
//  of occurrences of all unique words and stores the results in a tab-delimited
//  file.
//
//  Author:         JL Popyack
//  Date:           April 2011 -- based on "Map Tester" program maptest_v2.cpp
//
// ----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include <map>
	#include <algorithm>
	#include <fstream>
	#include <ctime>
	using namespace std ;

// ----------------------------------------------------------------------------
//
// -------------------------------- Prototypes --------------------------------
//
// ----------------------------------------------------------------------------

	string lowerCase(string s) ;
	string trim(string word) ;
	string promptForString(string prompt) ; // Need to supply code for this routine
	
// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

	int main (void) 
	{
	// ----------------------------------------------------------------------------
	// count is a map from string to int.
	// The int will be a count of the number of occurrences of the string
	// in a text file provided by the user.
	// ----------------------------------------------------------------------------
	// The code below shows how to store and retrieve values.
	// ----------------------------------------------------------------------------
	//	count["hello"] = 1 ;
	//	cout << count["hello"] << endl ;
	//	
	//	count["hello"]++ ;
	//	cout << count["hello"] << endl ;	
	// ----------------------------------------------------------------------------

		map<string,int> count ;
		clock_t start;
		double elapsedTime;
 
		string filename = promptForString("Input name of file containing book: ") ;
		ifstream fin(filename.c_str()) ;
		if( fin.fail() )
			cerr << "File not found" << endl ;

	// ---------------------------------------------
	//	Read the file, one word at a time.
	//	Put each word in a map, and count it.
	// ---------------------------------------------
		string word ;
		int numberOfWords=0 ;
		start = clock() ;
 		while( fin >> word )
		{
			word = lowerCase( trim(word) ) ;
			if( word.size()>0 )
				count[word]++ ;
			numberOfWords++ ;
			//cout << "word=" << word 
			//	<< "\tcount[\"" << word << "\"]=" << count[word]
			//	<< endl ;
		}
		fin.close() ;
		elapsedTime = ( clock() - start ) / (double)CLOCKS_PER_SEC;
		cout << "Done reading." << endl ;
		cout << numberOfWords << " words read." << endl ;
		cout<<"File read in "<< elapsedTime << " seconds" << endl ;		
		
	// ---------------------------------------------
	//	Copy all words in the map to a file,
	//	in the order they are stored.
	// ---------------------------------------------
		ofstream fout("DICTIONARY_"+filename) ;
		map<string,int>::iterator it = count.begin() ;
		numberOfWords=0 ;
		while( it != count.end() )
		{
			fout << it->first << "\t" << it->second << endl;
			numberOfWords++ ;
			it++ ;
		}
		cout << numberOfWords << " distinct words." << endl ;

		return 0 ;
	}
	
// ----------------------------------------------------------------------------
//
// -------------------------- Subprogram Definitions --------------------------
//
// ----------------------------------------------------------------------------


string promptForString(string prompt) // prompt user for string and return value
{
	cout << prompt << endl;
	string input;
	getline(cin, input); //get user input and return that value
	return input;
}
//----------------------------------------------------------------------------
//
//  Return lower-case version of string
//
//----------------------------------------------------------------------------
	string lowerCase(string s)
	{
		for(unsigned int i=0; i<s.size(); i++)
			if( s[i]>='A' && s[i]<='Z' )
				s[i] += 'a'-'A' ;
		return s ;
	}

// ----------------------------------------------------------------------------
//
//  Remove leading and trailing symbols from a string.
//  Words can still contain symbols, e.g., "can't", "co-op"
//
// ----------------------------------------------------------------------------
	string trim(string word)
	{		
		while( word.size()>0 && !( word[0] >= 'a' && word[0] <= 'z' )
			                 && !( word[0] >= 'A' && word[0] <= 'Z' ))
			word = word.substr(1) ;

		while( word.size()>0 && !( word.back() >= 'a' && word.back() <= 'z')
			                 && !( word.back() >= 'A' && word.back() <= 'Z' ))
			word = word.substr(0,word.size()-1) ;

		return word ;
	}
