#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Table {
public:
    Table(int columns_) {
        coloumns = columns_;
    }

    int coloumns;
    vector<vector<string>> data;
};

class SQL {
    unordered_map<string, Table *> db;
public:
    SQL(vector<string> &names, vector<int> &columns) {
        int n = names.size();
        for (int i = 0; i < n; i++) {
            db[names[i]] = new Table(columns[i]);
        }
    }

    void insertRow(string name, vector<string> row) {
        db[name]->data.push_back(row);
    }

    void deleteRow(string name, int rowId) {
        db[name]->data[rowId - 1].clear();
    }

    string selectCell(string name, int rowId, int columnId) {
        auto iter = db.find(name);
        if (iter == db.end()) {
            return "";
        }
        if (rowId > iter->second->data.size()) {
            return "";
        }
        vector<string> &row = db[name]->data[rowId - 1];
        if (row.size() < columnId) {
            return "";
        }
        return row[columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */