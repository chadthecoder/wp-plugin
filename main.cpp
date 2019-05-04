#include <iostream>
#include <fstream>
#include <string>

#include <unistd.h>
#include <direct.h>
#include <bits/stdc++.h>

int main()
{
    std::string name, description, version, author, authorURI;
    std::cout << "What should be the name of the plugin?" << std::endl;
    getline(std::cin, name);
    std::cout << "Give a short description of the plugin." << std::endl;
    getline(std::cin, description);
    std::cout << "What version is your plugin in?" << std::endl;
    getline(std::cin, version);
    std::cout << "Who is the author of this plugin?" << std::endl;
    getline(std::cin, author);
    std::cout << "What is the website for the plugin/author?" << std::endl;
    getline(std::cin, authorURI);

    std::string textDomain = name;
    transform(name.begin(), name.end(), textDomain.begin(), ::tolower);

    std::ofstream plugin;
    chdir("../");
    _mkdir(name.c_str());
    chdir(name.c_str());
    plugin.open("index.php");

    plugin  << "<?php" << std::endl
            << "/*" << std::endl
            << " * Plugin Name: " << name << std::endl
            << " * Description: " << description << std::endl
            << " * Version: " << version << std::endl
            << " * Author: " << author << std::endl
            << " * Author URI: " << authorURI << std::endl
            << " * Text Domain: " << textDomain << std::endl
            << " */" << std::endl << "?>";
    plugin.close();
    return 0;
}