//INPUT & FILES
#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <string>
//TIMING
#include <chrono>
//RANDOM
#include <cstdlib>
#include <ctime>

//STRUCTURES
#include "Graph.h"

using namespace std;

void mainMenu();
void displayMenu(string, string, string);
void menu_mst();
void menu_routes();
void menu_flow();
void test();
void printMST(int** out, int n);
void printRoute(int** out, int u);
void printRoutes(int** out, int n);
void printFlowList(GraphList* out, GraphList* g, int n);
void printFlowMatrix(Matrix* out, Matrix* g, int n);

int main(int argc, char const *argv[]){
    mainMenu();
    return 0;
}



// MENU ENTRIES
void mainMenu(){
    srand(time(0));

    char option;
	do{
		cout << endl;
		cout << "=== MENU GLOWNE ===" << endl;
		cout << "1.MST" << endl;
		cout << "2.Najkrotsze Sciezki" << endl;
		cout << "3.Maksymalny Przeplyw" << endl;
		cout << "4.Test" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";		
		option = getche();
		cout << endl;

		switch (option){
		case '1':
			menu_mst();
			break;

		case '2':
			menu_routes();
			break;

		case '3':
			menu_flow();
			break;
		case '4':
			test();
			break;
		}

	} while (option != '0');
}

void test(){
	//Time measurments
	const int nVertices = 7;
	const int nDensities = 3;

	const int vertices[nVertices] = {100, 150, 200, 250, 300, 350, 400};
	// const int vertices[nVertices] = {500, 1000, 1500, 2000, 2500, 3000, 3500};
	// const int vertices[nVertices] = {500, 1000, 5000, 10000, 20000, 30000, 40000};
	const int densities[nDensities] = {20, 60, 99};
	const int nTests = 100;


	Graph g(1);
	string fileName = "fordbellman_matrix.txt";
	fstream file;//(fileName, ios::out);
	
	// for(int v = 0; v < nVertices; v++){//number of vertex size
	// 	int **out = new int*[vertices[v]];
	// 	for(int i = 0; i < vertices[v]; i++){
	// 		out[i] = new int[2];
	// 	}
	// 	for(int d = 0; d < nDensities; d++){//number of density
	// 		for(int t = 0; t < nTests; t++){//number of test
	// 			g.generate(vertices[v], densities[d], true, 0, 100);
	// 			auto start = chrono::high_resolution_clock::now();

	// 			g.FordBellmanMatrix(out, 0);
				
    //         	auto end = chrono::high_resolution_clock::now();
	// 			cout << t << ": " << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;
	// 			file << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;

	// 		}
	// 	}
	// 	for(int i = 0; i < vertices[v]; i++){
	// 		delete[] out[i];
	// 	}
	// 	delete[] out;
	// }
	// file.close();
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	fileName = "fordfulkerson_dfs_matrix.txt";
	file.open(fileName, ios::out);


	for(int v = 0; v < nVertices; v++){//number of vertex size
		Matrix out(vertices[v]);
		for(int d = 0; d < nDensities; d++){//number of density
			for(int t = 0; t < nTests; t++){//number of test
				g.generate(vertices[v], densities[d], true, 0, 100);
				auto start = chrono::high_resolution_clock::now();

				g.FordFulkersonDFSMatrix(&out, 0, 1);
				
            	auto end = chrono::high_resolution_clock::now();
				cout << t << ": " << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;
				file << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;

			}
		}
	}
	file.close();
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	fileName = "fordfulkerson_bfs_matrix.txt";
	file.open(fileName, ios::out);


	for(int v = 0; v < nVertices; v++){//number of vertex size
		Matrix out(vertices[v]);
		for(int d = 0; d < nDensities; d++){//number of density
			for(int t = 0; t < nTests; t++){//number of test
				g.generate(vertices[v], densities[d], true, 0, 100);
				auto start = chrono::high_resolution_clock::now();

				g.FordFulkersonBFSMatrix(&out, 0, 1);
				
            	auto end = chrono::high_resolution_clock::now();
				cout << t << ": " << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;
				file << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;

			}
		}
	}
	file.close();
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	fileName = "fordfulkerson_dfs_list.txt";
	file.open(fileName, ios::out);


	for(int v = 0; v < nVertices; v++){//number of vertex size
		GraphList out(vertices[v]);
		for(int d = 0; d < nDensities; d++){//number of density
			for(int t = 0; t < nTests; t++){//number of test
				g.generate(vertices[v], densities[d], true, 0, 100);
				auto start = chrono::high_resolution_clock::now();

				g.FordFulkersonDFSList(&out, 0, 1);
				
            	auto end = chrono::high_resolution_clock::now();
				cout << t << ": " << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;
				file << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;

			}
		}
	}
	file.close();
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------
	fileName = "fordfulkerson_bfs_list.txt";
	file.open(fileName, ios::out);


	for(int v = 0; v < nVertices; v++){//number of vertex size
		GraphList out(vertices[v]);
		for(int d = 0; d < nDensities; d++){//number of density
			for(int t = 0; t < nTests; t++){//number of test
				g.generate(vertices[v], densities[d], true, 0, 100);
				auto start = chrono::high_resolution_clock::now();

				g.FordFulkersonBFSList(&out, 0, 1);
				
            	auto end = chrono::high_resolution_clock::now();
				cout << t << ": " << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;
				file << vertices[v] << "\t" << densities[d] << "\t" << (end-start)/1us << endl;

			}
		}
	}
	file.close();
}

