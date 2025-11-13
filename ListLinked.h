#include <ostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename T>

class ListLinked : public List<T>{

        private:
                Node<T>* first;
                int n;

        public:
                ListLinked(){
                        first = nullptr;
                        n = 0;
                }

                ~ListLinked(){
                        for(int i=0;i<n;i++){
                                Node<T>* aux = new Node<T>(0, nullptr);
                                aux = first->next;
                                delete first;
                                first = aux;
                        }
                }
                  int size()override{
                        return n;
                }
                void insert(int pos, T e)override{
                        if(pos<0 || pos>n){
                                throw out_of_range("Posicion no valida");
                        }
                        Node<T>* newElement = new Node<T>(e, nullptr);
                        Node<T>* aux = first;

                        if (pos == 0){
				newElement->next = first;
				first = newElement;
			}
                        }else{
				for(int i=0;i<pos-1<i++){
					aux = aux->next;
				}
                                if(aux!=nullptr){
                                        newElement->next = aux->next;
                                }
                                aux->next =  newElement;
                        }
                        n++;

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
                        }else{
                                T data_out;
                                Node<T>* aux = first;
                                Node<T>* aux2 = nullptr;
                                if(pos==0){
                                        data_out = aux->data;
                                        aux2 = aux->next;
                                        delete aux;
					first = aux2;
					n--;
                                        return data_out;
                                }
                                for(int i=0; i<pos;i++){
                                        aux = aux->next;
                                }
                                aux2 = first;
                                for(int i=0; i<pos-1;i++){
                                        aux2 = aux2->next;
                                }
                                data_out = aux->data;
                                aux2->next = aux->next;
                                delete aux;
                                n--;
                                return data_out;
                        }
                }
                               T get(int pos)override{
                        if(pos<0 || pos>size()-1){
                                throw out_of_range("Posicion no valida");
                        }else{
                                Node<T>* aux = first;
                                for(int i=0; i<pos;i++){
                                        aux = aux->next;
                                }
                                return aux->data;
                        }
                }
                int search(T e)override{
                        Node<T>* aux = first;
                        for(int i=0;i<n;i++){
                                if(aux->data == e){
                                        return i;
                                }else{
                                        aux = aux->next;
                                }
                        }
                        return -1;
                }
                                bool empty()override{
                       if(n!=0){
                                return false;
                        }else{return true;}
                }

                T operator[](int pos){
                        return get(pos);
                }

                friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
                        Node<T>* aux = list.first;
                        out<<"ListLinked --> [";
                        for(int i=0; i<list.n; i++){
                                out<<aux->data<<" ";
                                aux = aux->next;
                        }
                        out<<"]\n";
                        return out;
                }
};

