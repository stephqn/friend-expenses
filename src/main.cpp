//============================================================================
// Name        : main.cpp
// Author      : YH
// Version     :
// Copyright   : latest
// Description : Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"
#include "Donor.hpp"
#include "Csv.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <gtest/gtest.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define DEBUG
#undef DEBUG

#define NB_MAX_COLOR 7
using namespace std;

int main(int argc, char **argv)
{
	/********* LOCAL VARIABLES *********/
<<<<<<< HEAD


    int color_indexer = 0;
    float aExpensesPerPerson;

=======
   
    int color_indexer = 0;
    float aExpensesPerPerson = 0;

>>>>>>> upstream/master
    vector<Group> Groups;

    const char* colors[NB_MAX_COLOR] = {BOLDWHITE, BOLDRED, BOLDGREEN, BOLDBLUE, BOLDMAGENTA, BOLDCYAN, BOLDBLACK};
	/*---------------------------------*/
<<<<<<< HEAD

    Csv csv;
    if (argv[1] == NULL)
    {
    	cout << "\nNo input file specified... Exiting" << endl;
    	return 0;
    }

    csv.openCSV(string(argv[1]));
    if(argc > 2) /* TODO implement arguments handling */
    {
    	string COMMA = ",";
    	string append;
    	//cin >> modif;
    	append = argv[2] + COMMA + argv[3] + COMMA + argv[4] + COMMA + argv[5] + COMMA + argv[6] + "\n";

    	csv.writeCSV(append);
    }

   /*{
    	string COMMA = ",";
    	string append = argv[2] + COMMA + argv[3] + COMMA + argv[4] + COMMA + argv[5] + COMMA + argv[6] + "\n";
    	myFile << append;
    	myFile.seekg(0); // reposition ourselves at the beginning
    	}

    */

    //csv.readCSV(string(argv[1]));


    csv.readCSV();

    csv.createGroup(Groups);

=======
	Csv csv;
    if(argv[1] == NULL)
    {
    	cout << "\nNo input file specified... Exiting" << endl;
    	return 1;
    }
    csv.readCSV(string(argv[1]));
    csv.createGroup(Groups);

>>>>>>> upstream/master
#ifdef DEBUG
    for(int i=0; i<vPerson.size();i++)
    {
    	cout << vPerson[i]->getName() << vPerson[i]->getPhoneNumber() << endl;

    }

    for(int i=0; i<list_group.size(); i++)
    	cout << list_group[i] << endl;
#endif

    /*
     *  Prepare the output
     */

    cout << endl;

    for(unsigned int i=0; i<Groups.size(); i++)
    {
    	cout << "Total expenses for group " << BOLDBLUE << Groups[i].getGroupName() << " : " << BOLDRED << Groups[i].totalExpenses() << RESET <<endl;
    	aExpensesPerPerson = Groups[i].expensesPerPerson();
    	cout << "Average expenses per person : " << BOLDYELLOW << aExpensesPerPerson << RESET << endl;
    	cout << endl;
    }
    cout << setw(0) << left
        			 <<	BOLDWHITE << setw(16) << left
        		     << "Name" << setw(16) << left
        			 << "Phone Number" << setw(12) << left
        			 << "Expenses" << setw(10) << left
        	         << "Payback" << setw(13) << left
        	         << "Group" << setw(16) << left
        	         << "Type"
        	         << RESET
        	         << endl;
    cout << "-------------------------------------------------------------------------"
        << endl;

    for(vector<Group>::iterator it = Groups.begin(); it != Groups.end(); ++it)
    {
    	Group tmp = *it;
    	int exp = it->expensesPerPerson();
    	for (size_t i=0; i < tmp.size(); ++i)
    	{
    		// operate the payback first
    		tmp[i]->operatePayback(exp);
    		// display the values
    		cout << setw(0) << left
    			 <<	colors[color_indexer] << setw(16) << left
    		     << tmp[i]->getName() << setw(16) << left
    			 << tmp[i]->getPhoneNumber() << setw(12) << left
    			 << tmp[i]->getExpenses() << setw(10) << left
    	         << tmp[i]->getPayback() << setw(13) << left
    	         << tmp.getGroupName() << setw(16) << left
    	         << tmp[i]->getType()
    	         << RESET
    	         << endl;
    	}
    	if(color_indexer==NB_MAX_COLOR-1)
    		color_indexer=0;
    	else
    		color_indexer++;
    }
    cout << endl;
    return 0;
}
