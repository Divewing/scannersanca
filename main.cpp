#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

struct node{
	int id;
	int stat;
	string data;
	string token;
	node *next;
};
node *awl_smpl_alp = NULL;
node *awl_smpl_dgt = NULL;
node *awl_smpl_sym = NULL;
int talp=0,tdgt=0,tsym=0;
node *gbng_p1 = NULL;
node *gbng_p2 = NULL;
//Devide
void inpt_list_alp(int c,string data){
	node *temp, *temp2;
	temp = new node;
	temp->id = c;
	temp->stat = 0;
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
	temp->stat = 0;
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
	temp->stat = 0;
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

void bagikat(char filebuk[]){
	char kar,h_kar;
	int c=0;
	string teks;
	string digit;
	ifstream file(filebuk);
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
			talp = talp + 1;
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
			tdgt = tdgt + 1;
			inpt_list_dgt(c,digit);
			digit = '\0';
			
		}

		if(kar == '"'){
			teks = kar;
			do{
				file >> noskipws >> kar;
				teks += kar;
				if(kar=='"'){
				 kar='\n';
				}
			}while(kar !='\n');
			c = c+1;
			tsym=tsym+1;
			inpt_list_sym(c,teks);
			teks = '\0';
		}

		if(kar == '\''){
			teks = kar;
			do{
				file >> noskipws >> kar;
				teks += kar;
				if(kar=='\''){
				 kar='\n';
				}
			}while(kar !='\n');
			c = c+1;
			tsym=tsym+1;
			inpt_list_sym(c,teks);
			teks = '\0';
		}

 		if(kar =='#'){
			while(kar!='\n'){
				file >> noskipws >> kar;
			}
		}
		
		if(	(kar==';')||(kar==':')||(kar=='(')||
			(kar==')')||(kar=='+')||(kar=='-')||
			(kar=='/')||(kar=='\\')||(kar=='%')||
			(kar=='>')||(kar=='<')||(kar=='=')||
			(kar=='*')||(kar=='.')||(kar==',')||
			(kar=='{')||(kar=='}')||(kar=='[')||
			(kar==']')||(kar=='!')
		  ){
			c = c+1;
			teks = kar;
			tsym=tsym+1;
			inpt_list_sym(c,teks);
			teks='\0';
		}
		
	}
  file.close();
	}
}
string alp_konver(string bantu){
	int c;
	bool ketemu;
	string keyword[20] ={"var","mulai","selesai","int","string","program"
			   			,"float","tulis","baca","jika","maka","atau"
			   			,"ketika","lakukan","untuk","sampai","prosedur"
						,"kembalikan","fungsi"}; 

		c =0;
		ketemu = false;
		while(c!=19){
			if(keyword[c]==bantu){
				return "T_key_" + keyword[c];
				ketemu = true;
				c = 18;
			}
			c++;
		}
		if(ketemu==false){
			return "T_ident";
		}
	
} 

string dgt_konver(string bantu){
	int k,g;
	bool ketemu;

	
			g = 0;
			ketemu = false;
			k = bantu.length();
			while(g!=k){
				if(bantu[g]=='.'){
					ketemu = true;
					return "T_float";
					g = k;									
				}else{
					g++;
				}
			}
			if(ketemu==false){
			return "T_int";
			}

} 

string sym_konver(string bantu){
	int k,g;

	
			if(bantu[0]=='"'){
				if(bantu[bantu.length()-1]=='"'){
					return "T_string";
				}else{
					return "Error";
				}
			}else if(bantu[0]=='\''){
				if(bantu.length()>4){
					return "T_char";
				}else{
					return "Error";
				}
			}else if(bantu==";"){return "T_tikom";}
		   	else if(bantu==":"){return "T_tikdua";}
			else if(bantu=="("){return "T_bukrung";}
			else if(bantu==")"){return "T_tuprung";}
			else if(bantu=="+"){return "T_tambah";}
			else if(bantu=="-"){return "T_garbaw";}
			else if(bantu=="/"){return "T_mirkir";}
			else if(bantu=="\\"){return "T_mirkan";}
			else if(bantu=="%"){return "T_persen";}
			else if(bantu==">"){return "T_lebdar";}
			else if(bantu=="<"){return "T_kurdar";}
			else if(bantu=="="){return "T_samdeng";}
			else if(bantu=="*"){return "T_kali";}
			else if(bantu=="."){return "T_titik";}
			else if(bantu==","){return "T_koma";}
			else if(bantu=="{"){return "T_bukraw";}
			else if(bantu=="}"){return "T_tupraw";}
			else if(bantu=="["){return "T_bukkurkot";}
			else if(bantu=="]"){return "T_tupkurkot";}
			else if(bantu=="!"){return "T_seru";}
		  
	
} 


