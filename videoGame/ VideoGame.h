//
// Created by user on 4/14/2021.
//

/* this is the VideoGame header file
* Here we declare our private variables and our public set and get functions
*/
#include <iostream>
#ifndef _MIDTERM_VIDEOGAME_H
#define _MIDTERM_VIDEOGAME_H

class VideoGame {
    // these are our private variables
    std::string title;
    int releaseYear;
    std::string genre;
    std::string publisher;

public:
    /** setTitle Function
* This function sets the title
* @param title is the string value
*/
    void setTitle(std::string title);

    /** getTitle Function
* This function gets the title
*/
    std::string getTitle();

    /** setReleaseYear Function
* This function sets the releaseYear
* @param releaseYear is the string value
*/
    void setReleaseYear(int releaseYear);

    /** getReleaseYear Function
* This function gets the releaseYear
*/
    int getReleaseYear();

    /** setGenre Function
* This function sets the genre
* @param genre is the string value
*/
    void setGenre(std::string genre);

    /** getGenre Function
* This function gets the genre
*/
    std::string getGenre();

    /** setPublisher Function
* This function sets the publisher
* @param publisher is the string value
*/
    void setPublisher(std::string publisher);

    /** getPublisher Function
* This function gets the publisher
*/
    std::string getPublisher();


};
#endif //_MIDTERM_VIDEOGAME_H
