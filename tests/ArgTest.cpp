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
char *argvErrorNoFile[2];
char *argvErrorHelpAsked[1];
char *argvErrorPhoneOnly[1];

Arg ReadArgTest;
Arg WriteArgTest;
Arg ErrorArgTest;
Arg ErrorSansArg;
Arg ErrorNoFileMentionned;
Arg ErrorHelpAsked;
Arg ErrorPhoneOnly;

TEST(Arg, isReadOk)//Test avec 3 arguments correct lecture fichier
{
	argvRead[1] = "--file";
	argvRead[2] = "input.csv";
	ReadArgTest.readArg(3,argvRead,&state, &newdata);
	EXPECT_EQ(READ, state);
}

TEST(Arg, isWriteOk)//Test avec 13 arguments correct ecriture fichier
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

TEST(Arg, isErrorOk)//Test avec 2 arguments mais mauvaise syntaxe
{
	argvError[1] = "file";
	ErrorArgTest.readArg(2, argvError, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}

TEST(Arg, isErrorSansArgOk)//Test sans arguments
{
	ErrorSansArg.readArg(1, argvError, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}

TEST(Arg, isErrorNoFileMentionnedOk)//Test avec 2 argument dont l'oublie du fichier csv
{
	argvErrorNoFile[1] = "--file";
	ErrorNoFileMentionned.readArg(2, argvErrorNoFile, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}

TEST(Arg, isErrorHelpAskedOk)//Test avec 2 arguments dont l'oublie du fichier csv
{
	argvErrorHelpAsked[1] = "--help";
	ErrorHelpAsked.readArg(2, argvErrorHelpAsked, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}

TEST(Arg, isErrorPhoneOnlyOk)//Test avec 2 arguments mais mauvais syntaxe
{
	argvErrorPhoneOnly[1] = "--phone";
	ErrorPhoneOnly.readArg(2, argvErrorPhoneOnly, &state, &newdata);
	EXPECT_EQ(ERROR, state);
}
