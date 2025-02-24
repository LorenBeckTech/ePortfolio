# Software Engineering Enhancement

# First Enhancement (Enhanced from The orignal Python Code) 

## Narrative

The artifact that I chose is a text-based game called “Shape Monster Game,” which I originally created in 2022 during my IT-145 class using Python on Pycharm. The game is designed for children to help them practice reading by collecting shapes in different classrooms while avoiding the Shape Monster. The point of the game is to gather the shapes and return to the main office without meeting the running into the monster. The game is simple and educational, but it made a great project to show my coding skills.  

I chose to include this artifact in my ePortfolio because it shows my technical skills, creativity, and my ability to create educational tools. The game shows my journey from where I learned the basics of coding to using more advanced concepts such as object-oriented programming (OOP) and data structures.  I used std::unordered_map to show the rooms and their connections and used std::unordered_set for the collectedShapes to make sure that the shape collection and lookup operations were correct which helped with the game’s performance. It has a strong foundation for adding enhancements and has really shown my growth as a software developer. These enhancements not only improved the structure and readability but also made it more maintainable. I made sure that the related logic was kept together making it easier for future modifications and extensions.  

I exceeded the course outcomes I planned to achieve with the enhancements in Module One. My original plan was to implement a linked list and a hash table to show my understanding of data structures, however, I went abovve and beyond by incorporating additional advanced concepts. For example, I added std::unordered_ set for the collectedShapes, which allowed efficient shape collection and lookup operations. I also added a Game class to show OOP principles, to show the game logic within a flexible and maintainable structure. I then set up the foundation for CRUD with a to-do list which I will use to show my skills in the 3rd category, databases. I feel confident that I have successfully met the course outcomes, and I do not have any updates to my outcome-coverage plans. 

Reflecting on the process of enhancing and modifying the Shape Monster Game, I learned the importance of thorough testing and troubleshooting to make sure that the user has an enjoyable user experience. By testing the game with my son, I discovered that the theater room needed adjustments to provide a way out which I found to be very valuable feedback. I repeatedly played the game to identify and fix errors in the code, which showed how important debugging and using coding best practices for clean code is. This experience improved the game's functionality and also strengthened my problem-solving skills and attention to detail.

## Enhancements related to Software Engineering: 

- I showed my proficiency in multiple programming languages by converting the original game from Python to C++. I was able to adapt the code with differences in syntax and libraries between the two languages. I also used coding best practices and enhanced some of the game features.
  
## C++ Script

