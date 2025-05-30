#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <climits>
#include <set>

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

//this is the area where the Dijkstra is implmented. Big help from wikipeida sudocode to understand it lol
class GraphWithDijkstra : public Graph {
public:
    void dijkstra(const string& start, const string& end) {
        if (!adjTable.count(start) || !adjTable.count(end)) {
            cout << "One or both vertices do not exist.\n";
            return;
        }

        unordered_map<string, int> distance;
        unordered_map<string, string> previous;
        for (auto& pair : adjTable) {
            distance[pair.first] = INT_MAX;
        }
        distance[start] = 0;

        
        set<pair<int, string>> pq;
        pq.insert({0, start});
        while (!pq.empty()) {
            auto [dist, current] = *pq.begin();
            pq.erase(pq.begin());
            if (current == end) break;
            for (auto& [neighbor, weight] : adjTable[current]) {
                int newDist = dist + weight;

                if (newDist < distance[neighbor]) {
                    pq.erase({distance[neighbor], neighbor});
                    distance[neighbor] = newDist;
                    previous[neighbor] = current;
                    pq.insert({newDist, neighbor});
                }
            }
        }
        if (distance[end] == INT_MAX) {
            cout << "No path exists.\n";
            return;
        }
        vector<string> path;
        for (string at = end; !at.empty(); at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        cout << "Shortest path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << " (Total weight: " << distance[end] << ")\n";
    }
};

//start of the program
int main() {
    GraphWithDijkstra graph;
    string choice;
//the menue
    while (true) {
        cout << "\nPlease make a selection:\n";
        cout << "1. Add vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. remove vertex\n";
        cout << "4. Remove Edge\n";
        cout << "5. Print Adjacency Table\n";
        cout << "6. Find Shortest Path (Dijkstra)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1") {
            string label;
            cout << "Enter vertex label: ";
            cin >> label;
            graph.addVertex(label);
        } else if (choice == "2") {
            string from, to;
            int weight;
            cout << "From vertex: ";
            cin >> from;
            cout << "To vertex: ";
            cin >> to;
            cout << "Weight: ";
            cin >> weight;
            graph.addEdge(from, to, weight);
        } else if (choice == "3") {
            string label;
            cout << "Enter vertex to remove: ";
            cin >> label;
            graph.removeVertex(label);
        } else if (choice == "4") {
            string from, to;
            cout << "From vertex: ";
            cin >> from;
            cout << "To vertex: ";
            cin >> to;
            graph.removeEdge(from, to);
        } else if (choice == "5") {
            graph.printAdjTable();
        } else if (choice == "6") {
            string start, end;
            cout << "Start vertex: ";
            cin >> start;
            cout << "End vertex: ";
            cin >> end;
            graph.dijkstra(start, end);
        } else if (choice == "7") {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

