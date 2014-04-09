/*
 * TPerson.cpp
 *
 *  Created on: 9 avr. 2014
 *      Author: YH
 */

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Group.hpp"
#include "../src/Person.hpp"
#include "../src/Donor.hpp"

using namespace std;

Group myGroup("G1", 5);

/*
 * Test user defined constructor
 */

TEST(Group, isInitOk)
{
	EXPECT_EQ("G1", myGroup.getGroupName());
	EXPECT_EQ(5, myGroup.getNbPersGroup());
}

/*
 * Test setters
 */

TEST(Group, isSetterOk)
{
	myGroup.setGroupName("Righi");
	myGroup.setNbPersGroup(10);

	EXPECT_EQ("Righi", myGroup.getGroupName());
	EXPECT_EQ(10, myGroup.getNbPersGroup());
}

/*
 * Test adding persons to a group
 */

TEST(Group, isAddingOk)
{
	Person *A = new Person;
	Person *B = new Person;

	A->setName("P1");
	A->setPhoneNumber("0680");
	A->setExpenses(100);
	A->setType("Person");

	B->setName("P2");
	B->setPhoneNumber("8071");
	B->setExpenses(500);
	B->setType("Person");

	myGroup.push_back(A);
	myGroup.push_back(B);

	EXPECT_EQ(2, myGroup.size());
	EXPECT_EQ("P1", myGroup[0]->getName());
	EXPECT_EQ(500, myGroup[1]->getExpenses());
	EXPECT_EQ("Person", myGroup[1]->getType());
}

/*
 * Test calculation of total expenses of a group
 */

TEST(Group, isTotalExpensesOk)
{
	// Two persons 100 + 500
	EXPECT_EQ(600, myGroup.totalExpenses());

	// Now add a donor : donation set to 300
	Donor *C = new Donor;
	C->setName("D1");
	C->setPhoneNumber("0357");
	C->setExpenses(300);
	C->setType("Donor");
	myGroup.push_back(C);
	EXPECT_EQ(300, myGroup.totalExpenses());
}

/*
 * Test calculation of expenses per person
 */

TEST(Group, isExpensesPerPersonOk)
{
	// Two person + 1 donor
	myGroup.setNbPersGroup(2);
	EXPECT_EQ(150, myGroup.expensesPerPerson());
}
