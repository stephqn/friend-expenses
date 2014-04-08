/*
 * Person.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: YH
 */

#include "Person.hpp"
#include "Group.hpp"
#include <iostream>

using namespace std;

Person::Person() :
    _expenses(0),
    _payback(0) {
	_pGroup = new Group;
}

Person::~Person() {

}

Person::Person(const string name, const string phone, const float expenses, const string type)
{
	_name = name;
	_phoneNumber = phone;
	_expenses = expenses;
	_payback = 0;
	_type = type;
	_pGroup = new Group;
}
const string& Person::getName() const
{
	return _name;
}

const string& Person::getPhoneNumber() const
{
	return _phoneNumber;
}

float Person::getExpenses() const
{
	return _expenses;
}

float Person::getPayback() const
{
	return _payback;
}

void Person::setName(const string& name)
{
	_name = name;
}

void Person::setPhoneNumber(const string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Person::setExpenses(const float expenses)
{
	_expenses = expenses;
}

void Person::setPayback(const float expenses)
{
	_payback = expenses;
}

void Person::operatePayback(const float iExpensesPerPerson) {
    _payback = _expenses - iExpensesPerPerson;
}

//const string& Person::getGroup() const
//{
//	return _groupName;
//}
//void Person::setGroup(const string& groupName)
//{
//	_groupName = groupName;
//}

void Person::setType(const string& type)
{
	_type = type;
}

const string& Person::getType() const
{
	return _type;
}

void Person::setGroupName(const string& name)
{
	_pGroup->setGroupName(name);
}

const string& Person::getGroupName() const
{
	return _pGroup->getGroupName();
}
