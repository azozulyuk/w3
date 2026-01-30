
/* Citation and Sources...
-----------------------------------------------------------
Workshop 3
Module: 3
Filename: CC.cpp
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
#include <iostream>//for input and output 
#include <iomanip>//for formatting
#include "CC.h"//include the credir class header 
#include "cstr.h"//custom string 
using namespace std;//allow us using std
namespace seneca {
    void CC::set() {
        m_name = nullptr;//set pointer to null
        m_number = 0;//reset all card data:
        m_cvv = 0;
        m_expMon = 0;
        m_expYear = 0;
    }
      CC::CC() {
        set();//object now empty 
    }
       CC::CC(const char* name,
        unsigned long long number,
        short cvv,
        short expMon,
        short expYear) {
          set();
            if (validate(name, number, cvv, expMon, expYear)) {
            aloCopy(name);//copy card holder name 
          m_number = number;//store all data about card
            m_cvv = cvv;
            m_expMon = expMon;
            m_expYear = expYear;
        }
       }
    CC::~CC() {
        deallocate();//dree dynamic memory 
     }
        void CC::aloCopy(const char* name) {
        m_name = new char[strlen(name) + 1];//allocate memory for name 
        strcpy(m_name, name);//copy into memory 
    }
        void CC::deallocate() {
        delete[] m_name;//delete the allocated memory 
        m_name = nullptr;//set pointer to null
    }
      bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear) const {
      return name != nullptr &&//name must exist 
            strlen(name) > 2 &&//longer than 2 characters
            cardNo >= 4000000000000000ull &&//card range start
            cardNo <= 4099999999999999ull &&//range end 
            cvv >= 100 && cvv <= 999 &&//CVV default 3 digits
            expMon >= 1 && expMon <= 12 &&//month valid 
            expYear >= 24 && expYear <= 32;//year valid check 
       }
      void CC::prnNumber(unsigned long long n) const {
          cout << (n / 1000000000000ULL) << " "//print the first group 
              << setw(4) << setfill('0') << (n / 100000000ULL % 10000ULL) << " "
              << setw(4) << setfill('0') << (n / 10000ULL % 10000ULL) << " "
              << setw(4) << setfill('0') << (n % 10000ULL);
          cout << setfill(' ');//reset fill character
      }

   void CC::display(const char* name,
        unsigned long long number,
        short expYear,
        short expMon,
        short cvv) const {
         char lname[31]{};//local array 
      strcpy(lname, name, 30);//copy name from cstr.h
         cout << "| ";
         cout.width(30);
         cout.fill(' ');
        cout.setf(ios::left);
          cout << lname << " | ";
          cout.unsetf(ios::left);
          prnNumber(number);//print formatted number 
         cout << " | " << cvv << " | ";
       cout.unsetf(ios::left);//alligning ( left) 
            cout.setf(ios::right);//right
           cout.width(2);
          cout << expMon << "/" << expYear << " |" << endl;
         cout.unsetf(ios::right);
       }
          bool CC::isEmpty() const {
        return m_name == nullptr;
   }
       void CC::set(const char* cc_name,
        unsigned long long cc_no,
          short cvv,
          short expMon,
         short expYear) {
        deallocate();
        set();
          if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            aloCopy(cc_name);
             m_number = cc_no;
             m_cvv = cvv;
          m_expMon = expMon;
            m_expYear = expYear;
            }
        }
        void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;//check if empty 
        }
            else {
            display(m_name, m_number, m_expYear, m_expMon, m_cvv);//show all info
        }
    }
}
