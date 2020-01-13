 
/*
 * Patient.h
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: (For you to fill)
 * Date: (For you to fill)
 */

#pragma once
#include <iostream>
// You can add #include statements if you wish.
#include <string>




class Patient {
	
private:
    std::string Name, Address, Phone, Email;
    int Carecard;
    

    
public:

/* 
 * You can add more methods to this public interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default Constructor
	// Description: Create a patient with a care card number of "0000000000". 
	// Postcondition: All data members set to "To be entered", 
	//                except the care card number which is set to "0000000000".       
	Patient();

	// Parameterized Constructor
	// Description: Create a patient with the given care card number.
	// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
	//                All other data members set to "To be entered".
	Patient(string aCareCard);
	
	// Add more parameterized constructors here!

	// Getters and setters
	// Description: Returns patient's name.
	std::string getName() const;

	// Description: Returns patient's address.
	std::string getAddress() const;

	// Description: Returns patient's phone.
	std::string getPhone() const;

	// Description: Returns patient's email.
	std::string getEmail() const;
	
	// Description: Returns patient's care card.
	std::string getCareCard() const;

	// Description: Sets the patient's name.
	void setName(const std::string aName);

	// Description: Sets the patient's address.
	void setAddress(const std::string anAddress);

	// Description: Sets the patient's phone.
	void setPhone(const std::string aPhone);

	// Description: Sets the patient's email.
	void setEmail(const std::string anEmail);

    
    void setCareCard(const std::string aCareCard);
	// Overloaded Operators
	// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if both Patient objects have the same care card number.
	bool operator == (const Patient & rhs);

	// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the care card number of "this" Patient object is > the care card 
	//              number of "rhs" Patient object.
	bool operator > (const Patient & rhs);
	
	// For testing purposes!
	// Description: Prints the content of "this".
	friend ostream & operator<<(ostream & os, const Patient & p);

}; // end of Patient.h
