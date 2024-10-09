#include "header.h"
#include "rapidcsv.h"
using namespace std;
int main() {
    string config;
    readFile(config);
    configjson schema;
    TableNode* tables = ParseJson(config, schema);
    cout << schema.name << ' ' << schema.tuples_limit << endl;
    while (true){
        cout << "command >>  \n";
        string filePath = "/home/andrey/Documents/coding/project1/" + schema.name;
        filesystem::current_path(filePath);
        string command;
        getline(cin, command); 
        CommandType commandType = getCommandType(command);
        switch (commandType) {
            case CommandType::INSERT:
                Insert(command, tables, schema);
                break;
            case CommandType::DELETE:
                Delete(command, tables, schema);
                break;
            case CommandType::SELECT:
                Select(command, tables, schema);
                break;
            case CommandType::EXIT:
                cout << "Exiting..." << endl;
                return 0;
            case CommandType::UNKNOWN:
            default:
                cout << "Unknown command!" << endl;
                break;
        }
    }
    return 0;
}