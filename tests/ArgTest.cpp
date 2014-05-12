/*
 * ArgTest.cpp
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

int state = 0;
string newdata = "Empty";
char *argvRead[2];
char *argvWrite[12];
char *argvError[1];

Arg ReadArgTest;
Arg WriteArgTest;
Arg ErrorArgTest;

TEST(Arg, isReadOk)
{
	argvRead[1] = "--file";
	argvRead[2] = "input.csv";
	ReadArgTest.readArg(3,argvRead,&state, &newdata);
	EXPECT_EQ(READ, state);
}

TEST(Arg, isWriteOk)
{
	argvWrite[1] = "--name";
	argvWrite[2] = "toto";
	argvWrite[3] = "--phone";
	argvWrite[4] = "1234";
	argvWrite[5] = "--expense";
	argvWrite[6] = "200";
	argvWrite[7] = "--group";
	argvWrite[8] = "Righi";
	argvWrite[9] = "--type";
	argvWrite[10] = "Donor";
	argvWrite[11] = "--file";
	argvWrite[12] = "input.csv";
	WriteArgTest.readArg(13, argvWrite, &state, &newdata);
	EXPECT_EQ("toto,1234,200,Righi,Donor\n", newdata);
	EXPECT_EQ(WRITE, state);
}

TEST(Arg, isErrorOk)
{
	argvError[1] = "file";
	ErrorArgTest.readArg(1, argvError, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}
