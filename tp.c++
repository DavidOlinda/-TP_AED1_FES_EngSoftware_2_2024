#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <fstream>
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
    string getData() const { return data; }
    string getHora() const { return hora; }
    string getOrigem() const { return origem; }
    string getDestino() const { return destino; }
    int getCodigo_voo() const { return codigo_voo; }
    double getTarifa() const { return tarifa; }
    string getStatus() const { return status; }
    vector<Assento> &getAssentos() { return assentos; }
    vector<Tripulante *> &getTripulantes() { return tripulacao; }
    void ativarAviao() { this->status = "ativo"; }
    void adicionarTripulante(Tripulante *tripulante) { tripulacao.push_back(tripulante); }

    void exibirDados() const
    {
        cout << "#-#-#-#-# Código do Voo: " << codigo_voo << "#-#-#-#-#\n";
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
};

class Reserva
{
private:
    int codigo;
    string status = "aberta";
    Voo *voo;
    Assento *assento;
    Passageiro *passageiro;

public:
    Reserva(Voo *voo, Assento *assento, Passageiro *passageiro, int codigo)
    {
        this->voo = voo;
        this->assento = assento;
        this->passageiro = passageiro;
        this->codigo = codigo;
    }

    Voo *getVoo() const { return this->voo; }
    int getCodigo() const { return this->codigo; }
    string getStatus() const { return this->status; }
    void fechar() { this->status = "fechada"; }
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
void criarReserva(vector<Passageiro *> &passageiros, vector<Voo *> &voos, vector<Reserva *> &reservas, int codigo)
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

    Reserva *reserva = new Reserva(voo_selecionado, &voo_selecionado->getAssentos().at(opcao_assento), passageiro_atual, codigo);
    reservas.push_back(reserva);
    cout << "Assento reservado com sucesso!" << "\n";

