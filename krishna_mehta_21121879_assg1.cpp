#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//declaring all variables
int MAX_EVENTS = 30;

int a_score = 0, b_score = 0;
int shots_on_goal_a = 0, shots_on_goal_b = 0;
int shots_off_goal_a = 0, shots_off_goal_b = 0;
int yellow_fouls_a = 0, yellow_fouls_b = 0;
int red_fouls_a = 0, red_fouls_b = 0;
int shots_blocked_a = 0, shots_blocked_b = 0;

// Function prototypes before generating them
void shot_goal_a();
void shot_goal_b();
void foul_shot_a();
void foul_shot_b();
void team_a_foul();
void team_b_foul();
void too_close_foul_a();
void too_close_foul_b();
void print_stats(int half);

//main function
int main() {
    srand(unsigned(time(0))); // Seed the random number generator

    int num_of_events = rand() % MAX_EVENTS + 1; // Generate number of events
    cout << "Number of events: " << num_of_events << endl;

    for (int i = 1; i <= num_of_events; i++) {
        int event_number = rand() % 6 + 1; // Generate event number

        switch (event_number) {
            case 1:
                shot_goal_a();
                break;
            case 2:
                shot_goal_b();
                break;
            case 3:
                team_b_foul();
                break;
            case 4:
                team_a_foul();
                break;
            case 5:
                too_close_foul_b();
                break;
            case 6:
                too_close_foul_a();
                break;
        }

        // Print stats after half the events
        if (i == num_of_events / 2) {
            print_stats(1); // First half stats
            srand(static_cast<unsigned>(time(0))); // Reseed for randomness
        }
    }

    print_stats(2); // Final stats

    return 0;
}

// Functions
void shot_goal_a() {
    int possibility_shot = rand() % 4;
    if (possibility_shot == 0) {
        a_score++;
        shots_on_goal_a++;
        cout << "Team A scored a goal!\n";
    } else if (possibility_shot == 1) {
        shots_on_goal_a++;
        cout << "Team A shot but the goalkeeper saved it! What a save!\n";
    } else if (possibility_shot == 2) {
        shots_off_goal_a++;
        cout << "Team A's shot was off goal! Better luck next time!\n";
    } else {
        shots_blocked_a++;
        cout << "Team A's shot was blocked! Improve your offense!\n";
    }
}

void shot_goal_b() {
    int possibility_shot = rand() % 4;
    if (possibility_shot == 0) {
        b_score++;
        shots_on_goal_b++;
        cout << "Team B scored a goal!\n";
    } else if (possibility_shot == 1) {
        shots_on_goal_b++;
        cout << "Team B shot but the goalkeeper saved it! What a save!\n";
    } else if (possibility_shot == 2) {
        shots_off_goal_b++;
        cout << "Team B's shot was off goal! Better luck next time!\n";
    } else {
        shots_blocked_b++;
        cout << "Team B's shot was blocked! Improve your offense!\n";
    }
}

void foul_shot_a() {
    int foul_shot_goal = rand() % 3;
    if (foul_shot_goal == 0) {
        a_score++;
        shots_on_goal_a++;
        cout << "Team A scored their penalty shot!\n";
    } else {
        shots_on_goal_a++;
        cout << "Team A missed their penalty shot!\n";
    }
}

void foul_shot_b() {
    int foul_shot_goal = rand() % 3;
    if (foul_shot_goal == 0) {
        b_score++;
        shots_on_goal_b++;
        cout << "Team B scored their penalty shot!\n";
    } else {
        shots_on_goal_b++;
        cout << "Team B missed their penalty shot!\n";
    }
}

void team_a_foul() {
    int foul_card = rand() % 3;
    if (foul_card == 0) {
        cout << "Team A got a yellow card!\n";
        yellow_fouls_a++;
        foul_shot_b();
    } else if (foul_card == 1) {
        cout << "Team A got a red card!\n";
        red_fouls_a++;
        foul_shot_b();
    }
}

void team_b_foul() {
    int foul_card = rand() % 3;
    if (foul_card == 0) {
        cout << "Team B got a yellow card!\n";
        yellow_fouls_b++;
        foul_shot_a();
    } else if (foul_card == 1) {
        cout << "Team B got a red card!\n";
        red_fouls_b++;
        foul_shot_a();
    }
}

void too_close_foul_a() {
    cout << "Team A committed a foul too close to the goal! Team B gets a penalty shot:\n";
    int is_goal_scored = rand() % 3;
    if (is_goal_scored == 0) {
        b_score++;
        shots_on_goal_b++;
        cout << "Team B has scored a goal!\n";
    } else if (is_goal_scored == 1) {
        shots_on_goal_b++;
        cout << "Team B shot but saved by the goalkeeper!\n";
    } else {
        shots_off_goal_b++;
        cout << "Team B shot off goal!\n";
    }
}

void too_close_foul_b() {
    cout << "Team B committed a foul too close to the goal! Team A gets a penalty shot:\n";
    int is_goal_scored = rand() % 3;
    if (is_goal_scored == 0) {
        a_score++;
        shots_on_goal_a++;
        cout << "Team A has scored a goal!\n";
    } else if (is_goal_scored == 1) {
        shots_on_goal_a++;
        cout << "Team A shot but saved by the goalkeeper!\n";
    } else {
        shots_off_goal_a++;
        cout << "Team A shot off goal!\n";
    }
}

void print_stats(int half) {
    cout << "Half " << half << " Stats:\n";
    cout << "Final Score:\n";
    cout << "Team A: " << a_score << "\n";
    cout << "Team B: " << b_score << "\n";
    cout << "Shots on Goal A: " << shots_on_goal_a << "\n";
    cout << "Shots on Goal B: " << shots_on_goal_b << "\n";
    cout << "Shots Off Goal A: " << shots_off_goal_a << "\n";
    cout << "Shots Off Goal B: " << shots_off_goal_b << "\n";
    cout << "Blocked Shots A: " << shots_blocked_a << "\n";
    cout << "Blocked Shots B: " << shots_blocked_b << "\n";
    cout << "Yellow Cards A: " << yellow_fouls_a << "\n";
    cout << "Yellow Cards B: " << yellow_fouls_b << "\n";
    cout << "Red Cards A: " << red_fouls_a << "\n";
    cout << "Red Cards B: " << red_fouls_b << "\n";
    cout << "---------------------\n";
}
