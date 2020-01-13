 
/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: (For you to fill)
 * Date: (For you to fill)
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
// You need to complete this method.
    this->Name = "To be entered";
    this->Address = "To be entered";
    this->Email = "To be entered";
    this->Phone = "To be entered";
    this->Carecard = 0000000000;
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {

// You need to complete this method.
    this->Name = "To be entered";
    this->Address = "To be entered";
    this->Email = "To be entered";
    this->Phone = "To be entered";
    this->Carecard = aCareCard;

}

void Patient::setName(const string aName){
    this->Name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
    this->Address = anAddress;
}

// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone){
    this->Phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
    this->Email = anEmail;
}

void Patient::setCareCard(const int aCareCard){
    this->Carecard = aCareCard;
}

string Patient::getName(){
    return this->Name;
}

	// Description: Returns patient's address.
string Patient::getAddress(){
    return this->Address;
}

	// Description: Returns patient's phone.
string Patient::getPhone(){
    return this->Phone;
}

	// Description: Returns patient's email.
string Patient::getEmail(){
    return this->Email;
}
	
	// Description: Returns patient's care card.
string Patient::getCareCard(){
    return this->Carecard;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp
