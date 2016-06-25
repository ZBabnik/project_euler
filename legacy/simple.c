//#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char dir_name[50];
char dir_name_file[50];

int main()
{
    char problem_num;
    printf("Vnesi stevilko problema: ");
    scanf("%c", &problem_num);
    
    strcat(dir_name, "Problem_");
    strcat(dir_name, &problem_num);
    strcat(dir_name, "\0");
    
    int check = mkdir(dir_name, 0777);
    if(check == 0)  fprintf(stdout ,"Succesfuly created %s\n", dir_name);
    
    strcat(dir_name_file, "Problem_");
    strcat(dir_name_file, &problem_num);
    strcat(dir_name_file, "/aaa.c");
    strcat(dir_name_file, "\0");

    FILE* f = fopen(dir_name_file, "w");
    fprintf(f, "/* Navodila rabm še nardit ... */\n\n#include <stdio.h>\n#include <stdlib.h>\n\n int main()\n{\n    int res = 0;\n    printf();\n    return 0;\n}");
    /*
    Py_Initialize();
    PyRun_SimpleString("print 'HI!'\n");
    Py_Finalize();
    */
    fclose(f);
   
    return 0;
}