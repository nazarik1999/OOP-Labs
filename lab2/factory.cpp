#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"
#include "factory.h"

using namespace std;


//������ ������ �� ����� ������ ���� ���� ��������-�����
void Factory::ListAllObjects()
{
int n=pObjects.size();// �������� ����� �������� � ���������

cout << endl << "������ ��������: "<<endl<<"+++++++++++++++++++++++++++"<< endl;
for(int i=0;i<n;i++)
{
	cout << pObjects[i]->GetName()<< endl;;
}
cout << "+++++++++++++++++++++++++++" << endl;
}

//������� ������ �� ������� �������� ������� �� ���������
void Factory::ShowObject(void )
{
  int item,n;
  
  n=pObjects.size();// �������� ����� �������� � ���������
  
   if(n==0)	
  {
  	cout <<"!!!!! � ��������� ��� ��������."<< endl;  	
  	return;
  	}
  
  cout <<"�������� ����� ������� ��� ������ ��������:"<< endl;
  
  for(int i=0;i<n;i++)
  {
  	cout << (i+1) <<":"<<pObjects[i]->GetName()<< endl;
  }
  
  item=SelectItem(n);// ����������� ����� ������� ��� ������ ��������� ��� ��������
  
  cout << "��������: ";
  // ��� ������ �������� �c���������� ����������� �������, ���������������� � ������ ������-�������
  pObjects[item-1]->Show();
 
}

// �������� ������� �� ���������
void Factory::DeleteObject(void)
{
	int item,n;
  
  n=pObjects.size(); // ����� �������� � ���������
  
  if(n==0)	
  {
  	cout <<"!!!!! � ��������� ��� ��������."<< endl;
   	return;
   }
  
  cout<<"------------------------------------"<<endl;
  cout <<"�� ������ ����� ���������� �������:"<<endl;
   for(int i=0;i<n;i++)
  {
  	cout << (i+1) <<":"<<pObjects[i]->GetName()<< endl;
  }
  
  
  
  	item=SelectItem(n);// ����������� ����� ������� ��� ��� �������� �� ���������
  	item--;
  	
  	string name=pObjects[item]->GetName();// �������� ��������� ��� ������� ��� ����������� � ��������� �� ��������
  	
	pObjects.erase(pObjects.begin() + item );//������� ������ �� ���������
	
    cout <<"������ < "<< name << " > ������  �� ���������. " << endl;
}

//������ ���������� ������ ������ � ���������
void Factory::AddObject(void )
{ 
 int item;
 StringObj *pNewObj; // ��������� �� ������ �������� ������������ ������
 
		string name,value;
		
		cout << "�������� ��� ������������ �������:"<< endl;
		cout << "1.���������� ������"<<endl;
		cout << "2.������������ ������"<<endl;
		item=SelectItem(2); // ������ ������ ������ ����
		
		// ������ ����� �������
		cout <<"������� ���:";
		cin>> name;
		cin.get();
		
		cout <<"������� ��������:";
		
		char buffer[MAX_STRING_LEN];
		// ������ �������� �������
		cin.getline(buffer,MAX_STRING_LEN);
		value=buffer; 
		
		switch(item)
		{
			case 1: pNewObj = new SymbString(name,value); //������� ���������� ������
					break;
			case 2: // ��������� �� ������������ �������� ������
					if( isOctString(value) == false)
					{cout <<endl<<"!!!!! ������������ ��������. ������ ���� ������ �����(0-7)."<< endl;
						return;
					}
					pNewObj= new OctString(name,value); //������� ���������� ������
					break;
		}// end switch
		
		
		pObjects.push_back(pNewObj);// �������� ������-������ � ���������
		cout <<"������ ������� �������� � ���������."<< endl;
}
	
void Factory::Operations()
{

  int item;
  char buffer[MAX_STRING_LEN];
  string value;
 
 cout << "�������� ��� ������������ ��������:" << endl;
 cout << "1.���������� ������" << endl;
 cout << "2.������������ ������" << endl;

 item = SelectItem(2); // ������ ������ ������ ����

 switch (item)
 {
 case 1:
		{	cout << "������� 1-� ��������:";
			// ������ �������� �������
			cin.getline(buffer, MAX_STRING_LEN);
			value = buffer;
			SymbString s1("", value);

			cout << "������� 2-� ��������:";
			// ������ �������� �������
			cin.getline(buffer, MAX_STRING_LEN);
			value = buffer;
			SymbString s2("", value);
			SymbString s3 = s1 + s2;
			cout << "��������� ��������: "; s3.Show();
			}break;

 case 2: {	cout << "������� 1-� ��������(������ ����� 0-7):";
	 // ������ �������� �������
	 cin.getline(buffer, MAX_STRING_LEN);
	 value = buffer;

	 if (isOctString(value) == false)
	 {  
		 cout << endl << "!!!!! ������������ ��������. ������ ���� ������ �����(0-7)." << endl;
		 return;
	 }
	 OctString os1("", value);

	 cout << "������� 2-� �������� (������ ����� 0-7):";
	 // ������ �������� �������
	 cin.getline(buffer, MAX_STRING_LEN);
	 value = buffer;
	 if (isOctString(value) == false)
	 {
		 cout << endl << "!!!!! ������������ ��������. ������ ���� ������ �����(0-7)." << endl;
		 return;
	 }

	 OctString os2("", value);
	 SymbString os3 = os1 + os2;
	 cout << "��������� ��������: "; os3.Show();
 }break;


 }

}

//������� ��������� ���� � ������� ������ ������������
// �� 1 �� n
int Factory::SelectItem(int n)
{
	int item;
	while( true ) // ����������� ���� ���� �� ������ ������ ��������
	{
		cin >> item;
		if( (item > 0 && item <= n  ) && (cin.peek()=='\n')) 
		{ cin.get();
		  break; // ����� �� �����
		}
		else
		{// ����� �������� ��������
		cout <<"��������� �����. ��������� ����.(�� 1 �� "<< n <<"):"<<endl;
		cin.clear();
		
		while( cin.get()!='\n'){	}; // ���� ������� ������� Enter
		
		}
	}
	return item;
}
