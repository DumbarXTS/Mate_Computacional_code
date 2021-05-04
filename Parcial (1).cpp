#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Numero{
	int numero;
	int	mayor_eleccion;
	int pos_x;
	int pos_y;
};

void Crear_matriz(int* filas, int* columnas, Numero** p) {
    int* num1 = new int;
    for (short i = 0; i < *filas; ++i) {
    	for(int j = 0; j < *columnas; ++j){	
            *num1 = rand() % 10;
        	p[i][j].numero = *num1;
    	if (j % 2 == 0 || j == 0)
                cout << p[i][j].numero << ",";
            else
                cout << p[i][j].numero << "\t|\t";
            
        }
        cout << endl;
        cout << endl;
    }
    delete num1;
}

void Calculo(int* filas, int* columnas, Numero** p, Numero* persona1, Numero* persona2) {

	int* mayor = new int, *k = new int;
	*mayor = *k = 0;
    for (short i = 0; i < *filas; ++i) {
        persona1[i].pos_y = i;
        for (short j = 0; j < *columnas - 1; ++j) {
            if (*mayor <= p[i][j].numero) { 
                *mayor = p[i][j].numero;
                persona1[i].pos_x = j / 2;
            }
            ++j;
        }
        persona1[i].mayor_eleccion = *mayor;
        *mayor = 0;
        ++(*k);
        cout << endl;
    }
	*k = 0;
    for (short i = 1; i < *columnas; ++(++i)) {
        persona2[*k].pos_x = (i - 1)/2;
        for (short j = 0; j < *filas; ++j) {
            if (*mayor <= p[j][i].numero) {
                *mayor = p[j][i].numero;
                persona2[*k].pos_y = j;
            }
        }
        persona2[*k].mayor_eleccion = *mayor;
        *mayor = 0;
        ++(*k);
    }
    delete k;
}

void Calcular_Nash(int* filas, int* columnas, Numero* persona1, Numero* persona2){
	cout << "Equilibrio de Nash: " << "\n";
	
	for(int i = 0; i < *filas; ++i)
		for(int j = 0; j < *columnas; ++j){
			if(persona1[i].pos_x == persona2[j].pos_x && persona1[i].pos_y == persona2[j].pos_y){
				cout << persona1[i].mayor_eleccion << "," << persona2[j].mayor_eleccion << "\t"; 
				j = *columnas - 1;
			}
		}
}

void Matr(int* filas, int* columnas, Numero** p, int valor, Numero** aux){
	cout<<"\n";
	cout<<"\n";

					
			for(int i = 0; i < *filas - 1; ++i){
				for(int j = 0; j <*columnas; ++j){
					if(i!=valor){
						if (j % 2 == 0 || j == 0)
                			cout << p[i][j].numero << ",";
            			else
                			cout << p[i][j].numero << "\t|\t";
					}
				}	
				cout<<endl;
				cout<<endl;
			}
}

void Matr2(int* filas, int* columnas, Numero** p, int valor, Numero** aux){
	cout<<"\n";
	cout<<"\n";

					
			for(int i = 0; i < *filas; ++i){
				for(int j = 0; j < *columnas-2; ++j){
					if(j!=valor || j!=valor+1){
						if (j % 2 == 0 || j == 0)
                			cout << p[i][j].numero << ",";
            			else
                			cout << p[i][j].numero << "\t|\t";
					}
				}
				cout<<endl;
				cout<<endl;
			}
}

