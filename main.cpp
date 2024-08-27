#include <iostream>
#include <memory>
#include "Song.h"
#include<sstream>
#include<fstream>
// max size of the dynamic array
const int SIZE = 300;
//selection sort to sort according to chart position
int sortSongs(Song **, int size);


//print the top ten songs in the sorted array
void printTopTen(Song **,int size);
//print all the songs in the array
void print(Song**,int size);

//returns the actual number of songs read
// if more songs than size, then they are ignored.

int populateArray(std::string filename, Song**);
//search by title
int searchASong(Song** dataArray,int size);
//get the song by chart position
Song getSong(Song** dataArray, int size, int chartPosition);


int main() {
  // create a dynamic array of pointers to Song objects
   Song ** dataArray = new  Song*[SIZE];
  //populate the array by reading data from the file
   int size=populateArray("SongsData.txt",dataArray);
   //print the data Array
   //print(dataArray,size);
   // sort the song array using selection sort
   int sortSteps=sortSongs(dataArray,size);
   //print the number of steps
   //print the sorted data Array
   print(dataArray,size);
   //print the top ten songs
   printTopTen(dataArray,size);
   //search for a song by title

   int searchSteps=searchASong(dataArray,size); 
   //print the number of steps
} 
// Requires non negative size
// Effects Sorts the Songs dataArray
//using selection sortSongs
//Modifies dataArray
int sortSongs(Song ** dataArray, int size){
//GIVEN CODE
  int steps=0;
   Song * minValue= new Song();
   int minIndex=0;
   for (int i=0;i<size;i++){
      minValue=dataArray[i];
      minIndex=i;
  for (int j=i+1;j<size;j++){
    steps++;
    if (*dataArray[j]<minValue){
     
      minValue=dataArray[j];
      minIndex=j;
    }
  }
    dataArray[minIndex]=dataArray[i];
    dataArray[i]=minValue;
    
  }
  return steps;
  }

// Requires valid filename to open file
// Effects fills the Songs dataArray
//
//Modifies dataArray
int populateArray(std::string filename, Song** dataArray){
  
  //GIVEN CODE
  int size=0;
  std::string line;
  std::string title;
  std::string singer;
  int chartPosition;

  try{
    std::ifstream input(filename);
    if (input.fail()) throw new std::string(filename + " File Open Error");
    while(!input.eof()){
     getline(input,line);
     std::istringstream inpline(line);
     std::getline(inpline,title,',');
     std::getline(inpline,singer,',');
     inpline>>chartPosition;
     dataArray[size]= new Song(title,singer,chartPosition);
     size++;

    }
 
}
  catch(std:: string e){
    std::cout<<e<<std::endl;
  }
 return size;
}
//R size >0
//E uses the overloaded << operator in Song to print all the Songs
//M nothing
 void print(Song** dataArray,int size){
 //TODO
  
  }
//Requires size >0
//Effects Prints top ten songs by calling print data method
// if there are less than 10 songs in array then it prints them all otherwise it prints first 10 songs
//Modifies nothing
 void printTopTen(Song** dataArray,int size){
    //TODO
  }
 
//Requires size >0
//Effects Linear Searches for the song based on title 
//Prompts user for title
//Modifies Nothing
int searchASong(Song **dataArray, int size){
  int steps=0;
  std::cout<<"Which title are you searching ?";
  std::string title;
  getline(std::cin, title);
  //TODO
  return steps;
}

//Requires size >=0
// Effect Searches for song by title using chart position returns index if found otherwise -1
//uses linear search
//Modifies nothing

Song getSong(Song** dataArray, int size, int chartPosition){
//GIVEN CODE
 if (chartPosition<size)
   return *dataArray[chartPosition];
 else throw new std::string("Exception - Array Out of Bounds");
}