/*
 * Donor.hpp
 *
 *  Created on: 3 avr. 2014
 *      Author: yanis
 */

#ifndef DONOR_HPP_
#define DONOR_HPP_

#include "Person.hpp"
class Donor : public Person
{
public:
	Donor();
	Donor(const string name, const string phone, const float donation, const string groupName);

	~Donor();

private:
	float _donation;
};

#endif /* DONOR_HPP_ */
