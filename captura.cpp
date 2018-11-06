#include <iostream>
#include <windows.h>

using namespace std;

int nroV,nroVR,desktop,cons,VA;
int sm=0, s=0,m=0,h, intervalo;
int cam;
bool tfoto=false;
bool local=true;
bool amenudo=true;

    
void cambioLocal(void){
	
	if(local==false){
		
		int i=1;

		cout<<i;
			while(i<=cons){
	
				cout<<"entro-1 ",i;
				i++;
				cout<<i;
				Sleep(2000);
				keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
				keybd_event(VK_TAB,0x8f,0 , 0);//tab press
				Sleep(2000);

		}
	
		keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
		keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
		local=true;
		amenudo=false;
		cons=1;
		
	}


Sleep(10000);
}

void cambioAmenudo(void){
	
	if(amenudo==false){	
		int i=1;


		while(i<=cam){

			cout<<"entro-2 ",i;
			i++;
			Sleep(2000);
			keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
			keybd_event(VK_TAB,0x8f,0 , 0);//tab press
			Sleep(2000);

		}
		
		keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
		keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
		local=false;
		amenudo=true;
		cam=1;
	}
Sleep(10000);
}

void cronometro (void){
	
	 for(h=0; h<12; h++){
	 	
		for(m =0; m<60; m++){
			
			for(s=0; s<60; s++){
				system("cls");
				cout <<"\t\t\t\t" <<h << ":" << m << ":" << s << endl;
				Sleep(1000); 
				system("cls");
					if (s==intervalo ){
			
		
						if (local==false){
	
							cambioLocal();
						}
		
						if (amenudo==false){
							cambioAmenudo();
						}
		
					}				
			}
		}
	}

}

int main()
{



	
	bool valores=true;

	if(valores==true){
	
		local=false;
		amenudo=true;
		
		cout<<"ventana de donde quieres conservarse >";
			cin>>cons;
		cout<<"ventana de donde quiere cambiar amenudo >";
		cin>>cam;
		cam+1;
		cout<<"intervalo entre cada ventana en segundos";
		cin>>intervalo;
		valores=false;
		
	}
		
	do{
		cronometro();
		s=0;
	}while(true);

    return 0;
}

