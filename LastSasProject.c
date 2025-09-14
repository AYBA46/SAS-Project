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

void addPlayer() {
    if (count >= MAX_PLAYERS) {
        printf("Maximum players reached !");
        return; // To exit function addPlayer()
    }

    struct Player new_player; // Create an empty player

    new_player.id = next_id++; // Set the ID to next_id

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
    count++; // Add 1 to count, (Because we added a new player to the array)
}

void addMultiPlayers() {
    int n; // Number of players to add

    printf("Enter the number of players: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        addPlayer();
    }
}

void add() {
    int choice;

    printf("Enter: \n");
    printf("1- Add one player\n");
    printf("2- Add multiple players\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        addPlayer();
        break;
    case 2:
        addMultiPlayers();
        break;
    
    default:
        break;
    }
}

void sortByName() {
    int isVerified; // 0 == not verified/sorted, 1 == verified/sorted
    do { // Issue was the usage of = instead of ==
        isVerified = 1;
        for (int i=0; i<count-1; i++) {
            int j = i+1;
            int compareResult = strcmp(players[i].last_name, players[j].last_name);
            printf("Compare %s with %s. result: %d \n", players[i].last_name, players[j].last_name, compareResult);
            if (compareResult > 0) {
                printf("Swapping \n");
                char temp[50];
                struct Player tempPlayer;
                tempPlayer = players[i]; // Issue was swapping last names instead of whole player
                players[i] = players[j];
                players[j] = tempPlayer;
                isVerified = 0;
            } 

        }
    } while (isVerified == 0);
}

void sortByAge() {
    int isVerified; // 0 == not verified/sorted, 1 == verified/sorted
    do { // Issue was the usage of = instead of ==
        isVerified = 1;
        for (int i=0; i<count-1; i++) {
            int j = i+1;
            if (players[i].age > players[j].age) {
                printf("Swapping \n");
                char temp[50];
                struct Player tempPlayer;
                tempPlayer = players[i]; 
                players[i] = players[j];
                players[j] = tempPlayer;
                isVerified = 0;
            } 

        }
    } while (isVerified == 0);
}

void sortByGoals() {
    int isVerified; // 0 == not verified/sorted, 1 == verified/sorted
    do { // Issue was the usage of = instead of ==
        isVerified = 1;
        for (int i=0; i<count-1; i++) {
            int j = i+1;
            if (players[i].goals < players[j].goals) {
                printf("Swapping \n");
                char temp[50];
                struct Player tempPlayer;
                tempPlayer = players[i]; 
                players[i] = players[j];
                players[j] = tempPlayer;
                isVerified = 0;
            } 

        }
    } while (isVerified == 0);
}

void displayPlayers() {
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

void displayPlayersByName() {
    sortByName();
    displayPlayers();
}

void displayPlayersByAge() {
    sortByAge();
    displayPlayers();
}

void displayPlayersInPosition(char position[]) {
    // GD, DF, ML, AT
    printf("Displaying players in position %s\n", position);
    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (strcmp(players[i].position, position) == 0) {
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
}

void displayPlayersByPosition() {
    displayPlayersInPosition("GD");
    printf("------------------------------------\n");
    displayPlayersInPosition("DF");
    printf("------------------------------------\n");
    displayPlayersInPosition("ML");
    printf("------------------------------------\n");
    displayPlayersInPosition("AT");
    printf("------------------------------------\n");
}

void modifyPlayer() {
    int id, choice;

    printf("Enter the ID of the player to modify: ");
    scanf("%d", &id);

    printf("Enter: \n");
    printf("1 - Modify position \n");
    printf("2 - Modify age \n");
    printf("3 - Modify goals \n");
    scanf("%d", &choice);

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (players[i].id == id) {
            switch (choice)
            {
            case 1:
                printf("Enter the new position: ");
                scanf("%s", players[i].position);
                break;

            case 2:
                printf("Enter the new age: ");
                scanf("%d", &players[i].age);
                break;

            case 3:
                printf("Enter the new goals: ");
                scanf("%d", &players[i].goals);
                break;
            
            default:
                break;
            }
        }
    }
}

void deletePlayer() {
    int id;

    printf("Enter the ID of the player to delete: ");
    scanf("%d", &id);

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (players[i].id == id) {
            for (int j=i+1; j<count-1; j++) { // Loop through the players array, count is the limit
                players[j-1] = players[j];
            }
        }
    }
    count--;
}

