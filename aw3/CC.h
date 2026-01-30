
/* Citation and Sources...
-----------------------------------------------------------
Workshop 3
Module: 3
Filename: CC.h
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2026/01/28  Completing code
V0.8    2026/01/29  Debugged DMA
V0.9    -         Asked prof for help for XYZ
V1.0    2026/01/30  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/

#pragma once
#ifndef SENECA_CC_H//check if the header is not defined 
#define SENECA_CC_H

     namespace seneca {//start seneca namespace 

      class CC {//credit card class
          char* m_name;//store the name 
        unsigned long long m_number;//card number 
          short m_cvv;//cvv storing 
        short m_expMon;//the expiry month storing 
        short m_expYear;//the expiry year storing

           void aloCopy(const char* name);//allocate memory/store 
           void deallocate();//frees the memory 

        bool validate(const char* name,//check if the info is valid 
            unsigned long long cardNo,
            short cvv,
            short expMon,
            short expYear) const;

          void prnNumber(unsigned long long CCnum) const;//print the card number 

           void display(const char* name,
            unsigned long long number,
            short expYear,
            short expMon,
            short cvv) const;

       public:
           CC();//def constructor 
          CC(const char* name,
            unsigned long long number,
            short cvv,
            short expMon = 12,
            short expYear = 26);
        ~CC();//destructor 

        void set();//sets card data from user
        bool isEmpty() const;//check if the object is empty 

           void set(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon,
            short expYear);

        void display() const;//display the card 
        };

}

#endif
