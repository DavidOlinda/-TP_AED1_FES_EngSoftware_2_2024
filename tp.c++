#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pessoa
{
public:
    // Construtor da classe Pessoa
    Pessoa(int codigo, string nome, int telefone)
    {
        this->codigo = codigo;
        this->nome = nome;
        this->telefone = telefone;
    }

    // Métodos get
    int getCodigo() const { return codigo; }
    string getNome() const { return nome; }
    int getTelefone() const { return telefone; }

    // Métodos set
    void setCodigo(int codigo) { this->codigo = codigo; }
    void setNome(string nome) { this->nome = nome; }
    void setTelefone(int telefone) { this->telefone = telefone; }

private:
    int codigo;
    string nome;
    int telefone;
};

class Passageiro : public Pessoa
{
public:
    // Construtor da classe Passageiro
    Passageiro(int codigo, string nome, int telefone, string endereco, string fidelidade, int pontos_fidelidade)
        : Pessoa(codigo, nome, telefone)
    {
        this->endereco = endereco;
        this->fidelidade = fidelidade;
        this->pontos_fidelidade = pontos_fidelidade;
    }

    // Métodos get
    string getEndereco() const { return endereco; }
    string getFidelidade() const { return fidelidade; }
    int getPontosFidelidade() const { return pontos_fidelidade; }

    // Métodos set
    void setEndereco(string endereco) { this->endereco = endereco; }
    void setFidelidade(string fidelidade) { this->fidelidade = fidelidade; }
    void setPontosFidelidade(int pontos_fidelidade) { this->pontos_fidelidade = pontos_fidelidade; }

    // Método para exibir os dados do passageiro
    void exibirDados()
    {
        cout << "#### Código passageiro: " << getCodigo() << "\n";
        cout << "Nome passageiro: " << getNome() << "\n";
        cout << "Endereço do passageiro: " << endereco << "\n";
        cout << "Telefone passageiro: " << getTelefone() << "\n";
        cout << "Tem fidelidade? " << fidelidade << "\n";
        cout << "Pontos fidelidade: " << pontos_fidelidade << "\n";
    }

private:
    string endereco;
    string fidelidade;
    int pontos_fidelidade = 0;
};

class Tripulante : public Pessoa
{
public:
    // Construtor da classe Tripulante
    Tripulante(string cargo, int codigo, string nome, int telefone) : Pessoa(codigo, nome, telefone)
    {
        this->cargo = cargo;
    }

private:
    string cargo;
};

class Assento
{
public:
    // Construtor da classe Assento
    Assento(int numero_assento, string status)
    {
        this->numero_assento = numero_assento;
        this->status = status;
    }

private:
    int numero_assento;
    string status; // ocupado ou livre
};

class Voo
{
public:
    // Construtor da classe Voo
    Voo(int codigo_voo, int data, int hora, string origem, string destino, int codigo_aviao, string status, double tarifa, vector<Tripulante *> tripulacao, vector<Assento> assentos)
    {
        this->codigo_voo = codigo_voo;
        this->data = data;
        this->hora = hora;
        this->origem = origem;
        this->destino = destino;
        this->codigo_aviao = codigo_aviao;
        this->status = status;
        this->tarifa = tarifa;
        this->tripulacao = tripulacao;
        this->assentos = assentos;
    }

private:
    int codigo_voo;
    int data;
    int hora;
    string origem;
    string destino;
    int codigo_aviao;
    string status; // ativo ou inativo
    double tarifa;
    vector<Tripulante *> tripulacao;
    vector<Assento> assentos;
};

class Reserva
{
public:
    // Construtor da classe Reserva
    Reserva(Voo *voo, Assento *assento, Passageiro *passageiro)
    {
        this->voo = voo;
        this->assento = assento;
        this->passageiro = passageiro;
    }

private:
    Voo *voo;
    Assento *assento;
    Passageiro *passageiro;
};

// Função para ver os passageiros
void ver_Passageiro(const vector<Passageiro *> &passageiros)
{
    for (const auto &pessoa : passageiros)
    {
        pessoa->exibirDados();
    }
}

// Função para cadastrar um passageiro
void cadastrar_passageiro(vector<Passageiro *> &passageiros)
{
    int codigo;
    string nome, endereco, fidelidade;
    int telefone;

    cout << "Digite o código do passageiro: " << "\n";
    cin >> codigo;
    for (const auto &pessoa : passageiros)
    {
        if (pessoa->getCodigo() == codigo)
        {
            cout << "Código já existe!" << "\n";
            return;
        }
    }

    cout << "Digite o nome do passageiro: " << "\n";
    cin >> nome;

    cout << "Digite o endereço do passageiro: " << "\n";
    cin >> endereco;

    cout << "Digite o telefone do passageiro: " << "\n";
    cin >> telefone;

    cout << "Tem fidelidade: (Sim ou Não)" << "\n";
    cin >> fidelidade;

    Passageiro *passageiro = new Passageiro(codigo, nome, telefone, endereco, fidelidade, 0);
    passageiros.push_back(passageiro);
}

void menu(){
    cout << "****** Bem vindo a Companhia Aérea Voo Seguro ****** " << "\n";
    cout << "-------------------------------------------" << "\n";
    cout << "Escolha uma opcao: " << "\n";
    cout << "1. Cadastrar passageiro" << "\n";
    cout << "2. Ver passageiros" << "\n";
    cout << "0. Sair" << "\n";
}
int main()
{
    vector<Tripulante *> tripulantes;
    vector<Passageiro *> passageiros;
    vector<Voo *> voos;

    
    int opcao;
    do
    {
        menu();
        cin >> opcao;
        switch (opcao)
        {
        case 0: 
            cout << "Saindo...";
            break;
        case 1:
            cadastrar_passageiro(passageiros);
            break;
        case 2: 
            ver_Passageiro(passageiros);
            break;
        default:
            cout << "Opcao invalida!";
            break;
        }
    } while (opcao != 0);
    
    

    // Liberar memória alocada
    for (auto &p : passageiros)
    {
        delete p;
    }

    return 0;
}