void searchPlayerById() {
    int id;

    printf("Enter the ID of the player to search for: ");
    scanf("%d", &id);

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (players[i].id == id) {
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
}

void searchPlayerByLastname() {
    char last_name[50];

    printf("Enter the last name of the player to search for: ");
    scanf("%s", last_name);

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (strcmp(players[i].last_name, last_name) == 0) {
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
}

void showPlayerCount() {
    printf("Total player count: %d\n", count);
}

void showPlayerAverageAge() {
    int total = 0;
    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        total = total + players[i].age;
    }
    printf("Average players age: %d\n", total/count);
}

void showPlayersWithMoreGoals() {
    int goals;

    printf("Enter the number of goals: ");
    scanf("%d", &goals);

    for (int i=0; i<count; i++) { // Loop through the players array, count is the limit
        if (players[i].goals > goals) {
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
}

void showBestGoalScorer() {
    sortByGoals();
    printf("------------------------------------\n");
    printf("ID: %d\n", players[0].id);
    printf("First name: %s\n", players[0].first_name);
    printf("Last name: %s\n", players[0].last_name);
    printf("Position: %s\n", players[0].position);
    printf("Age: %d\n", players[0].age);
    printf("Goals: %d\n", players[0].goals);
    printf("Jersey number: %d\n", players[0].jersey_number);
}

void showOldestAndYoungestPlayers() {
    sortByAge();
    printf("Youngest:\n");
    printf("ID: %d\n", players[0].id);
    printf("First name: %s\n", players[0].first_name);
    printf("Last name: %s\n", players[0].last_name);
    printf("Position: %s\n", players[0].position);
    printf("Age: %d\n", players[0].age);
    printf("Goals: %d\n", players[0].goals);
    printf("Jersey number: %d\n", players[0].jersey_number);
    printf("------------------------------------\n");
    printf("Oldest:\n");
    printf("ID: %d\n", players[count-1].id);
    printf("First name: %s\n", players[count-1].first_name);
    printf("Last name: %s\n", players[count-1].last_name);
    printf("Position: %s\n", players[count-1].position);
    printf("Age: %d\n", players[count-1].age);
    printf("Goals: %d\n", players[count-1].goals);
    printf("Jersey number: %d\n", players[count-1].jersey_number);

}

void menu() {
    int choice;
    do {
        printf("\n--- Player Management Menu ---\n");
        printf("1. Add player(s)\n");
        printf("2. Display all players\n");
        printf("3. Display players sorted by name\n");
        printf("4. Display players sorted by age\n");
        printf("5. Display players by position\n");
        printf("6. Modify a player\n");
        printf("7. Delete a player\n");
        printf("8. Search player by ID\n");
        printf("9. Search player by last name\n");
        printf("10. Show player count\n");
        printf("11. Show average age\n");
        printf("12. Show players with more goals than...\n");
        printf("13. Show best goal scorer\n");
        printf("14. Show oldest and youngest players\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                displayPlayers();
                break;
            case 3:
                displayPlayersByName();
                break;
            case 4:
                displayPlayersByAge();
                break;
            case 5:
                displayPlayersByPosition();
                break;
            case 6:
                modifyPlayer();
                break;
            case 7:
                deletePlayer();
                break;
            case 8:
                searchPlayerById();
                break;
            case 9:
                searchPlayerByLastname();
                break;
            case 10:
                showPlayerCount();
                break;
            case 11:
                showPlayerAverageAge();
                break;
            case 12:
                showPlayersWithMoreGoals();
                break;
            case 13:
                showBestGoalScorer();
                break;
            case 14:
                showOldestAndYoungestPlayers();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
}
