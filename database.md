# Database Enhancement

## Narrative 
[Narrative](https://lorenbecktech.github.io/ePortfolio/narrative)<br/>

## C++ Script

```C++
// MonsterGameDataStructuresAndAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//define the To-do structure for the shapes
struct TodoShape {
    int id;
    std::string task;
    bool completed; 
};

class Game { // I added a Game Class to show OOP (Object-Oriented Programming) an better manage the games state and behavior. 
    //This makes the game easier to maintain. 
private:
    std::string location;
    std::vector<std::string> shapeCollection;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> rooms;
    std::unordered_set<std::string> collectedShapes; // Added unordered_set for collected shapes to allow average-time complexity for insertions and lookups. 
    // This makes the code more efficient and shows I understand Data Structures.
    std::vector<TodoShape> todoList; // added data structure for To-Do List 
    int nextTodoId; // added To-Do item ID tracker
    std::string monsterRoom;

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

    void showStatus() {
        std::cout << "You are in the " << location << "\n";
    }

    void monsterRules() {
        std::cout << "OH NO! THE SHAPE MONSTER IS IN THIS ROOM!\n";
        std::cout << "If you can guess the number that Shape Monster is thinking (1-3)..\n"; //updated to 1-3 to make it easier for the kids. 
        std::cout << "Then you defeat the Shape Monster and can continue collecting items\n";
        std::cout << "If you guess the number incorrectly YOU LOSE\n";
    }

    void initRooms() {  // I added the initRooms Method  to initialize the rooms and their connections,
        //but his way it separates the room setup logic from the main gameplay logic and makes the code more readable and maintainable
        rooms = {
            {"Main Office", {{"South", "Lounge"}, {"East", "Cafe"}}},
            {"Lounge", {{"North", "Main Office"}, {"East", "Gym"}, {"Shape", "Moon"}}},
            {"Gym", {{"West", "Lounge"}, {"North", "Cafe"}, {"Shape", "Triangle"}}},
            {"Cafe", {{"West", "Main Office"}, {"South", "Gym"}, {"East", "Locker Room"}, {"North", "School Nurse"}, {"Shape", "Rectangle"}}},
            {"School Nurse", {{"South", "Cafe"}, {"East", "Theater"}, {"Shape", "Heart"}}},
            {"Theater", {{"West", "School Nurse"}, {"South", "Library"}}}, // Added exits to School Nurse and Library
            {"Library", {{"North", "Theater"}, {"South", "Locker Room"}, {"Shape", "Diamond"}}},
            {"Locker Room", {{"North", "Library"}, {"West", "Cafe"}, {"Shape", "Circle"}}}
        };
    }

[Return to Homepage](https://lorenbecktech.github.io/ePortfolio/)