void displayMenu(string info, string alg1, string alg2){
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Wygeneruj losowo" << endl;
	cout << "3." << alg1 << endl;
	cout << "4." << alg2 << endl;
	cout << "5.Wyswietl" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu_mst(){
    Graph g(1);
    char opt;
    string fileName;
    fstream file;
    int edges, vertices;
	int density;
    int u, v, w;
	int** out;

	do{
		displayMenu("--- MST ---", "Kruskal", "Prim");
		opt = getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie z pliku
			cout << " Podaj nazwe pliku:";
			cin >> fileName;
            file.open(fileName, ios::in);
            if(!file.is_open()){
                cout << "Unable to open file." << endl;
				break;
            }
            file >> edges >> vertices;
            g.setN(vertices);
            for(int i = 0; i < edges; i++){
                file >> u >> v >> w;
                g.addEdge(u, v, w);
                g.addEdge(v, u, w);
            }
            file.close();
			
            g.showList();
            g.showMatrix();
			break;

		case '2': // tutaj generacja
			cout << "Podaj liczbe wierzcholkow: ";
			cin >> vertices;
			cout << "Podaj gestosc (w %): ";
			cin >> density;
			while(density > 100){
				cout << "Gestosc musi byc mniejsza niz 100%, podaj gestosc (w %): ";
				cin >> density;
			}
			g.generate(vertices, density, false, 1, 100);
			g.showList();
			g.showMatrix();
			break;

		case '3': // tutaj Kruskal
			out = new int*[vertices-1];
			for(int i = 0; i < vertices-1; i++){
				out[i] = new int[3];
			}

			g.KruskalList(out);
			cout << "Listowo:" << endl;
			printMST(out, vertices);

			g.KruskalMatrix(out);
			cout << "Macierzowo:" << endl;
			printMST(out, vertices);
			
			for(int i = 0; i < vertices-1; i++){
				delete[] out[i];
			}
			delete[] out;

			break;

		case '4': // tutaj Prim
			out = new int*[vertices-1];
			for(int i = 0; i < vertices-1; i++){
				out[i] = new int[3];
			}

			g.PrimList(out);
			cout << "Listowo:" << endl;
			printMST(out, vertices);

			g.PrimMatrix(out);
			cout << "Macierzowo:" << endl;
			printMST(out, vertices);
			
			for(int i = 0; i < vertices-1; i++){
				delete[] out[i];
			}
			delete[] out;

			break;

		case '5': // tutaj wyswietlanie
			g.showList();
			g.showMatrix();
			break;
		}

	} while (opt != '0');

}

void menu_routes(){
    Graph g(1);
    char opt;
    string fileName;
    fstream file;
    int edges, vertices;
	int start;
	int density;
	bool noCycle;
    int u, v, w;
	int** out;

	do{
		displayMenu("--- Najkrotsze Sciezki ---", "Dijkstra", "Ford-Bellman");
		opt = getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie z pliku
			cout << " Podaj nazwe pliku:";
			cin >> fileName;
            file.open(fileName, ios::in);
            if(!file.is_open()){
                cout << "Unable to open file." << endl;
				break;
            }
            file >> edges >> vertices >> start;
            g.setN(vertices);
            for(int i = 0; i < edges; i++){
                file >> u >> v >> w;
                g.addEdge(u, v, w);
            }
            file.close();
			
            g.showList();
            g.showMatrix();
			break;

		case '2': // tutaj generacja
			cout << "Podaj liczbe wierzcholkow: ";
			cin >> vertices;
			cout << "Podaj gestosc (w %): ";
			cin >> density;
			while(density > 100){
				cout << "Gestosc musi byc mniejsza niz 100%, podaj gestosc (w %): ";
				cin >> density;
			}
			start = 0;
			g.generate(vertices, density, true, 1, 100);
			g.showList();
			g.showMatrix();
			break;

		case '3': // tutaj Dijkstra
			out = new int*[vertices];
			for(int i = 0; i < vertices; i++){
				out[i] = new int[2];
			}

			g.DijkstraList(out, start);
			cout << "Listowo:" << endl;
			printRoutes(out, vertices);

			g.DijkstraMatrix(out, start);
			cout << "Macierzowo:" << endl;
			printRoutes(out, vertices);
			
			for(int i = 0; i < vertices; i++){
				delete[] out[i];
			}
			delete[] out;

			break;

		case '4': // tutaj FordBellman
			out = new int*[vertices];
			for(int i = 0; i < vertices; i++){
				out[i] = new int[2];
			}
			
			noCycle = g.FordBellmanList(out, start);
			cout << "Listowo:" << endl;
			if(!noCycle)cout << "Graf zawiera ujemny cykl." << endl;
			else printRoutes(out, vertices);

			noCycle = g.FordBellmanMatrix(out, start);
			cout << "Macierzowo:" << endl;
			if(!noCycle)cout << "Graf zawiera ujemny cykl." << endl;
			else printRoutes(out, vertices);
			
			for(int i = 0; i < vertices; i++){
				delete[] out[i];
			}
			delete[] out;
			break;

		case '5': // tutaj wyswietlanie
			g.showList();
			g.showMatrix();
			break;
		}

	} while (opt != '0');

}

