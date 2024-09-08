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

    string line, query;

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        
        if(line.substr(0,2)=="</"){
            current_tag.pop_back();
        }
        else{

            stringstream ss(line);
            string tag, attr, value, pass, current_tag_path;

            ss >> tag;  // Read '<' and the tag name
            tag = tag.substr(1);

            if(current_tag.empty()){
                current_tag.emplace_back(tag);
            }
            else{
                current_tag.emplace_back(current_tag.back() + "."+tag);
            }

            while(ss>>attr){
                ss>>pass;
                ss>>value;

                value = value.substr(1,value.size()-3);
                current_tag_path = current_tag.back();
                tag_list[current_tag_path][attr] = value;
            }
            // Skip the rest of the line
            
                
        }
    }

    for(int j=0 ; j<Q; j++){
        getline(cin,query);
        int pose = query.find("~");
        string tag_head = query.substr(0,pose);
        string value_part = query.substr(pose+1);

        if(tag_list.find(tag_head)== tag_list.end() ||
        tag_list[tag_head].find(value_part) == tag_list[tag_head].end()){
            cout<<"Not Found!"<<endl;
        }
        else{
            cout<<tag_list[tag_head][value_part]<<endl;
        }
    }

    return 0;
}