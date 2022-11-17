#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

void readline(FILE *fp, char *s, int size) {
    int len = 0;
    for (char c = fgetc(fp); c != '\n' && c != EOF; c = fgetc(fp)) {
    	if (len+1 >= size) {
    		s = realloc(s, size * 2);
    	}
    	s[len] = c;
        len++;
    }
    s[len] = '\0';
    s = realloc(s, len+1);
}

int main(int argc, char **argv) {
    if (argc < 3) { // Wrong number of arguments
        fprintf(stderr, "%s requires two arguments:\n\t%s <file_path> <command>\n", argv[0], argv[0]);
        return 1;
    }
    assert(argc >= 3); // Function called with 3 arguments
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) { // File opening error
        if(errno == EACCES)
            fprintf(stderr, "Read permission access of file %s denied\n", argv[1]);
        if(errno == EISDIR)
            fprintf(stderr, "%s is a directory\n", argv[1]);
        return 1;
    }
    char **cmd = argv + 2;
    int Nsize = 5; // Size of the array N (allocated in the next line)
    int *N = malloc(Nsize * sizeof(int)); // allocation of the array that will contain all the i (indexes) of argv where argv[i] = "@"
    int j = 0;
    for(int i = 0; i < argc-2; ++i) {
    	if (!strcmp(cmd[i], "@")) {
    		if (j >= Nsize) {
    			Nsize = Nsize * 2;
    			N = realloc(N, Nsize);
    		}
    		N[j] = i;
    		++j;
    	}
    }
    Nsize = j;
    N = realloc(N, Nsize);
    // now N contains all the i | argv[i] = "@"
    int size = 5;
    char *line = malloc(size * sizeof(char));
    readline(fp, line, size);
    while (!feof(fp)) {
        for (int i = 0; i < Nsize; ++i) {
            cmd[N[i]] = line;
        }
        
        pid_t pid = fork();
        switch(pid) {
        	case -1:
        		perror("fork() failed");
        		return 1;
        	case 0:	
        		//printf("Execution...\n");
        		execvp(cmd[0], cmd);
        		
        		perror("Execution failed");
        		return 1;
        	default:
        		wait(NULL);
        		//printf("Done\n");
        		//printf("\n");
        }
        
        free(line);
        char *line = malloc(size * sizeof(char));
    	readline(fp, line, size);
    }
    return 0;
}
