/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include <cstring>
#include "rank_functions.h"
#include <iomanip>

using std::cin; using std::cout; using std::endl;

int main()
{
    // TODO: create arrays needed
	double time[SIZE];
   // std::string country[SIZE];
    unsigned int drive_num[SIZE];
   // std::string name[SIZE];
    unsigned int rank[SIZE] = {1,1,1,1,1,1,1,1,1};
    char country[SIZE][STRING_SIZE];
    char lname[SIZE][STRING_SIZE];
    
    //char test[2][STRING_SIZE] = {"  Hel         ", "                   lps"};
    //prep_string_array(test);
    //trim(test[1]);
    
    

    // TOTO: prep all arrays
    prep_double_array(time);
    prep_unsigned_int_array(drive_num);
    //prep_unsigned_int_array(rank);
    prep_string_array(country);
    prep_string_array(lname);

    bool x = false;
    while(!x){
        x = get_driver_data(time,country,drive_num,lname);
        if(x){
            break;
        }
        cout << "Invalid Input." << endl;
        return 1;
    }
    
    
    //for(int i = 0; i < 2; ++i){
    //    cout << name[i] << endl;
    //}
	
    // TODO: load the driver's data into the array
    

    // if unable to load runner data
    //   1) output "Bad input" to standard out
    //   2) exit program by returning 1

    // TODO: determine ranking, notice the rank array receives the results
    set_rankings(time, rank);

    /*cout << "Final Results!" << endl;
    // TODO: Output results
    cout << "time  ";
    for (int i =0; i < 9; i++){
        cout << time[i] << " ";
    }
    cout << endl;
    cout << "name  ";
    for (int i =0; i < 9; i++){
        cout << name[i] << " ";
    }
    cout << endl;
    
    cout << "Rank ";
    for (int i = 0; i < 9; ++i){
        cout << rank[i] << " ";
    }
    */

    print_results(time, country, lname, rank);
    // this is not required in C++ but many people still explitly add it
    //return 0; 
}

