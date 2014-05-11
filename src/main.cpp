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
#include "Arg.hpp"
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

    int color_indexer = 0, state = 0;
    float aExpensesPerPerson = 0;

    string newdata = "Empty";

    vector<Group> Groups;

    const char* colors[NB_MAX_COLOR] = {BOLDWHITE, BOLDRED, BOLDGREEN, BOLDBLUE, BOLDMAGENTA, BOLDCYAN, BOLDBLACK};
	/*---------------------------------*/

    Csv csv;
    Arg arg;

	arg.readArg(argc,argv,&state, &newdata);//Gestion des arguments
	switch(state)
	{
		case ERROR:break;

		case WRITE: csv.openCSV(string(argv[12]));
				    csv.writeCSV(newdata);
				    break;
		case READ: csv.openCSV(string(argv[2])); break;
	}
	if(state == ERROR)//Fin du programme
	{
		cout << "\nExiting..." << endl;
		return 1;
	}
    csv.readCSV();
    csv.createGroup(Groups);

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
    	int exp = it->expensesPerPerson();
    	for (size_t i=0; i < it->size(); ++i)
    	{
    		// operate the payback first
    		(*it)[i]->operatePayback(exp);
    		// display the values
    		cout << setw(0) << left
    			 <<	colors[color_indexer] << setw(16) << left
    		     << (*it)[i]->getName() << setw(16) << left
    			 << (*it)[i]->getPhoneNumber() << setw(12) << left
    			 << (*it)[i]->getExpenses() << setw(10) << left
    	         << (*it)[i]->getPayback() << setw(13) << left
    	         << it->getGroupName() << setw(16) << left
    	         << (*it)[i]->getType()
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
