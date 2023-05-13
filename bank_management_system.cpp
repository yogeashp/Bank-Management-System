#include <iostream>

using namespace std;


class Bank_management_sys 

{

private:

    int acno;
    char name[30];
    long balance;

public:

    Bank_management_sys(){
        acno = 0 ;
        balance = 0  ;
    }

    void Open_Account();
    void Show_Account();
    void deposit();
    void Withdrawal();
    int Search_id(int);

};



void Bank_management_sys :: Open_Account(){
        
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter  Balance: ";
        cin >> balance;
        cout<<endl;
}

void Bank_management_sys :: Show_Account(){

        cout<<"-----------------------------------\n";
        cout<<"\n";
        cout << "\tAccount Number: " << acno << endl;
        cout << "\tName: " << name << endl;
        cout << "\tBalance Ammount: " << balance << endl;
        cout<<"\n";
        cout<<"-----------------------------------";
        cout<<endl;
}

void Bank_management_sys :: deposit(){
        
        long amt;
        cout<<endl;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
        cout<<endl;
}

void Bank_management_sys :: Withdrawal()
    {
        long amt;
        cout << "Enter Amount U want to withdraw? ";
        cin >> amt;
        cout<<endl;
        if (amt <= balance){

            balance = balance - amt;
            cout<<"Balance Amount in Account "<< acno <<" is: "<<balance;
        }
        else{
            cout << "Less Balance..." << endl;
        }
        cout<<endl;
    }

int Bank_management_sys::Search_id(int a)
{
    if (acno == a) {
        Show_Account();
        return (1);
    }
    return (0);
}

// main Program
int main()
{

    cout<<"\n\t\t\t BANK MANAGEMENT SYSTEM \n\n\n";
    
    // Variable Decleration 
    int n ;
    int to_be_found = 0; 
    int a; 
    int ch;

    // To get number of data's to be entered
    
    cout << "Enter the No of details to be Entered : ";
    cin>>n ; 
    cout<<endl;
    
    //Object of the class Bank_management_system having n objects
   
    Bank_management_sys C[n]; 

    for (int i = 0; i < n; i++) 
        C[i].Open_Account();
    
    do {
        
        // Display options
        
        cout << "\n\t1: Display All Accounts \n\t2: Display By Account No\n\t3: Deposit\n\t4: Withdraw\n\t5: Exit" << endl;

        // User input
        cout<<'\n';
        cout << "Please enter your choice: ";
        cin >> ch;
        cout<<endl;
 
        switch (ch) {
        case 1: // To display account information
            
            for (int i = 0; i < n; i++) {
                C[i].Show_Account();
            }
            break;
       
        case 2: // To search Detail 
    
            cout << "Account Number: ";
            cin >> a;
            cout<<endl;

            for (int i = 0; i < n; i++) {
                to_be_found = C[i].Search_id(a);
                if (to_be_found)
                    break;
            }

            if (!to_be_found)
                cout << "Record Not Found !" << endl;
            break;
       
       case 3: // deposit operation
            
            cout << "Enter Account Number To Deposit Amount: ";
            cin >> a;
            cout<<endl;
            
            for (int i = 0; i < n; i++) {
                to_be_found = C[i].Search_id(a);
                if (to_be_found) {
                    C[i].deposit();
                    cout<<"   Account Detail After Deposit ! \n";
                    C[i].Show_Account();
                    break;
                }
            }
            
            if (!to_be_found)
                cout << "Record Not Found !" << endl;
            break;
        
        case 4: // withdraw operation
            
            cout << "Enter Account Number To Withdraw Amount: ";
            cin >> a;
            for (int i = 0; i < n; i++) {
                to_be_found = C[i].Search_id(a);
                if (to_be_found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            
            if (!to_be_found)
                cout << "Record Not Found !" << endl;
            break;
        
        case 5: // exit
            
            cout << "Thank You ! For using Our System \n" << endl;
            break;
        
        default:
            
            cout << " Incorrect  Option" << endl;
        }
    } while (ch != 5);

    return 0;
}