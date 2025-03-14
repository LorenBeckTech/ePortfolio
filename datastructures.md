# Data Structures and Algorithm Enhancement

# Second Enhancement (Enhanced from the Software Engineering and Enhancement) 

## Narrative

The artifact that I chose is a text-based game called “Shape Monster Game,” which I originally created in 2022 during my IT-145 class using Python on Pycharm. The game is designed for children to help them practice reading by collecting shapes in different classrooms while avoiding the Shape Monster. The point of the game is to gather the shapes and return to the main office without meeting the running into the monster. The game is simple and educational, but it made a great project to show my coding skills.  

I chose to include this artifact in my ePortfolio because it shows my technical skills, creativity, and my ability to create educational tools. The game shows my journey from where I learned the basics of coding to using more advanced concepts such as object-oriented programming (OOP) and data structures.  I used std::unordered_map to show the rooms and their connections and used std::unordered_set for the collectedShapes to make sure that the shape collection and lookup operations were correct which helped with the game’s performance. It has a strong foundation for adding enhancements and has really shown my growth as a software developer. These enhancements not only improved the structure and readability but also made it more maintainable. I made sure that the related logic was kept together making it easier for future modifications and extensions.  

I exceeded the course outcomes I planned to achieve with the enhancements in Module One. My original plan was to implement a linked list and a hash table to show my understanding of data structures, however, I went abovve and beyond by incorporating additional advanced concepts. For example, I added std::unordered_ set for the collectedShapes, which allowed efficient shape collection and lookup operations. I also added a Game class to show OOP principles, to show the game logic within a flexible and maintainable structure. I then set up the foundation for CRUD with a to-do list which I will use to show my skills in the 3rd category, databases. I feel confident that I have successfully met the course outcomes, and I do not have any updates to my outcome-coverage plans. 

Reflecting on the process of enhancing and modifying the Shape Monster Game, I learned the importance of thorough testing and troubleshooting to make sure that the user has an enjoyable user experience. By testing the game with my son, I discovered that the theater room needed adjustments to provide a way out which I found to be very valuable feedback. I repeatedly played the game to identify and fix errors in the code, which showed how important debugging and using coding best practices for clean code is. This experience improved the game's functionality and also strengthened my problem-solving skills and attention to detail.

## Enhancements related to data Structures and Algorithms: 

- Unordered maps are used to represent the rooms and their connections. There is an unordered map that maps room names to their connected rooms and shapes. This structure provides efficient average-time complexity for insertions and lookups which makes the game more responsive. 

- Hash tables are used within the game by unordered maps and unordered sets to store key-value pairs. The unordered map of rooms and the unordered set of collected shapes leverage hash tables to provide efficient storage helps retrieve data. 

- The unordered set is used to keep track of the shapes collected by the player. This helps with checking if a shape has already been collected and is quick and efficient.

- The Game class encapsulates the game's state and behavior with  Object-Oriented Programming (OOP) by organizing the game's logic within the class. 

## Algorithms
Several algorithms are used throughout the game

- Random Room Selection: The random room function uses random number generation to select a room for the Shape Monster to hide in, adding an element of unpredictability to the game.

