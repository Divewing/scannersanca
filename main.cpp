#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

struct node{
	int id;
	string data;
	string token;
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

void alp_konver(){
	node *bantu;
	int c;
	bool ketemu;
	string keyword[17] ={"var","mulai","selesai","int","string","program"
			   			,"float","tulis","baca ","jika","maka","atau"
			   			,"ketika","lakukan","untuk","sampai"}; 
	if (awl_smpl_alp == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_alp;
		do{
		c =0;
		ketemu = false;
		while(c!=16){
			if(keyword[c]==bantu->data){
				bantu->token = "T_" + keyword[c];
				ketemu = true;
				c = 15;
			}
			c++;
		}
		if(ketemu==false){
			bantu->token = "T_ident";
		}
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	
} 

void dgt_konver(){
	node *bantu;
	int k,g;
	bool ketemu;

	if (awl_smpl_dgt == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_dgt;
		do{
			g = 0;
			ketemu = false;
			k =bantu->data.length();
			while(g!=k){
				if(bantu->data[g]=='.'){
					ketemu = true;
					bantu->token = "T_float";
					g = k;									
				}else{
					g++;
				}
			}
			if(ketemu==false){
			bantu->token = "T_int";
			}
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	
} 

void sym_konver(){
	node *bantu;
	int k,g;
	bool ketemu;

	if (awl_smpl_sym == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_sym;
		do{
			if(bantu->data[0]=='"'){bantu->token="T_string";}
			else if(bantu->data==";"){bantu->token="T_tikom";}
		   	else if(bantu->data==":"){bantu->token="T_tikdua";}
			else if(bantu->data=="("){bantu->token="T_bukrung";}
			else if(bantu->data==")"){bantu->token="T_tuprung";}
			else if(bantu->data=="+"){bantu->token="T_tambah";}
			else if(bantu->data=="-"){bantu->token="T_garbaw";}
			else if(bantu->data=="/"){bantu->token="T_mirkir";}
			else if(bantu->data=="\\"){bantu->token="T_mirkan";}
			else if(bantu->data=="%"){bantu->token="T_persen";}
			else if(bantu->data==">"){bantu->token="T_lebdar";}
			else if(bantu->data=="<"){bantu->token="T_kurdar";}
			else if(bantu->data=="="){bantu->token="T_samdeng";}
			else if(bantu->data=="*"){bantu->token="T_kali";}
			else if(bantu->data=="."){bantu->token="T_titik";}
			else if(bantu->data==","){bantu->token="T_koma";}
			else if(bantu->data=="{"){bantu->token="T_bukraw";}
			else if(bantu->data=="}"){bantu->token="T_tupraw";}
			else if(bantu->data=="["){bantu->token="T_bukkurkot";}
			else if(bantu->data=="]"){bantu->token="T_tupkurkot";}
			else if(bantu->data=="!"){bantu->token="T_seru";}
		  
			bantu = bantu->next;  
		}while (bantu != NULL);
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
			cout << bantu->id << "  ";
			cout << bantu->data << "       ";
			cout << bantu->token<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	cout << "Data Digit" << endl;
	if (awl_smpl_dgt == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_dgt;
		do{
			cout << bantu->id << "  ";
			cout << bantu->data << "       ";
			cout << bantu->token<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}
	cout << "Data Symbol" << endl;
	if (awl_smpl_sym == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_sym;
		do{
			cout << bantu->id << "  ";
			cout << bantu->data << "       ";
			cout << bantu->token<<endl;
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
			int k=1;
				do{
					if(k==1){teks = kar;};
					if(k==0){teks += kar;};
					file >> noskipws >> kar;
					k = 0;
				}while(isalnum(kar));
			c = c+1;
			inpt_list_alp(c,teks);
			teks = '\0';
		}

		if(isdigit(kar)){
				int k=1;
				do{
					if(k==1){digit = kar;};
					if(k==0){digit += kar;};
					file >> noskipws >> kar;
					k = 0;
				}while((isdigit(kar))||(kar=='.'));
			c = c+1;
			inpt_list_dgt(c,digit);
			digit = '\0';
			
		}

		if(kar == '"'){
			teks = kar;
			do{
				file >> noskipws >> kar;
				teks += kar;
			}while(kar !='"');
			c = c+1;
			
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
alp_konver();
dgt_konver();
sym_konver();
tampil_list();
hapus();
	return 0;
}



