# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <ctime>
# include <vector>

using namespace std;

struct numeros{
	int valor;
	bool estado;
};

struct bingote{
	numeros matriz[5][5];
};

void cartoncompleto( int ale[75], int cartones){
	
	numeros tabla[5][5];
	bingote vector[10];
	// Carton completo //
	cout << "\n";
	system("color 80");
	cout<<"\tB       I       N       G       O "<<endl<<endl;
	for(int k = 0; k < cartones; k++){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(tabla[i][j].valor<10)
					cout << " ";
					cout << "\t" << tabla[j][i].valor << " ";
					if (tabla[i][j].estado == true ){
						cout << " x ";
					}else{
						cout << "   ";
					}
				
			}
			cout<<endl;
		}		
	}
}

bool validar(int num, int cartones, numeros matriz[5][5]){

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(num == matriz[i][j].valor){
				return false;
			}
		}
	}	

	return true;	
}

bool verificar(int num, int ale[75]) {

	for(int i = 0; i<75; i++){
		if(num == ale[i]){
			return true;
		}
	}
	return false;		
}

void tacharprincipal(numeros bingo[15][5], int ale[75]){
	
	// Tachar tabla principal //
	//system("color E6");
	system("color 08");
	cout << "\n";
	cout<<"\tB       I       N       G       O "<<endl<<endl;
	for(int i=0;i<15;i++){
		for(int j=0;j<5;j++){
			if(bingo[i][j].valor<10)
				cout<<" ";
				cout<< "\t" << bingo[i][j].valor<<" ";
				if (bingo[i][j].estado == true ){
					cout << " x ";
				}else{
					cout << "   ";
				}
			
		}
		cout<<endl;
	}
	
}

bool ganador(numeros matriz[5][5], bingote vector[10], int cartones){

	bool flag = true;
	int cont[cartones];
	
	for (int k = 0; k < cartones; k++){
		cont[k] = 0;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if (vector[k].matriz[i][j].estado == true)
				   	cont[k]++;
					if( cont[k] == 24 ){
					    if(flag){
					    	cout<<endl<<endl<<"\t\t\t\t\tCARTONES GANADORES "<< endl;
					    	flag = false;
						}			
						cout<<endl<<endl<<"\t\t\t\t\tCARTON "<< "NUMERO -> " << k+1 << endl;
						system("pause");
					}
				
			}		
		}
	}
		
	if(!flag){
		  return true;	
	}else{
		return false;	
	}	 
  
}

bool ganador2(numeros matriz[5][5], bingote vector[10], int cartones){
	
	bool flag = true;
	int cont[cartones];
	
	for (int k = 0; k < cartones; k++){
		cont[k] = 0;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if (vector[k].matriz[i][j].estado == true){
				   	cont[k]++;
					if( cont[k] == 9 && vector[k].matriz[i][0].estado == true && vector[k].matriz[4][j].estado == true){
					    if(flag){
					    	cout<<endl<<endl<<"\t\t\t\t\tCARTONES GANADORES "<< endl;
					    	flag = false;
						}			
						cout<<endl<<endl<<"\t\t\t\t\tCARTON "<< "NUMERO -> " << k+1 << endl;
						system("pause");
					}
				}	
			}		
		}
	}
		
	if(!flag){
		  return true;	
	}else{
		return false;	
	}		 	
  
}

bool ganador3(numeros matriz[5][5], bingote vector[10], int cartones){

	int cont[cartones];
	
	for (int k = 0; k < cartones; k++){
		cont[k] = 0;
	 	for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				 if (vector[k].matriz[i][j].estado == true){
				    if(vector[k].matriz[i][j].estado == true && (j == i || i+j == 5 - 1)){
				    	cont[k]++;
				    	if( cont[k] == 8) {
				    		cout<<endl<<endl<<"\t\t\t\t\tCARTON GANADOR "<< "NUMERO -> " << k+1 << endl;
				          	 system("pause");
	           				return true;
							break;
						}			
					}     
				}
			}		
		}
	}	
				 
	return false;	
  
}

bool ganador4(numeros matriz[5][5], bingote vector[10], int cartones){

	int cont[cartones];
	
	for (int k = 0; k < cartones; k++){
	 	for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if (vector[k].matriz[i][j].estado == true){
				    if(vector[k].matriz[i][j].estado == true && (i == j)) {
				    	cont[k]++;
					   	if(cont[k] == 4){
	    					cout<<endl<<endl<<"\t\t\t\t\tCARTON GANADOR "<< "NUMERO -> " << k+1 << endl;
				          	 system("pause");
	           				return true;
							break;
						}
					}       
				}
			}		
		}
	}	
				 
	return false;	
  
}

