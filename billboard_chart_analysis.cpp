/* ---------------------------------------------
Program 4: Billboard Analysis

Course: CS 141, Spring 2022. Tues 9 am lab
System: Windows using CLion
Author: Filip Toloczko
---------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <algorithm>
using namespace std;

//Function to get position for each year from 1960-1980
int returnYear(string year){
  int addYears;
  
  if(year=="1960"){addYears=52138;}
  else if(year=="1961"){addYears=49538;}
  else if(year=="1962"){addYears=46938;}
  else if(year=="1963"){addYears=44338;}
  else if(year=="1964"){addYears=41738;}
  else if(year=="1965"){addYears=39138;}
  else if(year=="1966"){addYears=36488;}
  else if(year=="1967"){addYears=33888;}
  else if(year=="1968"){addYears=31288;}
  else if(year=="1969"){addYears=28688;}
  else if(year=="1970"){addYears=26088;}
  else if(year=="1971"){addYears=23488;}
  else if(year=="1972"){addYears=20838;}
  else if(year=="1973"){addYears=18238;}
  else if(year=="1974"){addYears=15588;}
  else if(year=="1975"){addYears=13038;}
  else if(year=="1976"){addYears=10443;}
  else if(year=="1977"){addYears=7801;}
  else if(year=="1978"){addYears=5202;}
  else if(year=="1979"){addYears=2602;}
  else if(year=="1980"){addYears=2;}

  return addYears;
}

//Function to get position for each year from 1981-2000
int returnYear81(string year){
  int addYears;
  
  if(year=="1981"){addYears=49602;}
  else if(year=="1982"){addYears=47002;}
  else if(year=="1983"){addYears=44352;}
  else if(year=="1984"){addYears=41752;}
  else if(year=="1985"){addYears=39152;}
  else if(year=="1986"){addYears=36552;}
  else if(year=="1987"){addYears=33952;}
  else if(year=="1988"){addYears=31302;}
  else if(year=="1989"){addYears=28702;}
  else if(year=="1990"){addYears=26102;}
  else if(year=="1991"){addYears=23502;}
  else if(year=="1992"){addYears=20902;}
  else if(year=="1993"){addYears=18302;}
  else if(year=="1994"){addYears=15652;}
  else if(year=="1995"){addYears=13052;}
  else if(year=="1996"){addYears=10452;}
  else if(year=="1997"){addYears=7852;}
  else if(year=="1998"){addYears=5252;}
  else if(year=="1999"){addYears=2652;}
  else if(year=="2000"){addYears=2;}

  return addYears;
}

//Function to display the opening message
void displayOpeningMessage(){
  cout<<"Program 4: BillBoard Analysis "<<endl;
  cout<<"CS 141, Spring 2022, UIC \n "<<endl;
  cout<<"This program will analyze weekly Billboard data spanning from 1960 - 2020.\n"<<endl;
  cout<<"Select file option:"<<endl;
  cout<<"   1. To analyze charts top 50: 1960 - 1980 data file"<<endl;
  cout<<"   2. To analyze charts top 50: 1981 - 2000 data file"<<endl;
  cout<<"   3. To analyze charts top 50: 2001 - 2020 data file"<<endl;
  cout<<"Your choice --> \n";
}

//Function to display menu options
void displayMenuOptions(){
  cout << "\nSelect a menu option: " << endl;
  cout << "   1. Display overall information about the data" << endl;
  cout << "   2. Display the Billboard info of the song with the most #1 occurrences for a given decade or year" << endl;
  cout << "   3. Display the Billboard info for the most long-lasting song on the charts for a given decade or year" << endl;
  cout << "   4. Display the Billboard info for the song with the greatest weekly climb on the charts given a decade or year" << endl;
  cout << "   5. Artist Search - Return the Billboard info for records that matches user input for artist search" << endl;
  cout << "   6. Exit" << endl;
  cout << "Your choice --> ";
}

//Function to get number of songs in file from 1960 to 1980
void getTopSongs60To80(){
  //variable declarations
 	string line, object;
  int numberOfEntries = 0;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream string(line);
		while(getline(string, object, ','))
			individualSongData.push_back(object);
		listOfSongData.push_back(individualSongData);
	}
  //incriment the variable storing the number of entries
	for(int songData=1;songData<listOfSongData.size();songData++){
    numberOfEntries+=1;
	}
  cout << numberOfEntries << endl;
}
//Function to get the amount of unique songs from 1960 to 1980
void getTotalSongs60To80(){
	//variable declarations
  string line, object;
  vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream string(line);
		while(getline(string, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //loop that stores one of each song title into a new vector
	for(int songData=1;songData<listOfSongData.size();songData++){
		if (find(uniqueSongs.begin(), uniqueSongs.end(), listOfSongData[songData][2]) != uniqueSongs.end()){
      continue;
    }
    else{
      uniqueSongs.push_back(listOfSongData[songData][2]);
    }
	}
  cout << uniqueSongs.size() << endl;
}

//Function to get number of songs in file from 1981 to 2000
void getTopSongs81To00(){
  //variable declarations
  string line, object;
  int numberOfEntries = 0;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream string(line);
		while(getline(string, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);  
	}
 
  //incriment the variable storing the number of entries
	for(int songData=1;songData<listOfSongData.size();songData++){
    numberOfEntries+=1;
	}
  cout << numberOfEntries << endl;
}

//Function to get the amount of unique songs from 1981 to 2000
void getTotalSongs81To00(){
	//variable declarations
  string line, object;
  vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //loop that stores one of each song title into a new vector
	for(int songData=1;songData<listOfSongData.size();songData++){
		if (find(uniqueSongs.begin(), uniqueSongs.end(), listOfSongData[songData][2]) != uniqueSongs.end()){
      continue;
    }
    else{
      uniqueSongs.push_back(listOfSongData[songData][2]);
    }
	}
  cout << uniqueSongs.size() << endl;
}

//Function to get the most popular song from 1960-1969
void getMostPopular60To69(){
  //variable declarations
  string number,author,title,line,object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=28688;listPosition<54737;listPosition++){
    uniqueSongs.push_back(listOfSongData[listPosition][6]);
  }	
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }
  
  //Variable declarations
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin())+28688;
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];

  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function to get the most popular song from 1970-1979
void getMostPopular70To79(){
  //variable declarations
  string number, author, title, line, object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=2602;listPosition<28687;listPosition++){
    uniqueSongs.push_back(listOfSongData[listPosition][6]);
  }	
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }
  
  //Variable declarations
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin())+2602;
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];
  
  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function to get the most popular song from 1981-1989
void getMostPopular81To89(){
  //Variable Declaration
  string number,author,title,line,object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=28702;listPosition<52201;listPosition++){
    uniqueSongs.push_back(listOfSongData[listPosition][6]);
  }	
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }
  
  //Variable declarations
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin())+28702;
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];
  
  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function to get the most popular song from 1989-1999
void getMostPopular90To99(){
  //Variable Declaration
  string number, author, title, line, object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=2802;listPosition<28701;listPosition++){
    uniqueSongs.push_back(listOfSongData[listPosition][6]);
  }	
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }

  //Variable declarations
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin())+2802;
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];
  
  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function to get the most popular song from 2000
void getMostPopular2000(){
  //Variable Declaration
  string number, author, title, line, object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=2;listPosition<2651;listPosition++){
    uniqueSongs.push_back(listOfSongData[listPosition][6]);
  }
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }
  
  //Variable declarations
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin())+2;
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];
  
  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function to get the most popular song from given year
void getMostPopularYear(string year){
  //Variable Declaration
  string number, author, title, line, object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;
 
	//open the csv file and read contents into a vector
  fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=1;listPosition<54737;listPosition++){
    string name;
    string split;
    name = listOfSongData[listPosition][0];
    split = name.substr( name.length() - 4 );
    if (split.find(year) != string::npos){
      uniqueSongs.push_back(listOfSongData[listPosition][6]);
    }
    else{
      continue;
    }
  }
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }
  
  //Variable declarations
  int addedYear = returnYear(year);
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin()+addedYear-1);
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];
  
  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;  
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Function get the most popular song from given year
void getMostPopularYear81(string year){
  //Variable Declaration
  string number, author, title, line, object;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<string> uniqueSongs;
  vector<int> topPositions;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass weeks on board values into a new vector
	for(int listPosition=1;listPosition<52201;listPosition++){
    string name;
    string split;
    name = listOfSongData[listPosition][0];
    split = name.substr( name.length() - 4 );
    if (split.find(year) != string::npos){
      uniqueSongs.push_back(listOfSongData[listPosition][6]);
    }
    else{
      continue;
    }
  }
  for (int listPosition = 0; listPosition<uniqueSongs.size(); listPosition++){
    number = uniqueSongs[listPosition];
    stringstream song(number);
    int songInt = 0;
    song >> songInt;
    topPositions.push_back(songInt);
  }

  //Variable declarations
  int addedYear = returnYear81(year);
  int maxSongIndex = (max_element(topPositions.begin(),topPositions.end()) - topPositions.begin()+addedYear-1);
  int maxSong = *max_element(topPositions.begin(), topPositions.end());
  title = listOfSongData[maxSongIndex][2];
  author = listOfSongData[maxSongIndex][3];

  //display outcome of option 3
  cout << "The song with the highest number of weeks on the charts is:" << endl;  
  cout << "        " << title << " by " << author << " with " << maxSong << " weeks on the chart.\n" << endl;
}

//Finds the most popular songs for a given artist from 1960-1980
void artistSearch60To80(string performer){
  //Variable Declarations
  string number,artist,artistUpperCase,position,title,dates,line,object;
  int numberSong = 1;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<vector<string>> songTitles;
  vector<string> artists;
  vector<int> topPositions;
  vector<string> checkName;
 
	//open the csv file and read contents into a vector
  fstream listOfSongs ("charts_top50_1960_1980.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass values into a new vector
	for(int listPosition=1;listPosition<54737;listPosition++){
    position = (listOfSongData[listPosition][1]);
    if (position=="1"){
      vector<string> entry;
      title = (listOfSongData[listPosition][2]);
      dates=(listOfSongData[listPosition][0]);
      artist=(listOfSongData[listPosition][3]);
      artistUpperCase=(listOfSongData[listPosition][3]);
      transform(artist.begin(), artist.end(), artist.begin(), ::tolower);
      entry.push_back(title);
      entry.push_back(dates);
      entry.push_back(artist);
      entry.push_back(artistUpperCase);
      songTitles.push_back(entry);
    }
    else{
      continue;
    }
  }

  //Loop through vector and print first 10 #1 songs for an artist
  for(int listPosition=0; listPosition<songTitles.size(); listPosition++){
    if(songTitles[listPosition][2].find(performer) != string::npos){          
      if (numberSong <= 10){
        if(numberSong == 1){
          cout << "Retrieval of first 10 #1 records found based upon search by artist name: " << endl;
        }
        cout<<numberSong<<") Song: " << songTitles[listPosition][0] << endl;
        cout << "    Artist: " << songTitles[listPosition][3] << endl;
        cout << "    Week of: " << songTitles[listPosition][1] << endl;
        cout << "    Week Position: 1" << endl;
        numberSong=numberSong+1;
        checkName.push_back(songTitles[listPosition][3]);
    }
    }
    else{
      continue;
    }
  }
  //If the vector is empty, return the following message
  if (checkName.size() == 0){
    cout << "No matching artists were found." << endl;
  }
}

//Finds the most popular songs for a given artist from 1981-2000
void artistSearch81To00(string performer){
  //Variable declarations
  string number, artist, artistUpperCase,position,title,dates,line,object;
  int numberSong = 1;
	vector<vector<string>> listOfSongData;
	vector<string> individualSongData;
	vector<vector<string>> songTitles;
  vector<string> artists;
  vector<int> topPositions;
  vector<string> checkName;

  //open the csv file and read contents into a vector
	fstream listOfSongs ("charts_top50_1981_2000.csv");
	while(getline(listOfSongs, line)){
		individualSongData.clear();
		stringstream str(line);
		while(getline(str, object, ',')){
			individualSongData.push_back(object);
    }
		listOfSongData.push_back(individualSongData);
	}

  //create a new vector and pass values into a new vector
	for(int listPosition=1;listPosition<52201;listPosition++){
    position = (listOfSongData[listPosition][1]);
    if (position=="1"){
      vector<string> entry;
      title = (listOfSongData[listPosition][2]);
      dates=(listOfSongData[listPosition][0]);
      artist=(listOfSongData[listPosition][3]);
      artistUpperCase=(listOfSongData[listPosition][3]);
      transform(artist.begin(), artist.end(), artist.begin(), ::tolower);
      entry.push_back(title);
      entry.push_back(dates);
      entry.push_back(artist);
      entry.push_back(artistUpperCase);
      songTitles.push_back(entry);
    }
    else{
      continue;
    }
  }

  //Loop through vector and print first 10 #1 songs for an artist
  for(int listPosition=0; listPosition<songTitles.size(); listPosition++){
    if(songTitles[listPosition][2].find(performer) != string::npos){         
      if (numberSong <= 10){
        if(numberSong == 1){
          cout << "Retrieval of first 10 #1 records found based upon search by artist name: " << endl;
        }
        cout<<numberSong<<") Song: " << songTitles[listPosition][0] << endl;
        cout << "    Artist: " << songTitles[listPosition][3] << endl;
        cout << "    Week of: " << songTitles[listPosition][1] << endl;
        cout << "    Week Position: 1" << endl;
        numberSong=numberSong+1;
        checkName.push_back(songTitles[listPosition][3]);
    }
    }
    else{
      continue;
    }
  }
  //If the vector is empty, return the following message
  if (checkName.size() == 0){
    cout << "No matching artists were found." << endl;
  }
}

//Main function
int main(){
  //Variable Declarations
  int choice;
  int menuOption;
  char timeOption;
  int yearChoice;
  
  //Calling The displayOpeningMessage() function
  displayOpeningMessage();
  //Get user input for display menu choice
  cin >> choice;
  
  //Loop that runs the program
  while (true){
    //display option 1
    if(choice == 1){
      //Call the displayMenuOptions() function
      displayMenuOptions();  
      //get user input for menu option
      cin >> menuOption;

      //menu option 1
      if(menuOption == 1){
          cout << "Total number of rows: ";
          getTopSongs60To80();
          cout << "Number of unique songs represented in the dataset: ";
          getTotalSongs60To80();
        }
      //menu option 2
      else if(menuOption == 2){
          cout << "Enter D to select a decade or Y to select a year." << endl;
          break;
        }
      //menu option 3
      else if(menuOption == 3){
          while(true){
          cout << "Enter D to select a decade or Y to select a year." << endl;
          cin >> timeOption;
          timeOption = tolower(timeOption);
          if ((timeOption != 'd') && (timeOption != 'y')){
            cout << "Your choice --> Invalid entry. Try again." << endl;
            continue;
          }
          else{
            if(timeOption == 'y'){
              cout<<"Your choice --> Enter the year you would like to choose (e.g. 2001)." << endl;
            }
            else if (timeOption == 'd'){
              cout << "Your choice --> Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010)." << endl;
            }
            cin >> yearChoice;
            if ((yearChoice<1960) || (yearChoice>1980)){
              cout << "No songs found in that timeframe. Be sure that the timeframe you";
              cout << "enter is within the one covered by the dataset chosen." << endl;
              break;
            }
            else{
              if(timeOption == 'd'){
                if((yearChoice>=1960) && (yearChoice<1970)){
                  getMostPopular60To69();
                  break;
                }
                else if ((yearChoice>=1970) && (yearChoice<1980)){
                  getMostPopular70To79();
                  break;
                }
                else if (choice == 1980){
                  return 0;
                }
              }
              else if(timeOption == 'y'){
                string p = to_string(yearChoice);
                getMostPopularYear(p);
                break;
              }
            }
          }
        }
      }
      //menu option 4
      else if(menuOption == 4){
          break;
        }
      //menu option 5
      else if(menuOption == 5){
        string performer;
        cout << "Enter search text to retrieve first 10 records of #1 songs that match by artist name: " << endl;
        cin.ignore();
        getline(cin, performer);
        transform(performer.begin(), performer.end(), performer.begin(), ::tolower);
        artistSearch60To80(performer);  
        }
      //menu option 6
      else if(menuOption == 6){
          break;
        }
      //invalid menu option  
      else{
          cout << "\nInvalid value.  Please re-enter a value from the menu options below." << endl;
          continue;
        }
      }
    //display option 2
    else if(choice == 2){
      displayMenuOptions();
      cin >> menuOption;

      //menu option 1
      if(menuOption == 1){
        cout << "Total number of rows: ";
        getTopSongs81To00();
        cout << "Number of unique songs represented in the dataset: ";
        getTotalSongs81To00();
      }
      //menu option 3
      else if(menuOption == 3){
        while(true){
          cout << "Enter D to select a decade or Y to select a year." << endl;
          cin >> timeOption;
          timeOption = tolower(timeOption);
          if ((timeOption != 'd') && (timeOption != 'y')){
            cout << "Your choice --> Invalid entry. Try again." << endl;
            continue;
          }
          else{
            if(timeOption == 'y'){
              cout<<"Your choice --> Enter the year you would like to choose (e.g. 2001)." << endl;
            }
            else if (timeOption == 'd'){
              cout << "Your choice --> Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010)." << endl;
            }
            cin >> yearChoice;
            if ((yearChoice<1980) || (yearChoice>2000)){
              cout << "No songs found in that timeframe. Be sure that the timeframe you";
              cout << "enter is within the one covered by the dataset chosen." << endl;
              break;
            }
            else{
              if(timeOption == 'd'){
                if((yearChoice>=1980) && (yearChoice<1990)){
                  getMostPopular81To89();
                  break;
                }
                else if ((yearChoice>=1990) && (yearChoice<2000)){
                  getMostPopular90To99();
                  break;
                }
                else if (yearChoice == 2000){
                  getMostPopular2000();
                }
            }
            else if(timeOption == 'y'){
              string p = to_string(yearChoice);
              getMostPopularYear81(p);
              break;
            }
              }
            }
          }
        }
      //menu option 5
      else if(menuOption == 5){
        string performer;
          cout << "Enter search text to retrieve first 10 records of #1 songs that match by artist name: " << endl;
          cin.ignore();
          getline(cin, performer);
          transform(performer.begin(), performer.end(), performer.begin(), ::tolower);
          artistSearch81To00(performer);
      }
      //menu option 6
      else if(menuOption == 6){
          break;
        }
      //invalid menu option
      else{
        cout << "\nInvalid value.  Please re-enter a value from the menu options                     below." << endl;
        continue;
      }
    }
    //invalid display choice
    else{
        cout << "Invalid value. Exiting Program.";
      break;
      }
    }
  }
  


