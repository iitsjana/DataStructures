//
// Created by user on 4/14/2021.
//

/* this is the VideoGame class file
* Here we define our set and get functions for our previously declared variables
*/
#include " VideoGame.h"

// setter
void VideoGame::setTitle(std::string Title) {
    title=std::move(Title);
}
// getter
std::string VideoGame::getTitle(){
    return (title);
}

// setter
void VideoGame::setReleaseYear(int ReleaseYear) {
    releaseYear=std::move(ReleaseYear);
}
// getter
int VideoGame::getReleaseYear() {
    return (releaseYear);
}

// setter
void VideoGame::setGenre(std::string Genre) {
    genre=std::move(Genre);
}
// getter
std::string VideoGame::getGenre() {
    return (genre);
}

// setter
void VideoGame::setPublisher(std::string Publisher) {
    publisher=std::move(Publisher);
}
// getter
std::string VideoGame::getPublisher() {
    return (publisher);
}