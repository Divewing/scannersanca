#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <fstream>


using namespace std;

struct node{
	int id;
	string data;
	node *next;
};
node *awl_smpl_alp = NULL;
node *awl_smpl_dgt = NULL;
node *awl_smpl_sym = NULL;

void inpt_list_alp(int c,string data){
	node *temp, *temp2;
	temp = new node;
	temp->id = c;
	temp->data = data;
	temp->next = NULL;
	if (awl_smpl_alp == NULL)
		awl_smpl_alp = temp;
	else{
		temp2 = awl_smpl_alp;
	while (temp2->next != NULL)
		temp2 = temp2->next;
		temp2->next = temp;
	}
} 

void inpt_list_dgt(int c,string data){
	node *temp, *temp2;
	temp = new node;
	temp->id = c;
	temp->data = data;
	temp->next = NULL;
	if (awl_smpl_dgt == NULL)
		awl_smpl_dgt = temp;
	else{
		temp2 = awl_smpl_dgt;
	while (temp2->next != NULL)
		temp2 = temp2->next;
		temp2->next = temp;
	}
} 

void inpt_list_sym(int c,string data){
	node *temp, *temp2;
	temp = new node;
	temp->id = c;
	temp->data = data;
	temp->next = NULL;
	if (awl_smpl_sym == NULL)
		awl_smpl_sym = temp;
	else{
		temp2 = awl_smpl_sym;
	while (temp2->next != NULL)
		temp2 = temp2->next;
		temp2->next = temp;
	}
} 

void tampil_list(){
	node *bantu;
	cout << "Data Alpha"<<endl;
	if (awl_smpl_alp == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_alp;
		do{
			cout << bantu->id << " ";
			cout << bantu->data<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	cout << "Data Digit" << endl;
	if (awl_smpl_dgt == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_dgt;
		do{
			cout << bantu->id << " ";
			cout << bantu->data<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	cout << "Data Symbol" << endl;
	if (awl_smpl_sym == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_sym;
		do{
			cout << bantu->id << " ";
			cout << bantu->data<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}

	
} 

void hapus(){
	node *bantu;
	if(awl_smpl_alp->next == NULL){
		delete awl_smpl_alp;
	}else{
		do{
			bantu = awl_smpl_alp;
			awl_smpl_alp = awl_smpl_alp->next;
			delete bantu;
		}while(awl_smpl_alp !=NULL);
	}
	
	if(awl_smpl_dgt->next == NULL){
		delete awl_smpl_dgt;
	}else{
		do{
			bantu = awl_smpl_dgt;
			awl_smpl_dgt = awl_smpl_dgt->next;
			delete bantu;
		}while(awl_smpl_dgt !=NULL);
	}

	if(awl_smpl_sym->next == NULL){
		delete awl_smpl_dgt;
	}else{
		do{
			bantu = awl_smpl_sym;
			awl_smpl_sym = awl_smpl_sym->next;
			delete bantu;
		}while(awl_smpl_sym !=NULL);
	}
	
	
} 



int main(int argc, char* argv[]) {
char kar,h_kar;
char namafile[41];
int c=0;
string teks;
string digit;
strcpy(namafile,argv[1]);
ifstream file(namafile);
if(file.is_open()){
	while(true!=(file.eof())){

		file >> noskipws >> kar;
	
		if(isalpha(kar)){
				do{
					teks += kar;
					file >> noskipws >> kar;
				}while(isalnum(kar));
			c = c+1;
			inpt_list_alp(c,teks);
			teks = '\0';
		}

		if(isdigit(kar)){
				do{
					digit += kar;
					file >> noskipws >> kar;
				}while((isdigit(kar))||(kar=='.'));
			c = c+1;
			inpt_list_dgt(c,digit);
			digit = '\0';
			
		}

		if(kar == '"'){
			do{
				teks += kar;
				file >> noskipws >> kar;
			}while(kar !='"');
			c = c+1;
			
			teks += kar;
			inpt_list_sym(c,teks);
			teks = '\0';
		}

 		if(kar =='#'){
			while(kar!='\n'){
				file >> noskipws >> kar;
			}
		}
		
		if(	(kar==';')||
		   	(kar==':')||
			(kar=='(')||
			(kar==')')||
			(kar=='+')||
			(kar=='-')||
			(kar=='/')||
			(kar=='\\')||
			(kar=='%')||
			(kar=='>')||
			(kar=='<')||
			(kar=='=')||
			(kar=='*')||
			(kar=='.')||
			(kar==',')||
			(kar=='{')||
			(kar=='}')||
			(kar=='[')||
			(kar==']')||
			(kar=='!')
		  ){
			c = c+1;
			teks = kar;
			inpt_list_sym(c,teks);
			teks='\0';
		}

	
		
		
	}
  file.close();
}
tampil_list();
hapus();
	return 0;
}



