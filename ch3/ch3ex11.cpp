#include <cstdlib>

#include "../PPP/PPP.h"

enum MatchResult
{
	Win,
	Loss,
	Draw,
	Error
};

MatchResult DetermineResult(int first_choice_index, int second_choice_index)
{
	if (first_choice_index < 0 || first_choice_index > 2)
		return Error;
	if (second_choice_index < 0 || second_choice_index > 2)
		return Error;

	if (first_choice_index == second_choice_index)
		return Draw;

	if (first_choice_index + 1 == second_choice_index && first_choice_index != 2)
		return Loss;
	if (first_choice_index + 2 == second_choice_index && first_choice_index == 0 /*first_choice_index != 1 && first_choice_index != 2*/)
		return Win;

	if (first_choice_index - 1 == second_choice_index && first_choice_index != 0)
		return Win;
	if (first_choice_index - 2 == second_choice_index && first_choice_index == 2 /*first_choice_index != 0 && first_choice_index != 1*/)
		return Loss;

	return Error;
}

int main()
{
	srand(time(0));

	string player_input = "";
	int player_score = 0;
	vector<string> bot_input = { "Rock", "Paper", "Scissors" };
	int bot_score = 0;
	
	char new_round = 'y';
	
	while (new_round == 'y')
	{
		cout << "Enter your hand (Rock, Paper or Scissors): ";
		cin >> player_input;
		cout << endl;
		int player_choice_index = -1;
		if (player_input == "Rock" || player_input == "rock")
		{
			player_choice_index = 0;
		}
		else if (player_input == "Paper" || player_input == "paper")
		{
			player_choice_index = 1;
		}
		else if (player_input == "Scissors" || player_input == "scissors")
		{
			player_choice_index = 2;
		}

		int bot_choice_index = rand() % 3;
		string bot_choice = bot_input[bot_choice_index];
		cout << "Computer picked: " << bot_choice << endl;

		MatchResult result = DetermineResult(player_choice_index, bot_choice_index);

		switch (result)
		{
		case Win:
			player_score++;
			cout << "Player won the round!" << endl;
			break;
		case Loss:
			bot_score++;
			cout << "Computer won the round!" << endl;
			break;
		case Draw:
			cout << "Draw! Score stays the same." << endl;
			break;
		default:
			cout << "ERROR: Invalid round!" << endl;
		}

		cout << "\nPlayer " << player_score << " - " << bot_score << " Computer" << endl << endl;

		do
		{
			cout << "New round (y/n): ";
			cin >> new_round;
		} while (new_round != 'y' && new_round != 'Y' && new_round != 'n' && new_round != 'N');
	}
}