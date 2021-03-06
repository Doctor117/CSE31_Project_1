#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
  // Implement if desire 

  return 0;
}

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {
	int length = 0;
	int count = 0;
	char* partial_line = (char*)malloc(MAXSIZE*sizeof(char));
	while(line[length] != '/0') {
		length++;
	} for (int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++) {
			*(partial_line+j) = line[i+j];
		}
		//printf("loop1\n");
		if(matches_leading(partial_line, pattern) || matches_leading(partial_line, remove_optional(pattern))){
			return 1;
		}
		free(partial_line);
		partial_line = (char*)malloc(MAXSIZE*sizeof(cahr));
		count++;
	}
	
	
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
