#include <iostream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;
class Pessoa
{
public:
    // Construtor da classe Pessoa
    Pessoa(int codigo, string nome, string telefone) // Alterado de int para string
    {
        this->codigo = codigo;
        this->nome = nome;
        this->telefone = telefone;
    }
    // Métodos get
    int getCodigo() const { return codigo; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; } // Alterado de int para string
    // Métodos set
    void setCodigo(int codigo) { this->codigo = codigo; }
    void setNome(string nome) { this->nome = nome; }
    void setTelefone(string telefone) { this->telefone = telefone; } // Alterado de int para string

private:
    int codigo;
    string nome;
    string telefone; // Alterado de int para string
};
class Passageiro : public Pessoa
{
public:
    // Construtor da classe Passageiro
    Passageiro(int codigo, string nome, string telefone, string endereco, string fidelidade, int pontos_fidelidade)
        : Pessoa(codigo, nome, telefone) // Alterado de int para string
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
        cout << "#### Codigo passageiro: " << getCodigo() << "\n";
        cout << "Nome passageiro: " << getNome() << "\n";
        cout << "Endereco do passageiro: " << endereco << "\n";
        cout << "Telefone passageiro: " << getTelefone() << "\n"; // Alterado de int para string
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
    Tripulante(int codigo, string nome, string telefone, string cargo)
        : Pessoa(codigo, nome, telefone), cargo(cargo) {} // Alterado de int para string
    // Métodos get
    string getCargo() const { return cargo; }
    // Métodos set
    void setCargo(string cargo) { this->cargo = cargo; }
    // Método para exibir os dados do tripulante
    void exibirDados()
    {
        cout << "#### Código tripulante: " << getCodigo() << "\n";
        cout << "Nome: " << getNome() << "\n";
        cout << "Telefone: " << getTelefone() << "\n"; // Alterado de int para string
        cout << "Cargo: " << cargo << "\n";
    }

private:
    string cargo;
};

class Assento
{
private:
    int numero_assento;
    string status; // "ocupado" ou "livre"

public:
    Assento(int numero_assento, string status)
    {
        this->numero_assento = numero_assento;
        this->status = status;
    }

    string getStatus() const
    {
        return status;
    }

    int getCodigo() const
    {
        return numero_assento;
    }

    void setStatusBusy()
    {
        this->status = "ocupado";
    }

    void setStatusFree()
    {
        this->status = "livre";
    }
};
class Voo
{
private:
    int codigo_voo;
    string data;
    string hora; // Alterado de int para string
    string origem;
    string destino;
    string status; // "ativo" ou "inativo"
    double tarifa;
    vector<Tripulante *> tripulacao;
    vector<Assento> assentos;

public:
    Voo(int codigo_voo, string data, string hora, string origem, string destino, string status, double tarifa, vector<Tripulante *> tripulacao, vector<Assento> assentos)
    {
        this->codigo_voo = codigo_voo;
        this->data = data;
        this->hora = hora;
        this->origem = origem;
        this->destino = destino;
        this->status = status;
        this->tarifa = tarifa;
        this->tripulacao = tripulacao;
        this->assentos = assentos;
    }
    int getCodigo_voo() const
    {
        return codigo_voo;
    }

    // Método atualizado para retornar uma referência ao vetor de assentos
    vector<Assento> &getAssentos()
    {
        return assentos;
    }

    vector<Tripulante *> &getTripulantes()
    {
        return tripulacao;
    }

    void exibirDados() const
    {
        cout << "****** Código do Voo: " << codigo_voo << "\n";
        cout << "Data: " << data << "\n";
        cout << "Hora: " << hora << "\n"; // Atualizado para string
        cout << "Origem: " << origem << "\n";
        cout << "Destino: " << destino << "\n";
        cout << "Status: " << status << "\n";
        cout << "Tarifa: " << tarifa << "\n";
        cout << "Tripulantes nesse voo: " << "\n";
        for (auto tripulante : tripulacao)
        {
            cout << tripulante->getCargo() << " com código " << tripulante->getCodigo() << " e nome: " << tripulante->getNome() << "\n";
        }
    }

    void ativarAviao()
    {
        this->status = "ativo";
    }

    void adicionarTripulante(Tripulante *tripulante)
    {
        tripulacao.push_back(tripulante);
    }
};

class Reserva
{
private:
    Voo *voo;
    Assento *assento;
    Passageiro *passageiro;

public:
    Reserva(Voo *voo, Assento *assento, Passageiro *passageiro)
    {
        this->voo = voo;
        this->assento = assento;
        this->passageiro = passageiro;
    }

    Voo *getVoo() const { return this->voo; }

    Assento *getAssento() const { return this->assento; }

