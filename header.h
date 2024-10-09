#include <iostream>
#include <fstream>
#include <filesystem> 
#include <string>
#include <sstream>
#include "rapidcsv.h"
using namespace std;

enum class CommandType {
    INSERT,
    DELETE,
    SELECT,
    UNKNOWN,
    EXIT
};

struct configjson {
    string name; 
    int tuples_limit; 
};
struct Node {
    string col;  // Имя колонки
    Node* next;  // Указатель на следующую колонку
};
struct TableNode {
    string tabl;  // Имя таблицы
    Node* columns;  // Указатель на первую колонку
    TableNode* next;  // Указатель на следующую таблицу
};
struct Nodeint{
    int pk;
    Nodeint* next;
};
struct Sel{
    string tab;
    string col;
    Nodeint* id;
    Sel* next;
};

void readFile(string &config);
TableNode* ParseJson(const string& config, configjson& schema);
CommandType getCommandType(const string& command);
void Insert(const string& command, TableNode* tables, const configjson &schema);
void Delete(const string& command, TableNode* tables, const configjson &schema);
void Select(string& command, TableNode* tables, configjson &schema);
