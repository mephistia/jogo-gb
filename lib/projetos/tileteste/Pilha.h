#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>

template <class T>

class Pilha {

public:

	// construtor
	Pilha<T>::Pilha() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
		cont = 0;
	}

	// destrutor
	Pilha<T>::~Pilha() {
		delete primeiro, ultimo, _undo;
	}

	// retornar tamanho
	int Pilha<T>::tamanho() {
		return tam;
	}


	// limpar pilha existente
	void Pilha<T>::clear() {
		primeiro = NULL;
		ultimo = NULL;
		tam = 0;
	}

	// adicionar
	void Pilha<T>::push(const T &dado) {
		Nodo<T> *add = new Nodo<T>;
		add->dado = dado;

		// se a pilha estiver vazia
		if (tam == 0) {
			add->proximo = NULL;
			add->anterior = NULL;
			primeiro = add;
			ultimo = add;
		}

		// se tiver só 1 elemento
		else if (tam == 1) {
			add->proximo = NULL;
			ultimo->proximo = add;
			add->anterior = ultimo;
			ultimo = add;
		}
		// inserir no final
		else {
			add->proximo = NULL;
			ultimo->proximo = add;
			add->anterior = ultimo;
			ultimo = add;
		}

		// aumentar o tamanho
		tam++;
	}

	// retornar topo
	T Pilha<T>::top() {
		if (tam > 0)
			return ultimo->dado;
	}

	// remover topo
	void Pilha<T>::pop() {
		
		 if (tam == 1) {
			clear();
			tam--;

		}
		else {
			ultimo->anterior->proximo = NULL;
			ultimo = ultimo->anterior;


			tam--;
		}

	}


	// remover 1 pra outra pilha
	void Pilha<T>::undo() {
		if (tam > 0) {
			if (_undo == NULL) {
				_undo = new Pilha;
			}

			T dado = ultimo->dado;
			_undo->push(dado);
			pop();
		}
		
	}

	// adicionar 1 da outra pilha
	void Pilha<T>::redo() {
		if (_undo->tam > 0) {
			T dado = _undo->top();
			push(dado);
			_undo->pop();
		}
		
	}

	// confere se a pilha de redo está vazia
	void Pilha<T>::isRedoEmpty() {
		if (_undo->tam > 0)
			return false;
		else
			return true;
	}


	// redo todos da outra pilha
	void Pilha<T>::redo_all() {
		if (_undo->tam > 0) {
			while (_undo->tam > 0) {
				redo();
			}
			
		}
		

	}

	// existe item?
	bool Pilha<T>::find(const T &dado) {
		if (tam > 0) {
			if (ultimo->dado == dado) {
				redo_all();
				return true;
			}
			else {
				undo();
				find(dado);
			}
		}
		else {
			return false;
		}
	}


private:
	Nodo<T> *primeiro; //base
	Nodo<T> *ultimo; // topo
	Pilha<T> *_undo; // pilha para redo
	int tam, cont;

};