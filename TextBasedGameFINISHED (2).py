# Loren Beck
#  importing random for theater room shape monster guessing game
from random import randint

number = randint(1, 10)
print(number)


# creating a function for how to play and the rules

def game_play():
    # print the object of the game
    print('Shape Monster Child Game')
    print('If you need to leave, just type Exit')
    print('Object of the game: collect shapes to bring back to the locked office')
    print('The shapes will be in the classrooms')
    print('but wait, there is a catch!!')
    print('The shape monster is hiding in one of the rooms.')
    print('and if you get to him before you can get back to the main office.........')
    print('YOU LOSE!')


def rules():
    print('Rules and directions:')
    print('Walk through the school and stop in classrooms on the way. In each classroom there will be a shape.')
    print('collect a [moon, triangle, heart, rectangle, diamond, and circle]')
    print('Watch out for the shape monster, who will be in one of the rooms.')
    print('move commands: North, South, East, West')
    print('Add to Inventory: collect shape')


# A dictionary that links rooms to other rooms and items

rooms = {
    'Main Office': {'South': 'Lounge', 'East': 'Cafe'},
    'Lounge': {'North': 'Main Office', 'East': 'Gym', 'Shape': 'Moon'},
    'Gym': {'West': 'Lounge', 'North': 'Cafe', 'Shape': 'Triangle'},
    'Cafe': {'West': 'Main Office', 'South': 'Gym', 'East': 'Locker Room', 'North': 'School Nurse',
             'Shape': 'Rectangle'},
    'School Nurse': {'South': 'Cafe', 'East': 'Theater', 'Shape': 'Heart'},
    'Theater': {},  # villain Shape Monster
    'Library': {'North': 'Theater', 'South': 'Locker Room', 'Shape': 'Diamond'},
    'Locker Room': {'North': 'Library', 'West': 'Cafe', 'Shape': 'Circle'}
}

# set the start room
location = 'Main Office'
# print out the rules and how to play
game_play()
rules()
# create an empty list to add the shapes to
shape_collection = []
print(shape_collection)
# create a while loop for the game with all the game play inside
while True:
    def show_status():
        print('you are in the {}'.format(location))

# show the room and location they can go without items
    for i in rooms[location].items():
        print(i, end=' ')
# prompt for their direction
    direction = input('Which direction would you like to go?').strip().lower().capitalize()
# gives them an out of the game
    if direction == 'Exit':
        print('Goodbye')
        break
# shows them the possible moves they can make
    possible_moves = rooms[location].keys()
    if direction in possible_moves:
        location = rooms[location][direction]
        print('You have moved to the {}'.format(location))
    else:
        print('Invalid move')
        # How to win the game you can also win if you guess the number correctly with the shape monster
    if location == 'Main Office' and shape_collection and 6 == len(shape_collection):
        print('You have unlocked the door and won the game')
        break
# villain room guess a number 1-10 if correct you win if wrong you automatically lose
    if location == 'Theater':
        def monster_rules():
            print('OH NO! THE SHAPE MONSTER IS IN THIS ROOM!')
            print('If you can guess the number that Shape Monster is thinking (1-10)..')
            print('Then you defeat the Shape Monster and can continue collecting items')
            print('If you guess the number incorrectly YOU LOSE')


        monster_rules()

        from random import randint

        number = randint(1, 10)

        guess = int(input('what is your guess?'))
        if guess == number:
            print('YOU GOT IT!')
        else:
            print('NOPE, You lose!')
            break
    item = rooms[location].get('Shape')
    if item is not None and item not in shape_collection:
        userinput = input('Would you like to pick up the {}?'.format(item)).strip().lower().capitalize()
        if userinput == 'Yes':

            shape_collection.append(item)
            print(shape_collection)
        elif userinput == 'No':
            print('You have chosen not to pick up this shape. Please come back for it')
    else:
        print('There is no shape to pick up here')
