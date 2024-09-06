#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    unordered_map<string, unordered_map<string, string>> tag_list;
    vector<string> current_tag;

    string line;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        
        stringstream ss(line);
        string tag, attr, value;

        ss >> tag;  // Read '<' and the tag name
        tag = tag.substr(1);
        cout <<"Tag: "<< tag << endl;

        // Skip the rest of the line
        
    }

    // ... rest of your code ...

    return 0;
}