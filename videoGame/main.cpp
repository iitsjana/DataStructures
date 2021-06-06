/*
* Midterm Exam- Video Game Implementation (Using Stacks).
* I. Jana Batiya.
* In this assignment we use stacks from the STL to implement a video game library functionality.
* We create a stack of video games. Add five different game objects to the stack.
* Then using a loop, we display the game information
*/


#include <iostream>
#include " VideoGame.h"
#include <stack>
#include <iterator>

/** Main Function
* Here we will create a stack, fill it with objects, and print the information
*... No params or returns for functions with no parameters or return value.
*/
int main() {

    std::stack<VideoGame> games; // Stack of type VideoGame is created
    VideoGame game1, game2, game3, game4, game5; // Creating five VideoGame objects

// Setting each object accordingly
    game1.setTitle("Batman: Akraham City");
    game1.setReleaseYear(2011);
    game1.setGenre("Action");
    game1.setPublisher("Rocksteady Studios");

    game2.setTitle("Broken Sword");
    game2.setReleaseYear(1996);
    game2.setGenre("Mystery");
    game2.setPublisher("Revolution Software");

    game3.setTitle("Dead Space");
    game3.setReleaseYear(2008);
    game3.setGenre("Horror");
    game3.setPublisher("Electronic Arts");

    game4.setTitle("The Witcher3: Wild Hunt");
    game4.setReleaseYear(2015);
    game4.setGenre("Fantasy");
    game4.setPublisher("CD Projekt");

    game5.setTitle("The Legend of Zelda");
    game5.setReleaseYear(1986);
    game5.setGenre("Adventure");
    game5.setPublisher("Nintendo");

// pushing each object into the stack
    games.push(game1);
    games.push(game2);
    games.push(game3);
    games.push(game4);
    games.push(game5);

    VideoGame temp; // creating a temporary VideoGame object

    // while the stack isn't empty
    while (!games.empty())
    {

        temp=games.top(); //retrieves the top element

        // Displaying the information
        std::cout<<"---------------------"<<std::endl;
        std::cout<<temp.getTitle()<<std::endl;
        std::cout<<temp.getReleaseYear()<<std::endl;
        std::cout<<temp.getGenre()<<std::endl;
        std::cout<<temp.getPublisher()<<std::endl;
        // pops the top element
        games.pop();

    }
    // For display purposes
    std::cout<<"---------------------"<<std::endl;


}
