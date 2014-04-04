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
    Person(const string name, const string phone, const float expenses, const string type);
    virtual ~Person();

    const string& getName() const;
    void setName(const string& name);

    const string& getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);

    float getExpenses() const;
    void setExpenses(const float expenses);

    float getPayback() const;
    void setPayback(const float payBack);

    void operatePayback(const float iExpensesPerPerson);

    //const string& getGroup() const;
    //void setGroup(const string& groupName);

    const string& getType() const;
    void setType(const string& type);

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
    string _groupName;
    string _type;
    Group *_pGroup;
};

#endif /* PERSON_HPP_ */
