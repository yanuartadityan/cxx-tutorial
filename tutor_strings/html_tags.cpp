//
// Created by Yanuar Nugraha on 28/10/19.
// Hackerrank problem: http://bit.ly/2q3hTow
//

#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;

void htmlTags() {

    // tags input
    int lenTags, lenQueries;
    cin >> lenTags >> lenQueries;
    cin.ignore();

    map<string, string> attributes;
    string inputStr, tag_preamble = "";

    for (int i = 0; i < lenTags; i++) {
        getline(cin, inputStr);

        // split inputStr into tokens
        stringstream ss(inputStr);
        string word, attr, val;
        size_t pos;

        while(getline(ss, word, ' ')){
            // catch the open tag
            if (word[0] == '<'){
                string tag;
                // catch the closing tag
                if (word[1] == '/'){
                    tag = word.substr(2);
                    tag = tag.substr(0, tag.length() - 1);

                    // see if the preamble exists
                    pos = tag_preamble.find("." + tag);
                    if (pos == string::npos){
                        tag_preamble = "";
                    } else{
                        tag_preamble = tag_preamble.substr(0, pos);
                    }

                } else {
                    // it's a tag opening
                    tag = word.substr(1);

                    // add to preamble
                    if (tag_preamble == ""){
                        tag_preamble = tag;
                    } else{
                        tag_preamble = tag_preamble + "." + tag;
                    }
                }
            }

            // if attribute is detected
            else if (word[0] != '=' and word[0] != '"') {
                attr = tag_preamble + '~' + word;
            }

            // if value is detected
            else if (word[0] == '"'){
                pos = word.find_last_of('"');
                val = word.substr(1, pos-1);
                // update the database
                attributes.insert({attr, val});
            }
        }
    }

    for (auto& t : attributes){
        cout << t.first << " = " << t.second << endl;
    }

    // query
    for (int i=0; i<lenQueries; i++) {
        getline(cin, inputStr);
        if (attributes.find(inputStr) == attributes.end())
            cout << "Not Found!" << endl;
        else
            cout << attributes[inputStr] << endl;
    }
}