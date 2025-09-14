#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 100

struct Player { // Player model
    int id;
    char first_name[50];
    char last_name[50];
    int jersey_number;
    char position[50];
    int age;
    int goals;
};

int count = 0; // Players count
int next_id = 1;
struct Player players[MAX_PLAYERS]; // Array of players, initial size = MAX_PLAYERS

void add() {
    int choice;


    printf("Enter: ");
    printf("1- Add one player");
    printf("2- Add multiple players");
    scanf("%d", &choice);

    if(choice == 1){
        addPlayer();
    }
    if(choice == 2){
        addMultiPlayers();
    }


}

void addPlayer() {
    struct Player new_player; // Create an empty player

    new_player.id = next_id; // Set the ID to count + 1

    printf("------------------------------------\n");

    printf("Enter player first name: ");
    scanf("%s", new_player.first_name);

    printf("Enter player last name: ");
    scanf("%s", new_player.last_name);

    printf("Enter player position: ");
    scanf("%s", new_player.position);

    printf("Enter player age: ");
    scanf("%d", &new_player.age);

    printf("Enter player jersey number: ");
    scanf("%d", &new_player.jersey_number);

    printf("Enter player goals: ");
    scanf("%d", &new_player.goals);

    players[count] = new_player; // Put the new player in the spot number count,
    count++; // Add 1 to coun, (Because we added a new player to the array)
}

void addMultiPlayers() {
    int n; // Number of players to add

    printf("Enter the number of players: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        addPlayer();
    }
}

void sortByName() {
    int isVerified = 0;
    while (isVerified == 0) { // Issue was the usage of = instead of ==
        isVerified = 1;
        for (int i=0; i<count-1; i++) {
            int j = i+1;
            int compareResult = strcmp(players[i].last_name, players[j].last_name);
            printf("Compare %s with %s. result: %d \n", players[i].last_name, players[j].last_name, compareResult);
            if (compareResult > 0) {
                printf("Swapping \n");
                struct Player tempPlayer;
                tempPlayer = players[i]; // Issue was swapping last names instead of whole player
                players[i] = players[j];
                players[j] = tempPlayer;
                isVerified = 0;
            }

        }
    }
}

void displayPlayersByName() {
    sortByName();

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        printf("------------------------------------\n");
        printf("ID: %d\n", players[i].id);
        printf("First name: %s\n", players[i].first_name);
        printf("Last name: %s\n", players[i].last_name);
        printf("Position: %s\n", players[i].position);
        printf("Age: %d\n", players[i].age);
        printf("Goals: %d\n", players[i].goals);
        printf("Jersey number: %d\n", players[i].jersey_number);
    }
}

int main() {
    addMultiPlayers();
    displayPlayersByName();
    printf("Finished");
}
