#include <iostream>

using namespace std;

struct Conta {
    int numConta;
    string nomeTitular;
    char senha[4];
    double saldo;
};

void criarConta(Conta contas[], int count) {
    cout << "Informe o número da conta: " << endl;
    cin >> contas[count].numConta;
    cout << "Informe o nome do titular: " << endl;
    cin >> contas[count].nomeTitular;
    cout << "Informe uma senha de 4 digitos: " << endl;
    cin >> contas[count].senha;
    cout << "Informe o saldo inicial da conta: " << endl;
    cin >> contas[count].saldo;
}

double consultarSaldo() {

}

int main() {
    Conta contas[50];

    int escolha;

    int numeroContas = 0;

    do {
        cout << "Escolha uma das opções: " << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Sacar" << endl;
        cout << "4. Consultar saldo" << endl;
        cout << "5. Sair" << endl;
        cin >> escolha;

        if (escolha == 1) {
            criarConta(contas, numeroContas);
            numeroContas++;
        } else if (escolha == 2) {

        } else if (escolha == 3) {

        } else if (escolha == 4) {

        }
    } while (escolha != 5);
    return 0;
}