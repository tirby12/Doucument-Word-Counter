#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<math.h>

using namespace std;

const int nof = 10000;
const int wid = 10000;
int wordcount=0;
string wordlist[wid];
int vector[wid];

void checkfile(fstream &myfile)
{
	
	char filename[20];
	cout << "Please input the name of the file.\n";
	cin.getline(filename, 20);
	myfile.open(filename, ios::in | ios::out);
	if (myfile.is_open())
	{
		cout<<"File Opened\n";
	}
	else
	{
		cout << "Unable to open file\n";
	}
}

int input( ) 
{	
	ifstream myfile;
	char filename[20];
	
	cout << "\nPlease input the name of the file.\n";
	cin.getline(filename, 20);
	myfile.open(filename, ios::in);
	string word="";
	char ch;
	
	if (myfile.is_open())
	{
		while(!myfile.eof())
		{				
			word="";
			
			do
			{
				myfile.get(ch);
				if(!isalpha(ch))
					break;
				else
					word += ch;										
			}
			while(!myfile.eof());
		
			cout<<word;
			bool wordcheck=true;
			
			if(wordcount==0)
			{
				wordlist[wordcount]=word;
				vector[wordcount]=1;
				wordcount++;
			}
			
			else
			{
				for(int j=0; j<wordcount; j++)
				{	
					if(word==wordlist[j])
					{
						wordcheck=true;
						vector[j]=vector[j]+1;
						break;
					}
				
					else if(word!=wordlist[j])
					{
						wordcheck=false;
					}

				}
				
				if(wordcheck==false)
 				{
					wordlist[wordcount+1]=word;
					vector[wordcount+1]=1;
					wordcount++;
				
				}
			}
		}

		myfile.close();
	}		
	
	else 
	{
		cout << "Unable to open file\n";
	}
		
	return 0;
}


int output(ofstream &myfile)
{
	myfile.open("vectorfile.txt", ios::out);
	if (myfile.is_open())
	{
		for(int i=0; i<=wordcount; i++)
		{
			myfile <<wordlist[i]<< " is in this document "<<vector[i]<< "times\n";
		}
		
		myfile.close();
	}
	else 
		cout << "Unable to open file";
	return 0;
}

int main()
{
	ofstream fout;
	string files="yes";
	while(files=="yes")
	{
		cin.ignore();
		input();
		cout<<"\nAre there anymore files?\n";
		cin>>files;
	}

	output(fout);

	return 0;
}