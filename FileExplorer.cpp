// #include <iostream>
// #include <filesystem>
// #include <string>
// using namespace std;
// namespace fs = filesystem;

// void ListFiles(const string& path) {
//     for (const auto& entry : fs::directory_iterator(path)) {
//         cout << entry.path().filename().string() << endl;
//     }
// }

// void DisplayMenu() {
//     cout << "\nFile Explorer Menu:\n";
//     cout << "1. List Files\n";
//     cout << "2. Open File\n";
//     cout << "3. Exit\n";
//     cout << "Enter your choice: ";
// }

// int main() {
//     string currentPath = fs::current_path().string();

//     while (true) {
//         cout << "\nCurrent Path: " << currentPath << "\n";
//         DisplayMenu();
        
//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 ListFiles(currentPath);
//                 break;
            
//             case 2: {
//                 string fileName;
//                 cout << "Enter the name of the file to open: ";
//                 cin >> fileName;
//                 string filePath = currentPath + "/" + fileName;

//                 if (fs::exists(filePath)) {
//                     cout << "\nOpening file: " << filePath << "\n";
//                     // Add code to open and read the file
//                 } else {
//                     cout << "\nFile not found.\n";
//                 }
//                 break;
//             }
            
//             case 3:
//                 cout << "Exiting...\n";
//                 return 0;
            
//             default:
//                 cout << "Invalid choice. Please select again.\n";
//                 break;
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <dirent.h>
// using namespace std;

// void ListFiles(const string& path) {
//     DIR *dir;
//     struct dirent *ent;
//     if ((dir = opendir(path.c_str())) != nullptr) {
//         while ((ent = readdir(dir)) != nullptr) {
//             cout << ent->d_name << endl;
//         }
//         closedir(dir);
//     } else {
//         perror("Error opening directory");
//     }
// }

// void DisplayMenu() {
//     cout << "\nFile Explorer Menu:\n";
//     cout << "1. List Files\n";
//     cout << "2. Open File\n";
//     cout << "3. Exit\n";
//     cout << "Enter your choice: ";
// }

// int main() {
//     string currentPath = ".";
//     vector<string> files;
    
//     while (true) {
//         cout << "\nCurrent Path: " << currentPath << "\n";
//         DisplayMenu();
        
//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 ListFiles(currentPath);
//                 break;
            
//             case 2: {
//                 string fileName;
//                 cout << "Enter the name of the file to open: ";
//                 cin >> fileName;
//                 string filePath = currentPath + "/" + fileName;
                
//                 // Add code to open and read the file
                
//                 break;
//             }
            
//             case 3:
//                 cout << "Exiting...\n";
//                 return 0;
            
//             default:
//                 cout << "Invalid choice. Please select again.\n";
//                 break;
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <dirent.h>
// #include <fstream>
// using namespace std;

// void ListFiles(const string& path) {
//     DIR *dir;
//     struct dirent *ent;
//     if ((dir = opendir(path.c_str())) != nullptr) {
//         while ((ent = readdir(dir)) != nullptr) {
//             cout << ent->d_name << endl;
//         }
//         closedir(dir);
//     } else {
//         perror("Error opening directory");
//     }
// }

// void DisplayMenu() {
//     cout << "\nFile Explorer Menu:\n";
//     cout << "1. List Files\n";
//     cout << "2. Open File\n";
//     cout << "3. Exit\n";
//     cout << "Enter your choice: ";
// }

// int main() {
//     string currentPath = ".";
//     vector<string> files;
    
//     while (true) {
//         cout << "\nCurrent Path: " << currentPath << "\n";
//         DisplayMenu();
        
//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 ListFiles(currentPath);
//                 break;
            
//             case 2: {
//                 string fileName;
//                 cout << "Enter the name of the file to open: ";
//                 cin >> fileName;
//                 string filePath = currentPath + "/" + fileName;
                
//                 ifstream inFile(filePath);
//                 if (inFile.is_open()) {
//                     string line;
//                     cout << "\nFile Contents:\n";
//                     while (getline(inFile, line)) {
//                         cout << line << endl;
//                     }
//                     inFile.close();
//                 } else {
//                     cout << "\nError opening file.\n";
//                 }
                
//                 break;
//             }
            
//             case 3:
//                 cout << "Exiting...\n";
//                 return 0;
            
//             default:
//                 cout << "Invalid choice. Please select again.\n";
//                 break;
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <fstream>
#include <cstdlib> // For system command
using namespace std;

void ListFiles(const string& path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            cout << ent->d_name << endl;
        }
        closedir(dir);
    } else {
        perror("Error opening directory");
    }
}

void DisplayMenu() {
    cout << "\nFile Explorer Menu:\n";
    cout << "1. List Files\n";
    cout << "2. Open File\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    string currentPath = ".";
    vector<string> files;
    
    while (true) {
        cout << "\nCurrent Path: " << currentPath << "\n";
        DisplayMenu();
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                ListFiles(currentPath);
                break;
            
            case 2: {
                string fileName;
                cout << "Enter the name of the file to open: ";
                cin >> fileName;
                string filePath = currentPath + "/" + fileName;
                
                if (fileName.find(".mp4") != string::npos) {
                    // Open .mp4 file using FFmpeg or other multimedia libraries
                    // For example, you can use system command to open the file with default media player
                    string command = "xdg-open " + filePath; // Linux command
                    system(command.c_str());
                } else {
                    ifstream inFile(filePath);
                    if (inFile.is_open()) {
                        string line;
                        cout << "\nFile Contents:\n";
                        while (getline(inFile, line)) {
                            cout << line << endl;
                        }
                        inFile.close();
                    } else {
                        cout << "\nError opening file.\n";
                    }
                }
                
                break;
            }
            
            case 3:
                cout << "Exiting...\n";
                return 0;
            
            default:
                cout << "Invalid choice. Please select again.\n";
                break;
        }
    }

    return 0;
}
