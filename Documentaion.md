| (Jackson Mossman)|
| :---          	|
|(S198037)      	|
|(C++  Player Profile DataBase) |
| (PlayerSaveAndLoad Documentaion) |

## Assesment Brief: 
This brief has been designed around the specific, cumulative evidence you must prepare for and present by your assessment milestone to demonstrate you have competency in the requisite knowledge and skills for this subject. Submissions conforming to this brief will provide the specific evidence listed in the table titled Assessment and Competency Requirements at the end of this assessment item. You may present additional, or other evidence of competency, but this should be as a result of individual negotiation with your teacher.General DescriptionFor this project you are to create a program that loads, updates, and saves player profile information to a binary file.For each player in your database you must store their name and high-score. When your program launches it will read previously saved profiles from a binary file, if such a file exists. If no file exists then one will be created.Your program will allow the user to create new profiles, or to search for a profile and update the containing information. When your program exists, any new or modified records will be written back to the binary file.When saving new or updated profiles you must ensure that you use random-access algorithms to ensure that only modified data is saved. You must not re-write the entire file every time your application runs.


## Requirements
Create a program that will create, modify and save player profiles to a random-access binary file. Your program must have the following features:

* Store the name and high-score information of the player. 

* Store the player name in a fixed-length array so that the position of each record can be calculated. This will enable you to update individualrecords in the file.

* The player profile data must be encapsulated in a user defined class.
* When your program launches, read the data file if it exists. If not, it should becreated.The player profile data must be loaded into a dynamic array (you must not use a container class, such as std::vector)
* After the data file has been read, player profiles are to be sorted alphabetically.
* Your program must allow the user to search for and update an individual player profile.oYou must implement binary search as the search algorithm (this must be a custom implementation, not a library function).
* When a player profile is updated or created, it should be written to the data file. Only the data that has changed should be written.
* You must use the file pointer (i.e., random access) to jump to the appropriate location in the file, and only overwrite the record that has changed.
* You must test your program to ensure its correct function. Include a test data file with your program

##  Input Information

 - The Keyboard is used to enter prompted responses

## Output Information 

- when program begins it will output a load message if a save was loaded if not will open the list of defult players
-  Then player will be prompted to save exit or search
-  entering search will enter the player into a search command where they can search for a existing player or if the player they are trying to find doesnt exits they will then generate a player with the given name and ask for a new score.
-  All players displayed will be alphabetically sorted 
## User interface Information

-The program will display information to console and commands will be executed through the console

# System Architecture

- A Majority of the Games funcinality is built into the game class this is where a majority of work is done

## Game

- The Purpose of the game class is to manage all the players on the list as well as displaying information to the user

Name: Start()

Type: void

Desc: to initialize the game variables

Name: draw()

Type: Void

Desc:Draw the Player list

Name: AddPlayer(Player X)

Type:Void

Desc: add player to the player list

Name: bubbleSort()

Type:Void

Desc:sort the players alphabetically

Name: Swap

Type:Void

Desc: swap the position of two players in the array

Name: m_player;

Type:Player*

Desc: to be the list of players

Name: GetCommand()

Type: void

Desc: get command from the user

Name:search()

Type:void 

Desc:open the search menu for the player

Name:save()

Type: void 

Desc: save the game

Name: load ()

Type: void

Desc: load the game

Name: BinarySarch(char* key)

Type: int

Desc: search for a char* position in a array


Name: Gameover

Type: bool

Desc: checks if game is over

Name: m_playerCount

Type: int

Desc: keeps current player count


Name: m_tempPlayerCount

Type: int

Desc: temporary player count

Name: m_tempPlayers

Type: Player*

Desc:  a temporary player list

## Player

Name:m_name

Type: char[30]

Desc: name of the player

Name: m_score

Type: int

Desc: score of player

Name: setName

Type: void 

Desc: set players name

Name: setScore

Type: void

Desc: set score of player

Name: save

Type: void

Desc: save player

Name: load

Type: bool

Desc: Trys to load player

