#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>

using namespace std;

  const int SIZE = 100;

class Git{

	public:
		string input[SIZE];
		string word[SIZE];
		int i = 0;
		int hold[SIZE];
	Git(){

	}

	Git(string file){

		ifstream infile;
		infile.open(file);

		infile>>input[i];
		while(infile){
			i++;
			infile>>input[i];
		}
		sort();
	}

  	void sort(){
		for(int i = 0; i<SIZE-1; i++){
			for(int j = 0; j<(SIZE-1) - i - 1; j++){
				if(input[j] > input[j+1]){
					swap(input[j], input[j+1]);

				}
			}
		}
		place();
	}

	void place(){
		int x = 0, j = 0;
		for(int i = 0; i< 100; i++){
			if(input[i] != input[i+1]){
				if(input[i] != "     "){
					word[j] = input[i];
					hold[j] = x;
					j++;
				}
			x = 0;
			}
			x++;
		}

		display(j);
	}
	void display(int size){

		for(int i =1; i < size ; i++){
			cout<<word[i]<<":"<<setw(8 - word[i].length())
				<<setfill(' ')<<right<<hold[i]<<endl;
		}

	}
};




int main(){

	string file;
	cout<<"Enter the file name: ";
	cin>>file;
	Git s1(file);

	return 0;
}