bool ganador5(numeros matriz[5][5], bingote vector[10], int cartones){

	int cont[cartones];
	
	for (int k = 0; k < cartones; k++){
	 	for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if (vector[k].matriz[i][j].estado == true){
				    if(vector[k].matriz[i][j].estado == true && (i+j == 5 - 1)) {
				    	cont[k]++;
					   	if(cont[k] == 4){
	    					cout<<endl<<endl<<"\t\t\t\t\tCARTON GANADOR "<< "NUMERO -> " << k+1 << endl;
				          	 system("pause");
	           				return true;
							break;
						}
					}       
				}
			}		
		}
	}	
				 
	return false;	
  
}

void cartones(numeros bingo[15][5]){
	
	bingote vector[10];
	numeros matriz[5][5];
	int num, ale[75], cont1, numeros[100];
	int cartones, i = 0, op;
	bool flag = false;
	
	cout << "__________________________\n";
	cout << "| Numero de cartones: ";
	cin >> cartones;
	cout << "|_________________________\n";
	system("pause");
	system("cls");
	srand(time(NULL));
	for(int k = 0; k < cartones; k++){
		for (int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(i == 0){
					num = rand() % 15 + 1;
					while(validar(num, cartones, vector[k].matriz) == false){
						num = rand() % 15 + 1;	
					}
					vector[k].matriz[i][j].valor = num;
					vector[k].matriz[i][j].estado = false;
				} else if(i == 1){
					num = rand() % 15 + 16;
					while(validar(num, cartones, vector[k].matriz) == false){
						num = rand() % 15 + 16;	
					}
					vector[k].matriz[i][j].valor = num;
					vector[k].matriz[i][j].estado = false;
				} else if(i == 2){
					num = rand() % 15 + 31;
					while(validar(num, cartones, vector[k].matriz) == false){
						num = rand() % 15 + 31;	
					}
					vector[k].matriz[i][j].valor = num;
					vector[k].matriz[i][j].estado = false;
				} else if (i == 3){
					num = rand() % 15 + 46;
					while(validar(num, cartones, vector[k].matriz) == false){
						num = rand() % 15 + 46;	
					}
					vector[k].matriz[i][j].valor = num;
					vector[k].matriz[i][j].estado = false;
				} else if(i == 4){
					num = rand() % 15 + 61;
					while(validar(num, cartones, vector[k].matriz) == false){  
						num = rand() % 15 + 61;	
					}
					vector[k].matriz[i][j].valor = num;
					vector[k].matriz[i][j].estado = false;
				}
				vector[k].matriz[2][2].valor = 0;
			}
		}
	}
	
	cout << "       |                                                                                  |\n";
	cout << "       |                          -> COMO QUIERE JUGAR <-                                 |\n";
	cout << "       |                                                                                  |\n";
	cout << "       |  1. Jugar con tabla completa                                                     |\n";
	cout << "       |  2. Jugar en L                                                                   |\n";	    
	cout << "       |  3. Jugar en X                                                                   |\n";
	cout << "       |  4. Jugar con Diagonales                                                         |\n";
	cout << "       |  5. Salir                                                                        |\n";
	cout << "       |                                                                                  |\n";
	cout << "       | -> Opcion |: ";
	cin >>  op;
	cout << "       |__________________________________________________________________________________|\n";
	
	switch(op){
		
		case 1:
			
			system("pause");
			system("cls");
			for(int k = 0; k < cartones; k++){
				cout << "\tPLANTILLA A JUGAR EN CARTON COMPLETO \n";
				cout << endl;
				for (int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						cout << "\t";
						cout << vector[k].matriz[j][i].valor << " ";
					}
					cout << "\n";
				}
				cout << endl;
			}	
			system("pause");
			system("cls");
			
			do{
								
				// Generar número aleatorio // 
				cout << "\t__________________________________\n";
				cout << "\t-Generando numero aleatorio- \n";
		
				for(int i = 0; i<75; i++){
					while(verificar(num, ale)){
						num = rand() % 76 + 1; 
					}
					ale[i] = num;
				}
				
				for(int i = 0; i<1; i++){
					cout << "\tNumero aleatorio: "<< ale[i];
				}
			
				for(int i=0;i<15;i++){
					for(int j=0;j<5;j++){
						if (bingo[i][j].valor == ale[0]){
							bingo[i][j].estado = true;
							break;
						}
					}	
				}
				
				tacharprincipal(bingo, ale);
				
				for(int k = 0; k < cartones; k++){
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							if (vector[k].matriz[i][j].valor == ale[0]){
								vector[k].matriz[i][j].estado = true;
								break;
							}
						}	
					}
				}
				
				cout << "\n";
				system("color 80");
				
				for(int k = 0; k < cartones; k++){
					cout << " _____________________________________________\n";
					cout << "                    CARTON  # " << k+1 << "         \n";
					cout << "\n";
					cout<<  "\tB       I       N       G       O          \n"<<endl;	
				
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							if(vector[k].matriz[i][j].valor<10)
								cout << " ";
								cout << "\t" << vector[k].matriz[j][i].valor << " ";
							if (vector[k].matriz[j][i].estado == true){
								cout << " x ";
							}else{
								cout << "   ";
							}
						}
						cout<<endl;
					}
					cout << "\n";		
				}
							
				ganador(matriz, vector, cartones);
			
				system ("pause");

				i++;
			}while(i != 76);	
			
			break;
					
		case 2:
			
			system("pause");
			system("cls");
			for(int k = 0; k < cartones; k++){
				cout << endl;
				cout << "\t\tPLANTILLA A JUGAR EN L\n";
				cout << endl;
				for (int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						if(vector[k].matriz[i][j].valor == vector[k].matriz[i][0].valor || vector[k].matriz[i][j].valor == vector[k].matriz[4][j].valor){
							cout << "\t";
							cout << vector[k].matriz[i][j].valor << " ";
						}else{
							cout << "\t";
							cout << "0";
						}
					}
					cout << endl;
				}
			}	
			
			system("pause");
			system("cls");
			do{

				// Generar número aleatorio // 
				cout << "\t__________________________________\n";
				cout << "\t-Generando numero aleatorio- \n";
		
				for(int i = 0; i<75; i++){
					while(verificar(num, ale)){
						num = rand() % 76 + 1; 
					}
					ale[i] = num;
				}
				
				for(int i = 0; i<1; i++){
					cout << "\tNumero aleatorio: "<< ale[i];
				}
			
	
				for(int i=0;i<15;i++){
					for(int j=0;j<5;j++){
						if (bingo[i][j].valor == ale[0]){
							bingo[i][j].estado = true;
							break;
						}
					}	
				}
				
				tacharprincipal(bingo, ale);
				
				for(int k = 0; k < cartones; k++){
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							if (vector[k].matriz[i][j].valor == ale[0]){
								vector[k].matriz[i][j].estado = true;
								break;
							}
						}	
					}
				}
				
				system("color 08");
				cout << "\n";
				
				for(int k = 0; k < cartones; k++){
					
					cout << " _____________________________________________\n";
					cout << "                    CARTON  # " << k+1 << "         \n";
					cout << "\n";
					cout<<  "\tB       I       N       G       O          \n"<<endl;	
					
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							cout << " ";
							cout << "\t";
							cout << vector[k].matriz[j][i].valor << " ";
							if (vector[k].matriz[j][i].estado == true && (i == 4 || j == 0)){
								cout << " x ";
							}else{
								cout << "   ";
							}
						}
						cout<<endl;
					}
					cout << "\n";
				}
		
				system("pause");
				ganador2(matriz, vector, cartones);
				i++;
			}while(i != 76);	
			
			break;	
		
		case 3:
			
			system("pause");
			system("cls");
			for(int k = 0; k < cartones; k++){
				cout << endl;
				cout << "\t\tPLANTILLA A JUGAR EN X\n";
				cout << endl;
				for (int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						if(i == j){
							cout << vector[k].matriz[i][j].valor << " ";
						}else{
							cout << " ";
						}
						if(i+j+1 == 5){
							cout << vector[k].matriz[i][j].valor;
						}else{
							cout << " ";
						}
					}
					cout << endl;
				}
				cout << endl;
			}
			
			system("pause");
			system("cls");
			do{

				// Generar número aleatorio // 
				cout << "\t__________________________________\n";
				cout << "\t-Generando numero aleatorio- \n";
		
				for(int i = 0; i<75; i++){
					while(verificar(num, ale)){
						num = rand() % 76 + 1; 
					}
					ale[i] = num;
				}
				
				for(int i = 0; i<1; i++){
					cout << "\tNumero aleatorio: "<< ale[i];
				}
			
	
				for(int i=0;i<15;i++){
					for(int j=0;j<5;j++){
						if (bingo[i][j].valor == ale[0]){
							bingo[i][j].estado = true;
							break;
						}
					}	
				}
				
				tacharprincipal(bingo, ale);
				
				for(int k = 0; k < cartones; k++){
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							if (vector[k].matriz[i][j].valor == ale[0]){
								vector[k].matriz[i][j].estado = true;
								break;
							}
						}	
					}
				}
				
				system("color 80");
		
				for(int k = 0; k < cartones; k++){
					
					cout << " _____________________________________________\n";
					cout << "                    CARTON  # " << k+1 << "         \n";
					cout << "\n";
					cout<<  "\tB       I       N       G       O          \n"<<endl;	
					
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							cout << " ";
							cout << "\t" << vector[k].matriz[i][j].valor << " ";	
							if (vector[k].matriz[i][j].estado == true && (j == i || i+j == 5 - 1)){
								cout << " x ";
							}else{
								cout << "   ";
							}
						}
						cout<<endl;
					}
					cout << endl;
				}
				system("pause");
				ganador3(matriz, vector, cartones);
				i++;
			}while(i != 76);
				
			break;
			
		case 4:
			
			system("pause");
			system("cls");
					
			cout << "       |                                                                                  |\n";
			cout << "       |                          -> COMO QUIERE JUGAR <-                                 |\n";
		    cout << "       |                                                                                  |\n";
		    cout << "       |  1. Diagonal Principal                                                           |\n";
		    cout << "       |  2. Diagonal Secundaria                                                          |\n";	    
			cout << "       |                                                                                  |\n";
			cout << "       | -> Opcion |: ";
			cin >>  op;
			cout << "       |__________________________________________________________________________________|\n";
			
			switch(op){
				
				case 1:
					
					system("pause");
					system("cls");
					for(int k = 0; k < cartones; k++){
						cout << endl;
						cout << "       PLANTILLA A JUGAR EN DIAGONAL PRINCIPAL\n";
						cout << endl;
						for (int i = 0; i < 5; i++){
							for(int j = 0; j < 5; j++){
								if(i == j){
									cout << "\t";
									cout << vector[k].matriz[i][j].valor << " ";
								}else{
									cout << "\t";
									cout << "0";
								}	
							}
							cout << endl;
						}
						cout << endl;
					}
					
					system("pause");
					system("cls");
					do{
		
						// Generar número aleatorio // 
						cout << "\t__________________________________\n";
						cout << "\t-Generando numero aleatorio- \n";
				
						for(int i = 0; i<75; i++){
							while(verificar(num, ale)){
								num = rand() % 76 + 1; 
							}
							ale[i] = num;
						}
						
						for(int i = 0; i<1; i++){
							cout << "\tNumero aleatorio: "<< ale[i];
						}
					
						for(int i=0;i<15;i++){
							for(int j=0;j<5;j++){
								if (bingo[i][j].valor == ale[0]){
									bingo[i][j].estado = true;
									break;
								}
							}	
						}
						
						tacharprincipal(bingo, ale);
						
						for(int k = 0; k < cartones; k++){
							for(int i=0;i<5;i++){
								for(int j=0;j<5;j++){
									if (vector[k].matriz[i][j].valor == ale[0]){
										vector[k].matriz[i][j].estado = true;
										break;
									}
								}	
							}
						}
						
						system("color 08");

						for(int k = 0; k < cartones; k++){
							cout << " _____________________________________________\n";
							cout << "                    CARTON  # " << k+1 << "         \n";
							cout << "\n";
							cout<<  "\tB       I       N       G       O          \n"<<endl;
							for(int i=0;i<5;i++){
								for(int j=0;j<5;j++){
									if(vector[k].matriz[i][j].valor<10)
										cout << " ";
										cout << "\t" << vector[k].matriz[j][i].valor << " ";
										if (vector[k].matriz[i][j].estado == true && (i == j)){
											cout << " x ";
										}else{
											cout << "   ";
										}
								}
								cout<<endl;
							}
							cout << endl;
						}
						system("pause");
						ganador4(matriz, vector, cartones);
						i++;
					}while(i != 76);
							
					break;
				
				case 2:
					
					system("pause");
					system("cls");
					for(int k = 0; k < cartones; k++){
						cout << endl;
						cout << "       PLANTILLA A JUGAR EN DIAGONAL SECUNDARIA\n";
						cout << endl;
						for (int i = 0; i < 5; i++){
							for(int j = 0; j < 5; j++){
								if(i+j == 5 - 1){
									cout << "\t";
									cout <<	vector[k].matriz[i][j].valor;
								}else{
									cout << "\t";
									cout << "0";
								}
							}
							cout << endl;
						}
						cout << endl;
					}
					
					system("pause");
					system("cls");
					do{
		
						// Generar número aleatorio // 
						cout << "\t__________________________________\n";
						cout << "\t-Generando numero aleatorio- \n";
				
						for(int i = 0; i<75; i++){
							while(verificar(num, ale)){
								num = rand() % 76 + 1; 
							}
							ale[i] = num;
						}
						
						for(int i = 0; i<1; i++){
							cout << "\tNumero aleatorio: "<< ale[i];
						}
			
						for(int i=0;i<15;i++){
							for(int j=0;j<5;j++){
								if (bingo[i][j].valor == ale[0]){
									bingo[i][j].estado = true;
									break;
								}
							}	
						}
						
						tacharprincipal(bingo, ale);
						
						for(int k = 0; k < cartones; k++){
							for(int i=0;i<5;i++){
								for(int j=0;j<5;j++){
									if (vector[k].matriz[i][j].valor == ale[0]){
										vector[k].matriz[i][j].estado = true;
										break;
									}
								}	
							}
						}
						
						system("color 80");
						for(int k = 0; k < cartones; k++){
							cout << " _____________________________________________\n";
							cout << "                    CARTON  # " << k+1 << "         \n";
							cout << "\n";
							cout<<  "\tB       I       N       G       O          \n"<<endl;
							for(int i=0;i<5;i++){
									for(int j=0;j<5;j++){
										if(vector[k].matriz[i][j].valor<10)
											cout << " ";
											cout << "\t" << vector[k].matriz[j][i].valor << " ";
										if (vector[k].matriz[i][j].estado == true && (i+j == 5 - 1)){
											cout << " x ";
										}else{
											cout << "   ";
										}
									}
									cout<<endl;
							}
							cout << endl;
						}
						system("pause");
						ganador5(matriz, vector, cartones);
						i++;
					}while(i != 76);
						
					break;
					
					
		}
		case 5:
			
			cout << "\t\tRECUERDA!!! EL QUE DESCUIDA SU CARTON LE CANTAN 'BINGO'...\n";
			cout << "\t   ________________________________________________________________\n";
			
			break;	
	}
}	

