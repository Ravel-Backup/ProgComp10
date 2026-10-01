#include <iostream>

using namespace std;

//Protótipos: 
	//Exercícios:
void comprasVerduras();
void arraysDimencoesSeparadas();
void vetoresSomados();

int soma_dosVetores(int []);

	//Atividades
void modificarValor();
void mediaParcial();
void operarVetores();
void provocar_memoryLeak();

//Funções:

int main() {
	// Exercício 01:
	comprasVerduras();

	// Exercício 02:
	arraysDimencoesSeparadas();

	// Exercício 03:
	vetoresSomados();

	// Atividades de fixação:
	// Atividade 01: 
	modificarValor();

	// Atividade 02:
	mediaParcial();

	// Atividade 03:
	operarVetores();

	// Atividade 04:
	provocar_memoryLeak(); // Comportamento indefinido proporsitalmente.
}

void comprasVerduras() {
	float verduras[3] = {};
	cout << "Prezado Cliente,\n"
		<< "Digite a quantidade de quilos desejados:";

	cout << "\nAlface: "; cin >> verduras[0];
	cout << "\nBeterraba: "; cin >> verduras[1];
	cout << "\nCenoura: "; cin >> verduras[2];

	float alface = 1.5, beterraba = 2.0, cenoura = 1.0;

	verduras[0] = verduras[0] * alface;
	verduras[1] = verduras[1] * beterraba;
	verduras[2] = verduras[2] * cenoura;

	cout << "Resumo da compra\n"
		<< "_________________";
	cout << "\nAlface: R$" << verduras[0];
	cout << "\nBeterraba: R$" << verduras[1];
	cout << "\nCenoura: R$" << verduras[2];
	cout << "\n_________________";
	cout << "\nTotal: R$" << verduras[0]+verduras[1]+verduras[2];
}

void arraysDimencoesSeparadas() {
	int vetA[5] = { 10,20,30,40,50 };
	int vetB[5] = { 10,20 };
	int vetC[5] = { 0,0,30 };
	cout << "Conteudo dos vetores:\n"
		<< "_________________";
	cout << "\nVetor A: ";
	for (int i = 0; i < 5; ++i) {
		cout << vetA[i] << " ";
	}
	cout << "\nVetor B: ";
	for (int i = 0; i < 5; ++i) {
		cout << vetB[i] <<  " ";
	}
	cout << "\nVetor C: ";
	for (int i = 0; i < 5; ++i) {
		cout << vetC[i] << " ";
	}
}

void vetoresSomados() {
	int vet[5] = {};
	cout << "Digite 5 valores: "; cin >> vet[0] >> vet[1] >> vet[2] >> vet[3] >> vet[4];
	cout << "A soma do vetor é " << soma_dosVetores(vet);
}
int soma_dosVetores(int vet[]) {
	int somatorio = 0;
	for (int i = 0; i < 5; ++i) {
		somatorio += vet[i];
	}
	return somatorio;
}

void modificarValor() {
	int vetor[5] = { 12, 40, 80, 50, 42 };
	int posicao = 0;
	cout << "\nVetor: ";
	for (int i = 0; i < 5; ++i) {
		cout << vetor[i] << " ";
	}
	cout << "\n"<< "_________________" 
		<< "\nAlterar a posicao: "; cin >> posicao;
	cout << "\nNovo valor: "; cin >> vetor[posicao];
	cout << "\n" << "_________________"
		<< "\nVetor: ";
	for (int i = 0; i < 5; ++i) {
		cout << vetor[i] << " ";
	}
}


void mediaParcial() {
	float notas[3] = {};
	cout << "Media Parcial:\n"
		<< "_________________";
	cout << "\nDigite os valores das notas: ";
	for (int i = 0; i < 3; ++i) {
		cin >> notas[i];
	}
	cout << "\n_________________";
	float media_modeloAntigo = ((notas[0] * 2) + (notas[1] * 3) + (notas[2] * 4)) / 9;
	float media_aritmetica = (notas[0] + notas[1] + notas[2]) / 3;
	cout << "\nResultado da media pelo modelo antigo: " << media_modeloAntigo;
	cout << "\nResultado da media pelo modelo novo: " << media_aritmetica;
}

void operarVetores() {
	double vetor[3] = {};

	cout << "Operandos os vetores:\n"
		<< "_________________";
	cout << "\nDigite os valores de 3 flutuantes: ";
	for (int i = 0; i < 3; ++i) {
		cin >> vetor[i];
	}
	cout << "\n_________________";

	double resultado = vetor[0] * (vetor[2] / vetor[1]);
	cout << "\nResultado da multipacacao do primeiro vetor pela divisao"
		<< "\ndo terceiro vetor pelo segundo vetor: " << resultado;
}

void provocar_memoryLeak() {
	int vetor[5] = { 10,20,30,40,50 };
	vetor[5] = 60; // Erro EXTREMAMENTE Grave; 
	cout << "Forcando um armazenamento fora de limite de memoria separada pelo OS:\n"
		<< "_________________";
	cout << "\nVetor: ";
	for (int i = 0; i < 6; ++i) {
		cout<<vetor[i];
	}
	cout << "\nUltrapassando os limites de proposito ate o sistema encerrar: ";
	for (int i = 0; i < 5000; ++i) {
		vetor[i] = i;
		cout << vetor[i];
	}

	// A posição para crash nem sempre será a mesma.
	// O sistema operacional enxerra a execução justamente porque antes de iniciar qualquer programa, ele reserva, aleatoriamente
	// um espaço reservado numa memoria virtual justamente para o sistema evitar vazamentos de dados de programa A para B.
	// sem esse espaço aleatório reservado o sistemas operacional se torna mais inseguro.
	// Quando um programa A salva um valor de um vetor dentro do seu espaço resevado, é justo que isso seja feito em endereços
	// que seguem uma sequencia, exemplo, 0x0100A10 -> 00x0100A14 -> 0x0100A18 e etc, se o valor o do vetor precisar armazenar em
	// 0x0100C10 mas esse valor estiver com outro programa que pode ser qualquer um, o sistema operacional identifica a violação
	// e o execerra antes mesmo de tal ser executado por segurança.
	// Desde modo, tentar armazenar uma informação fora do espaço reservado resulta em crash ou qualquer outro resultado, não é garantido.
}