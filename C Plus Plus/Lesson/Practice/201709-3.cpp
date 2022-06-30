#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;


void format(string &s)
{
    for(int i=0;i<s.size();i++)
        if(s[i]=='\\')
        s.erase(s.begin()+i);

}
void deal(string &json,string &add)
{
    string key,value;
    for(int i=0;i!=json.size();i++)
    
      if (json[i] == '"'){
			int j = json.find(":", i + 1);
			key = json.substr(i + 1, j - i - 2);
			if (add == "")
				key = add + key;
			else
				key = add + "." + key;
 
			if (json[j + 1] == '"'){
				if (json.find(",", j + 1) != string::npos)
					i = json.find(",", j + 1);
				else
					i = json.size() - 1;
				value = json.substr(j + 2, i - j - 3);
				format(key);
				format(value);
			}

        
         else{
			
				int count = 1;
				i = j + 2; 
				while (count != 0){
					if (json[i] == '{')
						++count;
					else if (json[i] == '}')
						--count;
					++i;
				}
				value = json.substr(j + 1, i - j - 1);
			
				deal(value, key);
			}
			mp[key] = value;
		}

}

int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
int n = 0, m = 0;
	cin >> n >> m;
	string s, json;

	string::iterator it;
	getline(cin, s);
	for (int i = 0; i != n; ++i){
		getline(cin, s);
		for (it = s.begin(); it != s.end();)
			if (isspace(*it))
				it = s.erase(it);
			else
				++it;
		json += s;
	}

string add;
	deal(json, add);
	for (int i = 0; i != m; ++i){
		cin >> s;
		if (mp.find(s) != mp.end()){
			if (mp[s][0] == '{')
				cout << "OBJECT" << endl;
			else
				cout << "STRING " << mp[s] << endl;;
		}
		else
			cout << "NOTEXIST" << endl;
	}
}