void merge(node *a1, node *a2, node *a,int kat){
	node *kiri;
	node *kanan;
	node *temp, *temp2;
	kiri = a1;
	kanan = a2;
	
	
	
	do{
		int ada=0;
		 if(kiri==NULL){
		//masukan semua data yang ada di kanan;
		do{
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		if(kanan->stat ==  0){
			kanan->stat = 1;
			if(kat==1){
				temp->token = alp_konver(kanan->data);
			}else if(kat==2){
				temp->token = dgt_konver(kanan->data);
			} else if(kat==3){
				temp->token = sym_konver(kanan->data);
			}
		}else{
			temp->token = kanan->token;
		}
		temp->next = NULL;
		if (a == NULL)
			a = temp;
		else{
			temp2 = a;
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
		if(kiri->stat ==  0){
			kiri->stat = 1;
			if(kat==1){
				temp->token = alp_konver(kiri->data);
			}else if(kat==2){
				temp->token = dgt_konver(kiri->data);
			} else if(kat==3){
				temp->token = sym_konver(kiri->data);
			}
		}else{
			temp->token = kiri->token;
		}
		temp->next = NULL;
		if (a == NULL)
			a = temp;
		else{
			temp2 = a;
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
		if(kiri->stat ==  0){
			kiri->stat = 1;
			if(kat==1){
				temp->token = alp_konver(kiri->data);
			}else if(kat==2){
				temp->token = dgt_konver(kiri->data);
			} else if(kat==3){
				temp->token = sym_konver(kiri->data);
			}
		}else{
			temp->token = kiri->token;
		}
		temp->next = NULL;
		if (a == NULL)
			a = temp;
		else{
			temp2 = a;
			
			while (temp2->next != NULL){
				temp2 = temp2->next;
				if(temp->id == temp2->id){
					ada = 1;
					temp2->next=NULL;	
				}
			}
			if(ada==0){
				temp2->next = temp;
			}
		}

		kiri = kiri->next;
	}else if(kiri->id > kanan->id){
		//inputkananlist
		
		temp = new node;
		temp->id = kanan->id;
		temp->data = kanan->data;
		if(kanan->stat ==  0){
			kanan->stat = 1;
			if(kat==1){
				temp->token = alp_konver(kanan->data);
			}else if(kat==2){
				temp->token = dgt_konver(kanan->data);
			} else if(kat==3){
				temp->token = sym_konver(kanan->data);
			}
		}else{
			temp->token = kanan->token;
		}
		temp->next = NULL;
		if (a == NULL)
			a = temp;
		else{
			temp2 = a;

			
			while (temp2->next != NULL){
				temp2 = temp2->next;
				if(temp->id == temp2->id){
					ada = 1;
					temp2->next=NULL;	
				}
			}
			if(ada==0){
				temp2->next = temp;
			}
		}

		kanan = kanan->next;
	}

	}while((kanan!=NULL)||(kiri!=NULL));
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



void tampil_list(char filebuk[]){
	node *bantu;
	cout << "Hasil Scan file "<< filebuk << " : "<<endl;
	cout << "no      || lexeme      || Token"<<endl<<endl;
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

void simpan(char filebuk[],char filesim[]){
	node *bantu;
	ofstream file;
	file.open(filesim);
	file << "Hasil Scan file "<< filebuk << " : "<<endl;
	file << "no      || lexeme      || Token"<<endl<<endl;
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

void dandc(node *a,int n,int kat){
	if(n>1){
//-----------------Bagi Menjadi dua bagian----------------
		int n1,n2,i;
		n1= n/2;
		n2= n1+1;
		node *a1 = NULL,*a2=NULL,*kiri,*kanan,*temp,*temp2,*bantu;
		kiri = a;
		kanan = a;
		for(i=1;i<=n2;i++){
			kanan = kanan->next;
					
		}
		//bagi menjadi dua;
		for(i=1;i<=n1;i++){
			temp = new node;
			temp->id = kiri->id;
			temp->data = kiri->data;
			temp->token = kiri->token;
			temp->next = NULL;
			if (a1 == NULL)
				a1 = temp;
			else{
				temp2 = a1;
				while (temp2->next != NULL)
					temp2 = temp2->next;
					temp2->next = temp;
			}

			kiri = kiri->next;
		}
		
		kanan = kiri;
		do{
			temp = new node;
			temp->id = kanan->id;
			temp->data = kanan->data;
			temp->token = kanan->token;
			temp->next = NULL;
			if (a2 == NULL)
				a2 = temp;
			else{
				temp2 = a2;
			while (temp2->next != NULL)
				temp2 = temp2->next;

				temp2->next = temp;
			}

			kanan = kanan->next;
		}while(kanan!=NULL);

//-----------------------------------------------------------------end dari pembagian menjadi dua		
		
		dandc(a1,n1,kat);
		dandc(a2,n2-1,kat);
		merge(a1,a2,a,kat);

//Simpan hasilnya ke simpul yang sesuai
		if(kat==1){
			awl_smpl_alp = a;
		}else if(kat==2){
			awl_smpl_dgt = a;
		}else if(kat==3){
			awl_smpl_sym = a;
		}
		
	}
}

int main(int argc, char* argv[]) {
if(argc>1){
	char filesim[41],filebuk[41];
	strcpy(filebuk,argv[1]);

	//Membagi menjadi tiga kategori
	bagikat(filebuk);

	//Divide and Conquer
	dandc(awl_smpl_alp,talp,1);
	dandc(awl_smpl_dgt,tdgt,2);
	dandc(awl_smpl_sym,tsym,3);

	//Memgabung ketiga kategori
	sort1();
	sort2();

	if(argc >= 3){
		if((strcmp(argv[2],"-o"))==0){
			strcpy(filesim,argv[3]);
			simpan(filebuk,filesim);
		}
	}else{
		tampil_list(filebuk);
	}

	hapus();
}else{
	cout << "Error :Tidak ada file input"<<endl;
	cout << "Scanner dihentikan. "<<endl;
}
return 0;
}
