#ifndef __CONTAS_FUNCTIONS
#define __CONTAS_FUNCTIONS
#include <stdbool.h>

#define TITULAR_SIZE 50
#define CONTA_FORMAT "%d,%lf,'%s'\n"
#define CONTAS_PATH "./data/contas.csv"
#define TEMP_PATH "./data/contas.temp"
#define CONTAS_BUFFER_SIZE 512

struct Conta{
  char titular[TITULAR_SIZE];
  double saldo;
  int numero;
};

/*
 * PROCURA CONTA E RETORNA TRUE OR FALSE
 * THROW: ERRO_ABERTURA_ARQUIVO
 */
bool existeConta(int num);

/*
 * CONVERTE CSV STRING PARA struct Conta, JOGA ERRO ERRO_FORMATO_CONTA_INVALIDO CASO O FORMATO
 * SEJA INVALIDO.
 *
 * THROW: ERROR_FORMATO_CONTA_INVALIDO
 */
int procuraConta(int num, struct Conta* dest);
/*
 * REALIZA DEBITO
 *
 * THROW: ERRO_VALOR_INVALIDO,
 *        ERRO_CONTA_NAO_ENCONTRADA,
 *        ERROR_SALDO_INSUFICIENTE
 *        ERRO_ABERTURA_ARQUIVO
 */
int realizaDebito(int num, double valor);
/*
 * REALIZA CREDITO
 *
 * THROW: ERRO_VALOR_INVALIDO,
 *        ERRO_CONTA_NAO_ENCONTRADA,
 *        ERRO_ABERTURA_ARQUIVO
 */
int realizaCredito(int num, double valor);
/*
 * REALIZA TRANSFERENCIA
 *
 * THROW: ERRO_VALOR_INVALIDO,
 *        ERRO_CONTA_NAO_ENCONTRADA,
 *        ERROR_SALDO_INSUFICIENTE
 *        ERRO_ABERTURA_ARQUIVO
 */
int realizaTransferencia(int numSaida, int numEntrada, double valor);
/*
 * PROCURA CONTA NO ARQUIVO ./data/contas.csv, CASO ENCONTRE RETORNA A LINHA E CASO DEST DIFERENTE DE NULL COPIA A STRUCT PARA DEST
 * 
 * THROW: ERRO_CONTA_NAO_ENCONTRADA
 */
struct Conta parseConta(char* contastr);
/*
 * EXCLUI CONTA POR NUMERO.
 *
 * THROW: ERRO_ABERTURA_ARQUIVO
 *        ERRO_CONTA_NAO_ENCONTRADA
 */
int excluiConta(int num);
/*
 * ATUALIZA CONTA JA EXISTENTE
 * THROW: ERRO_ABERTURA_ARQUIVO
 *        ERRO_CONTA_NAO_ENCONTRADA
 *
 */
int atualizaConta(struct Conta* conta);
/*
 * CRIA CONTA NAO EXISTENTE
 *
 * THROW: ERRO_ABERTURA_ARQUIVO
 *        ERRO_CONTA_JA_EXISTE
 */
int criaConta(struct Conta* conta);
#endif

