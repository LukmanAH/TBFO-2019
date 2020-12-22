
// TUGAS BESAR 2 TBFO
// File : Index.cpp
// Anggota Kelompok:
// 1. Muhammad Lukman Al Hakim (118140103)
// 2. Sicillia Putri Aisyah (118140091)
// 3. Tamara Damayanti (118140069)

#include<iostream>  
#include "arithmetic.h" 
using namespace std;
int main(){
	string x,tampil;              //deklarasi semua variabel yg dibutuhkan.
	bool q[21],mtk; 					// deklarasi aray bolean Q yg menggambarkan state2.
	int index, alur[21][200];
		
awal: 
	tampil="> ";
	getline(cin,x);					 //menginputkan string x
	for(int i=0; i<21; i++) q[i]=0;  //semua q(state) dibuat 0(false)
	index=0;					     //karena start state di qo, maka index = 0
	for(int i=0; i<21; i++) for(int j=0; j<200; j++)alur[i][j]=20-i;  
		
	alur[0][3]=1; 				  //Q0  +  # pindah ke Q1 (jika tidak maka pindah ke Q20)
	alur[1][0]=1;				  //Q1  +  spasi pindah ke Q2 (jika tidak maka pindah ke Q20)
	alur[2][35]=1;alur[2][67]=1;  //Q2  +  C/c Pindah ke Q3 (jika tidak maka pindah ke Q20)
	alur[2][51]=9;alur[2][83]=9;  //Q2  +  S/s Pindah ke Q10 (jika tidak maka pindah ke Q20)
	alur[3][37]=1;alur[3][69]=1;  //Q3  +  E/e Pindah ke Q4 (jika tidak maka pindah ke Q20)
	alur[4][52]=1;alur[4][84]=1;  //Q4  +  T/t Pindah ke Q5 (jika tidak maka pindah ke Q20)
	alur[5][33]=1;alur[5][65]=1;  //Q5  +  A/a Pindah ke Q6 (jika tidak maka pindah ke Q20)
	alur[6][43]=1;alur[6][75]=1;  //Q6  +  K/k Pindah ke Q7 (jika tidak maka pindah ke Q20)
	alur[7][0]=1;				  //Q7  +  spasi Pindah ke Q8 (jika tidak maka pindah ke Q20)
	alur[8][2]=1;				  //Q8  +  " Pindah ke Q9 (jika tidak maka pindah ke Q20)
	alur[9][2]=1;				  //Q9  +  " Pindah ke Q10 (jika tidak maka pindah ke Q20)
	alur[10][27]=8;			   	  //Q10  +  ; Pindah ke Q18 (fs cetak) (jika tidak maka pindah ke Q20)
	alur[11][37]=1;alur[11][69]=1;//Q11  +  E/e Pindah ke Q12 (jika tidak maka pindah ke Q20)
	alur[12][44]=1;alur[12][76]=1;//Q12  +  L/l Pindah ke Q13 (jika tidak maka pindah ke Q20)
	alur[13][37]=1;alur[13][69]=1;//Q13  +  E/e Pindah ke Q14 (jika tidak maka pindah ke Q20)
	alur[14][51]=1;alur[14][83]=1;//Q14  +  S/s Pindah ke Q15 (jika tidak maka pindah ke Q20)
	alur[15][33]=1;alur[15][65]=1;//Q15  +  A/a Pindah ke Q16 (jika tidak maka pindah ke Q20) 
	alur[16][41]=1;alur[16][73]=1;//Q16  +  I/i Pindah ke Q17 (jika tidak maka pindah ke Q20)
	alur[17][27]=2;				  //Q17  +  ; menuju Q18 (fs selesai) (jika tidak maka pindah ke Q20)
	
	for(int i=0; i<200; i++){       //Perulangan sebanyak sigma atau kemungkinan karakter yg dapat di input
		alur[18][i]=2;  			//Q18  +  apapun pindah ke Q20
		alur[19][i]=1;				//Q19  +  apapun pindah ke Q20
	}
		
	for(int i=0; i<x.length(); i++){			
			
			q[index] = false; //state sekarang dibuat false   
			if(index==8){
				if(x[i]>='0' && x[i]<='9' || x[i]=='*' || x[i]=='/' || x[i]=='+' || x[i]=='-'){ //mengecek jika ada inputan karakter angka dan operator
					tampil+=x[i];  //karakter disimpan di srting tampil
					goto skip;
				}else if(x[i]==';') {
					index+=10;  //menuju final state untuk cetak/menampilkan hasil
					mtk= true;  //menadai jika perlu dilakukan operasi matematika dengan touring machine
					goto skip;
				}
			}								    				
			 if(index==9 && x[i]!='"') tampil+=x[i];        //Menampung semua inputan di state 9 kecuali "
        	else if(index==9 && x[i]=='"') index +=1;		//ketika mendapat " berpindah ke q 10
			else index += alur[index][x[i]-' '];			//mengubah index(penanda state yg akan dituju
			if(index>20) index=20;
			skip:
			q[index] = true;							//state tujuan menjadi True	
	}
	
	if(q[18]){                   // karena q18 adalah FS ,Jika q[18] true, maka mencetak tampil,,  
		if(mtk) cout<<"> "<<cek(tampil)<<endl;
		else cout<<tampil<<endl;
		goto awal;				//kembali ke awal dan menginputkan string lagi
	}else if(q[19]){            // karena q19 adalah FS,maka jika Q[19]=true mencetak tulisan di bawah.
		cout<<"> Terimakasih Sudah menggunakan compiler sederhana ini.";	
	}else {						//karena FS hanya Q18 dan Q19 maka selain itu mencetak tulisan di bawah.
		cout<<"> Kode Program Tidak Sesuai peraturan."<<endl; 
		goto awal;				//kembali ke awal dan menginputkan string lagi.
	}  		
}
 
 
