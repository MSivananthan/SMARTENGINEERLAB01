#include <stdio.h>
#include <windows.h>

/*
 * Simple login CGI program
 */
int main() {
	printf("Content-Type: text/plain\n\n");
	
	char *data = getenv("QUERY_STRING");
	char *msg = "Invalid data";
	
	puts("<!-- Form data was:");
	puts(data);
	puts("-->");
	
	Sleep(2000);
	if (data != NULL) {
		if (strstr(data, "userId=bob") == NULL) {
			msg = "Invalid user name. Please try again.";
		} else if (strstr(data, "password=bobcat") == NULL) {
			msg = "Invalid password. Please try again.";
		} else {
			msg = "You have successfully logged in!";
		}
	}
	puts(msg);
}