    Passageiro *getPassageiro() const { return this->passageiro; }
};
// Função para cadastrar um passageiro
// Função para cadastrar um passageiro
void cadastrar_passageiro(vector<Passageiro *> &passageiros)
{
    int codigo;
    string nome, endereco, fidelidade, telefone; // Alterado de int para string
    cout << "Digite o codigo do passageiro: " << "\n";
    cin >> codigo;
    // Verificar se o código já existe
    for (auto pessoa : passageiros)
    {
        if (pessoa->getCodigo() == codigo)
        {
            cout << "Pessoa com o codigo existente!\n";
            return;
        }
    }

    cout << "Digite o nome do passageiro: " << "\n";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o endereco do passageiro: " << "\n";
    getline(cin, endereco);
    cout << "Digite o telefone do passageiro: " << "\n";
    getline(cin, telefone); // Alterado para getline em vez de cin
    cout << "Tem fidelidade? (Sim ou Nao): " << "\n";
    getline(cin, fidelidade);
    // Criar um novo passageiro e adicionar ao vetor
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
// Função para cadastrar um tripulante
void cadastrar_tripulante(vector<Tripulante *> &tripulantes)
{
    int codigo;
    string nome, cargo, telefone; // Alterado de int para string
    cout << "Digite o codigo do tripulante: " << "\n";
    cin >> codigo;
    // Verificar se o código já existe
    for (auto pessoa : tripulantes)
    {
        if (pessoa->getCodigo() == codigo)
        {
            cout << "Pessoa com o codigo existente!\n";
            return;
        }
    }

    cout << "Digite o nome do tripulante: " << "\n";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o telefone do tripulante: " << "\n";
    getline(cin, telefone); // Alterado para getline em vez de cin
    cout << "Digite o cargo do tripulante: " << "\n";
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
void cadastrar_Voo(vector<Voo *> &voos)
{
    int num_assentos, codigo_voo;
    double tarifa;
    string origem, destino, data, hora;

    cout << "Digite o codigo do voo: " << "\n";
    cin >> codigo_voo;
    for (const auto &p : voos)
    {
        if (p->getCodigo_voo() == codigo_voo)
        {
            cout << "Voo ja cadastrado!" << "\n";
            return;
        }
    }
    cout << "Digite a data desejada: " << "\n";
    cin >> data;
    cout << "Digite a hora desejada (hh:mm): " << "\n"; // Alterado para string
    cin >> hora;
    cin.ignore();

    cout << "Digite a origem: " << "\n";
    getline(cin, origem);

    cout << "Digite o destino: " << "\n";
    getline(cin, destino);

    cout << "Digite a tarifa: " << "\n";
    cin >> tarifa;
    cin.ignore();

    vector<Tripulante *> tripulacao;

    cout << "Numero de assentos no aviao: " << "\n";
    cin >> num_assentos;
    vector<Assento> assentos;
    for (int i = 0; i < num_assentos; i++)
    {
        Assento assento(i + 1, "desocupado");
        assentos.push_back(assento);
    }

    Voo *voo = new Voo(codigo_voo, data, hora, origem, destino, "inativo", tarifa, tripulacao, assentos);
    voos.push_back(voo);

    cout << "Voo cadastrado com sucesso!\n";
}

void ver_Voos(const vector<Voo *> &voo)
{
    if (voo.empty())
    {
        cout << "Nenhum voo cadastrado.\n";
        return;
    }

    for (const auto &p : voo)
    {
        p->exibirDados();
        cout << "--------------------------------\n";
    }
}
void agregar_tripulante(vector<Tripulante *> &tripulantes, vector<Voo *> &voos)
{
    int codigo_voo, codigo_tripulante;
    Voo *voo_selecionado = nullptr;
    cout << "Qual o codigo do voo para adicionar o tripulante: " << "\n";
    cin >> codigo_voo;

    for (auto voo : voos)
    {
        if (voo->getCodigo_voo() == codigo_voo)
        {
            voo_selecionado = voo;
            break;
        }
    }

    if (voo_selecionado == nullptr)
    {
        cout << "Esse voo nao existe!" << "\n";
        return;
    }

    cout << "Qual o codigo do tripulante para adicionar ao voo: " << "\n";
    cin >> codigo_tripulante;

    Tripulante *tripulante_atual = nullptr;
    for (auto tripulante : tripulantes)
    {
        if (tripulante->getCodigo() == codigo_tripulante)
        {
            tripulante_atual = tripulante;
            break;
        }
    }

    if (tripulante_atual == nullptr)
    {
        cout << "Esse tripulante nao existe!" << "\n";
        return;
    }

    for (auto tripulante : voo_selecionado->getTripulantes())
    {
        if (tripulante->getCargo() == tripulante_atual->getCargo())
        {
            cout << "Esse tripulante nao pode ser adicionado! Ja existe um membro com esse cargo." << "\n";
            return;
        }
    }

    voo_selecionado->adicionarTripulante(tripulante_atual);

    if (voo_selecionado->getTripulantes().size() == 3)
    {
        voo_selecionado->ativarAviao();
    }
}
void criarReserva(vector<Passageiro *> &passageiros, vector<Voo *> &voos, vector<Reserva *> &reservas)
{
    Passageiro *passageiro_atual = nullptr;
    Voo *voo_selecionado = nullptr;
    int codigo_passageiro, codigo_voo;

    cout << "Qual o código do avião: " << "\n";
    cin >> codigo_voo;

    for (auto voo : voos)
    {
        if (voo->getCodigo_voo() == codigo_voo)
        {
            voo_selecionado = voo;
            break;
        }
    }

    if (voo_selecionado == nullptr)
    {
        cout << "Esse voo não existe!" << "\n";
        return;
    }

    cout << "Qual o código do passageiro: " << "\n";
    cin >> codigo_passageiro;

    for (auto passageiro : passageiros)
    {
        if (passageiro->getCodigo() == codigo_passageiro)
        {
            passageiro_atual = passageiro;
            break;
        }
    }

    if (passageiro_atual == nullptr)
    {
        cout << "Esse passageiro não existe!" << "\n";
        return;
    }

    cout << "Em qual assento você deseja sentar? " << "\n";

    int opcao_assento;
    int i = 1;
    for (auto &assento : voo_selecionado->getAssentos())
    {
        if (assento.getStatus() == "ocupado")
        {
            cout << "# ";
        }
        else
        {
            cout << i << " ";
        }
        i++;
    }
    cout << "\n";
    cin >> opcao_assento;

    // Ajustando índice para zero-based
    opcao_assento--;

    if (voo_selecionado->getAssentos().at(opcao_assento).getStatus() == "ocupado")
    {
        cout << "Esse assento está ocupado!" << "\n";
        return;
    }

    voo_selecionado->getAssentos().at(opcao_assento).setStatusBusy();

    Reserva *reserva = new Reserva(voo_selecionado, &voo_selecionado->getAssentos().at(opcao_assento), passageiro_atual);
    reservas.push_back(reserva);
    cout << "Assento reservado com sucesso!" << "\n";
}
void ver_Reservas(const vector<Reserva *> &reservas)
{
    if (reservas.empty())
    {
        cout << "Nenhuma reserva cadastrada.\n";
        return;
    }

    for (const auto reserva : reservas)
    {
        cout << reserva->getVoo()->getCodigo_voo() << "\n";
        cout << reserva->getPassageiro()->getNome() << "\n";
        cout << reserva->getAssento()->getStatus() << "\n";
        cout << reserva->getAssento()->getCodigo() << "\n";
        cout << "--------------------------------\n";
    }
}
void ver_Voo_passageiro(vector<Reserva *> &reservas)
{
    int codigo_passageiro;
    cout << "Qual o codigo do passageiro: " << "\n";
    cin >> codigo_passageiro;

    int i = 0;
    for (auto &reserva : reservas)
    {
        if (reserva->getPassageiro()->getCodigo() == codigo_passageiro)
        {
            cout << "Codigo do Voo: " << reserva->getVoo()->getCodigo_voo() << "\n";
            cout << "Codigo do Assento: " << reserva->getAssento()->getCodigo() << "\n";
            cout << "------------------------------" << "\n";

            i++;
        }
    }
    if (i == 0)
    {
        cout << "--------------------------" << "\n";
        cout << "Passageiro inexistente ou sem reservas\n";
    }
}
// Menu principal
void menu()
{
    cout << "****** Bem vindo a Companhia Aerea Voo Seguro ****** " << "\n";
    cout << "-------------------------------------------" << "\n";
    cout << "Escolha uma opcao: " << "\n";
    cout << "1. Cadastrar passageiro" << "\n";
    cout << "2. Ver passageiros" << "\n";
    cout << "3. Cadastrar tripulante" << "\n";
    cout << "4. Ver tripulantes" << "\n";
    cout << "5. Cadastrar voo" << "\n";
    cout << "6. Ver voos" << "\n";
    cout << "7. Cadastrar tripulante no Voo" << "\n";
    cout << "8. Reservar" << "\n";
    cout << "9. Ver reserva" << "\n";
    cout << "10. Ver passageiros no voo" << "\n";
    cout << "0. Sair" << "\n";
}
int main()
{
    setlocale(LC_ALL, "");
    vector<Reserva *> reservas;
    vector<Passageiro *> passageiros;
    vector<Tripulante *> tripulantes;
    vector<Voo *> voos;
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
        case 5:
            cadastrar_Voo(voos);
            break;
        case 6:
            ver_Voos(voos);
            break;
        case 7:
            agregar_tripulante(tripulantes, voos);
            break;
        case 8:
            criarReserva(passageiros, voos, reservas);
            break;
        case 9:
            ver_Reservas(reservas);
            break;
        case 10: 
            ver_Voo_passageiro(reservas);
            break;
        default:
            cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    for (auto &p : passageiros)
        delete p;
    for (auto &t : tripulantes)
        delete t;
    return 0;
}