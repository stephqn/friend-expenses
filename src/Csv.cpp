/*
 * Csv.cpp
 *
 *  Created on: 24 avr. 2014
 *      Author: masse
 */

#include "Csv.hpp"

using namespace std;

Csv::Csv() : _nbPersPerGroup (0)
{
}

Csv::~Csv()
{
}

<<<<<<< HEAD
void Csv::openCSV(string myFileName)
{
	//const char* file;

	cout << "\nInput data file : " << myFileName << endl;
	ifstream _myFile;
	try
	{


		//_myFile.open();// file, ios::in | ios::out | ios::app);
		_myFile.open(myFileName.c_str(), ios::in | ios::out | ios::app);
		if (!_myFile)
			_myFile.exceptions(ifstream::failbit); // Set flag failbit for exceptions
	}
	catch (ios_base::failure &e)
	{
		cout << "Exception caught while opening your file : " << endl;
		cout << e.what() << endl;
	}

	cout << "nom du fichier : " << myFileName <<  endl;

}


//void Csv::writeCSV(string append, string argument[])
void Csv::writeCSV(string argument)
{
	ofstream _myFile;

	//string COMMA = ",";
	//append = argv[2] + COMMA + argv[3] + COMMA + argv[4] + COMMA + argv[5] + COMMA + argv[6] + "\n";
	//string append;
	//append = argument[2] + COMMA + argument[3] + COMMA + argument[4] + COMMA + argument[5] + COMMA + argument[6] + "\n";

	_myFile << argument;
	_myFile.seekp(0,ios::end); // reposition ourselves at the beginning

}

void Csv::readCSV()
=======
void Csv::readCSV(string myFileName)
>>>>>>> upstream/master
{
	bool group_status;
	int lineCounter(0);
	string currentLine;
	string item;
<<<<<<< HEAD
	/*const char* file;
=======
>>>>>>> upstream/master

	cout << "\nInput data file : " << myFileName << endl;
	ifstream _myFile;
	try
	{
<<<<<<< HEAD
		//_myFile.open(myFileName.c_str());// file, ios::in | ios::out | ios::app);
		_myFile.open(file, ios::in | ios::out | ios::app);
=======
		_myFile.open(myFileName.c_str());
>>>>>>> upstream/master
		if (!_myFile)
			_myFile.exceptions(ifstream::failbit); // Set flag failbit for exceptions
	}
	catch (ios_base::failure &e)
	{
		cout << "Exception caught while opening your file : " << endl;
		cout << e.what() << endl;
	}
<<<<<<< HEAD
	*/


=======
>>>>>>> upstream/master
	while (1)
	{
		vector<string> person;

		getline(_myFile, currentLine);

		if (lineCounter != 0)
		{
<<<<<<< HEAD
			cout << "nom du fichier : " <<  endl;

=======
>>>>>>> upstream/master
			if (_myFile.eof())
				break;
			stringstream ss(currentLine.c_str());

			while (std::getline(ss, item, ',')) {
				person.push_back(item);
<<<<<<< HEAD

=======
>>>>>>> upstream/master
			}
			Person *aPerson = new Person;
			if (person[4] == "Person") {
				aPerson = new Person;
				aPerson->setName(person[0]);
				aPerson->setPhoneNumber(person[1]);
				aPerson->setExpenses(atof(person[2].c_str()));
				aPerson->setGroupName(person[3]);
				aPerson->setType();
			}
			if (person[4] == "Donor")
			{
				aPerson = new Donor;
				aPerson->setName(person[0]);
				aPerson->setPhoneNumber(person[1]);
				aPerson->setExpenses(atof(person[2].c_str()));
				aPerson->setGroupName(person[3]);
				aPerson->setType();
			}
			if (_list_group.size() == 0)
				_list_group.push_back(person[3]);
			for (unsigned int i = 0; i < _list_group.size(); i++)
			{
				if (_list_group[i] == person[3]) //group existe deja
				{
					group_status = true;
					break;
				} else
					group_status = false;
			}
			if (!group_status)
			{
				_list_group.push_back(person[3]); // contient le nom des groupes
			}
			_vPerson.push_back(aPerson); // contient toutes les personnes
		}
		lineCounter++;
	}
}

<<<<<<< HEAD


=======
>>>>>>> upstream/master
void Csv::createGroup(vector<Group>& Groups)
{
	int nbDonor = 0;

	//trier les donnees lues dans le csv
	for (unsigned int i = 0; i < _list_group.size(); i++)
	{
		Group aGroup;
		aGroup.setGroupName(_list_group[i]);

		for (unsigned int j = 0; j < _vPerson.size(); j++) {
			if (_list_group[i] == _vPerson[j]->getGroupName()) {
				//personne par groupe
				_nbPersPerGroup++;
				aGroup.push_back(_vPerson[j]);
				if (_vPerson[j]->getType() == "Donor") {
					nbDonor++;
				}
			}
		}
		//remplir vecteur de group
		aGroup.setNbPersGroup(_nbPersPerGroup - nbDonor);
		_nbPersPerGroup = 0;
		nbDonor = 0;
		Groups.push_back(aGroup);
	}

}

void Csv::setName(const string& iNameFile)
{
	_nameFile = iNameFile;
}

