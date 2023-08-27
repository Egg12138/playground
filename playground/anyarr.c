#include "play.h"
const char *str = "Hello, World!****************";

typedef union object {
        union object *p;
        char a[200];
} obj;



int
main(int argc, char *argv[])
{
        const size_t str_size = strlen(str);
        obj * objs = (obj *)malloc(sizeof(obj) + str_size - 1);
        objs->p = (obj *)malloc(sizeof(obj) + str_size - 1);
        char *normal = (char *)malloc(sizeof(str_size) - 1);

        dbgl(sizeof(objs));
        dbgl(sizeof(objs->a));
        dbgl(sizeof(normal));
        dbgl(sizeof(str_size));

        strcpy(objs->a, str);
        strcpy(normal, str);
        dbgs(normal);
        dbgs(objs->a);
        int i = 0;
        do {
                printf("%c:", objs->a[i]);
                i++;
        } while (objs->a[i]);

        puts("\n---\n");

        i = 0;
        do {
                printf("%c:", normal[i]);
                i++;
        } while (normal[i]);

        puts("\n---\n");
        strcpy(normal + sizeof(str), str);
        strcpy(((char *)objs->a) , str);


        dbgs(normal);
        dbgs(objs->a);

        return 0;
}