int main(){
	
	numeros bingo[15][5];
	int val = 1;
	
	cout << "\n\n\n\n\n\n\n\n\n";
	system("color 6E");
	cout<<"\t\t\t\t	DIEGO     D   D     N   ANTONY   BRYAN  "<<endl;
	cout<<"\t\t\t\t	B     B   I   I B   O   B       A     O "<<endl;
	cout<<"\t\t\t\t	BRAYAN    B   E  R  T   R  EGO  N     N "<<endl;
	cout<<"\t\t\t\t	B     B   Y   G   A N   A    I  T     Y "<<endl;
	cout<<"\t\t\t\t	ANTONY    A   O    YA    YAND    DIEGO  "<<endl;
	cout << "\n";
	cout << "\t\t\t\t  ________________________________________________\n";	
	cout << "\t\t\t\t  |                 -> JUGAR <-                  |\n";
	cout << "\t\t\t\t  |______________________________________________|\n";
	cout << "     \t\t\t\t\t ";
	system("pause");
	system("cls");
	
	cout << "\t__________________________________________________________________________________\n";

	// llenar tabla principal // 
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 15; j++){
			bingo[j][i].valor = val;
			bingo[j][i].estado = false;
			val++;
		}
	}
	system("color 0E");
	// Imprimir tabla principal //
	cout << endl;
	cout<<"\t\t\t     ->  B       I       N       G       O  <-"<<endl<<endl;
	cout << "\t__________________________________________________________________________________\n";
	for(int i=0;i<15;i++){
		for(int j=0;j<5;j++){
			if(bingo[i][j].valor<10)
				cout<<" ";
				cout<< "\t\t" << bingo[i][j].valor<<" ";
		}
		cout<<endl;
	}
	cout << "\t__________________________________________________________________________________\n";
	
	cartones(bingo);	
	
	return 0;
}

