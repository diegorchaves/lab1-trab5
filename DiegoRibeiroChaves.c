#include <stdio.h>
#include <stdlib.h>

void clear ()
{
    system ("cls");
}

void imprime (char matriz [7][7])
{
    clear ();
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf ("%4c ", matriz [i][j]);
        }
        printf ("\n");
    }
}

void giraMatriz1 (char matriz [7][7])
{
    char temp = matriz [0][0];
    for (int j = 0; j < 6; j++)
    {
        matriz [0][j] = matriz [0][j+1];
    }
    for (int i = 0; i < 6; i++)
    {
        matriz [i][6] = matriz [i+1][6];
    }
    for (int j = 6; j > 0; j--)
    {
        matriz [6][j] = matriz [6][j-1];
    }
    for (int i = 6; i > 0; i--)
    {
        matriz [i][0] = matriz [i-1][0];
    }
    matriz [1][0] = temp;
}

void giraMatriz2 (char matriz [7][7])
{
    char temp = matriz [1][1];
    for (int i = 1; i < 5; i++)
    {
        matriz [i][1] = matriz [i+1][1];
    }
    for (int j = 1; j < 5; j++)
    {
        matriz [5][j] = matriz [5][j+1];
    }
    for (int i = 5; i > 1; i--)
    {
        matriz [i][5] = matriz [i-1][5];
    }
    for (int j = 5; j > 1; j--)
    {
        matriz [1][j] = matriz [1][j-1];
    }
    matriz [1][2] = temp;
}

void giraMatriz3 (char matriz [7][7])
{
    char temp = matriz [2][2];
    for (int j = 2; j < 4; j++)
    {
        matriz [2][j] = matriz [2][j+1];
    }
    for (int i = 2; i < 4; i++)
    {
        matriz [i][4] = matriz [i+1][4];
    }
    for (int j = 4; j > 2; j--)
    {
        matriz [4][j] = matriz [4][j-1];
    }
    for (int i = 4; i > 2; i--)
    {
        matriz [i][2] = matriz [i-1][2];
    }
    matriz [3][2] = temp;
}

void cruz (char matriz [7][7])
{
    if (matriz [0][3] == matriz [1][3] && matriz [1][3] == matriz [2][3] && matriz [0][3] != '.')
    {
        printf ("\nCRUZ DESENHADA NA TELA!");
    }
}

void xis (char matriz [7][7])
{
    if (matriz [0][0] == matriz [1][1] && matriz [1][1] == matriz [2][2] && matriz [0][0] != '.')
    {
        printf ("\nX DESENHADO NA TELA!");
    }
}

int main ()
{
    int escolha = 1;
    char matriz [7][7] = {
        {'O', '.', '.', '.', '.', '.', 'X'},
        {'.', 'X', '.', '.', '.', 'O', '.'},
        {'.', '.', '.', 'O', '.', '.', '.'},
        {'.', '.', 'X', '.', 'X', '.', '.'},
        {'.', '.', '.', 'O', '.', '.', '.'},
        {'.', 'O', '.', '.', '.', 'X', '.'},
        {'X', '.', '.', '.', '.', '.', 'O'},
    };

    imprime (matriz);

    while (escolha != 0)
    {
        printf ("\nEscolha qual camada deseja rodar (1, 2, ou 3 -- 0 para parar): ");
        scanf ("%d", &escolha);
        if (escolha > 3 || escolha < 0)
            printf ("Numero invalido. Tente novamente.\n");
        switch (escolha)
        {
        case 1:
            giraMatriz1 (matriz);
            imprime (matriz);
            cruz (matriz);
            xis (matriz);
            break;
        case 2:
            giraMatriz2 (matriz);
            imprime (matriz);
            cruz (matriz);
            xis (matriz);
            break;
        case 3:
            giraMatriz3 (matriz);
            imprime (matriz);
            cruz (matriz);
            xis (matriz);
        default:
            break;
        }
    }

    return 0;
}