/*
 * Group.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: YH
 */

#include "Group.hpp"
#include "Donor.hpp"

Group::Group()
{
	_nbPersGroup = 0;
}

Group::Group(const string groupName, int nbPers)
{
	_groupName = groupName;
	_nbPersGroup = nbPers;
	_nbPersGroup = 0;
}

Group::~Group() {

}

const string& Group::getGroupName() const
{
	return _groupName;
}

void Group::setGroupName(const string& name)
{
	_groupName = name;
}

float Group::totalExpenses() const {
    float aTotal = 0;
    for (size_t i=0; i < this->size(); i++) {
    	if(this->at(i)->getType() != "Donor")
    	{
    		aTotal += this->at(i)->getExpenses();
    	}
    	else
    	{
    		aTotal -=  this->at(i)->getExpenses();
    	}
    }
    return aTotal;
}

float Group::expensesPerPerson() const {
    float aExpense = this->totalExpenses() / _nbPersGroup;
    return aExpense;
}

int Group::getNbPersGroup() const
{
	return _nbPersGroup;
}

void Group::setNbPersGroup(int nbPersGroup)
{
	_nbPersGroup = nbPersGroup;
}
