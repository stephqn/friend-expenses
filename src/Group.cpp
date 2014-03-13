/*
 * Group.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#include "Group.hpp"

Group::Group() {

}

Group::Group(const string groupName, int nbPers)
{
	_groupName = groupName;
	_nbPersGroup = nbPers;
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
        aTotal += this->at(i).getExpenses();
    }
    return aTotal;
}

float Group::expensesPerPerson() const {
    float aExpense = this->totalExpenses() / this->size();
    return aExpense;
}
