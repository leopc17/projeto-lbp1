#include <iostream>

using namespace std;

struct Conta {
    string nomeTitular;
    int numeroConta;
    int senha;
    double saldo;
    double valorTotalSaque;
    double valorTotalDeposito;
};

int encontrarConta(Conta contas[], int quantidadeContas, int numeroConta) {
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
    int numeroConta;

    cout << "Informe o número da conta: ";
    cin >> numeroConta;

    bool contaDisponivel;

    if (encontrarConta(contas, quantidadeContas, numeroConta) >= 0) {
        contaDisponivel = false;
    } else {
        contaDisponivel = true;
    }

    if (contaDisponivel) {
        contas[quantidadeContas].numeroConta = numeroConta;

        cout << "Informe o primeiro nome do titular: ";
        cin >> contas[quantidadeContas].nomeTitular;

        cout << "Informe uma senha: ";
        cin >> contas[quantidadeContas].senha;

        cout << "Informe o saldo inicial da conta: ";
        cin >> contas[quantidadeContas].saldo;

        contas[quantidadeContas].valorTotalSaque = 0;
        contas[quantidadeContas].valorTotalDeposito = 0;

        cout << endl;
    } else {
        cout << "O número da conta escolhido está indisponível." << endl;
    }
}

void depositar(Conta contas[], int quantidadeContas) {
    int numeroConta, senha;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = encontrarConta(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite o valor: ";
        cin >> valor;

        contas[indiceConta].saldo += valor;
        contas[indiceConta].valorTotalDeposito += valor;

        cout << endl << "Você depositou: " << valor << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

void sacar(Conta contas[], int quantidadeContas) {
    int numeroConta, senha;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = encontrarConta(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite o valor: ";
        cin >> valor;

        contas[indiceConta].saldo -= valor;
        contas[indiceConta].valorTotalSaque += valor;

        cout << endl << "Você sacou: " << valor << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

void transferir(Conta contas[], int quantidadeContas) {
    int numeroConta, senha, numeroContaDestino;

    double valor;

    cout << "Digite o número da conta: ";
    cin >> numeroConta;

    int indiceConta = encontrarConta(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << "Digite a conta de destino: ";
        cin >> numeroContaDestino;

        cout << "Digite o valor: ";
        cin >> valor;

        int indiceContaDestino = encontrarConta(contas, quantidadeContas, numeroContaDestino);

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

    int indiceConta = encontrarConta(contas, quantidadeContas, numeroConta);

    cout << "Digite a senha: ";
    cin >> senha;

    bool senhaCorreta = verificaSenha(contas, senha, indiceConta);

    if (senhaCorreta) {
        cout << endl << "Saldo da conta: " << contas[indiceConta].saldo << " R$" << endl << endl;
    } else {
        cout << endl << "Senha incorreta." << endl << endl;
    }
}

double** criar_matriz(int m, int n) {
    double **matriz;

    matriz = new double*[m];

    for (int i = 0; i < m; i++) {
        matriz[i] = new double[n];
    }

    return matriz;
}

void ler_matriz(Conta contas[],double **mat, int lin){
    for(int i = 0; i < lin; i++){
        mat[i][0] = contas[i].numeroConta;
        mat[i][1] = contas[i].saldo;
        mat[i][2] = contas[i].valorTotalSaque;
        mat[i][3] = contas[i].valorTotalDeposito;
    }
}

void imprimir_matriz(double** mat, int lin, int col){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<"                      ";
        }
        cout<<endl;
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

    cout << "Tabela de informações dos usuários: " << endl;

    double **matriz = criar_matriz(quantidadeContas, 4);
    ler_matriz(contas, matriz, quantidadeContas);

    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Número da conta | Saldo da conta | Valor total de saque | Valor total de depósito" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    imprimir_matriz(matriz, quantidadeContas, 4);

    cout << matriz[2][1];

    return 0;
}