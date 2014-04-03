//============================================================================
// Name        : main.cpp
// Author      : aabou
// Version     :
// Copyright   : Your copyright notice
// Description : Tutorial - Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#undef DEBUG
using namespace std;

int main(int argc, char **argv)
{
	/********* LOCAL VARIABLES *********/

    string name, phone, gn, tmp, currentLine, item;
    bool group_status;

    int nbPersPerGroup = 0, lineCounter = 0;
    float aExpensesPerPerson;

    vector<string>  list_group;
    vector<Person> vPerson;
    vector<Group> Groups;

	/*---------------------------------*/
    if(argv[1] == NULL)
    {
    	cout << "\nNo input file specified... Exiting" << endl;
    	return 1;
    }
    cout << "\nInput data file : " << argv[1] << endl;
    ifstream myFile;
    myFile.exceptions(ifstream::failbit); // Set flag failbit for exceptions
    try
    {
    	myFile.open(argv[1]);
    }
    catch(ios_base::failure &e)
    {
    	cout << "Exception caught while opening your file : " << endl;
    	cout << e.what() << endl;
    }
    while(1)
    {

    	getline(myFile, currentLine);
    	if(lineCounter != 0)
    	{
    		if(myFile.eof()) break;
    		stringstream ss(currentLine.c_str());
    		vector<string> person;
    		while (std::getline(ss, item, ','))
    		{
    			person.push_back(item);
    		}
    		Person aPerson;
    		aPerson.setName(person[0]);
    		aPerson.setPhoneNumber(person[1]);
    		aPerson.setExpenses(atof(person[2].c_str()));
    		aPerson.setGroup(person[3]);
    		if(list_group.size() == 0)
    			list_group.push_back(person[3]);
    		for(unsigned int i=0; i<list_group.size(); i++)
    		{
    			if(list_group[i] == person[3]) //group existe deja
    			{
    				group_status = true;
    				break;
    			}
    			else
    				group_status = false;
    		}
    		if(!group_status)
    		{
    			list_group.push_back(person[3]); // contient le nom des groupes
    		}
    		vPerson.push_back(aPerson); // contient toutes les personnes
    	}
    	lineCounter++;

    }
#ifdef DEBUG
    for(int i=0; i<vPerson.size();i++)
    {
    	cout << vPerson[i].getName() << vPerson[i].getPhoneNumber() << endl;

    }

    for(int i=0; i<list_group.size(); i++)
    	cout << list_group[i] << endl;
#endif

    //trier les donnees lues dans le csv
    for(unsigned int i=0; i<list_group.size(); i++)
    {
    	Group aGroup;
    	aGroup.setGroupName(list_group[i]);
    	for(unsigned int j=0; j<vPerson.size(); j++)
    	{
    		if(list_group[i] == vPerson[j].getGroup())
    		{
    			//personne par groupe
    			nbPersPerGroup++;
    			aGroup.push_back(vPerson[j]);
    		}
    	}
    	//remplir vecteur de group
    	aGroup.setNbPersGroup(nbPersPerGroup);
    	nbPersPerGroup = 0;
    	Groups.push_back(aGroup);
    }

    /*
     *  Prepare the output
     */
    cout << endl;
    for(unsigned int i=0; i<Groups.size(); i++)
    {
    	cout << "Total expenses for group: "<< Groups[i].getGroupName() << " "<<Groups[i].totalExpenses() << endl;
    	aExpensesPerPerson = Groups[i].expensesPerPerson();
    	cout << "Expenses per person:\t" << aExpensesPerPerson << endl;
    	cout << endl;
    }

    cout << "Name\t\t" << "Phone Number\t" << "Expenses\t"
        << "Payback\t\t" << "Group\t" << endl;
    cout << "-----------------------------------------------------------------------"
        << endl;
    for(vector<Group>::iterator it = Groups.begin(); it != Groups.end(); ++it)
    {
    	Group tmp = *it;
    	int exp = it->expensesPerPerson();
    	for (size_t i=0; i < tmp.size(); ++i)
    	{
    		// operate the payback first
    		tmp[i].operatePayback(exp);
    		// display the values
    		cout << tmp[i].getName() << "\t\t" << tmp[i].getPhoneNumber()
    	            		<< "\t\t" << tmp[i].getExpenses() << "\t\t"
    	            		<< tmp[i].getPayback() << "\t\t" << tmp.getGroupName() << endl;
    	}
    }
    cout << endl;

    return 0;
}
