#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <direct.h>

int main()
{
    std::string name = name, description, version, author, authorURI;

    std::cout << "What should be the name of the plugin?" << std::endl;
    std::cin >> name;
    std::cout << "Give a short description of the plugin." << std::endl;
    std::cin >> description;
    std::cout << "What version is your plugin in?" << std::endl;
    std::cin >> version;
    std::cout << "Who is the author of this plugin?" << std::endl;
    std::cin >> author;
    std::cout << "What is the website for the plugin/author?" << std::endl;
    std::cin >> authorURI;
    
    std::ofstream plugin;
    chdir("../");
    _mkdir(name.c_str());
    chdir(name.c_str());
    plugin.open("index.php");
    plugin  << "<?php" << std::endl
            << "/*" << std::endl
            << " * Plugin Name: " << name.c_str() << std::endl
            << " * Description: " << description.c_str() << std::endl
            << " * Version: " << version.c_str() << std::endl
            << " * Author: " << author.c_str() << std::endl
            << " * Author URI: " << authorURI.c_str() << std::endl
            << " * Text Domain: " << name.c_str() << std::endl
            << " */" << std::endl << "?>";
    plugin.close();
    return 0;
}