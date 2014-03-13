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

using namespace std;

int main(int argc, char **argv) {
    unsigned int aNb = 0;
    string name, phone, gn, tmp;
    float expenses;
    int nbGroups;
    /*
     *  Register the input
     */
    cout << "How many groups are there ?" << endl;
    cin >> nbGroups;
    vector<Group> Groups;

    for(int j=1; j<=nbGroups; j++)
    {
    	cout << "How many people are you in group "<< j << " ? " << endl;
    	cin >> aNb;

    	cout << "What is the name of the group "  << endl;
    	cin >> gn;
    	Group aGroup(gn, aNb);
    	for (unsigned int i=0; i < aNb; i++)
    	{
    		cout << "What is the name of person " << i+1 << " ?" << endl;
    		cin >> name;
    		cout << "What is the phone number of person " << i+1 << " ?" << endl;
    		cin >> phone;
    		cout << "What is the expenses of person " << i+1 << " ?" << endl;
    		cin >> expenses;
    		Person aPerson(name,phone,expenses);
    		aGroup.push_back(aPerson);
    	}
    	Groups.push_back(aGroup);
    }

    /*
     *  Prepare the output
     */
    float aExpensesPerPerson;
    for(int i=0; i<nbGroups; i++)
    {
    	cout << endl;
    	cout << "Total expenses for group: "<< Groups[i].getGroupName() << "\t\t"<<Groups[i].totalExpenses() << endl;
    	aExpensesPerPerson = Groups[i].expensesPerPerson();
    	cout << "Expenses per person:\t" << aExpensesPerPerson << endl;
    	cout << endl;
    }


    cout << "Name\t\t" << "Phone Number\t" << "Expenses\t"
        << "Payback\t\t" << "Group\t" << endl;
    cout << "-----------------------------------------------------------------------"
        << endl;
    /* TODO Lire fichier CSV ifstream */
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
