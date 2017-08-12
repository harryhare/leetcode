/*588*/
#include<string>
#include<map>
#include<vector>
using namespace std;
class FileSystem {
public:
	map<string,string> files;
	map<string,FileSystem*> folders;
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        if(path=="/" || path=="")
		{
			vector<string> ans;
			auto i1=files.begin();
			auto i2=folders.begin();
			while(i1!=files.end() &&i2!=folders.end())
			{
				if(i1->first<i2->first)
				{
					ans.push_back(i1->first);
					i1++;
				}
				else
				{
					ans.push_back(i2->first);
					i2++;
				}
			}
			while(i1!=files.end())
			{
				ans.push_back(i1->first);
				i1++;
			}
			while(i2!=folders.end())
			{
				ans.push_back(i2->first);
				i2++;
			}
			return ans;
		}
		int i=1;
		for(i=1;path[i]!=0&&path[i]!='/';i++);
		string name=path.substr(1,i-1);
		//return folders[name]->ls(path.substr(i));
		auto iter=folders.find(name);
		if(iter!=folders.end())
		{
			return iter->second->ls(path.substr(i));
		}
		else
		{
			auto iter2=files.find(name);
			assert(iter2!=files.end());
			vector<string> ans;
			ans.push_back(name);
			return ans;
		}
    }
    
    void mkdir(string path) {
        if(path=="/" || path=="")
		{
			return;
		}
		int i=1;
		for(i=1;path[i]!=0&&path[i]!='/';i++);
		string name=path.substr(1,i-1);
		if(folders.find(name)==folders.end())
		{
			folders[name]=new FileSystem();
		}
		return folders[name]->mkdir(path.substr(i));
    }
    
    void addContentToFile(string filePath, string content) {
		int i=1;
		for(i=1;filePath[i]!=0&&filePath[i]!='/';i++);
		string name=filePath.substr(1,i-1);
		if(filePath[i]!=0)
		{
			folders[name]->addContentToFile(filePath.substr(i),content);
			return;
		}
		else
		{
			auto iter=files.find(name);
			if(iter==files.end())
			{
				files[name]=content;
			}
			else
			{
				files[name].append(content);
			}
		}
    }
    
    string readContentFromFile(string filePath) {
        int i=1;
		for(i=1;filePath[i]!=0&&filePath[i]!='/';i++);
		string name=filePath.substr(1,i-1);
		if(filePath[i]!=0)
		{
			return folders[name]->readContentFromFile(filePath.substr(i));
		}
		else
		{
			return files[name];
		}
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */