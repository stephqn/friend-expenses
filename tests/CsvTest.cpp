/*
 * CsvTest.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: stephan
 */

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Person.hpp"
#include "../src/Group.hpp"
#include "../src/Donor.hpp"
#include "../src/Arg.hpp"
#include "../src/Csv.hpp"

using namespace std;

Csv csv;
string myFileName;
string person = "toto,1234,200,Righi,Donor\n";
Person aPerson2;

TEST(Csv, isWriteOk)//
{
	myFileName = "inputTest.csv";
	csv.openCSV(myFileName);
	csv.writeCSV(person);
	csv.readCSV();/*
	EXPECT_EQ("tot", aPerson2.getName());
	EXPECT_EQ("1234", aPerson2.getPhoneNumber());
	EXPECT_EQ(200, aPerson2.getExpenses());
	EXPECT_EQ("Righi", aPerson2.getGroupName());
	EXPECT_EQ("Person",aPerson2.getType());*/
}

/*
TEST(Csv, isReadOk)//
{
	state = ERROR;
	csv.openCSV(string(argv[12]));
	EXPECT_EQ(READ, state);
}

TEST(Csv, isWriteOk)//
{
	state = ERROR;
	csv.openCSV(string(argv[12]));
	EXPECT_EQ(READ, state);
}

TEST(Csv, iscreateGroupOk)//
{
	state = ERROR;
	csv.openCSV(string(argv[12]));
	EXPECT_EQ(READ, state);
}

TEST(Csv, issetNameOk)//
{
	state = ERROR;
	csv.openCSV(string(argv[12]));
	EXPECT_EQ(READ, state);
}*/


