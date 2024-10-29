

/*START PROBLEM 1----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//Doing it as a separate function so I can get more practice w/pointers passed as arguments.
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
      
      //Move to next array element, decrement count since I'm "exhausting" the number of movements done.
      arr++;
      count--;
      
    };
    
    //Average is total / num of elements. It looks like some extra steps might be needed for more exact values.
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
    calcVals(entries, entrySize);
    
}
/*END PROBLEM 1------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*START PROBLEM 2----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

/*
Specific details organized by pointer type below.
*/

int main() {
    
    int const a = 3;
    int b = 10;
    
    // int *ptr1 = a can't be done as this pointer isn't constant.
    
    //However, this is considered a pointer to a constant, so this one DOES work.
    //This pointer can't edit the value at the address it's pointing to, but it is still capable of changing addresses.
    int const *ptr2 = &a;
    
    //This ptr acts as a regular pointer, no constant addresses pointed to, and it's not constant itself.
    int *ptr3 = &b;
    
    //This ptr is a constant pointer to a constant address.
    int* const ptr4 = &b;
    
    
    cout << "Initial:\n";
    cout << *ptr2 << endl;
    cout << *ptr3 << endl;
    cout << *ptr4 << endl;
    
    *ptr3 += 5;
    //The value of b is now 15.
    
    cout << "Result:\n";
    cout << *ptr2 << endl;
    cout << *ptr3 << endl;
    *ptr4 += 10;
    cout << *ptr4 << endl;
    
/*
    This shows that the only 
*/

    return 0;
}


/*END PROBLEM 2------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*START PROBLEM 3----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*END PROBLEM 3----------------------------------------------------------------------------------------------------------------------------------------------------------------*/