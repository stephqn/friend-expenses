/*
 * Csv.hpp
 *
 *  Created on: 24 avr. 2014
 *      Author: masse
 */

#ifndef CSV_HPP_
#define CSV_HPP_

#include <stdio.h>
<<<<<<< HEAD
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
=======
#include <iostream>
#include <fstream>
#include <string>
>>>>>>> upstream/master
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
<<<<<<< HEAD
	void openCSV(string myFileName);
	void readCSV();
	//void writeCSV(string append, string argument[]);
	void writeCSV(string argument);
=======
	void readCSV(string myFileName);
>>>>>>> upstream/master
	void createGroup (vector <Group>& groups);

private :

	string _nameFile;
	ifstream _myFile;
	vector<Person*> _vPerson;
	vector<string>  _list_group;
<<<<<<< HEAD
	const char* file;
=======
>>>>>>> upstream/master
	int _nbPersPerGroup;
};

#endif /* CSV_HPP_ */
