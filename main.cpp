#include "src/BTree.cpp"
#include <math.h>

int main()
{
    BTree<int> *arbre = new BTree<int>();

    int nb = pow(10,7);
    /// *** Insertion de 10^7
    cout << "\nInsertion de "<<nb<<"...."<<endl;
    for(int i = 0 ; i < nb ; i++)
         arbre->Insert(i);
    cout << "Insertion de "<<nb<< " fini\n--------------------------------\n"<<endl;

    while(true)
    {
        int elem;
        cout << "Inserer le nombre à chercher : ";
        cin >> elem;
        cout<<"************************************\n";
        srand(time(nullptr));
        long s = clock();

        if(arbre->recherche(elem))
            cout << elem  << " existe"<<endl;
        else
            cout << elem  << " n'existe pas "<<endl;

        long e = clock();
        float tim = (float)(e-s)/CLOCKS_PER_SEC;

        cout << "\nTime execution : " << tim << endl;
        cout<<"-----------------------------------\n";
        char c;
        cout << "Tapez O:pour continuer,N:pour sortir ===> ";
        cin >> c;
        if(c == 'n' || c == 'N')
            break;


    }


    delete arbre;
    return 0;
}
