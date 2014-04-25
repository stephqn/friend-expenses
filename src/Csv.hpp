/*
 * Csv.hpp
 *
 *  Created on: 24 avr. 2014
 *      Author: masse
 */

#ifndef CSV_HPP_
#define CSV_HPP_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include "Group.hpp"
#include "Person.hpp"
#include "Donor.hpp"

using namespace std;

class Csv
{
public:
	Csv();
	virtual ~Csv();

	void setName(const string& iNameFile);
	void readCSV(string myFileName);
	void createGroup (vector <Group>& groups);

private :

	string _nameFile;
	ifstream _myFile;
	vector<Person*> _vPerson;
	vector<string>  _list_group;
	int _nbPersPerGroup;
};

#endif /* CSV_HPP_ */
