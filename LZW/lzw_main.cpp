#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class LZW_CD{
	public:
		vector<int> encoder(string text){
			int dictSize = 256;
			string str;
			unordered_map<string , int> dictionary;
			for(int i = 0 ; i < dictSize; i++){
				str +=  (char) i;
				dictionary.insert({str,i});
				str = "";
			}

			str = "";
			vector<int> output ;

			for(char character : text ){
				string srchStr = str + character;
				if(dictionary.count(srchStr)){
					str = srchStr;
				}
				else{
					output.insert(output.end(),dictionary[str]);
					dictionary.insert({srchStr,dictSize++});
					str = character;
				}	
			}
			if(!str.empty()){
				output.insert(output.end(),dictionary[str]);
			}

			return output;

		}

		string decoder(vector<int> output){
			int dictSize = 256;
			string str;
			unordered_map<int, string > dictionary;
			for(int i = 0 ; i < dictSize; i++){
				str += (char) i;
				dictionary.insert({i,str});
				str  = "";
			}

			str = "";
			string characters ;
			characters += (char) output.at(0);
			output.erase(output.begin());
			string finalStr;
			finalStr += characters;

			for(int code : output ){
				string strValue = dictionary.count(code) ? dictionary[code] : characters + characters[0];
				finalStr += strValue;
				dictionary.insert({dictSize++,characters + strValue[0]});
				characters = strValue;
			}
			return finalStr;	
		}
};

int main(){
	LZW_CD compressor;
	string str1 = "Amaan Nayeem Jamdar";
	vector<int> output = compressor.encoder(str1);
	string str2 = compressor.decoder(output);
	cout << str1<<"\n";
	cout << str2;
		return 0;
}

