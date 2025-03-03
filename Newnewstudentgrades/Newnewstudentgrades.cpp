// Studentgradesproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



//void print2DArray(int arr[][5], int rows, int cols) {
  //  for (int i = 0; i < rows; ++i) {
    //    for (int k = 0; k < cols; ++k) {
      //      std::cout << arr[i][k] << " ";
        //}
       // std::cout << std::endl;
    //}
//}
//prints 2d array for int grade list. Mainly used for troubleshooting



//void printnames(std::string arr[], int row)
//print 1d array for student name list. Also mainly used for troubleshooting
//{
  //  std::cout << "(";
    //for (int i = 0; i < row; ++i) {
      //  std::cout << "\"" << arr[i] << "\"";
        //if (i < row - 1) {;
          //  std::cout << ", ";
        //}
    //}
    //std::cout << ")" << std::endl;
//}

void Calculateaverages(int arr1[][5], double arr[],int noscor) {
    //Calculateaverage function- calculates the average of the list per row 
    //inputs=5 column array with an unbound number of rows, Also an array of type double to store the output
    // inputs cont=number of students represented by noscor variable
    //outputs=average for each row in the array stored in the double array passed to this function.
    //preconditions-need type double array for output and an integer array for data to compute with and # of students
    // or number of scores
    //postconditions=returns averages for each row in the 2D array and stores them in a 1D type double array

    for (int i = 0; i < noscor; ++i) {
        double sum = 0;
        for (int b = 0; b < 5; ++b) {
            sum += arr1[i][b];
        }
        arr[i] = (sum) / 5;
        if (arr[i] > 100 or arr[i] < 0) {
            break;
        }
    }





}

int readfileto2arr(const string& filename, string arr1[], int maxSize, int arr2[][5]) {
    //Readfileto2arraysfunction-inputs the file and first gets the names then gets the scores and stores
    //them in two separate arrays. It stores it in the first array then closes stream and clears then opens new stream
    // to store the integers in the second array using a catch throw error trap and a stoi converter. returns#students
    
    //inputs=filename,string array1 4 student names, int maxsize or max# of students, int array2 a 2d array for
    //storing array
    // outputs=stores names in string array1 and numbers in 2 D integer array 2, returns#students
    //preconditions=file must be capable of being opened and having data to read
    //postconditions=stores names and integers in separate partially filled out arrays,returns#students
    int noscors = 0;
    ifstream file(filename);
    if (!file.is_open()) { 
        //closes function if file isn't open
        cerr << "Problem opening file: " << filename << endl;
       
    }
    //

    string line; //initialize file name
    string studentname; //initialize student name 
    int row = 0; //intial row selected for second matrix
    int Cols = 5; //max number of columns
    int numgrades = 0;
    int i = 0; //index for array 1
    
    //Gets string data for student names and stores it in string array1[] or arr1[].
    while (getline(file, line))
    {
        stringstream s(line);
        s >> studentname;
        arr1[i] = studentname;
        i++;



    }
    file.close();
    file.clear();
    //closes and clears data from memory aside from names stored in arr1[] so that we can procede to 
    //get a list of integers to store into array 2 or arr2[][], a 2d array.
    ifstream filefpen(filename);
    while (getline(filefpen, line)) {
        stringstream sa(line);
        int col = 0;
        
        string newint; //newint will always exist making one of the arguments below always true in the while loop
        while (getline(sa, newint, ' ') && col < Cols) {
            //while you have the stringstream line, newint and an empty space 
            // and columns are less than max columns run
            try {
                //try to convert string to integer
                arr2[row][col] = stoi(newint);
                //this line through stoi converts string to integer
                col++;
                
            }
            catch (const invalid_argument& ia) {
                //throw out invalid arguments


            }


        }
        noscors++;
        row++;
       
    }
    
    filefpen.close();
    return noscors;
}

int lettergradeconverter(double rawscore[], int noscor, string lettergrade[]) {
    for (int i = 0; i < noscor; i++) {
        string grade;
        //Lettergradeconverter function-converts average to a letter grade per the prompt and counts # of letter grades
        // returns 1 if it can't convert average to lettergrade, 0 otherwise
        //inputs=double array,max # of scores for partially filled array or int noscor
        // inputs cont=lettergrade array
        //outputs=string letter grade array and the # of students data for the print function,flag for exit program
        //preconditions=double array, max # of scores to be read or int noscore and a lettergrade array to store output
        //postconditions=outputs the lettergrade onto the lettergrade array and stores the # of students in counterv
        // for print2screen function's use and only flags exit for program if can't convert lettergrade
         
        //assigns a letter grade for each element based on its place in iteration i

        if (rawscore[i] >= 90 && rawscore[i] <= 100) {
            grade = "A";
        }
        else if (rawscore[i] >= 80 && rawscore[i] <= 89.99) {
            grade = "B";
        }
        else if (rawscore[i] >= 70 && rawscore[i] <= 79.99) {
            grade = "C";
        }
        else if (rawscore[i] >= 60 && rawscore[i] <= 69.99) {
            grade = "D";
        }
        else if (rawscore[i] >= 0 && rawscore[i] <= 59.99) {
            grade = "F";
        }
        else {
            
            return 1;
        }

        lettergrade[i] = grade;
        
    }
    return 0;
}

