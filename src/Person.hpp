/*
 * Person.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: YH
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
class Group;
using namespace std;

class Person
{
public:
    Person();
    Person(const string name, const string phone, const float expenses, const string gName);
    virtual ~Person();

    const string& getName() const;
    void setName(const string& name);

    const string& getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);

    virtual float getExpenses() const;
    virtual void setExpenses(const float expenses);

    float getPayback() const;
    void setPayback(const float payBack);

    virtual void operatePayback(const float iExpensesPerPerson);

    const string& getType() const;
    virtual void setType();

    /*
     * Getter & Setter to Group::_groupName
     * attribute is set through *_pGroup pointer
     */
    void setGroupName(const string& name);
    const string& getGroupName() const;

protected:
    string _name;
    string _phoneNumber;
    float _expenses;
    float _payback;
    string _type;
private:
    Group *_pGroup;

};

#endif /* PERSON_HPP_ */
