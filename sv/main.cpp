#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;
struct student{
	int id;
	string name;
	float score;
};
student input();
bool Checkid( student st ,vector<student> listsv);
bool checkscore(student st) ;
void output(vector<student>listsv);
void save(vector<student>listsv);
int key;

int main() {
	vector<student> listsv;
	
	
	do{
		cout<<"...............MENU.................\n";
		cout<<".  1. Input                        .\n";
		cout<<".  2. Display                      .\n";
		cout<<".  3. Save to file                 .\n";
		cout<<".  4. Load from file               .\n";
		cout<<".  0. Exit                         .\n";
		cout<<"....................................\n";
		cout<<" nhap lua chon";
		cin>>key;
		switch(key){		
			case 1:
			{
				student st;
				st= input();
				cout<<st.id<<st.name<<st.score;
				if(Checkid(st,listsv)&&checkscore(st)){
					listsv.push_back(st);
				}
				else{cout<<" loi id(trung khop) hoac diem(0-10) ";
				} 
			break;	
			}
				
			case 2:
			{
				cout<<"ID        NAME        SCORE"<<endl;
				output(listsv);
				break;
			}
			case 3:
			{
				save(listsv);
			}
			case 4:
			{
				ifstream fi;
				fi.open("data.txt");
				fi.close();
				break;
			}
			case 0:
			{
				exit(0);
				break;
			}
			default:
			{
				cout<<"nhap lai!"<<endl;
				break;
			}
		}
	cout<<endl;
	}while(key != 0);
}

bool Checkid(student st, vector<student> listsv){
	int sz=listsv.size();
	for(int i= 0;i<sz ; i++) {
		if(st.id == listsv[i].id) {
			return false;
		}
	}
	return true;
}
bool checkscore(student st){
		if(st.score<0||st.score>10){
			return false;
		}else return true;
}
student input(){
	student st;
    cout<<"nhap ma st:";
    cin>>st.id;
    cout<<"nhap ten: ";
    cin>>st.name;
    cout<<"nhap diem tb:";
    cin>>st.score;
    return st;
}
void output(vector<student>listsv){
	int sz=listsv.size();
	for(int i= 0;i<sz ; i++) {
		cout<<listsv[i].id<<"        "<<listsv[i].name<<"        "<<listsv[i].score<<endl;
	}
}
void save(vector<student>listsv){
	ofstream fo;
	int sz = listsv.size();
	fo.open("data.txt");
	for(int i=0; i<sz; i++) {
		fo<<listsv[i].id<<endl;
		fo<<listsv[i].name<<endl;
		fo<<listsv[i].score;
		if(i != sz-1) {
			fo<<endl;	
		}
	}
	fo.close();
}