void menu_flow(){
    Graph g(1);
    char opt;
    string fileName;
    fstream file;
    int edges, vertices;
	int source, sink;
	int density;
	bool noCycle;
    int u, v, w;
	int** out;

	do{
		displayMenu("--- Maksymalny Przeplyw ---", "Edmonds-Karp", "Ford-Fulkerson (DFS)");
		opt = getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie z pliku
			cout << " Podaj nazwe pliku:";
			cin >> fileName;
            file.open(fileName, ios::in);
            if(!file.is_open()){
                cout << "Unable to open file." << endl;
				break;
            }
            file >> edges >> vertices >> source >> sink;
            g.setN(vertices);
            for(int i = 0; i < edges; i++){
                file >> u >> v >> w;
                g.addEdge(u, v, w);
            }
            file.close();
			
            g.showList();
            g.showMatrix();
			break;

		case '2': // tutaj generacja
			cout << "Podaj liczbe wierzcholkow: ";
			cin >> vertices;
			cout << "Podaj gestosc (w %): ";
			cin >> density;
			while(density > 100){
				cout << "Gestosc musi byc mniejsza niz 100%, podaj gestosc (w %): ";
				cin >> density;
			}
			source = 0;
			sink = vertices-1;
			g.generate(vertices, density, true, 1, 100);
			g.showList();
			g.showMatrix();
			break;

		case '3': // tutaj BFS
		{
			Matrix m(vertices);
			GraphList l(vertices);
			cout << "Listowo: ";
			cout << " Przeplyw: " << g.FordFulkersonBFSList(&l, source, sink) << endl;
			cout << " Krawedzie: " << endl;
			printFlowList(&l, g.getList(), vertices);

			cout << "Macierzowo: ";
			cout << " Przeplyw: " << g.FordFulkersonBFSMatrix(&m, source, sink) << endl;
			cout << " Krawedzie: " << endl;
			printFlowMatrix(&m, g.getMatrix(), vertices);
		}

			break;

		case '4': // tutaj DFS
		{
			Matrix m(vertices);
			GraphList l(vertices);
			cout << "Listowo:" << endl;
			cout << " Przeplyw: " << g.FordFulkersonDFSList(&l, source, sink) << endl;
			cout << " Krawedzie: " << endl;
			printFlowList(&l, g.getList(), vertices);

			cout << "Macierzowo:" << endl;
			cout << " Przeplyw: " << g.FordFulkersonDFSMatrix(&m, source, sink) << endl;
			cout << " Krawedzie: " << endl;
			printFlowMatrix(&m, g.getMatrix(), vertices);
		}
			
			break;

		case '5': // tutaj wyswietlanie
			g.showList();
			g.showMatrix();
			break;
		}

	} while (opt != '0');

}


void printRoute(int** out, int u){
    if(out[u][1] != -1) printRoute(out, out[u][1]);
    cout << u << " ";
}

void printMST(int** out, int n){
	int sum = 0;
	cout << "krawedzie: " << endl;
	for(int i = 0; i < n-1; i++){
		cout << out[i][0] << " " << out[i][1] << " " << out[i][2] << endl;
		sum += out[i][2];
	}
	cout << "suma: " << sum << endl;
}

void printRoutes(int** out, int n){
	for(int i = 0; i < n; i++){
		cout << i << ": waga: " << out[i][0] << " sciezka: ";
		printRoute(out, i);
		cout << endl;
	}
}

void printFlowMatrix(Matrix* out, Matrix* graph, int n){
	Matrix help(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(graph->exists(i, j) && graph->getWeight(i, j)-out->getWeight(i, j) > 0){
				help.setWeight(i, j, graph->getWeight(i, j)-out->getWeight(i, j));
			}
		}
	}
	help.show();
}

void printFlowList(GraphList* out, GraphList* graph, int n){
	GraphList help(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(graph->exists(i, j) && graph->getWeight(i, j)-out->getWeight(i, j) > 0){
				help.addEdge(i, j, graph->getWeight(i, j)-out->getWeight(i, j));
			}
		}
	}
	help.show();
}