#include <iostream>

struct node
{
	int info;
	node* prev, * next;
};

struct List
{
	node* first = nullptr, * last = nullptr;
	int nrElem;

	void push_front(int key)
	{
		node* nod_nou = new node;
		nod_nou->info = key;
		nod_nou->prev = nullptr;
		nod_nou->next = first;
		if (last != nullptr)
		{
			first->prev = nod_nou;
		}
		else
		{
			last = nod_nou;
		}
		first = nod_nou;
	}

	void push_back(int key)
	{
		node* nod_nou = new node;
		nod_nou->info = key;
		nod_nou->next = nullptr;
		nod_nou->prev = last;
		if (last != nullptr)
		{
			last->next = nod_nou;
		}
		else
		{
			first = nod_nou;
		}
		last = nod_nou;
	}

	void pop_front()
	{
		if (last == nullptr)
			return;
		node* nod_nou = first;
		if (first == last)
		{
			first = nullptr;
			last = nullptr;
		}
		else
		{
			first = first->next;
			first->prev = nullptr;
		}
		delete nod_nou;
	}

	void pop_back()
	{
		node* nod_nou = last;
		if (last == nullptr)
			return;
		if (last == first)
		{
			first = nullptr;
			last = nullptr;
		}
		else
		{
			last = last->prev;
			last->next = nullptr;
		}
		delete nod_nou;
	}

	node* find(int key)
	{
		auto it = first;
		for (; it != nullptr; it = it->next)
			if (it->info == key)
				return it;
		return nullptr;
	}

	void erase(node* Nod)
	{
		if (Nod == nullptr)
			return;

		if (Nod == first)
			pop_front();
		else
			if (Nod == last)
				pop_back();
			else
			{
				Nod->prev->next = Nod->next;
				Nod->next->prev = Nod->prev;
				delete Nod;
			}
	}

	void remove(int key)
	{
		auto it = find(key);
		while (it != nullptr)
		{
			erase(it);
			it = find(key);
		}
	}


	void insert(node* Nod, int val)
	{
		if (Nod == first)
			push_front(val);
		else
		{
			node* nod_nou = new node;
			nod_nou->info = val;
			nod_nou->next = Nod;
			nod_nou->prev = Nod->prev;
			Nod->prev = nod_nou;
			nod_nou->prev->next = nod_nou;
		}
	}

	bool empty()
	{
		return last == nullptr;
	}

	void clear()
	{
		auto it = first;
		while (first != nullptr)
		{
			pop_front();
		}
	}

	void print()
	{
		auto it = first;
		for (; it != nullptr; it = it->next)
			std::cout << it->info << " ";
	}

	int size()
	{
		nrElem = 0;
		auto it = first;
		for (; it != nullptr; it = it->next)
			nrElem++;
		return nrElem;
	}

};

bool palindrom(List L)
{
	auto itFirst = L.first, itLast = L.last;
	while (itFirst != itLast)
	{
		if (itFirst->info != itLast->info)
			return false;
		itFirst = itFirst->next;
		itLast = itLast->prev;
	}
	return true;
}

bool compare(List L1, List L2)
{
	if (L1.size() != L2.size())
		return false;
	for (auto it1 = L1.first, it2 = L2.first; it1 != nullptr; it1 = it1->next, it2 = it2->next)
		if (it1->info != it2->info)
			return false;
	return true;
}

