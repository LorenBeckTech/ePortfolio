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
        std::cout << "If you can guess the number that Shape Monster is thinking (1-10)..\n";
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

    // setting up the CRUD operations for the To-Do List for the next category (will finish next milestone)
        // added createTodoShape, readTodoShape, updateTodoShape, and deleteTodoShape
        //Then I will initialize the todo list

    void createTodoShape(const std::string& task) {
        todoList.push_back({ nextTodoId++, task, false });
    }

    void initializeTodoList() {
        createTodoShape("Collect Moon");
        createTodoShape("collect Triangle");
        createTodoShape("collect heart");
        createTodoShape("Collect Rectangle");
        createTodoShape("Collect Diamond");
        createTodoShape("Collect Circle");

    }


public:
    Game() : location("Main Office") {
        std::srand(std::time(0));
        initRooms();
        monsterRoom = randomRoom();
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

            std::cout << "Which direction would you like to go? ";
            std::string direction;
            std::cin >> direction;
            std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
            direction[0] = ::toupper(direction[0]);

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

            if (location == "Main Office" && collectedShapes.size() == 6) {
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

int main() { // creates a Game object and calls its play method. This makes the entry point better. It makes it cleaned and focused.
    Game game;
    game.play();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
