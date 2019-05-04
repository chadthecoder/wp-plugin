#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/param.h>
#include <direct.h>

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
        std::ofstream plugin;
        std::string name = argv[1];
        chdir("../");
        _mkdir(name.c_str());
        chdir(name.c_str());
        plugin.open("index.php");
        plugin  << "<?php\n"
                << "/*\n" 
                << " * Plugin Name: " << name.c_str() << std::endl;
                if(argc == 3){ plugin << " * Description: " << std::string(argv[2]).c_str() << std::endl; }
                plugin << " * Version: " << "1.0" << std::endl
                << " * Author: " << "Chad McAdams" << std::endl
                << " * Author URI: " << "https://www.mcadamschad.com" << std::endl
                << " * Text Domain: " << name.c_str()
                << "\n */\n?>";
        plugin.close();
    }
    else
    {
        std::cout << "Please add one arguement for the name of the plugin./n";
    }
    
}