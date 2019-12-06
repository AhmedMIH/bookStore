#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;


class book
{
	public: char name[10];
		char auther[10];
		char RRn[5];
		char price[5];
		char year[5];
		char buffer[100];
};

fstream file;
book s;

void writerecord()
{
	file.open("BookStore.txt",ios::app);
	if(!file)
	{
		cout<<"cannot open the file in append mode";
		exit(1);
	}
	cout<<"\nenter the book name = ";
	cin>>s.name;
	cout<<"\nenter the auther = ";
	cin>>s.auther;
	cout<<"\nenter the RRN = ";
	cin>>s.RRn;
	cout<<"\nenter the price = ";
	cin>>s.price;
	cout<<"\nenter the year of publishe = ";
	cin>>s.year;


	strcpy(s.buffer,s.name);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.auther);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.RRn);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.price);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.year);

	strcat(s.buffer,"\n");
	file<<s.buffer;
	file.close();
}

void search()
{
	char enter[15];
	char extra[45];

	file.open("BookStore.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in read mode";
		exit(0);
	}
	int choice;
	cout << "\nenter number to select the way you need to search" << endl;
	cout << "0: Exit 1: RRN  2: Book_Name 3: Auther_Name" << endl;
	cin>>choice;

	while(!file.eof())
	{
		file.getline(s.name,10,'|');
		file.getline(s.auther,10,'|');
		file.getline(s.RRn,5,'|');
		file.getline(s.price,5,'|');
		file.getline(s.year,5,'\n');
		switch(choice){
        case 1:{
            cout << "enter RRN you need to search" << endl;
			cin >> enter;
			if(strcmp(s.RRn,enter)==0){
			cout<<"\nrecord found";
			cout<<"\nname\tAuhtor\tRRn\tPrice\tYear";

			cout<<"\n"<<s.name<<"\t"<<s.auther<<"\t";
			cout<<s.RRn<<"\t"<<s.price<<"\t"<<s.year;

			file.close();
			return;
			}
			break;
		}
		case 2:{
            cout << "enter BookName you need to search" << endl;
			cin >> enter;
			if(strcmp(s.name,enter)==0){
			cout<<"\nrecord found";
			cout<<"\nname\tAuhtor\tRRn\tPrice\tYear";

			cout<<"\n"<<s.name<<"\t"<<s.auther<<"\t";
			cout<<s.RRn<<"\t"<<s.price<<"\t"<<s.year;

			file.close();
			return;
			}
			break;
		}
		case 3:{
            cout << "enter Auther you need to search" << endl;
			cin >> enter;
			if(strcmp(s.auther,enter)==0){
			cout<<"\nrecord found";
			cout<<"\nname\tAuhtor\tRRn\tPrice\tYear";

			cout<<"\n"<<s.name<<"\t"<<s.auther<<"\t";
			cout<<s.RRn<<"\t"<<s.price<<"\t"<<s.year;

			file.close();
			return;
			}
			break;
		}
		}
	}
	cout<<"\nrecord not found";
	file.close();
	return;
}

void displayFile()
{
	int i;
	file.open("BookStore.txt",ios::in);

	if(!file)
	{
		cout<<"\ncannot open the file in read mode";
		exit(1);
	}

	i=0;
	printf("\n\nName\t\tAuther\t\tRRn\t\tPrice\t\tYear\n");


	while(!file.eof())
	{
		file.getline(s.name,15,'|');
		file.getline(s.auther,15,'|');
		file.getline(s.RRn,5,'|');
		file.getline(s.price,5,'|');
		file.getline(s.year,5,'\n');
		printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.name,s.auther,s.RRn,s.price,s.year);
		i++;
	}
	file.close();
}

void Delete(){
    book bt[100];
	int RRN;

	int counter = 0;

	file.open("BookStore.txt", ios::in);
	if (!file)
	{
		cout << "\nunable to open the file in input mode";

	}
	cout << "\nenter the RRN ";
	cin >> RRN;


	while (!file.eof())
	{

		file.getline(bt[counter].name, 10, '|');
		file.getline(bt[counter].auther, 10, '|');
		file.getline(bt[counter].RRn, 5, '|');
		file.getline(bt[counter].price, 5, '|');
		file.getline(bt[counter].year, 5, '\n');
		counter++;
	}
	file.close();
	file.open("BookStore.txt", ios::out);
	for (int j = 0; j < counter - 1; j++)
	{
		s = bt[j];

		if (atoi(s.RRn) == RRN)
		{
			continue;
		}


		strcpy(s.buffer,s.name);
        strcat(s.buffer,"|");
        strcat(s.buffer,s.auther);
        strcat(s.buffer,"|");
        strcat(s.buffer,s.RRn);
        strcat(s.buffer,"|");
        strcat(s.buffer,s.price);
        strcat(s.buffer,"|");
        strcat(s.buffer,s.year);
        strcat(s.buffer,"\n");
        file<<s.buffer;
	}
	file.close();
}
void modify()
{
	char RRN[10];

	int i;
	int j;
	book st[100];

	file.open("BookStore.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in input mode";
		exit(1);
	}
	cout<<"\nenter the RRN ";
	cin>>RRN;
	i=0;
	while(!file.eof())
	{
		file.getline(st[i].name,15,'|');
		file.getline(st[i].auther,15,'|');
		file.getline(st[i].RRn,5,'|');
		file.getline(st[i].price,5,'|');
		file.getline(st[i].year,5,'\n');
		i++;
	}
	i--;

	for(j=0;j<i;j++)
	{
		if(strcmp(RRN,st[j].RRn)==0)
		{
			cout<<"\nthe old values of the record with RRN"<<RRN<<"are";
			cout<<"\nname = "<<st[j].name;
			cout<<"\nAuther = "<<st[j].auther;
			cout<<"\nRRn = "<<st[j].RRn;
			cout<<"\nprice = "<<st[j].price;
			cout<<"\nYear = "<<st[j].year;

			cout<<"\nenter the book name = ";
            cin>>st[j].name;
            cout<<"\nenter the auther = ";
            cin>>st[j].auther;
            cout<<"\nenter the RRN = ";
            cin>>st[j].RRn;
            cout<<"\nenter the price = ";
            cin>>st[j].price;
            cout<<"\nenter the year of publishe = ";
            cin>>st[j].year;

			break;
		}
	}

	if(j==i)
	{
		cout<<"\nthe record with RRN " <<RRN<< "is not present ";
		return;
	}
	file.close();

	file.open("BookStore.txt",ios::out);
	if(!file)
	{
		cout<<"\nunable to open the file in output mode";
		return;
	}

	for(j=0;j<i;j++)
	{
		file<<st[j].name<<'|'<<st[j].auther<<'|'<<st[j].RRn
			<<'|'<<st[j].price<<'|'<<st[j].year<<'\n';
	}
	file.close();
}


int main()
{
	int choice;
	while(1)
	{
		cout<<"\n 0 : exit";
		cout<<"\n 1 : write to file";
		cout<<"\n 2 : display the file";
		cout<<"\n 3 : modify the file";
		cout<<"\n 4 : search";
		cout<<"\n 5 : Delete";
		cout<<"\n\n enter the choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1: writerecord();
				break;

			case 2: displayFile();
				break;

			case 3: modify();
				break;

			case 4: search();
				break;
            case 5:
                Delete();
                break;
			case 0: exit(0);

			default: cout<<"\ninvalid input...";
				break;
		}
	}
}
