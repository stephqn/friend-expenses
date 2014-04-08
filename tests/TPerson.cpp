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

TEST(Person, Init)
{
	EXPECT_EQ("Yanis", aPerson.getName());
	EXPECT_EQ("068071", aPerson.getPhoneNumber());
	EXPECT_EQ(100, aPerson.getExpenses());
	EXPECT_EQ("Person",aPerson.getType());
}

TEST(Person, Setters)
{
	aPerson.setName("Deneb");
	aPerson.setPhoneNumber("01234");
	aPerson.setExpenses(205);
	aPerson.setType("Person");

	EXPECT_EQ("Deneb", aPerson.getName());
	EXPECT_EQ("01234", aPerson.getPhoneNumber());
	EXPECT_EQ(205, aPerson.getExpenses());
	EXPECT_EQ("Person",aPerson.getType());
}

TEST(Person, Payback)
{
	aPerson.operatePayback(300);
	// Spent 205€, average spending per person is 300
	EXPECT_EQ(-95,aPerson.getPayback());
}

TEST(Person, Groupname)
{
	aPerson.setGroupName("TestGroup");
	EXPECT_EQ("TestGroup", aPerson.getGroupName());
}