int main()
{
	std::cout << "MENIU\n";
	std::cout << "0. EXIT\n";
	std::cout << "1. Adauga un element in capul listei.\n";
	std::cout << "2. Adauga un element la finalul listei.\n";
	std::cout << "3. Sterge primul element din lista.\n";
	std::cout << "4. Sterge ultimul element din lista.\n";
	std::cout << "5. Cauta o valoare si returneaza un pointer la nodul cu acea valoare.\n";
	std::cout << "6. Sterge un element din lista.\n";
	std::cout << "7. Sterge toate aparitiile unei valori.\n";
	std::cout << "8. Insereaza un element cu o anumita cheie inainte de nodul indicat.\n";
	std::cout << "9. Verifica daca lista e vida.\n";
	std::cout << "10. Goleste lista.\n";
	std::cout << "11. Afiseaza elementele listei.\n";
	std::cout << "12. Returneaza numarul de elemente din lista.\n";
	std::cout << "13. Verifica daca lista e palindrom.\n";
	std::cout << "14. Verifica daca doua liste sunt identice.\n";

	List lista;
	int ok = 1, valoare;
	int nr1, nr2, nr3, nr4, nr5, nr6, nr7;

	while (ok)
	{
		std::cout << "\nAlege o instructiune: ";
		std::cin >> valoare;

		switch (valoare)
		{
		case 0:
		{
			std::cout << "\nIesire din program.\n";
			ok = 0;
			break;
		}
		case 1:
		{
			std::cout << "\nScrie ce valoare vrei sa adaugi in lista (la inceput) ";
			std::cin >> nr1;
			lista.push_front(nr1);
			break;
		}
		case 2:
		{
			std::cout << "\nScrie ce valoare vrei sa adaugi in lista (la sfarsit) ";
			std::cin >> nr2;
			lista.push_back(nr2);
			break;
		}
		case 3:
		{
			lista.pop_front();
			std::cout << "\nPrimul element a fost sters.";
			break;
		}
		case 4:
		{
			lista.pop_back();
			std::cout << "\nUltimul element a fost sters";
			break;
		}
		case 5:
		{
			std::cout << "\nScrie ce cheie are elementul pe care il cauti ";
			std::cin >> nr3;
			auto adresa1 = lista.find(nr3);
			if (adresa1 != nullptr)
				std::cout << "\Elementul a fost gasit.";
			else
				std::cout << "\nElementul NU a fost gasit.";
			break;
		}
		case 6:
		{
			std::cout << "\nScrie ce cheie are elementul pe care doresti sa il elimini ";
			std::cin >> nr4;
			auto adresa2 = lista.find(nr4);
			lista.erase(adresa2);
			std::cout << "\nElementul dorit a fost sters";
			break;
		}
		case 7:
		{
			std::cout << "\nScrie cheia corespunzatoare tuturor acelor elemente pe care doresti sa le elimini ";
			std::cin >> nr5;
			lista.remove(nr5);
			std::cout << "\nElementele dorite au fost sterse.";
			break;
		}
		case 8:
		{
			std::cout << "\nScrie cheia elementului pe care doresti sa il inserezi ";
			std::cin >> nr6;
			std::cout << "\nScrie cheia pe care o are elementul inaintea caruia doresti sa se faca inserarea";
			std::cin >> nr7;
			auto adresa3 = lista.find(nr7);
			lista.insert(adresa3, nr6);
			std::cout << "\nElementul dorit a fost inserat.";
			break;
		}
		case 9:
		{
			if (lista.empty())
				std::cout << "\nLista este vida";
			else
				std::cout << "\nLista NU este vida";
			break;
		}
		case 10:
		{
			lista.clear();
			std::cout << "\nLista s-a golit.";
			break;
		}
		case 11:
		{
			std::cout << "\nLista este: ";
			lista.print();
			break;
		}
		case 12:
		{
			std::cout << "\nNumarul de elemente din lista este: " << lista.size();
			break;
		}
		case 13:
		{
			if (palindrom(lista))
				std::cout << "\nLista data este palindrom.";
			else
				std::cout << "\nLista data NU este palindrom.";
			break;
		}
		case 14:
		{
			List lista2;
			std::cin >> lista2.nrElem;
			for (int i = 0; i < lista2.nrElem; i++)
			{
				int valoare;
				std::cin >> valoare;
				lista2.push_back(valoare);
			}
			if (compare(lista, lista2))
				std::cout << "\nListele sunt identice.";
			else
				std::cout << "\nListele NU sunt identice.";
			break;
		}
		default:
		{	std::cout << "\nInstructiunea aleasa nu exista. Alege alta.\n"; }
		}
	}

	return 0;
}