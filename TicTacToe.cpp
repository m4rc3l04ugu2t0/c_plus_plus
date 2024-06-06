#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits.h>
#include <cstdlib>  // Para srand e rand
#include <ctime>    // Para time

#define AI_PLAYER "  o  "
#define HUMAN_PLAYER "  x  "

using namespace std;

// Função para limpar a tela
void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para imprimir o tabuleiro
void DrawBoards(string play[]) {
    clearScreen();
    cout << play[0] << "|" << play[1] << "|" << play[2] << endl;
    cout << "-----" << "|" << "-----" << "|" << "-----" << endl;
    cout << play[3] << "|" << play[4] << "|" << play[5] << endl;
    cout << "-----" << "|" << "-----" << "|" << "-----" << endl;
    cout << play[6] << "|" << play[7] << "|" << play[8] << endl;
}

// Função para verificar se ainda há movimentos disponíveis no tabuleiro
bool isMovesLeft(string board[9]) {
    for (int i = 0; i < 9; i++)
        if (board[i] == "     ")
            return true;
    return false;
}

// Função para avaliar o tabuleiro e retornar um valor se um jogador ganhou
int evaluate(string board[9]) {
    string b[3][3] = {
        {board[0], board[1], board[2]},
        {board[3], board[4], board[5]},
        {board[6], board[7], board[8]}
    };

    // Verificar linhas para X ou O vitória.
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == AI_PLAYER)
                return +10;
            else if (b[row][0] == HUMAN_PLAYER)
                return -10;
        }
    }

    // Verificar colunas para X ou O vitória.
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == AI_PLAYER)
                return +10;
            else if (b[0][col] == HUMAN_PLAYER)
                return -10;
        }
    }

    // Verificar diagonais para X ou O vitória.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == AI_PLAYER)
            return +10;
        else if (b[0][0] == HUMAN_PLAYER)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == AI_PLAYER)
            return +10;
        else if (b[0][2] == HUMAN_PLAYER)
            return -10;
    }

    // Nenhum vencedor: retornar 0
    return 0;
}

// Função minimax
int minimax(string board[9], int depth, bool isMax) {
    int score = evaluate(board);

    // Se o AI_PLAYER ganhou o jogo, retornar o score
    if (score == 10)
        return score - depth;

    // Se o HUMAN_PLAYER ganhou o jogo, retornar o score
    if (score == -10)
        return score + depth;

    // Se não há mais movimentos e ninguém ganhou, é um empate
    if (!isMovesLeft(board))
        return 0;

    // Se é a vez do AI_PLAYER (maximizador)
    if (isMax) {
        int best = INT_MIN;

        // Percorrer todas as células vazias
        for (int i = 0; i < 9; i++) {
            // Verificar se a célula está vazia
            if (board[i] == "     ") {
                // Fazer o movimento
                board[i] = AI_PLAYER;

                // Chamar minimax recursivamente e escolher o valor máximo
                best = max(best, minimax(board, depth + 1, !isMax));

                // Desfazer o movimento
                board[i] = "     ";
            }
        }
        return best;
    }
    // Se é a vez do HUMAN_PLAYER (minimizador)
    else {
        int best = INT_MAX;

        // Percorrer todas as células vazias
        for (int i = 0; i < 9; i++) {
            // Verificar se a célula está vazia
            if (board[i] == "     ") {
                // Fazer o movimento
                board[i] = HUMAN_PLAYER;

                // Chamar minimax recursivamente e escolher o valor mínimo
                best = min(best, minimax(board, depth + 1, !isMax));

                // Desfazer o movimento
                board[i] = "     ";
            }
        }
        return best;
    }
}

// Função para encontrar o melhor movimento para o AI_PLAYER
int machine(string board[9]) {
    int bestVal = INT_MIN;
    int bestMove = -1;

    // Percorrer todas as células, avaliar minimax para cada célula vazia e retornar a melhor
    for (int i = 0; i < 9; i++) {
        // Verificar se a célula está vazia
        if (board[i] == "     ") {
            // Fazer o movimento
            board[i] = AI_PLAYER;

            // Computar o valor da função minimax para este movimento
            int moveVal = minimax(board, 0, false);

            // Desfazer o movimento
            board[i] = "     ";

            // Se o valor do movimento atual é melhor que o melhor valor, atualizar bestMove
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
}

// Função para a jogada do jogador humano
int MovePlayer(string board[9]) {
    string position;
    cout << "Digite a posição (1-9): ";
    cin >> position;
    position.erase(remove(position.begin(), position.end(), ' '), position.end());

    try {
        int positionNum = stoi(position) - 1;
        if (positionNum < 0 || positionNum >= 9) {
            throw invalid_argument("Posição inválida.");
        }

        if (board[positionNum] != "     ") {
            cout << "Posição já ocupada. Tente novamente." << endl;
            return -1;
        } else {
            board[positionNum] = HUMAN_PLAYER;
        }
    } catch (const invalid_argument& e) {
        cerr << "Erro: Posição inválida. Insira um número de 1 a 9." << endl;
        return -1;
    } catch (const out_of_range& e) {
        cerr << "Erro: Posição inválida. Insira um número de 1 a 9." << endl;
        return -1;
    }

    return 0;
}

int main() {
    string board[9] = {"     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     "};
    srand(time(0)); // Inicializar a semente do gerador de números aleatórios
    int currentPlayer = rand() % 2 + 1; // Aleatoriamente escolher o jogador inicial (1 ou 2)

    while (true) {
        DrawBoards(board);

        if (currentPlayer == 1) {
            if (MovePlayer(board) == -1) {
                continue;
            }
        } else {
            int bestMove = machine(board);
            board[bestMove] = AI_PLAYER;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Verificar se alguém ganhou ou se é empate
        int score = evaluate(board);
        if (score == 10) {
            DrawBoards(board);
            cout << "A máquina ganhou!" << endl;
            break;
        } else if (score == -10) {
            DrawBoards(board);
            cout << "Você ganhou!" << endl;
            break;
        } else if (!isMovesLeft(board)) {
            DrawBoards(board);
            cout << "É um empate!" << endl;
            break;
        }
    }

    return 0;
}

