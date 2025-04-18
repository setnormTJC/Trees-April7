// Filesystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<filesystem>
#include <iostream>


int main()
{
    auto currentPath = std::filesystem::current_path(); 
    std::filesystem::directory_iterator directoryIterator(currentPath); 

    std::cout << "Parent folder: " << currentPath << "\n";


    std::cout << "First file in directory: \n" <<  * directoryIterator << "\n";
    directoryIterator++; 
    std::cout << "Next file in directory: \n" << *directoryIterator << "\n";

    //for (const auto& it : currentPath.)



    std::cout << "Hello World!\n";
}
