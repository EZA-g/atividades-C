#ifndef MEUBANCO_H
#define MEUBANCO_H

#define MAX_CLIENTES 100
#define MAX_CONTAS 2
#define MAX_HISTORICO 30
#define MAX_TRANSACOES 5

typedef struct {
    int tipo;
    int numero;
    float saldo;
} Conta;

typedef struct {
    char nome[20];
    int id;
    Conta contas[MAX_CONTAS];
    int quantidadeContas;
    int possuiEmprestimo;
    int possuiTitulo;
    float historicoCliente[MAX_TRANSACOES][3];
    int quantidadeTransacoes;
} Cliente;

typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int quantidadeClientes;
    int aberto;
    int proximoNumero;
    char historico[MAX_HISTORICO][120];
    int quantidadeEventos;
} Banco;

void menuInicial(void);
void menuCadCliente(void);
void cadCliente(char nome_c[]);
void menuConta(void);
void addConta(int tipo_con, int num_con);
void menuTrans(void);

void deposito(int cliente, int conta);
void saque(int cliente, int conta);
void emprestimo(int cliente, int conta);
void emprestimoCheck(void);
void TituloCheck(void);
void saldoAlerta(void);
void saldoCheck(void);
void menuHistorico(void);
void historicoCliente(void);
void historicoGeral(void);
void registrarTransacao(int cliente, int tipo, float valor, int tipoConta);
void comprarTitulo(void);
void sorteioCheck(void);
void realizarSorteio(void);


#endif
