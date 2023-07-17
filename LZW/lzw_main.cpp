#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


vector<int> encoder(string text){
	int dictSize = 256;
	string str;
	unordered_map<string , int> dictionary;
	for(int i = 0 ; i < dictSize; i++){
		str += (char) i;
		dictionary.insert({str,i});
		str  = "";
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



int main(){
	string str1 = "WYS*WYGWYS*WYSWYSG";
	vector<int> output = encoder(str1);
	for(int j : output){
		cout << j <<'\n';
	}
	return 0;
}

