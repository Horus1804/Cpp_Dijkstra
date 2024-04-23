/***************************/
/* Algorithm de Dijkstra's */
/***************************/
#include "Node.h"

int main(int argc, char* argv[])
{
    std::vector<Nodes*> graphs;
    Nodes A('A');
    Nodes B('B');
    Nodes C('C');
    Nodes D('D');
    Nodes E('E');
    Nodes F('F');
    Nodes G('G');
    Nodes H('H');
    Nodes I('I');
    Nodes J('J');

    A.addNeighbor(&B, 85);
    A.addNeighbor(&C, 217);
    A.addNeighbor(&E, 173);
    B.addNeighbor(&F, 80);
    C.addNeighbor(&G, 186);
    C.addNeighbor(&H, 103);
    D.addNeighbor(&H, 183);
    E.addNeighbor(&J, 502);
    F.addNeighbor(&I, 250);
    H.addNeighbor(&J, 167);
    I.addNeighbor(&J, 84);

    graphs.emplace_back(&A);
    graphs.emplace_back(&B);
    graphs.emplace_back(&C);
    graphs.emplace_back(&D);
    graphs.emplace_back(&E);
    graphs.emplace_back(&F);
    graphs.emplace_back(&G);
    graphs.emplace_back(&H);
    graphs.emplace_back(&I);
    graphs.emplace_back(&J);

    // Affichage des voisins de chaque noeud
    for (Nodes* n : graphs)
    {
        n->showNeighbors();
        std::cout << std::endl;
    }

    // Demander à l'utilisateur de choisir une node de départ et une node d'arrivée
    char start, end;

    std::cout << "Entrez le noeud de départ: ";
    std::cin >> start;

    std::cout << "Entrez le noeud d'arrivée: ";
    std::cin >> end;


    // Algorithme de Dijkstra avec un système de poids
    std::vector<Nodes*> path;
    std::vector<Nodes*> visited;
    std::vector<int> weights;
    Nodes* current = nullptr;
    Nodes* startNode = nullptr;
    Nodes* endNode = nullptr;
    int weight = 0;

    for (Nodes* n : graphs)
    {
        if (n->getName() == start)
        {
			startNode = n;
		}
        if (n->getName() == end)
        {
			endNode = n;
		}
	}

    if (startNode == nullptr || endNode == nullptr)
    {
		std::cout << "Erreur: Le noeud de départ ou le noeud d'arrivée n'existe pas." << std::endl;
		return 1;
	}

    path.emplace_back(startNode);

    visited.emplace_back(startNode);

    while (current != endNode)
    {
        for (std::pair<Nodes*, int> p : path.back()->getNeighbors())
        {
            if (std::find(visited.begin(), visited.end(), p.first) == visited.end())
            {
                if (current == nullptr || weight + p.second < weight)
                {
					current = p.first;
					weight = p.second;
				}
                else
                {
					weight += p.second;
                }
			}
		}

		path.emplace_back(current);
		visited.emplace_back(current);
		weights.emplace_back(weight);
	}

    for (Nodes* n : path)
    {
        
        std::cout << n->getName() << " -> ";

    }


    std::cout << "Fin" << std::endl;



    return 0;
}