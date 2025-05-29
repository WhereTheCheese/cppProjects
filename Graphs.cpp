#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Graph {
protected:
    unordered_map<string, unordered_map<string, int>> adjTable;

public:
//Add a vertex
    void addVertex(const string& label) {
        if (adjTable.find(label) == adjTable.end()) {
            adjTable[label] = {};
        } else {
            cout << "Vertex '" << label << "' already exists." << endl;
        }
    }
//Remove vetex
    void removeVertex(const string& label) {
        if (adjTable.erase(label)) {
            for (auto& pair : adjTable) {
                pair.second.erase(label);
            }
        } else {
            cout << "Vertex '" << label << "' does not exist :(" << endl;
        }
    }
//Add an edge 
    void addEdge(const string& from, const string& to, int weight) {
        if (adjTable.count(from) && adjTable.count(to)) {
            adjTable[from][to] = weight;
        } else {
            cout << "One or both of the vertexes mentied do not exist" << endl;
        }
    }
//Renmove an edge
    void removeEdge(const string& from, const string& to) {
        if (adjTable.count(from)) {
            adjTable[from].erase(to);
        } else {
            cout << "Vertex '" << from << "' does not exist.\n";
        }
    }
//pritns a table
    void printAdjTable() {
        cout << "\nAdjacency Table:\n";
        for (auto& [vertex, neighbors] : adjTable) {
            cout << vertex << ": ";
            for (auto& [neighbor, weight] : neighbors) {
                cout << "(" << neighbor << ", " << weight << ") ";
            }
            cout << endl;
        }
    }
};

