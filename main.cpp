#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <typeinfo>
#include "genBST.h"
#include "Node.h"

using namespace std;
double distance ( double lat1, double lon1, double lat2,  double lon2)
{
    const double r = 3956;
    const double deg_to_radians = M_PI / 180;
    lat1 = lat1 * deg_to_radians;
    lat2 = lat2 * deg_to_radians;
    lon1 = lon1 * deg_to_radians;
    lon2 = lon2 * deg_to_radians;
    double d;
    d = r * acos(sin(lat1) * sin(lat2) + cos(lat1)* cos(lat2)*cos(lon1-lon2));
    return d;
}

/**
 * This option allows the user to directly compute the distances between two sets of coordinates
 */
void option_1 () {
    double lat1, lon1, lat2, lon2;
    cout << "Enter the coordinates of the first point:" << endl;
    cin >> lat1 >> lon1;
    cout << "Enter the coordinates of the second point:" << endl;
    cin >> lat2 >> lon2;
    cout << "Distance between points (" << lat1 << "," << lon1 << ") and ("<< lat2 << "," << lon2 << ") is " << distance(lat1, lon1, lat2, lon2) << endl;
}

/**
 * This option allows the user to directly enter a single set of coordinates, and return the nearest
 * city, with its distance from that location.
 */
void option_2 () {}

/**
 * Prompts the user to provide the name of the city and its coordinates (lat,lon).
 * Inserts city into the tree (if it isn't there already).
 * User has two options:
 *        -Find the nearest (other) city in the tree and report its distance from the given city.
 *        -Find and list the names and distances of all cities within a user-provided
 *         distance r in miles from the given city.
 */
void option_3 () {}

void read_file() {
    ifstream inputFile("states.txt");
    string line;
    while(getline(inputFile, line)) {
        if (line.find('#') == string::npos) {
            cout << line << endl;
        }

    };
}



struct State {
    std::string name;
    double latitude;
    double longitude;
};

//
// std::vector<State> readStates(const std::string& filename) {
//     std::vector<State> states;
//     std::ifstream file(filename);
//
//     if (!file.is_open()) {
//         std::cerr << "Could not open the file!" << std::endl;
//         return states;
//     }
//
//     std::string line;
//     while (std::getline(file, line)) {
//         if (line.find('#') == string::npos) {
//             std::stringstream ss(line);
//             std::string stateName;
//             double latitude, longitude;
//
//             // Read all parts of the state name until we get to the latitude and longitude
//             std::getline(ss, stateName, ','); // Assuming comma separates name from latitude/longitude
//
//             // Read latitude and longitude
//             ss >> latitude;
//             ss.ignore(1, ',');  // Ignore the comma after latitude
//             ss >> longitude;
//
//             states.push_back({stateName, latitude, longitude});
//         }
//     }
//
//     return states;
// }


void splitState(string line, string& stateName, double& lat, double& lon) {
    int position = 0;
    while (!std::isdigit(line[position])) {
        stateName += line[position];
        position++;
    }
    line.erase(0, position);
    while (line.find(' ')!= string::npos) {
        int p2 = line.find(' ');
        string latString = line.substr(0, p2);
        lat = stod(latString);
        line.erase(0, p2 + 1);
    }
    lon = stod(line);
};

int main() {
    // string line;
    // ifstream inputFile("states.txt");
    // while (getline(inputFile,line)) {
    //     if (line.find('#') == string::npos) {
    //         string stateName;
    //         double lat, lon;
    //         splitState(line, stateName, lat, lon);
    //         cout << "City Name: " << stateName << endl;
    //         cout << "Latitude: " << lat << endl;
    //         cout << "Longitude: " << lon << endl << endl;
    //     }
    //
    // }

    Node state1("Louisville", 38, 85);
    Node state2("Chicago", 41, 87);
    Node state3("Washington", 38, 77);
    Node state4("Nashville", 36, 87);
    Node state5("Atlanta", 34, 84);

    Node state6("Pittsburgh", 40, 79);
    Node state7("New York", 40, 74);
    Node state8("Cleveland", 41, 81);
    Node state9("Dayton", 39, 84);
    Node state10("Montreal", 45, 73);
    // Node state6("School", 34, 84);


    BST<Node> states;
    states.insert(state1);
    states.insert(state2);
    states.insert(state3);
    states.insert(state4);
    states.insert(state5);
    states.insert(state6);
    states.insert(state7);
    states.insert(state8);
    states.insert(state9);
    states.insert(state10);

    Node state11("montana",47,73);
    Node* search = states.search(state11);
    search->print();

    return 0;


    // bool state = true;
    // while (state) {
    //     int option;
    //     cout << "\n----------- [ Options ] ----------- \n(1) Calculate Distance between two cities.\n(4) Exit Program.\n-----------------------------------\nEnter the a number : ";
    //     cin >> option;
    //     switch (option) {
    //         case 1:
    //             option_1();
    //         break;
    //         case 2:
    //             option_2();
    //         break;
    //         case 3:
    //             option_3();
    //         break;
    //         case 4:
    //             state = false;
    //         default:
    //             cout << "\n\n\nInvalid option: Please try again." << endl;
    //         break;
    //     }
    // }
    //
    // return 0;
}

// ifstream inputFile("light_brigade.txt"); // Open the file
//
// if (!inputFile) { // Check if the file opened successfully
//     cerr << "Error opening file!" << endl;
//     return 1; // Exit with error code
// }
//
// string line; // line to be parsed.
// int lineNum = 0; // Marks line number
// BST<Node> wordTree;
// Node* match;
// while (getline(inputFile, line)) { // Read line by line
//     vector<string> tokens; //contains tokens
//     lineNum++;
//
//     //Ignores empty lines and comments.
//     if (line.find('#') == string::npos && !line.empty()) {
//
//         //converts all the words in a given line into lower case.
//         transform(line.begin(), line.end(), line.begin(), ::tolower);
//
//         //splits line.
//         splitLine(line, tokens, ' ');
//
//         //Adds each word found in the line to the tree.
//         for (auto i : tokens) {
//             Node node(i);
//
//             match = wordTree.search(node);
//
//             //Checks to see if there is already a duplicate of the Node in the tree.
//             if(match != nullptr) {
//
//                 //If so, it adds the found line number unto the set of line numbers in that given node.
//                 match->addLineNumber(lineNum);
//             }
//             else {
//
//                 //Otherwise it creates a new node(word) in the tree and adds the current line number to that node.
//                 node.addLineNumber(lineNum);
//                 wordTree.insert(node);
//             }
//         }
//     }
// }
