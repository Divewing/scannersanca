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
node *gbng_p1 = NULL;
node *gbng_p2 = NULL;
//Devide
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
	string keyword[20] ={"var","mulai","selesai","int","string","program"
			   			,"float","tulis","baca","jika","maka","atau"
			   			,"ketika","lakukan","untuk","sampai","prosedur"
						,"kembalikan","fungsi"}; 
	if (awl_smpl_alp == NULL)
		cout << "Data Kosong";
	else{
		bantu = awl_smpl_alp;
		do{
		c =0;
		ketemu = false;
		while(c!=19){
			if(keyword[c]==bantu->data){
				bantu->token = "T_key_" + keyword[c];
				ketemu = true;
				c = 18;
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
			else if(bantu->data[0]=='\''){bantu->token="T_char";}
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

void sort1(){
	node *kiri;
	node *kanan;
	node *temp, *temp2;
	kiri = awl_smpl_alp;
	kanan = awl_smpl_dgt;
	
	
	do{

		 if(kiri==NULL){
		//masukan semua data yang ada di kanan;
		do{
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		temp->token = kanan->token;
		temp->next = NULL;
		if (gbng_p1 == NULL)
			gbng_p1 = temp;
		else{
			temp2 = gbng_p1;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kanan = kanan->next;
		}while(kanan!=NULL);
	}else if(kanan==NULL){
		//masukan semua data yang ada di kiri;
		do{
		temp = new node;
		temp->id = kiri->id;
		temp->data = kiri->data;
		temp->token = kiri->token;
		temp->next = NULL;
		if (gbng_p1 == NULL)
			gbng_p1 = temp;
		else{
			temp2 = gbng_p1;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kiri = kiri->next;
		}while(kiri!=NULL);
	}else if(kiri->id < kanan->id){
		//inputkirikelist
		
		temp = new node;
		temp->id = kiri->id;
		temp->data = kiri->data;
		temp->token = kiri->token;
		temp->next = NULL;
		if (gbng_p1 == NULL)
			gbng_p1 = temp;
		else{
			temp2 = gbng_p1;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kiri = kiri->next;
	}else if(kiri->id > kanan->id){
		//inputkananlist
		
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		temp->token = kanan->token;
		temp->next = NULL;
		if (gbng_p1 == NULL)
			gbng_p1 = temp;
		else{
			temp2 = gbng_p1;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kanan = kanan->next;
	}

	}while((kanan!=NULL)||(kiri!=NULL));
}

void sort2(){
	node *kiri;
	node *kanan;
	node *temp, *temp2;
	kiri = awl_smpl_sym;
	kanan = gbng_p1;
	
	
	do{

		 if(kiri==NULL){
		//masukan semua data yang ada di kanan;
		do{
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		temp->token = kanan->token;
		temp->next = NULL;
		if (gbng_p2 == NULL)
			gbng_p2 = temp;
		else{
			temp2 = gbng_p2;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kanan = kanan->next;
		}while(kanan!=NULL);
	}else if(kanan==NULL){
		//masukan semua data yang ada di kiri;
		do{
		temp = new node;
		temp->id = kiri->id;
		temp->data = kiri->data;
		temp->token = kiri->token;
		temp->next = NULL;
		if (gbng_p2 == NULL)
			gbng_p2 = temp;
		else{
			temp2 = gbng_p2;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kiri = kiri->next;
		}while(kiri!=NULL);
	}else if(kiri->id < kanan->id){
		//inputkirikelist
		
		temp = new node;
		temp->id = kiri->id;
		temp->data = kiri->data;
		temp->token = kiri->token;
		temp->next = NULL;
		if (gbng_p2 == NULL)
			gbng_p2 = temp;
		else{
			temp2 = gbng_p2;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kiri = kiri->next;
	}else if(kiri->id > kanan->id){
		//inputkananlist
		
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		temp->token = kanan->token;
		temp->next = NULL;
		if (gbng_p2 == NULL)
			gbng_p2 = temp;
		else{
			temp2 = gbng_p2;
			while (temp2->next != NULL)
				temp2 = temp2->next;
				temp2->next = temp;
		}

		kanan = kanan->next;
	}

	}while((kanan!=NULL)||(kiri!=NULL));
}


void tampil_list(){
	node *bantu;
	
	cout << "Hasil Scan : "<<endl;
<<<<<<< HEAD
	cout << "no      ||word      || Token"<<endl<<endl;
=======
	cout << "no      ||lexeme      || Token"<<endl<<endl;
>>>>>>> 9351f7d6b97d1ae6b0e4b9240149d1df9672bae1
	if (gbng_p2 == NULL)
		cout << "Data Kosong";
	else{
		bantu = gbng_p2;
		do{
			cout << bantu->id << "        ";
			cout << bantu->data << "          ";
			cout << bantu->token<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}

	
} 

void simpan(char namafile[]){
	node *bantu;
	ofstream file;
	file.open(namafile);
	file << "Hasil Scan : "<<endl;
<<<<<<< HEAD
	file << "no      ||word      || Token"<<endl<<endl;
=======
	file << "no      ||lexeme      || Token"<<endl<<endl;
>>>>>>> 9351f7d6b97d1ae6b0e4b9240149d1df9672bae1
	if (gbng_p2 == NULL)
		file << "Data Kosong";
	else{
		bantu = gbng_p2;
		do{
			file << bantu->id << "        ";
			file << bantu->data << "          ";
			file << bantu->token<<endl;
			bantu = bantu->next;  
		}while (bantu != NULL);
	}

	file.close();
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

	if(gbng_p1->next == NULL){
		delete gbng_p1;
	}else{
		do{
			bantu = gbng_p1;
			gbng_p1 = gbng_p1->next;
			delete bantu;
		}while(gbng_p1 !=NULL);
	}
	
	if(gbng_p2->next == NULL){
		delete gbng_p2;
	}else{
		do{
			bantu = gbng_p2;
			gbng_p2 = gbng_p2->next;
			delete bantu;
		}while(gbng_p2 !=NULL);
	}	
} 



int main(int argc, char* argv[]) {
char kar,h_kar;
char namafile[41],out[3];
strcpy(out,"-o");
int c=0;
string teks;
string digit;
<<<<<<< HEAD
strcpy(namafile,argv[3]);
=======
>>>>>>> 9351f7d6b97d1ae6b0e4b9240149d1df9672bae1
ifstream file(argv[1]);
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

		if(kar == '\''){
			teks = kar;
			do{
				file >> noskipws >> kar;
				teks += kar;
			}while(kar !='\'');
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
sort1();
sort2();
<<<<<<< HEAD
tampil_list();
simpan(namafile);
=======

if(argc >= 3){
	if((strcmp(argv[2],"-o"))==0){
		strcpy(namafile,argv[3]);
		simpan(namafile);
	}
}else{
	tampil_list();
}


>>>>>>> 9351f7d6b97d1ae6b0e4b9240149d1df9672bae1
hapus();
	return 0;
}



