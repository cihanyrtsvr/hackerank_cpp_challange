#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    
    int N, Q;
    cin >> N >> Q;
    cin.ignore();  // Ignore the newline after reading N and Q

    unordered_map<string, unordered_map<string, string>> tag_attributes; // Main hashmap to store tags and their attributes
    vector<string> tag_stack; // Stack to track the current tag hierarchy

    // Reading HRML lines
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            // Closing tag, remove the last tag from the stack
            tag_stack.pop_back();
        } else {
            // Opening tag or tag with attributes
            stringstream ss(line);
            string tag, attr, value, temp;
            char ch;

            ss >> ch >> tag;  // Read <tag_name (ch is '<')

            // Remove '>' if present at the end of the tag name
            if (tag.back() == '>') {
                tag.pop_back();
            }

            // Update the current tag path
            if (!tag_stack.empty()) {
                tag_stack.push_back(tag_stack.back() + "." + tag);
            } else {
                tag_stack.push_back(tag);
            }

            // Full path to the current tag
            string current_tag_path = tag_stack.back();

            // Extract attributes and store them
            unordered_map<string, string> attributes;
            while (ss >> attr) {
                ss >> temp; // Skip '='
                ss >> value;

                // Remove the quotes around the attribute value
                value = value.substr(1, value.size() - 3);

                // Store the attribute in the hashmap
                tag_attributes[current_tag_path][attr] = value;
            }
        }
    }

    // Processing queries
    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);

        // Split query into tag path and attribute
        size_t pos = query.find('~');
        string tag_path = query.substr(0, pos);
        string attribute = query.substr(pos + 1);

        // Check if the tag path and attribute exist
        if (tag_attributes.find(tag_path) != tag_attributes.end() &&
            tag_attributes[tag_path].find(attribute) != tag_attributes[tag_path].end()) {
            cout << tag_attributes[tag_path][attribute] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
