#ifndef COMMAND_FUNC_H
#define COMMAND_FUNC_H


class FCommand {
public:
    FCommand();
    ~FCommand();
    void echo_str(char *str_echo)
    {
        printf(str_echo);
    }
    void get_username(char *_your_username)
    {
        _your_username = getenv("USER");
    }
    void list_dir(const char *path) 
    {
        struct dirent *entry; // #i.. <dirent.h>
        DIR *dir = opendir(path); // open path dir
   
        if (dir == NULL) 
        {
            return;
        }
        while ((entry = readdir(dir)) != NULL) 
        {
            std::cout << entry->d_name << "  ";
        }
        closedir(dir);
    }
    void plus_num(uint64_t first_num, uint64_t sec_num)
    {
        printf("First number: ");
        std::cin >> first_num;
        printf("Second number ");
        std::cin >> sec_num;
        uint64_t fs_num = sec_num + first_num;
        std::cout << fs_num << "\n";
    }
    void fetcheya(int ram_size, char *cpu_type)
    {
       // fsync__->CPU(cpu_type);
    }
    void error_undfnd(char *undefined_str)
    {
        undefined_str = "This is Undefined \n";
        printf(undefined_str);
    }
    void _file_path(char *list_path_def_name)
    {
         list_dir("/home/"); 
    }
    void _term_(char *file_str)
    {
        file_str = "$|";
        printf(file_str);
    }
    void help()
    {
      //  std::cin >> _cin;
   
     printf(_help_str);
        
    }
    void cd_func(char *new_path)
    {
        
    }
    void hello()
    {
      //  *_h_str = *_hello_str; -> This code calling Segmentation Fault error. 
        printf(_help_str);
    }
    void printerror(char *err_str, int8_t err_number)
    {
        printf(err_str, err_number);
    }

    void error_syntax(char *err_str, int8_t err_number)
    {   
      
        printerror(err_str, err_number);
    }
private:
    char *_hello_str = "help arguments:\n"
    "echo <arg>\n"
    "intnumber plus intnumber\n"
    "./<file>\n"
    "brk || cls -> Close Scrift Shell \n"
    "cd <folder> \n"
    "ls -> List\n"
    "-f || fetcheya -> System info ";
    char *_help_str = "Welcome ScriftLang Terminal\n"
    "ScriftLang licensed with GPLv3'\n"
    "Copyright (c) 2020 Ferhat Gecdogan\n";
};


#endif // COMMAND_FUNC_H