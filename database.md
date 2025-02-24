# Database Enhancement

# Third Enhancement (Enhanced from Data Structure and Enhancement) 

## Narrative

The artifact that I chose is a text-based game called “Shape Monster Game,” which I originally created in 2022 during my IT-145 class using Python on Pycharm. The game is designed for children to help them practice reading by collecting shapes in different classrooms while avoiding the Shape Monster. The point of the game is to gather the shapes and return to the main office without meeting the running into the monster. The game is simple and educational, but it made a great project to show my coding skills.  

I chose to include this artifact in my ePortfolio because it shows my technical skills, creativity, and my ability to create educational tools. The game shows my journey from where I learned the basics of coding to using more advanced concepts such as object-oriented programming (OOP) and data structures.  I used std::unordered_map to show the rooms and their connections and used std::unordered_set for the collectedShapes to make sure that the shape collection and lookup operations were correct which helped with the game’s performance. It has a strong foundation for adding enhancements and has really shown my growth as a software developer. These enhancements not only improved the structure and readability but also made it more maintainable. I made sure that the related logic was kept together making it easier for future modifications and extensions.  

I exceeded the course outcomes I planned to achieve with the enhancements in Module One. My original plan was to implement a linked list and a hash table to show my understanding of data structures, however, I went abovve and beyond by incorporating additional advanced concepts. For example, I added std::unordered_ set for the collectedShapes, which allowed efficient shape collection and lookup operations. I also added a Game class to show OOP principles, to show the game logic within a flexible and maintainable structure. I then set up the foundation for CRUD with a to-do list which I will use to show my skills in the 3rd category, databases. I feel confident that I have successfully met the course outcomes, and I do not have any updates to my outcome-coverage plans. 

Reflecting on the process of enhancing and modifying the Shape Monster Game, I learned the importance of thorough testing and troubleshooting to make sure that the user has an enjoyable user experience. By testing the game with my son, I discovered that the theater room needed adjustments to provide a way out which I found to be very valuable feedback. I repeatedly played the game to identify and fix errors in the code, which showed how important debugging and using coding best practices for clean code is. This experience improved the game's functionality and also strengthened my problem-solving skills and attention to detail

## Enhancements related to databases: 

In the Shape Monster Game, CRUD (Create, Read, Update, Delete) operations are incorporated through the to-do list feature.

Create
The createTodoShape method allows the player to create new tasks in the to-do list. This method adds a new to-do item to the list with an incremented ID and a specified task, allowing the game to track the collection tasks that need to be completed.

Read
The readTodoShape method allows the player to view all tasks in the to-do list. It displays each task’s ID, description, and completion status, enabling the player to keep track of their progress in collecting the shapes.

Update
The updateTodoShape method allows the player to mark a task as completed. By updating the completion status of a task based on its ID, the game keeps an accurate record of which shapes have been collected.

Delete
The deleteTodoShape method allows the player to remove a task from the to-do list. This makes sure that completed or irrelevant tasks can be cleared from the list, keeping it organized and focused on the rest of the tasks.

# CRUD within the Game
The to-do list menu provides the player with options to view, update, and delete tasks in the to-do list. This menu ensures that the player can interact with the to-do list in a user-friendly manner, performing CRUD operations as needed. This feature enhances the interactivity of the game by allowing players to manage their collection tasks effectively and track their progress in an educational and fun way.

By incorporating CRUD operations into the Shape Monster Game, the to-do list feature enhances the game's interactivity and provides a practical demonstration of managing data within a software project.

## C++ Script

{% raw %}
```cpp


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

{% endraw %}

[Return to Homepage](https://lorenbecktech.github.io/ePortfolio/)
