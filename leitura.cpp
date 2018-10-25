#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct Aluno{
	unsigned int sexo:1;
	unsigned int idade:7;
	unsigned int renda:10;
	unsigned int escolaridade:2;
	unsigned int idioma:12;
	unsigned int pais:8;
	unsigned int localizador:24;
};

Aluno aluno[1000000000];

void pais_sexo_qtde(void){
	int cont0[256] = {0};
	int cont1[256] = {0};
	
	for(int j=0;j<1000000000;j++){
		for(int k=0;k<256;k++){
			if(aluno[j].pais == k and aluno[j].sexo==0)		
				cont0[k]++;
			else if(aluno[j].pais == k and aluno[j].sexo==1)
				cont1[k]++;
		}
	}
	
	for(int k=0;k<256;k++){
		cout << "Pais: " << k << " Sexo: " << 0 << " Quantidade: " << cont0[k] << endl;
		cout << "Pais: " << k << " Sexo: " << 1 << " Quantidade: " << cont1[k] << endl << endl;
	}	
	
}

void pais_sexo_idade_qtde(void){
	int cont[256][128][2] = {{{0}}};
	
	for(int i=0;i<1000000000;i++){
		for(int j=0;j<256;j++){
			for(int k=0;k<128;k++){
				for(int l=0;l<2;l++){
					if(aluno[i].pais == j and aluno[i].idade == k and aluno[i].sexo == l)
						cont[j][k][l]++;
										
				}
			}
		}
	}
	
	for(int a=0;a<256;a++){
		for(int b=0;b<128;b++){
			for(int c=0;c<2;c++){
				cout << "Pais: " << a << " Idade: " << b << " Sexo: " << c << " Quantidade: " << cont[a][b][c] << endl;
			}
		}
	}
	
}

void pais_sexo_mediaSalario(void){
	int cont[256][2] = {{0}};
	int salario[256][2] = {{0}};
	
	for(int i=0;i<1000000000;i++){
		for(int j=0;j<256;j++){
			for(int k=0;k<2;k++){
				if(aluno[i].pais == j and aluno[i].sexo == k){
					cont[j][k]++;
					salario[j][k] += aluno[i].renda;
				}
			}
		}
	}
	
	for(int a=0;a<256;a++){
		for(int b=0;b<2;b++){
			int media = (salario[a][b]/cont[a][b]);
			cout << "Pais: " << a << " Sexo: " << b << " Media de Renda: " << media << endl;
		}
	}
}

void pais_sexo_mediaIdade(void){
	int cont[256][2] = {{0}};
	int idade[256][2] = {{0}};
	
	for(int i=0;i<1000000000;i++){
		for(int j=0;j<256;j++){
			for(int k=0;k<2;k++){
				if(aluno[i].pais == j and aluno[i].sexo == k){
					cont[j][k]++;
					idade[j][k] += aluno[i].idade;
				}
			}
		}
	}
	
	for(int a=0;a<256;a++){
		for(int b=0;b<2;b++){
			int media = (idade[a][b]/cont[a][b]);
			cout << "Pais: " << a << " Sexo: " << b << " Media de Idade: " << media << endl;
		}
	}
	
}

void pais_sexo_pais15(void){
	int cont[2] = {0};
	
	for(int i=0;i<1000000000;i++){
		for(int j=0;j<2;j++){
				if(aluno[i].pais == 15 and aluno[i].sexo == j)
					cont[j]++;
		}
	}
	
	for(int a=0;a<2;a++)
		cout << "Pais: 15 " << "Sexo: " << a << " Quantidade: " << cont[a] << endl;
		
}
 
void pais15_sexo1_qtde(void){
	int cont = 0;
	
	for(int i=0;i<1000000000;i++)
		if(aluno[i].pais == 15 and aluno[i].sexo == 1)
			cont++;
			
	cout << "Pais: 15 Sexo: 1 " << cont << endl; 
	
}

void pais0_15_sexo_qtde(){
	int cont[16][2] = {{0}};
	
	for(int i=0;i<1000000000;i++){
		for(int j=0;j<16;j++){
			for(int k=0;k<2;k++){
				if(aluno[i].pais == j and aluno[i].sexo == k)
					cont[j][k]++;	
			}
		}
	}
	
	for(int a=0;a<16;a++){
		for(int b=0;b<2;b++){
			cout << "Pais: " << a << " Sexo: " << b << " Quantidade: " << cont[a][b] << endl;
		}
	}
	
}

void mediaRenda_idadeMenor61_paisMenor15(){
	int cont[16] = {0};
	int renda[16] = {0};

	for(int i=0;i<1000000000;i++){
		for(int j=0;j<16;j++){
			if(aluno[i].idade <= 60 and aluno[i].pais == j){
				cont[j]++;
				renda[j] += aluno[i].renda; 
			}
		}
	}
	
	cout << cont[5] << endl;
	cout << renda[5];
	
	for(int a=0;a<16;a++){
		int media = renda[a]/cont[a];
		cout << "Pais: " << a << " Media renda: " << media << endl;
	}
	
}

void pais_idioma_idioma20_paisMenor16(void){
	int cont[16] = {0};
	
	for(int i=0;i<1000000000;i++){
		for (int j=0;j<16;j++){
			if(aluno[i].pais == j and aluno[i].idioma == 20)
				cont[j]++;
		}
	}
	
	for(int a=0;a<16;a++){
		cout << "Pais: " << a << " Quantidade: " << cont[a] << endl;
	}
	
}

void mediaEscolaridade_pais(void){
	int cont = 0;
	int escolaridade = 0;
	
	for(int i=0;i<1000000000;i++){
		if(aluno[i].pais == 50){
			cont++;
			escolaridade += aluno[i].escolaridade;
		}
	}
	
	int media = escolaridade/cont;
	
	cout << "Pais: " << 50 << " Media Escolaridade: " << media << endl;
	
}

int main(){
	fstream arq("pessoas123.dat",ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	
	arq.seekg(0,ios_base::beg);

	for(int i=0;i<1000000000;i++)
		arq.read((char*) &aluno[i], sizeof(Aluno));
	
	arq.close();
	
	pais_sexo_qtde();
	pais_sexo_idade_qtde();
	pais_sexo_mediaSalario();
	pais_sexo_mediaIdade();
	pais_sexo_pais15();
	pais15_sexo1_qtde();
	pais0_15_sexo_qtde();
	mediaRenda_idadeMenor61_paisMenor15();
	pais_idioma_idioma20_paisMenor16();
	mediaEscolaridade_pais();
	
	return 0;
}
