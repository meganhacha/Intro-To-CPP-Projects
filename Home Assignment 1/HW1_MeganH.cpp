// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
void problem1(double* arr, int arrSize);
void problem3(vector<double> temps);

//PROBLEM 1 PROGRAM -------------------------------------------------------------------------------------------------------------------------------------------------------------------
void problem1(double* arr, int arrSize) {
    //I assume there's a MAX-type value, but we haven't gone over it, so I'm doing 1000000.
    double smallest = 1000000; 
    double largest = 0;
    
    for(int i = 0; i < arrSize; i++) {
        
        if(arr[i] < smallest) {
            smallest = arr[i];
        };
        
        if (arr[i] > largest) {
            largest = arr[i];
        };
        
    };
    cout << "The largest value is: " << largest << " and the smallest is: " << smallest << "\n\n";
};
//END PROBLEM 1 PROGRAM -------------------------------------------------------------------------------------------------------------------------------------------------------------------




//PROBLEM 2 CLASS -------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Student{
    
    private:
        double grades[5];
        string name;
        bool pass;
        double average;
        
        void didPass() {
            if (average < 60) {
                pass = false;
            }
            else {
                pass = true;
            };
        }
        
    public:
        //Input grades, do calculations & such.
        void inputGrades(double* studentGrades) {
            int total = 0;
            
            for (int k = 0; k < 5; k++) {
                grades[k] = studentGrades[k];
                
                total += studentGrades[k];
            };
            
            average = total / 5;
            didPass();
        };
        
        void setName(string studentName) {
            name = studentName;
        };
        
        void displayAverage() {
            cout << "Average score: " << average;
        };
        
        void displayPassed() {
            if(pass == 0) {
                cout << "\n" << name << " did not pass.\n\n";
            }
            else {
                cout << "\n" << name << " passed.\n\n";
            };
        };
        
        
};
//END PROBLEM 2 CLASS -------------------------------------------------------------------------------------------------------------------------------------------------------------------



//PROBLEM 3 PROGRAM -------------------------------------------------------------------------------------------------------------------------------------------------------------------
void problem3(vector<double> temps) {
    double highest = 0;
    //Highest temp ever recorded was 56.7C (per NASA).
    double lowest = 56.7;
    double tempTotal = 0;
    
    for(double &val : temps) {
        tempTotal += val;
        
        if (val > highest) {
            highest = val;
        };
        
        if (val < lowest) {
            lowest = val;
        };
    };
    
    cout << "The average temperature is: " << tempTotal/temps.size() <<"C.\n";
    
    cout << "The highest temperature recorded is: " << highest << "C. The lowest temperature recorded is: " << lowest <<"C.\n";
    
    
};
//END PROBLEM 3 PROGRAM -------------------------------------------------------------------------------------------------------------------------------------------------------------------



//PROBLEM 4 CLASS -------------------------------------------------------------------------------------------------------------------------------------------------------------------

class BankAccount {
    
    private:
        int accountNumber;
        double balance;
        string accountHolderName;
        
    public:
        BankAccount(int acctNum, double initialBal, string holderName) {
            accountNumber = acctNum;
            balance = initialBal;
            accountHolderName = holderName;
        };
        
        void depositFunds(double amount) {
            balance += amount;
            
            cout << amount << " deposited. Your current balance is now " << balance <<".\n";
        }
        
        void withdrawFunds(double amount) {
            if (amount <= balance) {
                balance -= amount;
                
                cout << amount << " withdrawn from account. Current balance is now " << balance <<".\n";
            }
            else {
                cout << "Insufficient funds. Please try again.\n";
            };
        }
        
        
        void displayBalance() {
          cout << "Your current balance is " << balance << ".\n";  
        };
        
        string getName() {
            return accountHolderName;
        };
        
        
    
};

//END PROBLEM 4 CLASS -------------------------------------------------------------------------------------------------------------------------------------------------------------------




//Going through each in main to chain the problems.
int main() {

 //PROBLEM 1 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int size;
    string name;
    double grades[5];
        cout << "Problem 1: How many values are you entering?" << endl;
    cin >> size;
    
    if (size > 0) {
        double values[size];
        cout << "Enter the values:\n";
        for (int j = 0; j < size; j++) {
        cin >> values[j];
        
        };
        
        problem1(values, size);
    }
    else {
        cout << "Must have at least 1 value.\n\n";
    };
//END PROBLEM 1 -------------------------------------------------------------------------------------------------------------------------------------------------------------------




//PROBLEM 2 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    cout << "Problem 2:\nEnter the student's name:\n";
    cin >> name;
    
    cout << "Enter the student's 5 grades:\n";
    cin >> grades[0];
    cin >> grades[1];
    cin >> grades[2];
    cin >> grades[3];
    cin >> grades[4];
    
    Student student;
    student.setName(name);
    student.inputGrades(grades);
    student.displayAverage();
    student.displayPassed();
//END PROBLEM 2 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    


//PROBLEM 3 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    vector<double> temperatures(7);
    
    cout << "Enter the daily temperatures for the past 7 days.\n";
    
    for (double &temp : temperatures) {
        cin >> temp;
    };
    
    problem3(temperatures);
//END PROBLEM 3 -------------------------------------------------------------------------------------------------------------------------------------------------------------------




//PROBLEM 4 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int accountNum;
    double initialBalance;
    double deposit;
    double withdrawal;
    string acctHolderName;
    int runBankFunctions = 1;
    
    cout << "Please enter your account number.\n";
    cin >> accountNum;
    
    cout << "Please enter the account holder's name.\n";
    cin >> acctHolderName;
    
    cout << "Please enter the initial balance of this account.\n";
    cin >> initialBalance;
    
    BankAccount currentUser(accountNum, initialBalance, acctHolderName);
    cout << "Hello " << currentUser.getName() <<". ";
     
    while(runBankFunctions != 0) {
        
        cout << "Please choose from one of the following options:" << "\n1. Deposit funds\n2. Withdraw funds\n3. View current balance\n0. Exit the program.\n";
        
        cin >> runBankFunctions;
        
        if (runBankFunctions == 1) {
            cout << "Enter the amount you would like to deposit.\n";
            cin >> deposit;
            
            currentUser.depositFunds(deposit);
        }
        else if (runBankFunctions == 2) {
            cout << "Enter the amount you would like to withdraw.\n";
            
            cin >> withdrawal;
            currentUser.withdrawFunds(withdrawal);
        }
        else if (runBankFunctions == 3) {
            currentUser.displayBalance();
        }
        else if (runBankFunctions == 0) {
            exit(0);
        }
        else {
            cout << "Entry not valid. Please enter the number of the action you would like to perform.\n";
        }
        
        runBankFunctions = 1;
    };
//END PROBLEM 4 -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    return 0;
};