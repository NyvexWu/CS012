//include any standard libraries needed
#include<iostream>
#include<fstream>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
    ifstream inputFile;

   // verify file name provided on command line
    if (argc > 2)
    {
        return 0;
    }
   // open file and verify it opened
    inputFile.open(argv[1]);
    if(!inputFile.is_open())
    {
        return 0;
    }
   // Declare an array of doubles of size ARR_CAP.
    double arr[ARR_CAP];
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    double temp;
    int arrSize = 0;
    while(inputFile >> temp)
    {
        arr[arrSize] = temp;
        arrSize++;
    }
    
   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "mean: " <<  mean(arr, arrSize) << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    int indexVal;
    cout << "Enter index of value to be removed (0 to " << arrSize-1 << "): " << endl;
    cin >> indexVal;
    cout << endl;

   // Call the display function to output the array.
    cout << "Before removing value: ";
    display(arr, arrSize);
   
   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(arr, arrSize, indexVal);
    
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: ";
    display(arr, arrSize);
   
   // Call the mean function again to get the new mean
    cout << "Mean: " << mean(arr, arrSize);
   
	return 0;
}


double mean(const double array[], int arraySize)
{
    //  - Passes in an array along with the size of the array.
    //  - Returns the mean of all values stored in the array.
    double sum = 0;
    double avg;
    for (int i = 0; i < arraySize; i++)
    {
        sum = sum + array[i];
    }
    avg = sum / arraySize;
    return avg;
}


void remove(double array[], int& arraySize, int index)
{
    //  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
    //  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
    //  - Reduces arraySize by 1.
    for (int i = index; i < arraySize -1; ++i)
    {
        array[i] = array[i + 1];
    }
    arraySize = arraySize - 1;
}


void display(const double array[], int arraySize)
{
    // - Passes in an array and the size of the array.
    // - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
    cout << array[0];
    for (int i = 1; i < arraySize; i++)
    {
        cout << ", " << array[i];
    }
}