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
    Tripulante(int codigo, string nome, int telefone, string cargo)
        : Pessoa(codigo, nome, telefone), cargo(cargo) {}
    // Métodos get
    string getCargo() const { return cargo; }
    // Métodos set
    void setCargo(string cargo) { this->cargo = cargo; }
    // Método para exibir os dados do tripulante
    void exibirDados()
    {
        cout << "#### Código tripulante: " << getCodigo() << "\n";
        cout << "Nome: " << getNome() << "\n";
        cout << "Telefone: " << getTelefone() << "\n";
        cout << "Cargo: " << cargo << "\n";
    }
private:
    string cargo;
};
// Função para verificar se um código já existe
bool codigoExiste(const vector<Pessoa *> &pessoas, int codigo)
{
    for (const auto &p : pessoas)
    {
        if (p->getCodigo() == codigo)
            return true;
    }
    return false;
}
// Função para cadastrar um passageiro
void cadastrar_passageiro(vector<Passageiro *> &passageiros)
{
    int codigo, telefone;
    string nome, endereco, fidelidade;
    cout << "Digite o código do passageiro: " << "\n";
    cin >> codigo;
    // Verificar se o código já existe
    if (codigoExiste(reinterpret_cast<const vector<Pessoa *> &>(passageiros), codigo))
    {
        cout << "Código já existe!\n";
        return;
    }
    cout << "Digite o nome do passageiro: " << "\n";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o endereço do passageiro: " << "\n";
    getline(cin, endereco);
    cout << "Digite o telefone do passageiro: " << "\n";
    cin >> telefone;
    cout << "Tem fidelidade? (Sim ou Não): " << "\n";
    cin.ignore();
    getline(cin, fidelidade);
    // Criar um novo passageiro e adicioná-lo ao vetor
    Passageiro *passageiro = new Passageiro(codigo, nome, telefone, endereco, fidelidade, 0);
    passageiros.push_back(passageiro);
    cout << "Passageiro cadastrado com sucesso!\n";
}
// Função para ver os passageiros
void ver_passageiros(const vector<Passageiro *> &passageiros)
{
    if (passageiros.empty())
    {
        cout << "Nenhum passageiro cadastrado.\n";
        return;
    }
    // Exibir os dados de todos os passageiros
    for (const auto &p : passageiros)
    {
        p->exibirDados();
        cout << "--------------------------------\n";
    }
}
// Função para cadastrar um tripulante
void cadastrar_tripulante(vector<Tripulante *> &tripulantes)
{
    int codigo, telefone;
    string nome, cargo;
    cout << "Digite o código do tripulante: " << "\n";
    cin >> codigo;
    // Verificar se o código já existe
    if (codigoExiste(reinterpret_cast<const vector<Pessoa *> &>(tripulantes), codigo))
    {
        cout << "Código já existe!\n";
        return;
    }
    cout << "Digite o nome do tripulante: " << "\n";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o telefone do tripulante: " << "\n";
    cin >> telefone;
    cout << "Digite o cargo do tripulante: " << "\n";
    cin.ignore();
    getline(cin, cargo);
    // Criar um novo tripulante e adicioná-lo ao vetor
    Tripulante *tripulante = new Tripulante(codigo, nome, telefone, cargo);
    tripulantes.push_back(tripulante);
    cout << "Tripulante cadastrado com sucesso!\n";
}
// Função para ver os tripulantes
void ver_tripulantes(const vector<Tripulante *> &tripulantes)
{
    if (tripulantes.empty())
    {
        cout << "Nenhum tripulante cadastrado.\n";
        return;
    }
    // Exibir os dados de todos os tripulantes
    for (const auto &t : tripulantes)
    {
        t->exibirDados();
        cout << "--------------------------------\n";
    }
}
// Menu principal
void menu()
{
    cout << "****** Bem vindo a Companhia Aérea Voo Seguro ****** " << "\n";
    cout << "-------------------------------------------" << "\n";
    cout << "Escolha uma opção: " << "\n";
    cout << "1. Cadastrar passageiro" << "\n";
    cout << "2. Ver passageiros" << "\n";
    cout << "3. Cadastrar tripulante" << "\n";
    cout << "4. Ver tripulantes" << "\n";
    cout << "0. Sair" << "\n";
}
int main()
{   
    setlocale(LC_ALL, "pt_BR.UTF-8");
    vector<Passageiro *> passageiros;
    vector<Tripulante *> tripulantes;
    int opcao;
    do
    {
        menu();
        cin >> opcao;
        switch (opcao)
        {
        case 0:
            cout << "Saindo...\n";
            break;
        case 1:
            cadastrar_passageiro(passageiros);
            break;
        case 2:
            ver_passageiros(passageiros);
            break;
        case 3:
            cadastrar_tripulante(tripulantes);
            break;
        case 4:
            ver_tripulantes(tripulantes);
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
    // Liberar memória alocada
    for (auto &p : passageiros)
        delete p;
    for (auto &t : tripulantes)
        delete t;
    return 0;
}