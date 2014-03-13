/*
 * Person.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#include "Person.hpp"

Person::Person() :
    _expenses(0),
    _payback(0) {

}

Person::~Person() {

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
