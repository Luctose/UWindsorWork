#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int row = 0;
	int column = 0;
	row = atoi(argv[1]);
	column = atoi(argv[2]);
	int filedes[2]; // Destination for pipe
	
	// Make the pipe
	pipe(filedes);

	int *A = (int *) malloc((row * column) * sizeof(int));
	int i, j;
	int nbytes; // Bytes read
	char *readInt = malloc(sizeof(char) * 5); // For reading from the pipe
	printf("Enter the matrix elements:\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("A[%d, %d] = ", i, j);
			scanf("%d", A + i * column + j);
		}
		printf("\n");
	}

	int n = 0;
	printf("Enter a number: ");
	scanf("%d", &n);

	for(int i = 0; i < row; ++i){
		pid_t pid = fork();
		if(pid == -1){ // Not able to create child
			printf("Parent PID %d => \n", getpid());
			for(j = 0; j < column; j++){
				*(A + i * column + j) = n * (*(A + i * column + j));
				printf("%d * A[%d, %d] = %d\n", n, i, j, *(A + i * column + j));
			}
		}
		else if(pid == 0){ // Child
			close(filedes[0]); // Close read end as child doesn't need it
			printf("Child %d PID: %d\n", i, getpid());
			for(j = 0; j < column; j++){
				*(A + i * column + j) = n * (*(A + i * column + j));
				// Send the int to a char array to store it in pipe
				sprintf(readInt, "%d", *(A + i * column + j));
				// Write the new value to the pipe
				write(filedes[1], readInt, sizeof(int));
				printf("%d * A[%d, %d] = %d\n", n, i, j, *(A + i * column + j));
			}
			exit(0);
		}
	}
	wait(0);
	// Parent closes write side of pipe
	close(filedes[1]);

	printf("Final matrix elements:\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			// Read pre calculate integer from child
			nbytes = read(filedes[0], readInt, sizeof(int));
			// Set it to the appropriate indicies of the matrix
			*(A + i * column + j) = atoi(readInt);
			printf("A[%d, %d] = %d\n", i, j, *(A + i * column + j));
		}
		printf("\n");
	}
	// Free dynamic memory
	free(A);
	free(readInt);
	exit(0);
}
