

/*START PROBLEM 1----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//Separate function not necessary, but it's good practice.
void calcVals(int* arr, int n) {

    //Just need totalHours and maxHours for now -- average can be calculated later.
    int totalHours = 0;
    int maxHours = 0;
    
    //Start at count w/ value of n (or the length of the array).
    int count = n;
    while (count != 0) {
      
      //Add the value pointed to by *arr to totalHours.
      totalHours += *arr;
      
      //If the array index being pointed to has a value larger than the current max, it becomes the new maximum value.
      if (*arr > maxHours) {
          maxHours = *arr;
      };
      
      //Move to next array element, decrement count since I'm "exhausting" the number of movements done. Another valid option is doing a for loop that increments to n - 1.
      arr++;
      count--;
      
    };
    
    //Average is total / num of elements. It looks like some extra steps might be needed for more exact values since entries is an array of integers.
    double avgHours = totalHours / n;
    
    //Print totalHours, avgHours, maxHours.
    cout << "The total hours studied are: " << totalHours << ".\nAnd the average amount of hours spent studying are: "<< avgHours <<".\nAnd the most hours spent studying are: "<< maxHours << ".";
        
};


int main() {
    //This will store the size of the array.
    int entrySize;
    
    //Prompt for array size, create new array called entries w/given size.
    cout << "Please enter the number of entries.\n";
    cin >> entrySize;
    int entries[entrySize];
    
    //Prompt for hours being entered, don't proceed until amount entered = entrySize - 1.
    cout << "Please enter each element.\n";
    for (int i = 0; i < entrySize; i++) {
        cin >> entries[i];;
    };
    
    //Create new pointer and have it point at the first element of entries.
    int *ptr = entries;
    
    //Pass to calcVals to do the rest of the process.
    calcVals(ptr, entrySize);
    
}
/*END PROBLEM 1------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*START PROBLEM 2----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

/*
Specific details organized by pointer type below.
*/

int main() {
    
    //Creating a constant and non-constant variable.
    int const a = 3;
    int b = 10;
    
    
    //Pointer to a constant: the address it points to can be changed, but the value can't.
    int const *ptr2 = &a;

    //Constant pointer to constant: the pointer cannot be changed to point to a different address, but the value of (in this example) b can be changed.
    int* const ptr4 = &b;
    
    //Regular pointer: address and value at that address can both be changed.
    int *ptr3 = &b;
    
    
    cout << "Initial:\n";
    cout << "ptr2 = ptr --> constant: " << *ptr2 << endl;
    cout << "ptr3 = constant ptr --> constant: " << *ptr3 << endl;
    cout << "ptr4 = regular pointer: "<< *ptr4 << endl;
    
    //This will change the value of b to 15.
    *ptr3 += 5;
    //This will also change the value of b, so it is now 25.
    *ptr4 += 10;
   
    
    cout << "\nResult:\n";
    cout << "ptr2 = ptr --> constant: " << *ptr2 << endl;
    cout << "ptr3 = constant ptr --> constant: " << *ptr3 << endl;
    cout << "ptr4 = regular pointer: "<< *ptr4 << endl;

    //The results show the two pointer types that can change the values of the variables they point to: ptr3 and ptr4.

    return 0;
}
/*END PROBLEM 2------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*START PROBLEM 3----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Pointer for dynamic allocation of students array.
    string *students = nullptr;
    string topStudent;
    
    //Pointer for dynamic allocation of grades array.
    double *grades = nullptr;
    double highestGrade = 0;
    int numStudents;
    
    cout << "Enter the number of students:\n";
    //Used to denote size of dynamic arrays.
    cin >> numStudents;
    
    //Dynamic allocation of both students and grades arrays.
    students = new string[numStudents];
    grades = new double[numStudents];
    
    for (int i = 0; i < numStudents; i++) {
    //Change student number in list with each iteration. Since arrays start w/0, add 1 to make it more user-friendly. (start @ student 1, not student 0).
        cout << "Please enter the name for student " << (i+1) << ": ";
        cin >> students[i];
        
        cout << "Please enter the test score for " << students[i] << ": ";
        cin >> grades[i];
        cout << "\n";
    };
    
    //To find the top score, iterate through the grades array, find index of highest score, use that same index to find name from names array.
    for(int i = 0; i < numStudents; i++) {
        
        if (grades[i] > highestGrade) {
            highestGrade = grades[i];
            topStudent = students[i];
        };
        
    };
    
    cout << "The student who received the highest grade is " << topStudent << ", with a score of " << highestGrade << ".";
    
    //Free the allocated memory.
    delete [] students;
    delete [] grades;
    students = nullptr;
    grades = nullptr;
    return 0;
}
/*END PROBLEM 3----------------------------------------------------------------------------------------------------------------------------------------------------------------*/