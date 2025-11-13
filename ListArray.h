#include <ostream>
#include "List.h"
using namespace std;

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;//puntero al inicio del array qeu almacenara los elementos de la lista del array
		int max;//tamanyo actual del array 	
		int n;// num elementos que contiene la lista
		static const int MINSIZE = 2;
		void resize (int new_size){ //redimensionar el array al tamaño especificado
			T* new_arr = new T[new_size];//Crear un nuevo array dinámico de new_size elementos
			for(int i=0;i<n;i++){ //copia el contenido del arr en newarr
				new_arr[i] = arr[i];
			}
			delete[] arr;
			T* arr = new_arr;//Actualizar el puntero arr para que apunte a la dirección de memoria en la que se encuentra el nuevo array.
			max = new_size;
		}
	public:
		ListArray();//Método constructor sin argumentos. Se encargará de reservar memoria dinámica para crear un array de MINSIZE elementos de tipo T, además de inicializar el resto de atributos de instancia
		~ListArray();//liberar la memoria dinámica reservada.
		int size(){
			return n;
		}
		void insert(int pos, T e)override{
			if(pos<0||pos>size()-1){
				throw out_of_range("Posicion no valida");
			}
			n++;
			if(n>max){
				resize(n+1);
			}
			for(int i=n;i>=pos;i--){
			arr[i]=arr[i-1];
			}
			arr[pos] = e;
		}

        void append(T e)override{
			insert(n, e);
		}

        void prepend(T e)override{
			insert(0, e);
		}

        T remove(int pos)override{
			if(pos<0||pos>size()-1){	
				throw out_of_range("Posicion no valida");
			}
			int aux = arr[pos];
			for(int i=pos;i<n;i++){
				arr[i] = arr[i+1];
			}
			return aux;
		}

        T get(int pos)override{
			if(pos<0 || pos>size()-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}
		int search(T e)override{
			for(int i=0;i<n;i++){
				if(arr[i]==e){
					return i;
				}
			}
			return -1;
		}

        bool empty ()override{
		       if(n!=0){
		       		return true;
		 	}else{return false;}
		}

		T operator[](int pos){
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out<<"List --> [";
			for(int i=0; i<list.n;i++){
				out<<list.arr[i];
			}
			out<<"]\n";
			return out;
		}

};
