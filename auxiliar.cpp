# include <iostream>
# include <string>
#include "TreeNode.h"

using namespace std;

template <typename T>
class Arbol_B
{
private:
    int *data;
    Arbol_B **child_ptr;
    bool leaf;
    int n;

    Arbol_B<T> *root = NULL,
    *np = NULL, *x = NULL;

public:
    Arbol_B(){   // inicializa
        int i;
        np = new Arbol_B;
        np->data = new int[5];
        np->child_ptr = new Arbol_B *[6];
        np->leaf = true;
        np->n = 0;
        for (i = 0; i < 6; i++)
        {
            np->child_ptr[i] = NULL;
        }
        cout << "Se inicializo" << endl;
        //return np;

    };

    T splitChild(Arbol_B *x, int i)
    {
        int j, mid;
        Arbol_B *np1, *np3, *y;
        //Arbol_B<T> np3;
        np3->leaf = true;
        if (i == -1)
        {
            mid = x->data[2];
            x->data[2] = 0;
            x->n--;
            Arbol_B<T> np1;
            np1->leaf = false;
            x->leaf = true;
            for (j = 3; j < 5; j++)
            {
                np3->data[j - 3] = x->data[j];
                np3->child_ptr[j - 3] = x->child_ptr[j];
                np3->n++;
                x->data[j] = 0;
                x->n--;
            }
            for (j = 0; j < 6; j++)
            {
                x->child_ptr[j] = NULL;
            }
            np1->data[0] = mid;
            np1->child_ptr[np1->n] = x;
            np1->child_ptr[np1->n + 1] = np3;
            np1->n++;
            root = np1;
        }
        else
        {
            y = x->child_ptr[i];
            mid = y->data[2];
            y->data[2] = 0;
            y->n--;
            for (j = 3; j < 5; j++)
            {
                np3->data[j - 3] = y->data[j];
                np3->n++;
                y->data[j] = 0;
                y->n--;
            }
            x->child_ptr[i + 1] = y;
            x->child_ptr[i + 1] = np3;
        }
        return mid;
    }

    void insert(T *pData){   // inserta en el 
        cout << "hola mundo" << endl;
        int i;
        int temp;
        x = root;

        if(x == NULL){
            Arbol_B<T> *root; // llama constructor oara crear una nueva raiz
            x = root;
        }
        else{
            if (x->leaf == true && x->n == 5) // si hay un maximo de 5 hojas en un nivel, sino haga split de nodo
            {
                // temp = splitChild(x, -1); // esta variable sigue dando problema
                x = root;
                for (int i = 0; i < x->n; i++)
                {
                    NULL;
                }
                
            }   
        }
    }

};

int main(){

    Arbol_B<string> *nArbol;
    TreeNode<string> *nNodo;

    string *nNum = new string(); // crea nuevo pointer
    *nNum = "hola mundo"; // define contenido del pointer

    nArbol->insert(nNum);

    return 0;
}