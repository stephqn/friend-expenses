/*
 * Person.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>

using namespace std;

class Person
{
public:
    Person();
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

private:
    string _name;
    string _phoneNumber;
    float _expenses;
    float _payback;
};

#endif /* PERSON_HPP_ */
