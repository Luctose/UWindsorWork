#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
	printf("exec_math_bs pid: %d\n", getpid());
	char *program = malloc(sizeof(char) * 300);
	sprintf(program, "#include <stdio.h>\n"
			"#include <stdlib.h>\n"
			"#include <unistd.h>\n"
			"int result;\n"
			"int main(void){\n"
			"printf(\"math pid: %%d\\n\", getpid());\n"
			"int a = 0;\n"
			"int b = 0;\n"
			"a = %s;\n"
			"b = %s;\n"

			"result = a %s b;\n"

			"printf(\"%%d %s %%d = %%d\\n\", a, b, result);\n"
			"return 0;\n"
			"}\n", argv[2], argv[3], argv[1], argv[1]);

	int fd = creat("./math.c", S_IRUSR | S_IWUSR);
	printf("fd for math.c file: %d\n", fd);
	write(fd, program, strlen(program));
	free(program);
	system("cc ./math.c -o math");
	int newfd = open("./math", O_RDONLY);
	char *newargv[] = {"./math", NULL};
	char *newenviron[] = {NULL};
	int res = fexecve(newfd, newargv, newenviron);

	printf("%d\n", res);
}
