#include <iostream>
using namespace std;
int main(){
	string a;     									 //deklarasi string input
	bool q[3];     									 //Deklarasi q sebagai aray of bool, dan q Menggambarkan state-state pada FA
	int index=0, pindah[2][3] = {0,1,-1,1,-1,0}; 	 //alur yg mengatur perpindahan state 		
	cin>>a;        									 //string diinputkan pengguna	
	for(int i=0; i<a.length();i++){            		 //mengecek string inputan per karakter
			q[index] = false;                   	 //karena akan terjadi perpindahan state, state sementara menjadi false          
            index += pindah[a[i]-48][index];   		 //mengubah index(penanda state yg akan dituju)
			q[index] = true; 						 //state tujuan berpindah/state yg ditandai index menjadi true
	}												 
	if(q[0]) cout<<"Diterima"; 						 //jika q[0] true, string diterima karena berhenti pada q0 (Final State)
	else     cout<<"Ditolak";						 //jika q[0] false, string tidak diterima karena tidak berhenti pada q0(Final state}
} 													
