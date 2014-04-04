/*
 * Person.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
class Group;
using namespace std;

class Person //: public Group
{
public:
    Person();
    Person(const string name, const string phone, const float expenses);
    virtual ~Person();
    const string& getName() const;
    const string& getPhoneNumber() const;
    float getExpenses() const;
    float getPayback() const;
    void setName(const string& name);
    void setPhoneNumber(const string& phoneNumber);
    void setExpenses(const float expenses);
    void setPayback(const float payBack);
    void operatePayback(const float iExpensesPerPerson);
    const string& getGroup() const;
    void setGroup(const string& groupName);
    void setType(const string& type);
    const string& getType() const;



protected:
    string _name;
    string _phoneNumber;
    float _expenses;
    float _payback;
    string _groupName;
    string _type;
};

#endif /* PERSON_HPP_ */
