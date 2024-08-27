#include "Song.h"
//default constructor
Song::Song(){
  title="";
  singer="";
  chartPosition=0;
}
//custom constructor
Song::Song(std::string title, std::string singer, int chartPosition){
 //TODO
}
//GIVEN CODE
std::string Song::toString(){
  return "Title: "+title+ " Singer: "+singer+ " ChartPosition: "+std::to_string(chartPosition);
}
//GIVEN CODE
std::ostream& operator<<(std::ostream & str, Song *s){
   str<< s->toString();
   return str;
}
//
 int Song::getChartPosition(){
   return 0;// change this
  //TODO
 }
 
 //GIVEN CODE
 //operator < overloading
  bool Song::operator<(Song *b){
    return chartPosition<b->getChartPosition();
  }
//return title
  std::string Song::getTitle(){

  //TODO
  return "";// change this
  }


