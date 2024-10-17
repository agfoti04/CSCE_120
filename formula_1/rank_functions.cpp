#include <iostream>
#include <iomanip>
#include <cstring>
#include "rank_functions.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	for(int i = 0; i < 9; ++i){
		ary[i] = 0.0;
	}
	
  //TODO
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	for(int i =0; i < 9; ++i){
		ary[i] = 0;
	}
  //TODO
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{	char set[STRING_SIZE] = "N/A"; 
	for(int i = 0; i < 9; ++i){
		strcpy(ary[i], set);
	}
	//TODO
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	int len = strlen(str);
    int index = 0;   

    bool word = false; 
    int start = 0;      

    while (isspace(str[start])) {
        start++;
    }
    for (int i = start; i < len; ++i) {
        if (!isspace(str[i])) {
            
            str[index++] = str[i];
            word = true;
        } else if (word) {
            
            if (str[i] == ' ') {
                str[index++] = ' ';
                word = false; 
            }
        }
    }
    if (index > 0 && str[index - 1] == ' ') {
        index--;
    }

    str[index] = '\0';
}

//-------------------------------------------------------
// Name: get_driver_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_driver_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
	
		unsigned int temp1;
    	char temp2[STRING_SIZE];
    	double temp3;
		char temp4[STRING_SIZE];
	for(int i = 0; i < 9; ++i){
		//time data valid
		cin >> temp3;
		if(temp3 <= 0){
			//cout << "Invalid Input." << endl;
			return false;
		}
		else{
			timeArray[i] = temp3;
			//cout << "Good input" << endl;
			temp3 = 0.0;
			}
		//country data valid
		cin >> temp2;
		if(strlen(temp2) != 3){
			//cout << "Invalid Input." << endl;
			return false;
		}
		else{
			for(int j = 0; j < 3; ++j){
				if(!isalpha(temp2[j]) || !isupper(temp2[j])){
					//cout << "Invalid Input." << endl;
					return false;
				}
				countryArray[i][j] = temp2[j];
				//cout << "YIPPE!" << endl;
				
			}
			
			
			
		}
		//number data valid
		cin >> temp1;
		if(temp1 < 100){
			numberArray[i] = temp1;
			//cout << "Horray" << endl;
		}
		else{
			return false;
		}

		
		cin >> temp4;
		trim(temp4);
		
		//cout << temp4 << endl;

		if(strlen(temp4) < 1){
			return false;
		}
		
		else{
			for(int j = 0; j < int(strlen(temp4)); ++j){
				if(!isalpha(temp4[j]) && temp4[j] != ' '){
					//cout << "Invalid Input." << endl;
					return false;
				}
				if(isalpha(temp4[j])){
					//lastnameArray[i][j] = temp4[j];
				}
				
				
				//cout << "Yppiee!!!!" << endl;
			}
			strcpy(lastnameArray[i], temp4);
			
		}
		//cout << "good boy" << endl;

		if(i > 8){
			return true;
		}

		
	}
  //TODO
  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: set_rankings
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void set_rankings(const double timeArray[], unsigned int rankArray[])
{
	
	//cout << timeArray[1];
	for(int i = 0; i < 9; ++i){
		rankArray[i] = 1;
	}

	for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (timeArray[j] < timeArray[i]) {
                //cout << timeArray[i] << endl;
                rankArray[i]++;
            }
        }
    }
	
	
	

	//TODO
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}