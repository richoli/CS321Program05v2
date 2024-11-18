//
// Created by kaipo on 10/18/2024.
//

#include "Node.h"

Node::Node(string cityName, double lat, double lon) {
    this->stateName = cityName;
    this->lat = lat;
    this->lon = lon;
}


Node::Node() {
    stateName = "";
    lat = 0.0;
    lon = 0.0;
}

void Node::print() {
    cout << "State: " << stateName << endl;
    cout << "Latitude: " << lat << endl;
    cout << "Longitude: " << lon << endl;
}

void Node::addCityName(string cityName) {
    this->stateName = cityName;
}

void Node::addCoordinates(double lat, double lon) {
    this->lat = lat;
    this->lon = lon;
}

bool Node::operator>(Node & node) const{
    return lat > node.lat || lat == node.lat;
}
bool Node::operator<(Node & node) const{
    return lon > node.lon || lon == node.lon;
}


bool Node::operator==(Node & node) const{
    return lat == node.lat && lon == node.lon;
}

ostream& operator<<(std::ostream& os,const Node & node) {
    os << node.stateName;
    cout << " " << node.lat << " " << node.lon;
    cout << endl;
    return os;
}