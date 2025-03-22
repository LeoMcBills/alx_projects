#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to fetch data from GitHub API using curl
void fetch_github_data() {
	// Get the Github token from the environment variable
	const char *token = getenv("GITHUB_TOKEN");

	if (token != NULL) {
		// Construct the curl command with the token
		char command[1024];
		snprintf(command, sizeof(command), "curl -s -H \"Authorization: token %s\" https://api.github.com/users/LeoMcBills > github_data.json", token);

		// Execute the curl command
		system(command);
	} else {
		// If the token is not set or out of date, display an error message
		fprintf(stderr, "Error: Github token not set or out of date in the environment variable.\n");
	}
}

// Function to read specific data from JSON file
int read_contributions() {
    FILE *file = fopen("github_data.json", "r");
    if (file == NULL) {
        printf("Failed to open JSON file.\n");
        return -1;
    }

    char line[256];
    int followers = 0;
    int public_repos = 0;

    // Parse the JSON file
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\"followers\":")) {
            sscanf(line, " \"followers\": %d,", &followers);
        }
        if (strstr(line, "\"public_repos\":")) {
            sscanf(line, " \"public_repos\": %d,", &public_repos);
        }
    }
    fclose(file);

    printf("\033[2J\033[H"); // Clear terminal screen
    printf("====================================\n");
    printf("   📊 GitHub Activity Monitor\n");
    printf("====================================\n");
    printf("👤 Followers: %d\n", followers);
    printf("📁 Public Repositories: %d\n", public_repos);
    printf("🟢 Status: %s\n", (followers > 0) ? "Active" : "Inactive");
    printf("====================================\n");
    
    return followers;
}

// Function to show the dot when active
void show_active_dot(int is_active) {
    if (is_active) {
        printf("\033[32m●\033[0m Active on GitHub\n"); // Green dot
    } else {
        printf("\033[31m●\033[0m Inactive\n"); // Red dot
    }
}

int main() {
    printf("Starting GitHub activity monitor...\n");
    while (1) {
        fetch_github_data();
        int is_active = read_contributions();
        show_active_dot(is_active > 0);
        sleep(10); // Refresh every 10 seconds
    }
    return 0;
}

