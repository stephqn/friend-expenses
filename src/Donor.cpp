/*
 * Donor.cpp
 *
 *  Created on: 3 avr. 2014
 *      Author: YH
 */

#include "Donor.hpp"
#include "Group.hpp"
#include <iostream>

using namespace std;
Donor::Donor()
{
	_donation = 0;
}

Donor::Donor(const string name, const string phone, const float donation)
{
	_name = name;
	_phoneNumber = phone;
	_donation = donation;
}

Donor::~Donor()
{
}

void Donor::operatePayback(const float iExpensesPerPerson) {
    _payback = 0;
}

void Donor::setType()
{
	_type = "Donor";
}

void Donor::setExpenses(const float donation)
{
	_donation = donation;
}

float Donor::getExpenses() const
{
	return _donation;
}
