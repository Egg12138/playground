#include "play.h"

extern char **environ;


char varname_buf[64];

void check_varname() {
        char *value = getenv((char *)varname_buf);
        dbgs(value);
}

int
main(int argc, char *argv[])
{
        char **envs;
        for (envs = environ; *envs; envs++) {
                //dbgs(*envs);
                for (int idx = 0; (*envs)[idx]; idx++) {
                        varname_buf[idx] = (*envs)[idx];
                        if ((*envs)[idx] == '=') {
                               varname_buf[idx] = '\0';
                               break;
                        }
                }
                dbgs(varname_buf);
                check_varname();
                }
        
        return 0;
}
