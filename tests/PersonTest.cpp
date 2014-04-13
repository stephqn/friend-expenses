/*
 * TPerson.cpp
 *
 *  Created on: 8 avr. 2014
 *      Author: yanis
 */

#include <iostream>
#include <gtest/gtest.h>
#include "../src/Person.hpp"

using namespace std;

Person aPerson("Yanis","068071",100,"Person");

/*
 * Test user defined constructor
 */

TEST(Person, isInitOk)
{
	EXPECT_EQ("Yanis", aPerson.getName());
	EXPECT_EQ("068071", aPerson.getPhoneNumber());
	EXPECT_EQ(100, aPerson.getExpenses());
	EXPECT_EQ("Person",aPerson.getType());
}

/*
 * Test setters
 */

TEST(Person, isSetterOk)
{
	aPerson.setName("Deneb");
	aPerson.setPhoneNumber("01234");
	aPerson.setExpenses(205);
	aPerson.setType();

	EXPECT_EQ("Deneb", aPerson.getName());
	EXPECT_EQ("01234", aPerson.getPhoneNumber());
	EXPECT_EQ(205, aPerson.getExpenses());
	EXPECT_EQ("Person",aPerson.getType());
}

/*
 * Test calculation of payback
 */

TEST(Person, isPaybackOk)
{
	aPerson.operatePayback(300);
	// Spent 205€, average spending per person is 300
	EXPECT_EQ(-95,aPerson.getPayback());
}

/*
 * Test setting Group::_groupName via pointer from class Person
 */

TEST(Person, isGroupNameOk)
{
	aPerson.setGroupName("TestGroup");
	EXPECT_EQ("TestGroup", aPerson.getGroupName());
}
