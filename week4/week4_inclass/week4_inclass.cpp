//
//  main.cpp
//  week4_in_class
//
//  Created by Thao Pham on 2/2/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//enumeration
enum class PlayerClass{Warrior, Mage, Bowman, Thief, InvalidPlayerClass};

//structure representing a single player character
struct GamePlayer{
    string name;
    string gender;
    PlayerClass occupation;
    string gold;
};

/*function definitions*/
void print_command_menu()
{
    cout << "COMMAND MENU"
     << "\nshow   - Display all players"
     << "\nadd    - Add a player"
     << "\ndelete - Delete a player"
     << "\nexit   - Exit program\n\n";
}

PlayerClass get_player_class_from_string(string player_class){
    PlayerClass result;
    if(player_class == "Warrior")
        result = PlayerClass::Warrior;
    else if(player_class == "Mage")
        result = PlayerClass::Mage;
    else if(player_class == "Bowman")
        result = PlayerClass::Bowman;
    else if(player_class == "Thief")
        result = PlayerClass::Thief;
    else
        result = PlayerClass::InvalidPlayerClass;
    return result;
}

void read_file_into_vector(vector<GamePlayer>& player_characters)
{
    ifstream input_file;
    string line;
    string temp_str;

    GamePlayer temp;
    PlayerClass temp_pc;

    input_file.open("/Applications/Studying/SP22/CSCI_4100/Week 4/week4_in_class/week4_in_class_Thao_Pham/players.txt");

    if (input_file)
    {
        //as long as we have something to read...
        while (!input_file.eof())
        {
            //read it
            getline(input_file, temp.name, '\t');

            getline(input_file, temp_str, '\t');
            temp_pc = get_player_class_from_string(temp_str);
      
            temp.occupation = temp_pc;

            getline(input_file, temp.gender, '\t');

            input_file >> temp.gold;
            input_file.ignore(1000, '\n');
                
            player_characters.push_back(temp);
        }

        input_file.close();
    }
}

string get_string_from_player_class(PlayerClass pc)
{
    string result;
    
    if (pc == PlayerClass::Warrior)
            result = "Warrior";
        else if (pc == PlayerClass::Mage)
            result = "Mage";
        else if (pc == PlayerClass::Bowman)
            result = "Bowman";
        else if (pc == PlayerClass::Thief)
            result = "Thief";
        else
            result = "InvalidPlayerClass";
    
    return result;
}

void write_players_file(const vector<GamePlayer>& player_characters)
{
    ofstream outfile;

    outfile.open("/Applications/Studying/SP22/CSCI_4100/Week 4/week4_in_class/week4_in_class_Thao_Pham/players.txt");
    //write over existing file
    for (int i = 0; i < player_characters.size(); ++i)
    {
        GamePlayer temp = player_characters.at(i);

        outfile << temp.name << "\t";
        outfile << get_string_from_player_class(temp.occupation) << "\t";
        outfile << temp.gender << "\t";
        outfile << temp.gold;
        if (i != player_characters.size() - 1) //not last one
        {
            outfile << endl;
        }

    }
    outfile.close();

}

void show_all_players(const vector<GamePlayer>& player_characters)
{
    for (unsigned int i = 0; i < player_characters.size(); ++i)
        {
            GamePlayer player = player_characters.at(i);
            cout << i+1 << ".  ";
            cout << left << setw(13) << player.name;
            cout << left << setw(16) << get_string_from_player_class(player.occupation);
            cout << left << setw(6) << player.gender;
            cout << left << setw(16) << player.gold;
            cout << endl;
        }
}

void add_player(vector<GamePlayer>& player_characters)
{
    string player_name;
    string player_class1;
    string dummy;
    PlayerClass pc;
    string player_sex;
    string player_gold;

    cout << "  Create a Mage, Warrior, Bowman, or Thief" << endl;

    cout << "Name: ";
//    getline(cin, player_name);
    cin >> player_name;

    cout << "Class: ";
//    getline(cin, player_class1);
    cin >> player_class1;
    pc = get_player_class_from_string(player_class1);
    if (pc == PlayerClass::InvalidPlayerClass)
    {
        cout << "  Invalid class, try again" << endl;
        cout << "Class: ";
//        getline(cin, player_class1);
        cin >> player_class1;
        pc = get_player_class_from_string(player_class1);
    }

    cout << "Sex: ";
//    getline(cin, player_sex);
    cin >> player_sex;
    cout << "Gold: ";
    cin >> player_gold;
    
    getline(cin, dummy);  //consume newline

    GamePlayer new_player;
    new_player.name = player_name;
    new_player.occupation = pc;
    new_player.gender = player_sex;
    new_player.gold = player_gold;

    //add to vector
    player_characters.push_back(new_player);

    //add to file
    write_players_file(player_characters);
}

void delete_player(vector<GamePlayer>& player_characters)
{
    int num_to_delete;

    string dummy;
    cout << "\nNumber to delete: ";
    cin >> num_to_delete;
    getline(cin, dummy);  //consume the newline

    num_to_delete -= 1;  //the index is one less than number entered

    if (num_to_delete >= 0 && num_to_delete < player_characters.size())
    {
        //remove from vector
        player_characters.erase(player_characters.begin() + num_to_delete);
        cout << "\nRemoved player character." << endl;

        //remove from file - rewrite without the removed character
        write_players_file(player_characters);
    }
    else
    {
        cout << "\nInvalid number entered. Try again." << endl;
    }
}

void process_command(string command, vector<GamePlayer>& player_characters)
{
    
    if (command == "show")
        show_all_players(player_characters);
    else if (command == "add")
        add_player(player_characters);
    else if (command == "delete")
        delete_player(player_characters);
    else if (command != "exit")
        cout << "Invalid command.\n\n";
}

int main()
{
    cout << "RPG Start Screen\n\n";
    
    PlayerClass get_player_class_from_string(string player_class);
    
    vector<GamePlayer> player_characters;
    read_file_into_vector(player_characters);
    
//   READ command
    
//   READ game player vector
    
//   READ player file
    
//   PRINT command menu
    print_command_menu();
    
    cout << "\nCommand: ";
    string command;
    cin >> command;

//   SET command
    
//   WHILE command is not equal to exit
//        CALL process_command with command, player_characteristics
//        SET command
    while(command != "exit")
    {
        process_command(command,player_characters);
        
        cout << "\nCommand: ";
        cin>> command;
    }

    return 0;
}