- Number Guessing: The number-guessing game within the monster rules uses a simple random number generation algorithm to determine the Shape Monster's secret number.

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


    std::string randomRoom() {
        std::vector<std::string> possibleRooms = { "Lounge", "Gym", "Cafe", "School Nurse", "Library", "Locker Room" };
        return possibleRooms[std::rand() % possibleRooms.size()];
    }

    // CRUD operations for the to-do list 
    //initializing the todo list 

    void createTodoShape(const std::string& task) {
        todoList.push_back({ nextTodoId++, task, false });
        std::cout << "To-Do item: " << task << std::endl; 
    }

    void readTodoShape() {
        std::cout << "To-Do List: " << std::endl;
        for (const auto& todo : todoList) {
            std::cout << "ID: " << todo.id << ", Task: " << todo.task << ", completed: " << (todo.completed ? "Yes" : "No") << std::endl;
        }
    }

    void updateTodoShape(int id) {
        for (auto& todo : todoList) {
            if (todo.id == id) {
                todo.completed = true; 
                std::cout << "To-Do item completed: " << todo.task << std::endl;
                return;
            }
        }
        std::cout << "To-Do item ID " << id << " not found." << std::endl; // If loop completes without finding an item with the matching ID 

    }

    void deleteTodoShape(int id) {
        auto it = std::remove_if(todoList.begin(), todoList.end(), [id](const TodoShape& todo) { return todo.id == id; });
        if (it != todoList.end()) {
            std::cout << "deleted To-Do item: " << it->task << std::endl;
            todoList.erase(it, todoList.end());
        }
        else {
            std::cout << "To-Do item ID " << id << " Not found." << std::endl;
        }
    }
    //initialize to-do list with tasks to collect the shapes.
    void initializeTodoList() {
        createTodoShape("Collect Moon");
        createTodoShape("collect Triangle");
        createTodoShape("collect heart");
        createTodoShape("Collect Rectangle");
        createTodoShape("Collect Diamond");
        createTodoShape("Collect Circle");

    }

    //display the to-do list menu

    void todoListMenu() {
        while (true) {
            std::cout << "\nTo-Do List Menu:\n";
            std::cout << "1. Show To-Do List\n";
            std::cout << "2. Mark To-Do Item as Completed\n";
            std::cout << "3. Delete To-Do Item\n";
            std::cout << "4. Exit To-Do List Menu\n";
            std::cout << "Choose an option: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                readTodoShape();
            }
            else if (choice == 2) {
                std::cout << "Enter the ID o the To-Do item to mark complete: ";
                int id; 
                std::cin >> id;
                updateTodoShape(id);
            }
            else if (choice == 3) {
                std::cout << "Enter the ID of the To-Do item to delete: "; 
                int id;
                std::cin >> id; 
                deleteTodoShape(id);
            }
            else if (choice == 4) {
                break;
            }
            else {
                std::cout << "option is invalid. Please try again. \n";
            }
        }
    }


public:
    Game() : location("Main Office"), nextTodoId(1) { // upda
        std::srand(std::time(0));
        initRooms();
        monsterRoom = randomRoom();
        initializeTodoList(); // initialize the to-do list when the game starts
    }

    void play() { // Moved the game loop to be within the class. This makes the flow of the game better and and keeps all related logic together. 
        gamePlay();
        rules();

        std::cout << "[]" << std::endl;

        while (true) {
            showStatus();

            for (const auto& item : rooms[location]) {
                std::cout << item.first << ": " << item.second << " ";
            }
            std::cout << std::endl;

            std::cout << "Which direction would you like to go? Or type 'menu' to see the To-Do list" << std::endl;
            std::string direction;
            std::cin >> direction;
            std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
            direction[0] = ::toupper(direction[0]);

            if (direction == "Exit") {
                std::cout << "Goodbye" << std::endl;
                break;
            }

            if (direction == "Menu") {
                todoListMenu();
                continue;
            }

            auto possibleMoves = rooms[location];
            if (possibleMoves.find(direction) != possibleMoves.end()) {
                location = possibleMoves[direction];
                std::cout << "You have moved to the " << location << std::endl;
            }
            else {
                std::cout << "Invalid move" << std::endl;
            }

            if (location == "Main Office" && collectedShapes.size() == 6) {
                std::cout << "You have unlocked the door and won the game" << std::endl;
                break;
            }

            if (location == monsterRoom) {
                monsterRules();

                int number = std::rand() % 3 + 1; //updated to the new range to make it easier. 
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
            if (item != rooms[location].end() && collectedShapes.find(item->second) == collectedShapes.end()) {
                std::cout << "Would you like to pick up the " << item->second << "? ";
                std::string userinput;
                std::cin >> userinput;
                std::transform(userinput.begin(), userinput.end(), userinput.begin(), ::tolower);

                if (userinput == "yes") {
                    collectedShapes.insert(item->second);
                    std::cout << "[ ";
                    for (const auto& shape : collectedShapes) {
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
    }
};

int main() { // created a Game object to call its play method. This makes the entry point better. It makes it cleaned and focused.
    Game game;
    game.play();
    return 0;
}


{% endraw %}

[Return to Homepage](https://lorenbecktech.github.io/ePortfolio/)