{% raw %}
```cpp



// MonsterGameC++.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>    // input and output operations 
#include <string>      // for using std::string
#include <cstdlib>     // for std::rand and std::srand
#include <ctime>       // for std::time
#include <vector>      // for using std::vector
#include <unordered_map> // for using hash table 
#include <algorithm>   // for algorithms like std::find and transform

void gamePlay() {
    std::cout << "Shape Monster Child Game\n";
    std::cout << "If you need to leave, just type Exit\n";
    std::cout << "Object of the game: collect shapes to bring back to the locked office\n";
    std::cout << "The shapes will be in the classrooms\n";
    std::cout << "but wait, there is a catch!!\n";
    std::cout << "The shape monster is hiding in one of the rooms.\n";
    std::cout << "and if you get to him before you can get back to the main office.........\n";
    std::cout << "YOU LOSE!\n";
}

void rules() {
    std::cout << "Rules and directions:\n";
    std::cout << "Walk through the school and stop in classrooms on the way. In each classroom there will be a shape.\n";
    std::cout << "Collect a [moon, triangle, heart, rectangle, diamond, and circle]\n";
    std::cout << "Watch out for the shape monster, who will be in one of the rooms.\n";
    std::cout << "Move commands: North, South, East, West\n";
    std::cout << "Add to Inventory: collect shape\n";
}

void showStatus(const std::string& location) {
    std::cout << "You are in the " << location << "\n";
}

void monsterRules() {
    std::cout << "OH NO! THE SHAPE MONSTER IS IN THIS ROOM!\n";
    std::cout << "If you can guess the number that Shape Monster is thinking (1-10)..\n";
    std::cout << "Then you defeat the Shape Monster and can continue collecting items\n";
    std::cout << "If you guess the number incorrectly YOU LOSE\n";
}

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> rooms = {
    {"Main Office", {{"South", "Lounge"}, {"East", "Cafe"}}},
    {"Lounge", {{"North", "Main Office"}, {"East", "Gym"}, {"Shape", "Moon"}}},
    {"Gym", {{"West", "Lounge"}, {"North", "Cafe"}, {"Shape", "Triangle"}}},
    {"Cafe", {{"West", "Main Office"}, {"South", "Gym"}, {"East", "Locker Room"}, {"North", "School Nurse"}, {"Shape", "Rectangle"}}},
    {"School Nurse", {{"South", "Cafe"}, {"East", "Theater"}, {"Shape", "Heart"}}},
    {"Theater", {}},  // Villain Shape Monster
    {"Library", {{"North", "Theater"}, {"South", "Locker Room"}, {"Shape", "Diamond"}}},
    {"Locker Room", {{"North", "Library"}, {"West", "Cafe"}, {"Shape", "Circle"}}}
};

std::string location = "Main Office";
std::vector<std::string> shapeCollection;
std::string monsterRoom;

int main() {
    std::srand(std::time(0)); // Seed for random number generator 
    gamePlay();
    rules();

    // List of possible rooms the monster can be in (excluding Main Office)
    std::vector<std::string> possibleRooms = { "Lounge", "Gym", "Cafe", "School Nurse", "Library", "Locker Room" };
    monsterRoom = possibleRooms[std::rand() % possibleRooms.size()]; // Randomly select a room for the monster

    std::cout << "[]" << std::endl; // Print initial empty shape collection 

    while (true) {
        showStatus(location);

        for (const auto& item : rooms[location]) {
            std::cout << item.first << ": " << item.second << " ";
        }
        std::cout << std::endl;

        std::cout << "Which direction would you like to go? ";
        std::string direction;
        std::cin >> direction;
        std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
        direction[0] = ::toupper(direction[0]); // Capitalize the first letter

        if (direction == "Exit") {
            std::cout << "Goodbye" << std::endl;
            break;
        }

        auto possibleMoves = rooms[location];
        if (possibleMoves.find(direction) != possibleMoves.end()) {
            location = possibleMoves[direction];
            std::cout << "You have moved to the " << location << std::endl;
        }
        else {
            std::cout << "Invalid move" << std::endl;
        }

        if (location == "Main Office" && shapeCollection.size() == 6) {
            std::cout << "You have unlocked the door and won the game" << std::endl;
            break;
        }

        if (location == monsterRoom) {
            monsterRules();

            int number = std::rand() % 10 + 1;
            int guess;
            std::cout << "What is your guess? ";
            std::cin >> guess;

            if (guess == number) {
                std::cout << "YOU GOT IT!" << std::endl;
            }
            else {
                std::cout << "NOPE, You lose!" << std::endl;
                break;
            }
        }

        auto item = rooms[location].find("Shape");
        if (item != rooms[location].end() && std::find(shapeCollection.begin(), shapeCollection.end(), item->second) == shapeCollection.end()) {
            std::cout << "Would you like to pick up the " << item->second << "? ";
            std::string userinput;
            std::cin >> userinput;
            std::transform(userinput.begin(), userinput.end(), userinput.begin(), ::tolower);

            if (userinput == "yes") {
                shapeCollection.push_back(item->second);
                std::cout << "[ ";
                for (const auto& shape : shapeCollection) {
                    std::cout << shape << " ";
                }
                std::cout << "]" << std::endl;
            }
            else {
                std::cout << "You have chosen not to pick up this shape. Please come back for it." << std::endl;
            }
        }
        else {
            std::cout << "There is no shape to pick up here" << std::endl;
        }
    }
    return 0;
}


{% endraw %}

[Return to Homepage](https://lorenbecktech.github.io/ePortfolio/)
