#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
	// Creating file descriptors
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *filename = "./log.txt";
	int fd_in = open("/dev/pts/0", O_RDONLY);
	
	// Check if it opened
	if(fd_in == -1){
		printf("Error in opening device!\n");
		return;
	}

	int fd_out = creat(filename, mode);

	// Check if it opened
	if(fd_out == -1){
		printf("Error in creating file!\n");
		return;
	}
	
	// Variables to write to log.txt and read from tty
	char buf[30];
	ssize_t bytes_written;
	ssize_t bytes_read;
	
	sprintf(buf, "The file descriptor is %d\n", fd_in);
	
	// Write the fd to log.txt
	bytes_written = write(fd_out, buf, sizeof(buf));
	if(bytes_written <= 0){
		printf("Error in writing to the file!");
	}
	// Empty buffer
	int i = 0;
	while(buf[i] != '\0'){
		buf[i] = '\0';
		i++;
	}

	// Variables to control when to end loop
	char stop[4];
	strcpy(stop, "END");
	int count = 0;

	while((bytes_read = read(fd_in, buf, sizeof(buf))) > 0){
		bytes_written = write(fd_out, buf, sizeof(buf));
		if(bytes_written <= 0){
			printf("Error in writing to the file!");
		}
		for(int i = 0; i < 3; i++){
			if(buf[i] == stop[i]){
				count++;
			}
		}
		// Empty buffer
		i = 0;
		while(buf[i] != '\0'){
			buf[i] = '\0';
			i++;
		}

		if(count >= 3){
			break;
		}
		count = 0;
	}

	int result = close(fd_in);
	if(result == -1){
		printf("Error in closing the device!\n");
	}
	result = close(fd_out);
	if(result == -1){
		printf("Error in closing the device!\n");
	}
	return;
}