    bool piloto;
    bool copiloto;
    for (auto tripulante : voo_selecionado->getTripulantes())
    {
        if (tripulante->getCargo() == "piloto")
        {
            piloto = true;
        }
        else if (tripulante->getCargo() == "copiloto")
        {
            copiloto = true;
        }
    }
    if (piloto == true and copiloto == true)
    {
        voo_selecionado->ativarAviao();
        return;
    }
    if (voo_selecionado->getStatus() == "inativo")
    {
        cout << "**********************************************" << "\n";
        cout << "Aviso: Esse voo está inativo!" << "\n";
        return;
    }
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
        cout << "Codigo da reserva: " << reserva->getCodigo() << "\n";
        cout << "Codigo do voo: " << reserva->getVoo()->getCodigo_voo() << "\n";
        cout << "Nome do passageiro: " << reserva->getPassageiro()->getNome() << "\n";
        cout << "Status do assento: " << reserva->getAssento()->getStatus() << "\n";
        cout << "Codigo do assento: " << reserva->getAssento()->getCodigo() << "\n";
        cout << "Status da reserva: " << reserva->getStatus() << "\n";
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
        if (reserva->getPassageiro()->getCodigo() == codigo_passageiro and reserva->getStatus() == "aberta")
        {
            cout << "Codigo da reserva: " << reserva->getCodigo() << "\n";
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
bool comparadorCodigo(int voo_codigo, string prefix)
{
    string codigo_str = to_string(voo_codigo);
    return codigo_str.substr(0, prefix.size()) == prefix;
}

bool comparadorNome(string nome, string prefix)
{
    return nome.substr(0, prefix.size()) == prefix;
}
void pesquisar_Voo(vector<Voo *> &voos)
{
    string codigo_aviao;
    cout << "Qual codigo do aviao: " << "\n";
    cin >> codigo_aviao;

    for (auto &voo : voos)
    {
        if (comparadorCodigo(voo->getCodigo_voo(), codigo_aviao))
        {
            voo->exibirDados();
        }
    }
}
void pesquisarPessoas(vector<Passageiro *> &passageiros)
{
    string codigonome_passageiro;
    cout << "Qual é o nome ou codigo do passageiro" << "\n";
    cin >> codigonome_passageiro;

    for (auto &passageiro : passageiros)
    {
        if (comparadorCodigo(passageiro->getCodigo(), codigonome_passageiro) || comparadorNome(passageiro->getNome(), codigonome_passageiro))
        {
            passageiro->exibirDados();
        }
    }
}
void pesquisarTripulante(vector<Tripulante *> &tripulantes)
{
    string codigo_tripulante;
    cout << "Qual é o nome ou codigo do tripulante" << "\n";
    cin >> codigo_tripulante;

    for (auto &tripulante : tripulantes)
    {
        if (comparadorCodigo(tripulante->getCodigo(), codigo_tripulante) || comparadorNome(tripulante->getNome(), codigo_tripulante))
        {
            tripulante->exibirDados();
        }
    }
}
void reservaBaixa(vector<Reserva *> &reservas)
{
    int cod_reserva;
    cout << "Qual o código da reserva: " << "\n";
    cin >> cod_reserva;

    for (auto &reserva : reservas)
    {
        if (reserva->getCodigo() == cod_reserva)
        {
            if (reserva->getStatus() == "fechado")
            {
                cout << "**********************************************" << "\n";
                cout << "Aviso: Essa reserva ja foi fechada\n";
                return;
            }

            if (reserva->getPassageiro()->getFidelidade() == "sim")
            {
                reserva->getPassageiro()->setPontosFidelidade(reserva->getPassageiro()->getPontosFidelidade() + 10);

                cout << "**********************************************" << "\n";
                cout << "Aviso: 10 pontos para fidelidade!\n";
            }

            reserva->fechar();
            reserva->getAssento()->setStatusFree();
            cout << "Aviso: Valor final R$ " << reserva->getVoo()->getTarifa() << endl;
            cout << "Aviso: Reserva Fechada com sucesso!\n";
            break;
        }
    }
}

// Menu principal
void menu()
{
    cout << "**********************************************" << "\n";
    cout << "*                                            *" << "\n";
    cout << "*    Bem-vindo à Companhia Aérea Voo Seguro  *" << "\n";
    cout << "*                                            *" << "\n";
    cout << "**********************************************" << "\n";
    cout << "-----------------------------------------------" << "\n";
    cout << "Escolha uma opcao: " << "\n";
    cout << "\n";
    cout << "Gestão:\n";
    cout << " 1. Cadastrar voo" << "\n";
    cout << " 2. Cadastrar passageiro" << "\n";
    cout << " 3. Cadastrar tripulante" << "\n";
    cout << " 4. Cadastrar tripulante em Voo" << "\n";
    cout << " 5. Cadastrar Reserva" << "\n";

    cout << "Visualização:\n";
    cout << " 6. Ver voos" << "\n";
    cout << " 7. Ver passageiros" << "\n";
    cout << " 8. Ver tripulantes" << "\n";
    cout << " 9. Ver reserva" << "\n";
    cout << " 10. Ver Voos de passageiro" << "\n";

    cout << "Pesquisa:\n";
    cout << " 11. Pesquisar Voos" << "\n";
    cout << " 12. Pesquisar Passageiros" << "\n";
    cout << " 13. Pesquisar Tripulante" << "\n";

    cout << "Pagamento:\n";
    cout << " 14. Dar baixa em reserva" << "\n";

    cout << " 0. Sair" << "\n";
    cout << "\n";
    cout << "-----------------------------------------------" << "\n";
}

// Funções para salvar e carregar dados
void salvarDados(const vector<Passageiro *> &passageiros, const vector<Tripulante *> &tripulantes,
                 const vector<Voo *> &voos, const vector<Reserva *> &reservas)
{
    ofstream arquivo("dados.bin", ios::binary | ios::out);
    if (!arquivo)
    {
        cerr << "Erro ao abrir arquivo para salvar dados." << endl;
        return;
    }

    // Salvar passageiros
    size_t tamanho = passageiros.size();
    arquivo.write((char *)&tamanho, sizeof(tamanho));
    for (auto passageiro : passageiros)
    {
        int codigo = passageiro->getCodigo();
        arquivo.write((char *)&codigo, sizeof(codigo));

        size_t len = passageiro->getNome().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(passageiro->getNome().c_str(), len);

        len = passageiro->getTelefone().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(passageiro->getTelefone().c_str(), len);

        len = passageiro->getEndereco().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(passageiro->getEndereco().c_str(), len);

        len = passageiro->getFidelidade().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(passageiro->getFidelidade().c_str(), len);

        int pontosFidelidade = passageiro->getPontosFidelidade();
        arquivo.write((char *)&pontosFidelidade, sizeof(pontosFidelidade));
    }

    // Salvar tripulantes
    tamanho = tripulantes.size();
    arquivo.write((char *)&tamanho, sizeof(tamanho));
    for (auto tripulante : tripulantes)
    {
        int codigo = tripulante->getCodigo();
        arquivo.write((char *)&codigo, sizeof(codigo));

        size_t len = tripulante->getNome().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(tripulante->getNome().c_str(), len);

        len = tripulante->getTelefone().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(tripulante->getTelefone().c_str(), len);

        len = tripulante->getCargo().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(tripulante->getCargo().c_str(), len);
    }

    // Salvar voos
    tamanho = voos.size();
    arquivo.write((char *)&tamanho, sizeof(tamanho));
    for (auto voo : voos)
    {
        int codigo = voo->getCodigo_voo();
        arquivo.write((char *)&codigo, sizeof(codigo));

        size_t len = voo->getData().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(voo->getData().c_str(), len);

        len = voo->getHora().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(voo->getHora().c_str(), len);

        len = voo->getOrigem().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(voo->getOrigem().c_str(), len);

        len = voo->getDestino().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(voo->getDestino().c_str(), len);

        len = voo->getStatus().size();
        arquivo.write((char *)&len, sizeof(len));
        arquivo.write(voo->getStatus().c_str(), len);

        double tarifa = voo->getTarifa();
        arquivo.write((char *)&tarifa, sizeof(tarifa));
    }

    // Salvar reservas
    tamanho = reservas.size();
    arquivo.write((char *)&tamanho, sizeof(tamanho));
    for (auto reserva : reservas)
    {
        int codigo = reserva->getCodigo();
        arquivo.write((char *)&codigo, sizeof(codigo));

        int codigoVoo = reserva->getVoo()->getCodigo_voo();
        arquivo.write((char *)&codigoVoo, sizeof(codigoVoo));

        int codigoAssento = reserva->getAssento()->getCodigo();
        arquivo.write((char *)&codigoAssento, sizeof(codigoAssento));

        int codigoPassageiro = reserva->getPassageiro()->getCodigo();
        arquivo.write((char *)&codigoPassageiro, sizeof(codigoPassageiro));
    }

    arquivo.close();
}

void carregarDados(vector<Passageiro *> &passageiros, vector<Tripulante *> &tripulantes,
                   vector<Voo *> &voos, vector<Reserva *> &reservas)
{
    ifstream arquivo("dados.bin", ios::binary | ios::in);
    if (!arquivo)
    {
        cerr << "Nenhum arquivo de dados encontrado. Iniciando com dados vazios." << endl;
        return;
    }

    // Carregar passageiros
    size_t tamanho;
    arquivo.read((char *)&tamanho, sizeof(tamanho));
    for (size_t i = 0; i < tamanho; ++i)
    {
        int codigo;
        arquivo.read((char *)&codigo, sizeof(codigo));

        size_t len;
        string nome, telefone, endereco, fidelidade;

        arquivo.read((char *)&len, sizeof(len));
        nome.resize(len);
        arquivo.read(&nome[0], len);

        arquivo.read((char *)&len, sizeof(len));
        telefone.resize(len);
        arquivo.read(&telefone[0], len);

        arquivo.read((char *)&len, sizeof(len));
        endereco.resize(len);
        arquivo.read(&endereco[0], len);

        arquivo.read((char *)&len, sizeof(len));
        fidelidade.resize(len);
        arquivo.read(&fidelidade[0], len);

        int pontosFidelidade;
        arquivo.read((char *)&pontosFidelidade, sizeof(pontosFidelidade));

        passageiros.push_back(new Passageiro(codigo, nome, telefone, endereco, fidelidade, pontosFidelidade));
    }

    // Carregar tripulantes
    arquivo.read((char *)&tamanho, sizeof(tamanho));
    for (size_t i = 0; i < tamanho; ++i)
    {
        int codigo;
        arquivo.read((char *)&codigo, sizeof(codigo));

        size_t len;
        string nome, telefone, cargo;

        arquivo.read((char *)&len, sizeof(len));
        nome.resize(len);
        arquivo.read(&nome[0], len);

        arquivo.read((char *)&len, sizeof(len));
        telefone.resize(len);
        arquivo.read(&telefone[0], len);

        arquivo.read((char *)&len, sizeof(len));
        cargo.resize(len);
        arquivo.read(&cargo[0], len);

        tripulantes.push_back(new Tripulante(codigo, nome, telefone, cargo));
    }

    // Carregar voos
    arquivo.read((char *)&tamanho, sizeof(tamanho));
    for (size_t i = 0; i < tamanho; ++i)
    {
        int codigo;
        arquivo.read((char *)&codigo, sizeof(codigo));

        size_t len;
        string data, hora, origem, destino, status;
        double tarifa;

        arquivo.read((char *)&len, sizeof(len));
        data.resize(len);
        arquivo.read(&data[0], len);

        arquivo.read((char *)&len, sizeof(len));
        hora.resize(len);
        arquivo.read(&hora[0], len);

        arquivo.read((char *)&len, sizeof(len));
        origem.resize(len);
        arquivo.read(&origem[0], len);

        arquivo.read((char *)&len, sizeof(len));
        destino.resize(len);
        arquivo.read(&destino[0], len);

        arquivo.read((char *)&len, sizeof(len));
        status.resize(len);
        arquivo.read(&status[0], len);

        arquivo.read((char *)&tarifa, sizeof(tarifa));

        voos.push_back(new Voo(codigo, data, hora, origem, destino, status, tarifa, {}, {}));
    }

    // Carregar reservas
    arquivo.read((char *)&tamanho, sizeof(tamanho));
    for (size_t i = 0; i < tamanho; ++i)
    {
        int codigo, codigoVoo, codigoAssento, codigoPassageiro;

        arquivo.read((char *)&codigo, sizeof(codigo));
        arquivo.read((char *)&codigoVoo, sizeof(codigoVoo));
        arquivo.read((char *)&codigoAssento, sizeof(codigoAssento));
        arquivo.read((char *)&codigoPassageiro, sizeof(codigoPassageiro));

        Voo *voo = nullptr;
        for (auto v : voos)
        {
            if (v->getCodigo_voo() == codigoVoo)
            {
                voo = v;
                break;
            }
        }

        Assento *assento = nullptr;
        if (voo)
        {
            for (auto &a : voo->getAssentos())
            {
                if (a.getCodigo() == codigoAssento)
                {
                    assento = &a;
                    break;
                }
            }
        }

        Passageiro *passageiro = nullptr;
        for (auto p : passageiros)
        {
            if (p->getCodigo() == codigoPassageiro)
            {
                passageiro = p;
                break;
            }
        }

        if (voo && assento && passageiro)
        {
            reservas.push_back(new Reserva(voo, assento, passageiro, codigo));
        }
        else
        {
            cerr << "Erro ao carregar reserva: dados inconsistentes para a reserva com código " << codigo << "." << endl;
        }
    }

    arquivo.close();
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    vector<Reserva *> reservas;
    vector<Passageiro *> passageiros;
    vector<Tripulante *> tripulantes;
    vector<Voo *> voos;

    carregarDados(passageiros, tripulantes, voos, reservas);
    int opcao;
    do
    {
        menu();
        cin >> opcao;
        switch (opcao)
        {
        case 0:
            system("cls");
            cout << "Obrigado por usar!\n";
            salvarDados(passageiros, tripulantes, voos, reservas);
            break;
        case 1:
            system("cls");
            cadastrar_Voo(voos);
            break;
        case 2:
            system("cls");
            cadastrar_passageiro(passageiros);
            break;
        case 3:
            system("cls");
            cadastrar_tripulante(tripulantes);
            break;
        case 4:
            system("cls");
            agregar_tripulante(tripulantes, voos);
            break;
        case 5:
            system("cls");
            criarReserva(passageiros, voos, reservas, reservas.size() + 1);
            break;
        case 6:
            system("cls");
            ver_Voos(voos);
            break;
        case 7:
            system("cls");
            ver_passageiros(passageiros);
            break;
        case 8:
            system("cls");
            ver_tripulantes(tripulantes);
            break;
        case 9:
            system("cls");
            ver_Reservas(reservas);
            break;
        case 10:
            system("cls");
            ver_Voo_passageiro(reservas);
            break;
        case 11:
            system("cls");
            pesquisar_Voo(voos);
            break;
        case 12:
            system("cls");
            pesquisarPessoas(passageiros);
            break;
        case 13:
            system("cls");
            pesquisarTripulante(tripulantes);
            break;
        case 14:
            system("cls");
            reservaBaixa(reservas);
            break;
        default:
            system("cls");
            cout << "**********************************************" << "\n";
            cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    for (auto &p : passageiros)
        delete p;
    for (auto &t : tripulantes)
        delete t;
    return 0;
}