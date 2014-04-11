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

	string toto;
	toto = toto + toto;
    string name, phone, gn, tmp, currentLine, item;
    bool group_status;

    int nbPersPerGroup = 0, lineCounter = 0, nbDonor=0, color_indexer = 0;
    float aExpensesPerPerson;

    vector<string>  list_group;
    vector<Person*> vPerson;
    vector<Group> Groups;

    const char* colors[NB_MAX_COLOR] = {BOLDWHITE, BOLDRED, BOLDGREEN, BOLDBLUE, BOLDMAGENTA, BOLDCYAN, BOLDBLACK};
	/*---------------------------------*/
    if(argv[1] == NULL)
    {
    	cout << "\nNo input file specified... Exiting" << endl;
    	return 1;
    }
    cout << "\nInput data file : " << argv[1] << endl;
    ifstream myFile;
    Person *aPerson;
    try
    {
    	myFile.open(argv[1]);
    	if(!myFile) myFile.exceptions(ifstream::failbit); // Set flag fail bit for exceptions
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
//    		Person *aPerson = new Person;
    		/* TODO modifier boucle if + déclaration *person *donor */
    		if(person[4] == "Person")
    		{
    			aPerson = new Person;
    			aPerson->setName(person[0]);
    			aPerson->setPhoneNumber(person[1]);
    			aPerson->setExpenses(atof(person[2].c_str()));
    			aPerson->setGroupName(person[3]);
    			aPerson->setType(person[4]);
    		}
//    		Donor *aDonor = new Donor;
    		if (person [4] == "Donor")
    		{
    			aPerson = new Donor;
    			aPerson->setName(person[0]);
    			aPerson->setPhoneNumber(person[1]);
    			aPerson->setExpenses(atof(person[2].c_str()));
    			aPerson->setGroupName(person[3]);
    			aPerson->setType(person[4]);
    		}
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
//    		if(person[4] == "Person")
    			vPerson.push_back(aPerson); // contient toutes les personnes
//    		else
//    		{
//    			Person* transDonor = dynamic_cast<Person*>(aDonor);
//    			vPerson.push_back(aDonor);
//    		}
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
    		if(list_group[i] == vPerson[j]->getGroupName())
    		{
    			//personne par groupe
    			nbPersPerGroup++;
    			aGroup.push_back(vPerson[j]);
    			if(vPerson[j]->getType() == "Donor")
    			{
    				nbDonor++;
    			}
    		}
    	}
    	//remplir vecteur de group
    	aGroup.setNbPersGroup(nbPersPerGroup-nbDonor);
    	nbPersPerGroup = 0;
    	nbDonor = 0;
    	Groups.push_back(aGroup);
    }

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

    cout << BOLDWHITE <<"Name\t\t" << "Phone Number\t" << "Expenses\t"
        << "Payback\t\t" << "Group\t" << RESET << endl;
    cout << "-----------------------------------------------------------------------"
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
    		cout << colors[color_indexer]
    		     << tmp[i]->getName() << "\t\t"
    			 << tmp[i]->getPhoneNumber() << "\t\t"
    			 << tmp[i]->getExpenses() << "\t\t"
    	         << tmp[i]->getPayback() << "\t\t"
    	         << tmp.getGroupName()
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