void Eliminar_Columnas(int* filas, int* columnas, Numero* persona1, Numero* persona2, Numero** p, Numero** aux,Numero** aux2){
	int comprobador = 0;
	int comprobador2 = 0;
	int valor = -1;
	int valor2 = -1;
	for(int i = 0; i < *filas; ++i){
		for(int j = 0; j < *columnas-1; ++(++j)){
			if(p[i][j].numero > p[i][j + 1].numero){
				if(persona1[i].pos_x != persona2[j].pos_x && persona1[i].pos_y != persona2[j].pos_y && persona1[i].pos_x != persona2[j+1].pos_x && persona1[i].pos_y != persona2[j+1].pos_y){
					++comprobador;
				}
			}	
			if(p[i][j+1].numero > p[i][j].numero){
				if(persona1[i].pos_x != persona2[j].pos_x && persona1[i].pos_y != persona2[j].pos_y && persona1[i].pos_x != persona2[j+1].pos_x && persona1[i].pos_y != persona2[j+1].pos_y){
					++comprobador2;
				}
			}
			if(comprobador == (*columnas/2) -1 && persona1[i].pos_x != persona2[j].pos_x && persona1[i].pos_y != persona2[j].pos_y && persona1[i].pos_x != persona2[j+1].pos_x && persona1[i].pos_y != persona2[j+1].pos_y || comprobador2 == (*columnas/2)-1 && persona1[i].pos_x != persona2[j].pos_x && persona1[i].pos_y != persona2[j].pos_y && persona1[i].pos_x != persona2[j+1].pos_x && persona1[i].pos_y != persona2[j+1].pos_y){
				valor = j;	
		}
	}
		comprobador = 0;	
		comprobador2 = 0;	
	}
	for(int i = 0; i < *columnas; ++(++i)){
		for(int j = 0; j < *filas-1; ++j){
			if(p[j][i].numero > p[j+1][i].numero){
				if(persona1[j].pos_x != persona2[i].pos_x && persona1[j].pos_y != persona2[i].pos_y || persona1[j].pos_x != persona2[i+1].pos_x && persona1[j].pos_y != persona2[i+1].pos_y){
					++comprobador;
				}
			}
				if(p[j][i+1].numero > p[j][i].numero){
					if(persona1[i].pos_x != persona2[j].pos_x && persona1[i].pos_y != persona2[j].pos_y || persona1[i+1].pos_x != persona2[j].pos_x && persona1[i+1].pos_y != persona2[j].pos_y) {
						++comprobador2;
					}
				}
			if(comprobador == *filas-1 && persona1[j].pos_x != persona2[i].pos_x && persona1[j].pos_y != persona2[i].pos_y || persona1[j].pos_x != persona2[i+1].pos_x && persona1[j].pos_y != persona2[i+1].pos_y || comprobador2 == *filas-1 && persona1[j].pos_x != persona2[i].pos_x && persona1[j].pos_y != persona2[i].pos_y || persona1[j].pos_x != persona2[i+1].pos_x && persona1[j].pos_y != persona2[i+1].pos_y)
				valor2 = j;		
		}
		comprobador = 0;
		comprobador2 = 0;		
	}
	if(0 <= valor)
		Matr(filas, columnas, p, valor, aux);
	if(0<=valor2)
		Matr2(filas, columnas, p, valor2, aux2);
}

int main(){
	
	srand(time(NULL));

    int* filas = new int;
    *filas = 2 + rand() % (4 - 2);
    int* b = new int;
    *b = rand() % 2;
    int* columnas = new int;
    if (*b == 1)
        *columnas = 4;
    else
        *columnas = 6;
    delete b;   
    
	Numero** aux = new Numero*[*filas];
    Numero** aux2 = new Numero*[*filas];	
    Numero** p = new Numero*[*filas];
    Numero persona1[6];
    Numero persona2[6];
	for(int i = 0; i < *filas; ++i){
	p[i] = new Numero[*columnas];
	aux[i]=new Numero[*columnas];
	aux2[i]=new Numero[*columnas];
	}
	
	
    Crear_matriz(filas, columnas, p);
	Calculo(filas, columnas, p, persona1, persona2);
	Calcular_Nash(filas, columnas, persona1, persona2);
	Eliminar_Columnas(filas, columnas, persona1, persona2, p, aux,aux2);
	
	return 0;
}
