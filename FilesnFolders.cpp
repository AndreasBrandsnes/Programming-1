// LearningVectors04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "File.h"
#include "Folder.h"
#include "GetTime.h"

using namespace std;

const int max_folders = 5;
const int max_files = 10;

int main()
{
    vector<Folder> folders;
    int number_ofFolders = 0;
    vector<Folder> v;

    bool isRunning = true;
     srand(time(NULL));

    while (isRunning)
    {
        cout << "MENU";
        cout << "\n01. Create folder";
        cout << "\n02. Create file";
        cout << "\n03. Display folders";
        cout << "\n04. Display files in folder";
        cout << "\n05. Change name of folder";
        cout << "\n06. Change name of file in folder";
        cout << "\n07. Show size of folder";
        cout << "\n08. Show current biggest file";
        cout << "\n09. Quit";


        cout << "\n\nPlease choose from the menu above: " << endl;
        int choise;
        cin >> choise;

        switch (choise)
        {
        // Create a folder
        case 1:
            if (folders.size() < max_folders) {
                Folder newFolder;
                cout << "\nPlease enter name of new folder: ";
                cin >> newFolder.folder_name;
                folders.push_back(newFolder);
            }
            else {
                cout << "\nMaximum amout of folders reached. You cannot create any more folders!";
                //cout << "\nPlease delete folders before trying to create a new folder." << endl;
            }
            break;

        // Create a file in folder
        case 2:

            if (folders.empty())
            {
                cout << "\nNo folders. Shame!" << endl;
            }
            else {
                int folder_list;

                cout << "\nWhich folder would you like to create a file within? (0 - " << folders.size() - 1 << "): " << endl;
                cout << "These are the current folders avaible: " << endl;
                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl; // I want to display the names of the folder in a list.
                }
                cin >> folder_list;
                if (folder_list >= 0 && folder_list < folders.size())
                {
                    if (folders[folder_list].files.size() < max_files)
                    {
                        File newFile;
                        cout << "\nPlease enter the file name: ";
                        cin >> newFile.file_name;
                        
                        folders[folder_list].files.push_back(newFile);
                    }
                    else
                    {
                        cout << "\nThe folder is full!" << endl;
                    }
                }
                else
                {
                    cout << "\nInvalid folder index! Try again!" << endl;
                }

                break;

        // Display folders
        case 3:
            if (folders.empty())
            {
                cout << "There are no folders to show. Try creating a folder!";
            }
            else
            {
                cout << "\n\nList of current folders: " << endl;
                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }
            }
            break;

        // Display files in folder
        case 4:
            if (folders.empty() == false)
            {
                int folder_list;
                cout << "Select a folder (0 - " << folders.size() - 1 << ").\n";
                
                for (int i = 0; i < folders.size(); i++) 
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }

                cin >> folder_list;
                
                if (folder_list >= 0 && folder_list < folders.size())
                {
                    cout << endl;
                    for (int i = 0; i < folders[folder_list].files.size(); i++)
                    {
                        cout << folders[folder_list].files[i].file_name
                             << " size: " << folders[folder_list].files[i].size
                             << "MB " << folders[folder_list].files[i].dt << endl;
                    }

                    cout << endl;
                }
            }
            else
            {
                cout << "\nThere are no folders, therefore no files to display!" << endl;
            }
            break;

            // Change name of folder
        case 5:
            if (folders.empty() == false)
            {
                int folder_list;
                cout << "Select a folder (0 - " << folders.size() - 1 << ").\n";

                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }

                cin >> folder_list;

                cout << "Enter the new name of the folder: ";

                string new_folder_name;
                string old_name = folders[folder_list].folder_name;

                cin >> new_folder_name;

                folders[folder_list].folder_name = new_folder_name;

                cout << "Folder " << old_name << " has changed to " << new_folder_name << endl << endl;
            }
            else
            {
                cout << "\nThere are no folders, therefore no files to display!" << endl;
            }

        // Change name of file in folder
        case 6:
            if (folders.empty() == false)
            {
                int folder_list;
                cout << "Select a folder (0 - " << folders.size() - 1 << ").\n";

                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }

                cin >> folder_list;

                if (folder_list >= 0 && folder_list < folders.size())
                {
                    
                    for (int i = 0; i < folders[folder_list].files.size(); i++)
                    {
                        cout << i << ": " << folders[folder_list].files[i].file_name << endl;
                    }

                    cout << "\nPlease select a file (0 -" << folders[folder_list].files.size() << "):" << endl;
                    cin >> choise;
                    cout << "Please enter new name of file: ";
                    string new_file_name;
                    cin >> new_file_name;

                    folders[folder_list].files[choise].file_name = new_file_name;
                }
            }
            else
            {
                cout << "\nThere are no folders, therefore no files to display!" << endl;
            }
            break;

        // Show size of folder
        case 7:
            if (folders.empty() == false)
            {
                int folder_list;
                cout << "Select a folder (0 - " << folders.size() - 1 << ").\n";

                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }

                cin >> folder_list;

                if (folder_list >= 0 && folder_list < folders.size())
                {
                    int size = 0;

                    for (int i = 0; i < folders[folder_list].files.size(); i++)
                    {
                        size += folders[folder_list].files[i].size;
                    }

                    cout << endl << "Folder " << folders[folder_list].folder_name << " size: " << size << endl << endl;
                }
            }
            else
            {
                cout << "\nThere are no folders, therefore no files to display!" << endl;
            }

            break;

        // Show info on current biggest file in folder
        case 8:
            if (folders.empty() == false)
            {
                int folder_list;
                cout << "Select a folder (0 - " << folders.size() - 1 << ").\n";

                for (int i = 0; i < folders.size(); i++)
                {
                    cout << i << ": " << folders[i].folder_name << endl;
                }

                cin >> folder_list;

                if (folder_list >= 0 && folder_list < folders.size())
                {
                    int largestFileSize = -1;
                    int largestFileIndex;

                    for (int i = 0; i < folders[folder_list].files.size(); i++)
                    {
                        if (folders[folder_list].files[i].size > largestFileSize)
                        {
                            largestFileSize = folders[folder_list].files[i].size;
                            largestFileIndex = i;
                        }
                    }

                    cout << endl << "Largest file in folder "
                         << folders[folder_list].folder_name
                         << " is file "
                         << folders[folder_list].files[largestFileIndex].file_name
                         << ": "
                         << folders[folder_list].files[largestFileIndex].size
                         << "MB "
                         << folders[folder_list].files[largestFileIndex].dt
                         << endl
                         << endl;
                }
            }
            else
            {
                cout << "\nThere are no folders, therefore no files to display!" << endl;
            }

            break;

        // Quit
        case 9:
            isRunning = false;
            break;
            }
        }
    }
}
