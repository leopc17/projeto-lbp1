#include <iostream>

using namespace std;

struct Conta {
    string nomeTitular;
    int numeroConta;
    int senha;
    double saldo;
};

int retornaIndice(Conta contas[], int quantidadeContas, int numeroConta) {
    for (int i = 0; i < quantidadeContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            return i;
        }
    }

    return -1;
}

bool verificaSenha(Conta contas[], int senha, int indiceConta) {
    if (contas[indiceConta].senha == senha) {
        return true;
    } else {
        return false;
    }
}

void criarConta(Conta contas[], int quantidadeContas) {
    cout << "Informe o número da conta: ";
    cin >> contas[quantidadeContas].numeroConta;
    cout << "Informe o nome do titular: ";
    cin >> contas[quantidadeContas].nomeTitular;
    cout << "Informe uma senha: ";
    cin >> contas[quantidadeContas].senha;
    cout << "Informe o saldo inicial da conta: ";
    cin >> contas[quantidadeContas].saldo;
    cout << endl;
}

void depositar(Conta contas[], int quantidadeContas) {
    int numeroConta, senha;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = retornaIndice(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite o valor: ";
        cin >> valor;

        contas[indiceConta].saldo += valor;

        cout << endl << "Você depositou: " << contas[indiceConta].saldo << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

void sacar(Conta contas[], int quantidadeContas) {
    int numeroConta, senha;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = retornaIndice(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite o valor: ";
        cin >> valor;

        contas[indiceConta].saldo -= valor;

        cout << endl << "Você sacou: " << contas[indiceConta].saldo << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

void transferir(Conta contas[], int quantidadeContas) {
    int numeroConta, senha, numeroContaDestino;

    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = retornaIndice(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite a conta de destino: ";
        cin >> numeroContaDestino;

        cout << "Digite o valor: ";
        cin >> valor;

        int indiceContaDestino = retornaIndice(contas, quantidadeContas, numeroContaDestino);

        contas[indiceContaDestino].saldo += valor;
        contas[indiceConta].saldo -= valor;

        cout << endl << "Você fez uma transferencia no valor de: " << valor << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

void consultarSaldo(Conta contas[], int quantidadeContas) {
    int numeroConta, senha;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = retornaIndice(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << endl << "Saldo da conta: " << contas[indiceConta].saldo << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

int main() {
    Conta *contas = new Conta[50];

    int escolha;

    int quantidadeContas = 0;

    do {
        cout << "Escolha uma das opções: " << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Sacar" << endl;
        cout << "4. Transferir" << endl;
        cout << "5. Consultar saldo" << endl;
        cout << "6. Sair" << endl;
        cin >> escolha;

        if (escolha == 1) {
            criarConta(contas, quantidadeContas);
            quantidadeContas++;
        } else if (escolha == 2) {
            depositar(contas, quantidadeContas);
        } else if (escolha == 3) {
            sacar(contas, quantidadeContas);
        } else if (escolha == 4) {
            transferir(contas, quantidadeContas);
        } else if (escolha == 5) {
            consultarSaldo(contas, quantidadeContas);
        }
    } while (escolha != 6);

    return 0;
}