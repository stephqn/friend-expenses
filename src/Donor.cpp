/*
 * Donor.cpp
 *
 *  Created on: 3 avr. 2014
 *      Author: yanis
 */

#include "Donor.hpp"

Donor::Donor()
{

}

Donor::Donor(const string name, const string phone, const float donation, const string groupName)
{
	_name = name;
	_phoneNumber = phone;
	_donation = donation;
	_groupName = groupName;
}

Donor::~Donor()
{
	// TODO Auto-generated destructor stub
}

