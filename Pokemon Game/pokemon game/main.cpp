#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//initialize the health of the player and the opponent
	int player_health = 100;
	int cpu_health = 100;
	//game end message
	string cpu_wins = "Game over you lost :(";
	string u_win = "Game over you win!!!!!";
	//starting message
	string welcome = "Welcome to the match, may fortune smile upon you and Good Luck!!!!!!";
	//battle choices
	string fight = "1. burn\t2. slash\n3. heal";

	srand((int)time(0));
	//move damage and healing numbers
	int move1;//this ratio will be used for the healing move as well
	int move2;
	//variable the makes opponent pick a move after yours
	int enemy_choice;
 	cout << "You go first" << endl;
	do
	{
		//number to represent move choice
		int choice=0;
		cout << "pick your move:\n" << fight << endl;
		cin >> choice;//user input
		switch (choice)
		{
		case 1:
			move1= (rand() % 25);
			cpu_health -= move1;
			cout << "you used slash!!! Opponent recieves " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
			//check to see if opponent's health is gone
			if (cpu_health <= 0)
			{
				break;
			}
			//if not then the opponent will move
			else
			{
				enemy_choice = (rand() % 2);
				switch (enemy_choice)
				{
				case 0:
					move1 = (rand() % 25);
					player_health -= move1;
					cout << "opponent used punch!!! You recieve " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 1:
					move2 = (rand() % 35);
					if (move2 < 10)
					{
						move2 += 10;
					}
					player_health -= move2;
					cout << "opponent used crush!!! You recieve " << move2 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 2:
					move1 = (rand() % 25);
					cpu_health += move1;
					cout << "opponent used heal!!! healed " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				}
				break;
			}
			break;
		case 2:
			move2 = (rand() % 35);
			if (move2 < 10)
			{
				move2 += 10;
			}
			cpu_health -= move2;
			cout << "you used burn!!! Opponent recieves " << move2 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
			if (cpu_health <= 0)
			{
				break;
			}
			else
			{
				enemy_choice = (rand() % 2);
				switch (enemy_choice)
				{
				case 0:
					move1 = (rand() % 25);
					player_health -= move1;
					cout << "opponent used punch!!! You recieve " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 1:
					move2 = (rand() % 35);
					if (move2 < 10)
					{
						move2 += 10;
					}
					player_health -= move2;
					cout << "opponent used crush!!! You recieve " << move2 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 2:
					move1 = (rand() % 25);
					cpu_health += move1;
					cout << "opponent used heal!!! healed " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				}
				break;
			}
			break;
		case 3:
			move1 = (rand() % 25);
			player_health += move1;
			cout << "you used heal!!! you heal " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " left.\n\n";
			if (cpu_health <= 0)
			{
				break;
			}
			else
			{
				enemy_choice = (rand() % 2);
				switch (enemy_choice)
				{
				case 0:
					move1 = (rand() % 25);
					player_health -= move1;
					cout << "opponent used punch!!! You recieve " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 1:
					move2 = (rand() % 35);
					if (move2 < 10)
					{
						move2 += 10;
					}
					player_health -= move2;
					cout << "opponent used crush!!! You recieve " << move2 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				case 2:
					move1 = (rand() % 25);
					cpu_health += move1;
					cout << "opponent used heal!!! healed " << move1 << " damage\nYou have " << player_health << " health left\nOpponent has " << cpu_health << " health left.\n\n";
					break;
				}

				break;
			}
			break;
		}
	}
	while (player_health >= 0 && cpu_health >= 0);

	if (player_health > cpu_health)
	{
		cout << u_win << endl;
	}
	else
	{
		cout << cpu_wins << endl;
	}




	return 0;
}