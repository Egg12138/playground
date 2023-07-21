#include <stdio.h>
#include <stdlib.h>

#define CMD(a,b) {(a),(b)},


void *say_hello(const char *user) {
    printf("Hello %s\n", user);
}

void *say_working(const char *prog) {
    printf("%s is working...\n", prog);
}

void *say_parsing(const char *binary) {
    printf("pasing %s...\n", binary);
}

struct cmd {
    const char *cmdname;
    void (*handler)(const char *arg);

} commands[] = {
        CMD("gcc",say_hello)
        CMD("exa",say_hello)
        CMD("rg", say_working)
        CMD("fd", say_working)
        CMD("nm", say_parsing)
        CMD("", NULL) // ensure the parsing cmp loop can end correclty
};

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s PATTERN DO\n", argv[0]);
        fprintf(stderr, "pattern-list contains: \
                gcc - (say hello) \n\
                exa - (say hello) \n\
                rg - (say working)\n\
                fd - (say working)\n\
                nm - (say parsing)\n\
                ");
        return 1;
    }
    
    for (struct cmd *cmd2Bhandler = &commands[0]; cmd2Bhandler->handler; cmd2Bhandler++) {
        for (char **argument = &argv[2]; *argument && strcmp(argv[1], cmd2Bhandler->cmdname) ;argument++ ) {
            if (argument != argv + 2) printf("\n"); // only handler arguemnt 2(0,1,2)
            cmd2Bhandler->handler(*argument);
        }
    }

    return 0;

}