void printresults2screen(double arr[], string arr1[], string arr2[],int counterv)
// printresults2screen functions-prints results to the screen using the 3 arrays, name, average and letter grade.
// Uses a counter to progress it.
// and total#students to limit the number displayed onscreen stored through variable integer counterv
//inputs=averages array, name array,grade array, and total#names stored in int counterv
//outputs=results displayed on screen
//preconditions=averages array type double, name array type string, and grade array type string and total#names as an int.
//postconditions=prints out the student names,averages, and grades to the screen.
{
    //constants for the alignment for the width
    const int namWidth = 10;
    const int averageWidth = 10;
    const int lgwidth = 10;
    int size = 10;
    //cout << counterv << "counterv again" << endl;
    //printing headers
    std::cout << left << setw(namWidth) << "Name" << setw(averageWidth) << "Average" << setw(lgwidth) << " Letter Grade" << endl;

    //printing separation space between header and columns

    std::cout << (namWidth + averageWidth + lgwidth, " ") << endl;

    //printing aligned columns


    //cout << "CounterV"<< counterv << endl;
  

    int j = 0;

    while ( j<counterv) {
        //counterv=max # of students, returned from the calculate student letter grade function
        cout << left << setw(namWidth) << arr1[j]<<
             setw(averageWidth) << arr[j] << right<< setw(2)<<
             arr2[j] << endl;
        j++;


    }




}


//This program initializes 4 parallel arrays-averages,names, lettergrade, and gradelist.
//Then it reads from a file and stores student names in the names array and scores in the gradelist array.
//Then it calculates the averagesm storing it in averages array and then converts letter grades
//storing it in the letter grade array
//The lettergrade functon is returned as an integer which counts the number of students in the class
//This integer is input into the printresults2screen to limit the number of results shown in the partially filled array.
//Then the results are printed onto the screen with appropriate header names and below them, appropriate data.
//If for whatever reason a letter grade cannot be computed due to either incorrect number of scores per student
//or average is above 100.0 then terminate program with correct error message

//Testing Notes:
//Please note that I tested this using 2 other functions that aren't part of the main anymore named printnames and
//print 2D array. I used these 2 functions for testing and for printing. I also hard coded numrows and numcols for
//one of them so that I could troubleshoot. Also note that I troubleshooted using counterv to count the number
//of iterations to ensure that I could see how many students the machine thought were in the class at which stage in the
//program. I didn't include a write up on these separate functions because they were more troubleshooting and were not
//"Official" functions in the main program but rather pseudocode at the end of the day after the testing was done.
//For they were used for troubleshooting and are not part of the main final program. But i commented them out in case
//anyone wanted to validate my troubleshooting style.

int main()
{
    int exitcond;//flag for if lettergrade can't compute, terminate program
    
    int noscores;//number of names derived from reading file
    double averages[] = { 0,0,0,0,0,0,0,0,0,0 };
    string names[] = { "n/a", "n/a", "n/a", "n/a","n/a","n/a", "n/a", "n/a", "n/a","n/a"};
    string lettergrade[] = { "n/a", "n/a", "n/a", "n/a","n/a","n/a", "n/a", "n/a", "n/a","n/a"};
    //int size = sizeof(names) / sizeof(names[0]); //used 4 testing 4 printnames func
    //printnames(names, size); //used for testing
    int gradelist[10][5] = { {999,999,999,999,999}, {999,999,999,999,999},
        {999,999,999,999,999}, {999,999,999,999,999}, {999,999,999,999,999},
        {999,999,999,999,999},{999,999,999,999,999},{999,999,999,999,999},
        {999,999,999,999,999},{999,999,999,999,999} };
    
    //print2DArray(gradelist, 10, 5);//used for testing

    //const int maxSize = 5; used for testing

    const string filename = "Studentgrades.txt";
    
    
     noscores=readfileto2arr(filename, names, 5, gradelist);
  
     
    //printnames(names, size); //used for testing
    //print2DArray(gradelist, 10, 5);//used for testing
     
    Calculateaverages(gradelist, averages,noscores);
    
     exitcond=lettergradeconverter(averages, noscores, lettergrade);//returns flag
    //terminates if lettergrade is not able to be calculated due to incorrect data
     if (exitcond == 1) {
         cout << "Error: check text file scores and try again" << endl;
     }
     else {
         //cout << "counterv here" << counterv << endl;
         printresults2screen(averages, names, lettergrade, noscores);
     }


}
