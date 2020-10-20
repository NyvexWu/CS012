#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   string inputFile;
   string outputFile;
   vector<int> fileInts;
   int temp;
   int count = 0;
   int sum = 0;
   int avg;
   if (argc < 3)
   {
       cout << "usage " << argv[0] << " inputfile outfile" << endl;
       exit(EXIT_FAILURE);
   }
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFile;
   // Verify file opened correctly.
   inFile.open(inputFile);
   // Output error message and return 1 if file stream did not open correctly.
   if (!(inFile.is_open()))
   {
       cout << "Error opening file " << inputFile << endl;
       exit(EXIT_FAILURE);
   }
   // Read in integers from input file to vector.
   while (inFile >> temp)
   {
       fileInts.push_back(temp);
       inFile.ignore();
       ++count;
   }
   // Close input stream.
   inFile.close();
   // Get integer average of all values read in.
   for (unsigned int i = 0; i < fileInts.size(); ++i)
   {
       sum = sum + fileInts.at(i);
   }
   avg = sum / count;
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < fileInts.size(); ++i)
   {
       fileInts.at(i) = fileInts.at(i) - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFile;
   outFile.open(outputFile);
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!(outFile.is_open()))
   {
       cout << "Error opening file" << outputFile << endl;
       exit(EXIT_FAILURE);
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   outFile << fileInts.at(0);
   for (unsigned int i = 1; i < fileInts.size(); ++i)
   {
       outFile << ", " << fileInts.at(i);
   }
   cout << endl;
   // Close output stream.
   outFile.close();
   return 0;
}