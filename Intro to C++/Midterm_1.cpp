#include <iostream>
using namespace std;


// QUESTION 2 ---------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

void areaByReference(double *height, double *width, double *area){
    *area = (*height * *width);
};

void areaByValue(double height, double width, double area) {
    area = height * width;
}

int	main()	{
    bool loop = true;
    double height;
    double width;
    double area = 0;
    string choice;
    string changeInput;
    
    while (loop) {
        cout << "Please enter the height of the rectangle.\n";
        cin >> height;
        
        cout << "Now enter the width.\n";
        cin >> width;
        
        if (height <= 0 || width <=0) {
            cout <<"Please ensure that you entered a valid height and width.\n";
            continue;
        };
        
        areaByValue(height, width, area);
        
        cout << "The area by value is: " << area << endl;
        
        areaByReference(&height, &width, &area);
        
        cout << "The area by reference is: " << area << endl;
        
        cout << "Rectangle area calculated. Would you like to re-enter values? Enter y for yes or any other character to quit.\n";
        
        cin >> choice;
        
        if (choice == "y"){
            area = 0;
            continue;
        }
        else {
            loop = false;
        }
    }
    return 0;
    
}
// END QUESTION 2-------------------------------------------------------------------------------------------------------------------------------------------------------------





// QUESTION 3-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    
    int nums[] = {1, 15, 32, 0, 21, 87};
    int *ptr;
    
    
    ptr = nums;
    
    cout << "The pointer starts at the value " << *ptr <<endl;
    
    ptr++;
    cout << "When incrementing by one, the pointer moves to the next value, which is " << *ptr <<endl;
    
    ptr--;
    cout << "If decrementing from here, the pointer goes back to the previous index, which is " << *ptr <<endl;
    
    
    ptr += 2;
    cout << "Further jumps than just one can happen, too. Two jumps puts us at the value " << *ptr;

    return 0;
}

// END QUESTION 3-------------------------------------------------------------------------------------------------------------------------------------------------------------



// QUESTION 4 -------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr1Size, arr2Size;
    //No preferred array type specified, defaulting to int.
    
    cout << "What is the size of array 1?\n";
    cin >> arr1Size;
    int arrEntry1[arr1Size];
    cout <<"Please enter the elements in array 1.\n";
    
    for (int i = 0; i < arr1Size; i++) {
        cin >> arrEntry1[i];
    }
    
    cout << "What is the size of array 2?\n";
    cin >> arr2Size;
    int arrEntry2[arr2Size];
    cout << "Please enter the elements in array 2.\n";
    
    for (int j = 0; j < arr2Size; j++) {
        cin >> arrEntry2[j];
    }
    
    int newSize = arr1Size + arr2Size;
    int combinedArr[newSize];
    cout << "The total number of elements is " <<newSize <<endl;
    
    //For loop for array1.
    for (int k = 0; k < arr1Size; k++) {
        combinedArr[k] = arrEntry1[k];
    }
    
    //For loop for array2. Because array2 starts in the combined array where array1 stops, there has to be a separate way to iterate through its contents.
    int iterateIndex = 0;
    for (int l = arr1Size; l < newSize; l++) {
        combinedArr[l] = arrEntry2[iterateIndex];
        iterateIndex++;
    }
    
    for (int m = 0; m < newSize; m++) {
        cout << combinedArr[m] << " ";
    }
}
// END QUESTION 4 -------------------------------------------------------------------------------------------------------------------------------------------------------------