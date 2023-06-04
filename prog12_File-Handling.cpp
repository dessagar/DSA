#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

struct student
{
	int roll;
	char name[20];
};


class database
{
	struct student st;
	public:
		void insert_data();
		void read_data();
		void search_data();
		void update_data();
		void delete_data();
		void sort_data();
};
void database::sort_data()
{
	ifstream file;
	ofstream out;
	struct student st[50],temp;
	int i=0,n,j;

	file.open("database.txt",ios::binary|ios::in);
	file.read((char*)&st[i],sizeof(st[i])); 		//Important

	while(!file.eof())
	{
		i++;
		file.read((char*)&st[i],sizeof(st[i]));
	}
	file.close();

	n=i; //total no of records are taken into var n

	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(st[i].roll>st[j].roll)
			{
				temp=st[i];
				st[i]=st[j];
				st[j]=temp;
			}
		}
	}
	out.open("database.txt",ios::binary|ios::trunc|ios::out);
	for(i=0;i<n;i++)
	{
		out.write((char*)&st[i],sizeof(struct student));
	}
	out.close();

}

void database::read_data()
{
	struct student st;
	ifstream file;

	file.open("database.txt",ios::binary|ios::in);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		cout<<"\n"<<st.roll<<"\t"<<st.name;
		file.read((char*)&st,sizeof(st));
	}

	cout<<"\n";

	file.close();
}

void database::update_data()
{
	struct student st;
	int roll_number,flag=0,flag1=0;
	ifstream file;
	ofstream ofile;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);
	ofile.open("db1.txt",ios::binary|ios::out|ios::trunc);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			cout<<"\nEnter new name of the student";
			cin>>st.name;
			ofile.write((char*)&st,sizeof(st));
			flag=1;flag1=1;
		}
		if(flag==0)
		{
			ofile.write((char*)&st,sizeof(st));
		}
		flag=0; //reset for next iteration
		
		file.read((char*)&st,sizeof(st));
	}
	if(flag1==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}
	cout<<"\n";
	remove("database.txt");
	rename("db1.txt","database.txt");

	file.close();
}

void database::delete_data()
{
	struct student st;
	int roll_number,flag=0,flag1=0;
	ifstream file;
	ofstream ofile;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);
	ofile.open("db1.txt",ios::binary|ios::out|ios::trunc);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			flag=1;
			flag1=1;
		}
		if(flag==0)
		{
			ofile.write((char*)&st,sizeof(st));
		}
		flag=0;
		file.read((char*)&st,sizeof(st));
	}
	if(flag1==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}
	cout<<"\n";
	remove("database.txt");
	rename("db1.txt","database.txt");

	file.close();
}

void database::search_data()
{
	struct student st;
	int roll_number,flag=0;
	ifstream file;

	cout<<"\nEnter the roll no. of the record that you want to search :";
	cin>>roll_number;

	file.open("database.txt",ios::binary|ios::in);

	file.read((char*)&st,sizeof(st)); 		//Important

	while(!file.eof())
	{
		if(roll_number==st.roll)
		{
			cout<<"\nRECORD FOUND!!!";
			cout<<"\n"<<st.roll<<"\t"<<st.name;
			flag=1;
			break;
		}
		file.read((char*)&st,sizeof(st));
	}
	if(flag==0)
	{
		cout<<"\nRECORD NOT FOUND!!!\n";
	}

	cout<<"\n";

	file.close();
}



void database::insert_data()
{
	ofstream file;

	file.open("database.txt",ios::binary|ios::out|ios::app);

	cout<<"Enter the roll number and name of the student : ";
	cin>>st.roll>>st.name;


	file.write((char*)&st,sizeof(struct student));
	file.close();
}

int main()
{
	database obj;
	int choice;
	while(1)
	{
		cout<<"\n1.Insert Record";
		cout<<"\n2.Search Record";
		cout<<"\n3.Update Record";
		cout<<"\n4.Delete Record";
		cout<<"\n5.Sort Records";
		cout<<"\n6.Display Records";
		cout<<"\n7.Quit";
		cout<<"\nEnter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.insert_data();
				break;
			case 2:
				obj.search_data();
				break;
			case 3:
				obj.update_data();
				break;
			case 4:
				obj.delete_data();
				break;
			case 5:
				obj.sort_data();
				break;
			case 6:
				obj.read_data();
				break;
			case 7:
				return 0;
		};
	}
}


// sorting:
// =====================
// The function starts by declaring necessary variables, including an array of student structures (st[50]), a temporary structure (temp), and variables for iteration (i, j).
// It opens the file "database.txt" in binary input mode (ios::binary|ios::in) using an input file stream (ifstream).
// It reads the first record from the file using file.read() and stores it in st[i]. The size of the structure (sizeof(st[i])) is used as the read length.
// A while loop is used to read the remaining records from the file. Inside the loop, i is incremented, and the next record is read and stored in st[i]. This loop continues until the end of the file (!file.eof()).
// Once all records are read, the file is closed (file.close()), and the total number of records (n) is determined based on the value of i.
// The sorting process begins using nested for loops. The outer loop iterates from 0 to n, and the inner loop iterates from i+1 to n.
// Inside the inner loop, an if condition checks if the roll value of st[i] is greater than the roll value of st[j]. If true, it means the records are out of order, so a swap operation is performed using the temporary structure temp. This swapping ensures that the records are sorted in ascending order based on the roll field.
// After the sorting is completed, an output file stream (ofstream) named out is opened in binary output mode (ios::binary|ios::trunc|ios::out).
// The sorted records are written back to the file using a for loop. Each record (st[i]) is written to the file using out.write(), with the size of the student structure (sizeof(struct student)) as the write length.
// Finally, the output file is closed (out.close()), and the sorting process is complete.


// file.read((char*)&st,sizeof(st));
// file.read((char*)&st,sizeof(st));


// update:
// The function starts by declaring necessary variables, including a student structure (st), the roll number to search (roll_number), and flags (flag and flag1) to track the search and update status.
// It opens the file "database.txt" in binary input mode (ios::binary|ios::in) using an input file stream (ifstream), and opens a new file "db1.txt" in binary output mode (ios::binary|ios::out|ios::trunc) using an output file stream (ofstream).
// The user is prompted to enter the roll number of the record they want to search and update.
// The first record from the file is read using file.read() and stored in st. The size of the structure (sizeof(st)) is used as the read length.
// A while loop is used to iterate through the file until the end is reached (!file.eof()). Inside the loop, the following actions take place:
// a. If the roll number of the current record (st.roll) matches the provided roll number, it means the record is found. The user is notified, and they are prompted to enter a new name for the student.
// b. The updated record (st) is written to the new file (ofile.write()), effectively updating the record with the new name. The flag and flag1 variables are set to 1 to indicate that a record was found and updated.
// c. If the current record does not match the provided roll number, it is written to the new file as it is
// d. The flag variable is reset to 0 for the next iteration.
// e. The next record is read from the file using file.read().
// If flag1 is still 0 after iterating through all records, it means that the provided roll number was not found in the file. The user is notified that the record was not found.
// The original "database.txt" file is removed using remove(), and the new file "db1.txt" is renamed to "database.txt" using rename(). This effectively replaces the original file with the updated records.
// Finally, the file streams are closed (file.close() and ofile.close()).



