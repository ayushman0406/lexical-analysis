#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


struct Symbol {
    string name;
    string type;
    int size;
    int LOD;
};


int getSize(const string& type) {
    if (type == "int") return 4;
    else if (type == "char") return 2;
    else if (type == "long") return 8;
    return 0;  
}


vector<Symbol> createSymbolTable(const string& code) {
    vector<Symbol> symbolTable;
    istringstream stream(code);
    string line;
    int currentLOD = 0;  

    while (getline(stream, line)) {
        stringstream ss(line);
        string word;

        
        if (line.find('{') != string::npos) {
            currentLOD++;
            continue;
        } else if (line.find('}') != string::npos) {
            currentLOD--;
            continue;
        }

        
        size_t semicolonPos = line.find(';');
        if (semicolonPos != string::npos) {
            currentLOD++;
        }

        
        ss >> word;  
        if (word == "int" || word == "char" || word == "long") {  
            string varName;
            while (ss >> varName) {
                if (varName.find('=') != string::npos) {
                    varName = varName.substr(0, varName.find('='));  
                }
                if (varName.back() == ';' || varName.back() == ',') {
                    varName.pop_back();  
                }
                symbolTable.push_back({varName, word, getSize(word), currentLOD});
            }
        }
    }

    return symbolTable;
}


void displaySymbolTable(const vector<Symbol>& symbolTable) {
    cout << "Name\tType\tSize\tLOD" << endl;
    for (const auto& symbol : symbolTable) {
        cout << symbol.name << "\t" << symbol.type << "\t\t" << symbol.size << "\t\t" << symbol.LOD << endl;
    }
}

int main() {
    
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    
    string code((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    vector<Symbol> symbolTable = createSymbolTable(code);

    displaySymbolTable(symbolTable);

    return 0;
}
