#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <limits>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
// ************  --------------  CLASSES   --------------  ************//

class Padroes
{
protected:
    int codigo;
    string nome;
};

class PASSAGEIRO : protected Padroes /// MODIFICOU
{

private:
    int pontosFidelidade;
    string endereco, telefone;
    bool fidelidade;

public:

    void setCodigoPassageiro(int codigoPassageiro) { codigo = codigoPassageiro; }
    int getCodigoPassageiro() const { return codigo; }

    void setTelefonePassageiro(string telefonePassageiro) { telefone = telefonePassageiro; }
    string getTelefonePassageiro() const { return telefone; }

    void setPontosFidelidadePassageiro(int pontosFidelidadePassageiro) { pontosFidelidade = pontosFidelidadePassageiro; }
    int getPontosFidelidadePassageiro() const { return pontosFidelidade; }

    void setNomePassageiro(string nomePassageiro) { nome = nomePassageiro; }
    string getNomePassageiro() const { return nome; }

    void setEnderecoPassageiro(string enderecoPassageiro) { endereco = enderecoPassageiro; }
    string getEnderecoPassageiro() const { return endereco; }

    void setFidelidadePassageiro(bool fidelidadePassageiro) { fidelidade = fidelidadePassageiro; }
    bool getFidelidadePassageiro() const { return fidelidade; }

};


class CARGO /// MODIFICOU
{
public:
    int codigoPiloto, codigoCopiloto, codigoComissario;
    string nomePiloto, nomeCopiloto, nomeComissario;
    string telefonePiloto, telefoneCopiloto, telefoneComissario;

    void setCodigoPiloto(int codigo) { codigoPiloto = codigo; }
    void setNomePiloto(const string& nome) { nomePiloto = nome; }
    string getNomePiloto() const { return nomePiloto; }

    void setTelefonePiloto(const string& telefone) { telefonePiloto = telefone; }
    string getTelefonePiloto() const { return telefonePiloto; }

    void setCodigoCopiloto(int codigo) { codigoCopiloto = codigo; }
    void setNomeCopiloto(const string& nome) { nomeCopiloto = nome; }
    string getNomeCopiloto() const { return nomeCopiloto; }

    void setTelefoneCopiloto(const string& telefone) { telefoneCopiloto = telefone; }
    string getTelefoneCopiloto() const { return telefoneCopiloto; }

    void setCodigoComissario(int codigo) { codigoComissario = codigo; }
    void setNomeComissario(const string& nome) { nomeComissario = nome; }
    string getNomeComissario() const { return nomeComissario; }

    void setTelefoneComissario(const string& telefone) { telefoneComissario = telefone; }
    string getTelefoneComissario() const { return telefoneComissario; }
};

class TRIPULACAO : protected Padroes { /// MODIFICOU
private:
    int telefone, codigo;
    string nome;
    CARGO cargo;

public:
    void setCodigo(int codigoTripulacao) {
        if (codigoTripulacao > 0) {
            codigo = codigoTripulacao;
        } else {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigo() const { return codigo; }

    void setTelefone(int telefoneTripulacao) {
        if (telefoneTripulacao > 0) {
            telefone = telefoneTripulacao;
        } else {
            throw invalid_argument("Digite um telefone maior que 0");
        }
    }

    int getTelefone() const { return telefone; }

    void setNomeTripulacao(const string& nomeTripulacao) { nome = nomeTripulacao; }
    string getNomeTripulacao() const { return nome; }

    CARGO& getCargo() { return cargo; }
};

class DATA
{
private:
    int dia;
    int mes;
    int ano;

public:
    void setDia(int d)
    {
        if (d > 0 && d <= 31)
        {
            dia = d;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 1 a 31");
        }
    }

    int getDia() const { return dia; }

    void setMes(int m)
    {
        if (m > 0 && m <= 12)
        {
            mes = m;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 1 a 12");
        }
    }

    int getMes() const { return mes; }

    void setAno(int a)
    {
        if (a >= 2024 && a <= 2050)
        {
            ano = a;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 2024 a 2050");
        }
    }

    int getAno() const { return ano; }
};


class ENDERECOPASSAGEIRO { // teste - joao
private:
    string pais, estado, cidade;

public:
    // Setters
    void setPaisPassageiro(string paisPassageiro) { pais = paisPassageiro; }
    string getPaisPassageiro() const { return pais; }

    void setEstadoPassageiro(string estadoPassageiro) { estado = estadoPassageiro; }
    string getEstadoPassageiro() const { return estado; }

    void setCidadePassageiro(string cidadePassageiro) { cidade = cidadePassageiro; }
    string getCidadePassageiro() const { return cidade; }

    void InserirEnderecoPassageiro() {
        cout << "Digite o nome do pa�s: ";
        getline(cin, pais);

        cout << "Digite o nome do estado: ";
        getline(cin, estado);

        cout << "Digite o nome da cidade: ";
        getline(cin, cidade);

    }
};

class PILOTO{ /// N SEI SE MUDOU ALGO MAS DEIXA PQ TA FUNCIONADNO
private:
    string nome, telefone;
    int codigo;

public:
    void setNomePiloto(string nomePiloto) { nome = nomePiloto; }
    string getNomePiloto() const { return nome; }

    void setTelefonePiloto(string telefonePiloto) { telefone = telefonePiloto; }
    string getTelefonePiloto() const { return telefone; }

    void setCodigoPiloto(int codigoPiloto) { codigo = codigoPiloto; }
    int getcodigoPiloto() const { return codigo; }

    void InserirDadosPiloto() {
        cout << "Digite o nome do piloto: ";
        cin.ignore();
        getline(cin, nome);

        cout << "Digite o telefone do piloto: ";
        cin.ignore();
        getline(cin, telefone);

        cout << "Digite o codigo do piloto (ex: 1234): ";
        cin >> codigo;
    }

};
class COPILOTO{ /// MODIFICOU ND MAS TA FUNCIONADNO ALGO
};
class COMISSARIO{ /// MODIFICOU ND MAS TA FUNCIONANDO ALGO
};

// ************  --------------  FUNCOES   --------------  ************//

///---------- Fidelidade ----------
void atualizarPontosFidelidade(int codigoPassageiro, const string& nomePassageiro) {
    const string nomeArquivo = "Fidelidade.txt";
    vector<pair<int, pair<string, int>>> fidelidades;
    bool encontrado = false;

    // Ler dados existentes no arquivo Fidelidade.txt
    ifstream arquivoEntrada(nomeArquivo);
    if (arquivoEntrada.is_open()) {
        string linha;
        while (getline(arquivoEntrada, linha)) {
            istringstream ss(linha);
            int codigo, pontos;
            string nome;
            getline(ss, linha, ',');
            codigo = stoi(linha);
            getline(ss, nome, ',');
            ss >> pontos;

            if (codigo == codigoPassageiro) {
                pontos += 10; // Incrementa 10 pontos
                encontrado = true;
            }
            fidelidades.push_back({codigo, {nome, pontos}});
        }
        arquivoEntrada.close();
    }

    // Adicionar novo passageiro se n�o encontrado
    if (!encontrado) {
        fidelidades.push_back({codigoPassageiro, {nomePassageiro, 10}});
    }

    // Salvar dados atualizados no arquivo
    ofstream arquivoSaida(nomeArquivo);
    if (arquivoSaida.is_open()) {
        for (const auto& entry : fidelidades) {
            arquivoSaida << entry.first << "," << entry.second.first << "," << entry.second.second << "\n";
        }
        arquivoSaida.close();
    } else {
        cerr << "Erro ao abrir o arquivo de fidelidade para escrita." << endl;
    }

    cout << "Pontos de fidelidade atualizados com sucesso!" << endl;
}

void consultarPontosFidelidade(int codigoPassageiro) {
    const string nomeArquivo = "Fidelidade.txt";
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            istringstream ss(linha);
            int codigo, pontos;
            string nome;
            ss >> codigo;
            getline(ss, nome, ',');
            ss >> pontos;

            if (codigo == codigoPassageiro) {
                cout << "Passageiro: " << nome << "\nPontos de fidelidade: " << pontos << endl;
                arquivo.close();
                return;
            }
        }
        arquivo.close();
        cout << "Passageiro n�o encontrado no sistema de fidelidade." << endl;
    } else {
        cerr << "Erro ao abrir o arquivo de fidelidade." << endl;
    }
}

int CadastroPassageiro(PASSAGEIRO& passageiro) {
    static int contadorCodigoPassageiro = 1000; // Contador inicial

    // Tentar ler o contador existente do arquivo
    ifstream arquivoLeitura("contadorCodigoPassageiro.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoPassageiro;
        arquivoLeitura.close();
    }

    ofstream arquivo("dadosPassageiro.txt", ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os passageiros!" << endl;
        return -1;
    }

    cout << "---------- Cadastro de Passageiros ----------\n";
    int continuar;
    do {
        string nomePassageiro, telefonePassageiro;

        // Entrada de dados
        cout << "Digite o nome do passageiro: ";
        cin.ignore();
        getline(cin, nomePassageiro);

        cout << "Digite o n�mero de telefone do passageiro: ";
        cin >> telefonePassageiro;

        // Gerar c�digo do passageiro
        int codigoPassageiro = contadorCodigoPassageiro++;

        // Salvar dados no arquivo
        arquivo << codigoPassageiro << "," << nomePassageiro << ",Passageiro," << telefonePassageiro << "\n";

        cout << "\nPassageiro cadastrado com sucesso! C�digo: " << codigoPassageiro << "\n";

        // Perguntar se deseja continuar
        cout << "Deseja cadastrar outro passageiro? (1 - Sim, 0 - N�o): ";
        cin >> continuar;

    } while (continuar == 1);

    arquivo.close();

    // Atualizar o contador no arquivo
    ofstream arquivoContador("contadorCodigoPassageiro.txt");
    if (arquivoContador.is_open()) {
        arquivoContador << contadorCodigoPassageiro;
        arquivoContador.close();
    }

    return 0;
}


int CadastroTripulacao(TRIPULACAO& tripulacao) {
    static int contadorCodigoTripulacao = 1000; // Contador inicial

    // Tentar ler o contador existente do arquivo
    ifstream arquivoLeitura("contadorCodigoTripulacao.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoTripulacao;
        arquivoLeitura.close();
    }

    ofstream arquivo("dadosTripulacao.txt", ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os tripulantes!" << endl;
        return -1;
    }

    cout << "---------- Cadastro de Tripulantes ----------\n";
    int continuar;
    do {
        string nomeTripulante, telefoneTripulante, cargo;
        int tipo;

        // Entrada de dados
        cout << "Digite o nome do tripulante: ";
        cin.ignore();
        getline(cin, nomeTripulante);

        cout << "Digite o n�mero de telefone do tripulante: ";
        cin >> telefoneTripulante;

        cout << "Escolha o cargo:\n1 - Piloto\n2 - Copiloto\n3 - Comiss�rio\nEscolha: ";
        cin >> tipo;

        switch (tipo) {
            case 1: cargo = "Piloto"; break;
            case 2: cargo = "Copiloto"; break;
            case 3: cargo = "Comiss�rio"; break;
            default:
                cout << "Op��o inv�lida! Cadastro cancelado.\n";
                return -1;
        }

        // Gerar c�digo do tripulante
        int codigoTripulante = contadorCodigoTripulacao++;

        // Salvar dados no arquivo
        arquivo << codigoTripulante << "," << nomeTripulante << "," << cargo << "," << telefoneTripulante << "\n";

        cout << "\nTripulante cadastrado com sucesso! C�digo: " << codigoTripulante << "\n";

        // Perguntar se deseja continuar
        cout << "Deseja cadastrar outro tripulante? (1 - Sim, 0 - N�o): ";
        cin >> continuar;

    } while (continuar == 1);

    arquivo.close();

    // Atualizar o contador no arquivo
    ofstream arquivoContador("contadorCodigoTripulacao.txt");
    if (arquivoContador.is_open()) {
        arquivoContador << contadorCodigoTripulacao;
        arquivoContador.close();
    }

    return 0;
}



class Voo {
private:
    std::string codigoVoo, data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario;
    bool status;  // true = ativo, false = inativo
    double tarifa;

public:
    void criarInformacoes(const string& nomeArquivo) {
    static int contadorCodigoVoo = 2000; // C�digo inicial para voos
    static int contadorCodigoAviao = 100; // C�digo inicial para avi�es

    // Ler contadores existentes dos arquivos, se dispon�veis
    ifstream arquivoLeitura("contadorCodigoVoo.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoVoo;
        arquivoLeitura.close();
    }

    ifstream arquivoLeituraAviao("contadorCodigoAviao.txt");
    if (arquivoLeituraAviao.is_open()) {
        arquivoLeituraAviao >> contadorCodigoAviao;
        arquivoLeituraAviao.close();
    }

    string data, hora, origem, destino;
    int codigoPiloto = 0, codigoCopiloto = 0, codigoComissario = 0;
    double tarifa;
    bool pilotoValido = false, copilotoValido = false, comissarioValido = false;

    cout << "---------- Cadastro de Voo ----------\n";

    // Gerar c�digo do voo
    int codigoVoo = contadorCodigoVoo++;
    cout << "C�digo do voo gerado automaticamente: " << codigoVoo << "\n";

    // Gerar c�digo do avi�o
    int codigoAviao = contadorCodigoAviao++;
    cout << "C�digo do avi�o gerado automaticamente: " << codigoAviao << "\n";

    // Entrada de data, hora, origem e destino
    cout << "Digite a data (DD-MM-AAAA): ";
    cin >> data;

    cout << "Digite a hora (HH:MM): ";
    cin >> hora;

    cout << "Digite a origem: ";
    cin.ignore(); //limpar buffer para evitar bugs
    getline(cin,origem);

    cout << "Digite o destino: ";
    cin.ignore(); //limpar buffer para evitar bugs
    getline(cin,destino);

    // Validar c�digo do piloto
do {
    cout << "Digite o c�digo do piloto (Ex: 1234): ";
    cin >> codigoPiloto;

    // Verifica se a entrada foi inv�lida
    if (cin.fail()) {
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora qualquer entrada residual
        cout << "Entrada inv�lida. Digite um n�mero v�lido.\n";
        continue; // Volta ao in�cio do loop para pedir novamente o c�digo
    }

    pilotoValido = validarTripulante(codigoPiloto, "Piloto");

    if (!pilotoValido) {
        cout << "Erro: C�digo do piloto inv�lido ou n�o encontrado! Tente novamente.\n";
    }
} while (!pilotoValido);

// Validar c�digo do copiloto
do {
    cout << "Digite o c�digo do copiloto (Ex: 4321): ";
    cin >> codigoCopiloto;

    if (cin.fail()) {
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entrada inv�lida
        cout << "Entrada inv�lida. Digite um n�mero v�lido.\n";
        continue;
    }

    copilotoValido = validarTripulante(codigoCopiloto, "Copiloto");

    if (!copilotoValido) {
        cout << "Erro: C�digo do copiloto inv�lido ou n�o encontrado! Tente novamente.\n";
    }
} while (!copilotoValido);

// Validar c�digo do comiss�rio
do {
    cout << "Digite o c�digo do comiss�rio (Ex: 2314): ";
    cin >> codigoComissario;

    if (cin.fail()) {
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entrada inv�lida
        cout << "Entrada inv�lida. Digite um n�mero v�lido.\n";
        continue;
    }

    comissarioValido = validarTripulante(codigoComissario, "Comiss�rio");

    if (!comissarioValido) {
        cout << "Erro: C�digo do comiss�rio inv�lido ou n�o encontrado! Tente novamente.\n";
    }
} while (!comissarioValido);



    // Status do voo e tarifa
    string status = "Ativo";
    cout << "Digite a tarifa: ";
    cin >> tarifa;

    // Salvar os dados no arquivo de voos
    ofstream arquivo(nomeArquivo, ios::app);
    if (arquivo.is_open()) {
        arquivo << codigoVoo << "," << data << "," << hora << "," << origem << "," << destino << ","
                << codigoAviao << "," << codigoPiloto << "," << codigoCopiloto << "," << codigoComissario
                << "," << status << "," << tarifa << "\n";
        arquivo.close();
        cout << "Voo cadastrado com sucesso!\n";
    } else {
        cerr << "Erro ao abrir o arquivo de voos para salvar.\n";
        return;
    }

    // Atualizar contadores nos arquivos
    ofstream arquivoVooContador("contadorCodigoVoo.txt");
    if (arquivoVooContador.is_open()) {
        arquivoVooContador << contadorCodigoVoo;
        arquivoVooContador.close();
    }

    ofstream arquivoAviaoContador("contadorCodigoAviao.txt");
    if (arquivoAviaoContador.is_open()) {
        arquivoAviaoContador << contadorCodigoAviao;
        arquivoAviaoContador.close();
    }
}



bool validarTripulante(int codigo, const string& cargoEsperado) {
    ifstream arquivo("dadosTripulacao.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de tripulantes para valida��o.\n";
        return false;
    }

    string linha;
    while (getline(arquivo, linha)) {
        istringstream ss(linha);
        string codigoStr, nome, cargo, telefone;

        getline(ss, codigoStr, ',');
        getline(ss, nome, ',');
        getline(ss, cargo, ',');
        getline(ss, telefone, ',');

        if (stoi(codigoStr) == codigo && cargo == cargoEsperado) {
            arquivo.close();
            return true;
        }
    }

    arquivo.close();
    return false;
}
};



class Assento {
private:
    string numero;
    string voo;
    string status; // "livre" ou "ocupado"
    string nome;
    string tipoPessoa; // Novo campo
    int codigo;

public:
    Assento() : status("livre"), codigo(0), tipoPessoa("N/A") {}

    // Getters e Setters
    string getNumero() const { return numero; }
    void setNumero(const string& numero) { this->numero = numero; }

    string getVoo() const { return voo; }
    void setVoo(const string& voo) { this->voo = voo; }

    string getStatus() const { return status; }
    void setStatus(const string& status) { this->status = status; }

    string getNome() const { return nome; }
    void setNome(const string& nome) { this->nome = nome; }

    string getTipoPessoa() const { return tipoPessoa; }
    void setTipoPessoa(const string& tipoPessoa) { this->tipoPessoa = tipoPessoa; }

    int getCodigo() const { return codigo; }
    void setCodigo(int codigo) { this->codigo = codigo; }

    // Carregar assentos de um arquivo
    static vector<Assento> carregarAssentos(const string& nomeArquivo) {
        vector<Assento> assentos;
        ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de assentos." << endl;
            return assentos;
        }

        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Assento assento;
            string codigoStr;

            getline(ss, assento.numero, ',');
            getline(ss, assento.voo, ',');
            getline(ss, assento.status, ',');
            getline(ss, assento.nome, ',');
            getline(ss, assento.tipoPessoa, ',');
            getline(ss, codigoStr);

            assento.codigo = codigoStr.empty() ? 0 : stoi(codigoStr);
            assentos.push_back(assento);
        }

        arquivo.close();
        return assentos;
    }

    // Salvar assentos em um arquivo
    static void salvarAssentos(const string& nomeArquivo, const vector<Assento>& assentos) {
        ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo para salvar os assentos." << endl;
            return;
        }

        for (const auto& assento : assentos) {
            arquivo << assento.numero << "," << assento.voo << "," << assento.status << ",";
            if (assento.getStatus() == "ocupado") {
                arquivo << assento.nome << "," << assento.tipoPessoa << "," << assento.codigo;
            }
            arquivo << endl;
        }

        arquivo.close();
    }
};



    // Fun��o para reservar um assento
void reservarAssento() {
    string numero, voo, nome, tipoPessoa, cargo;
    int codigo;

    cout << "Digite o n�mero do assento: ";
    cin >> numero;
    cout << "Digite o c�digo do voo: ";
    cin >> voo;

    vector<Assento> assentos = Assento::carregarAssentos("assentos.txt");

    for (auto& assento : assentos) {
        if (assento.getNumero() == numero && assento.getVoo() == voo) {
            if (assento.getStatus() == "livre") {
                cout << "Digite seu nome: ";
                cin.ignore();
                getline(cin, nome);

                cout << "Digite seu c�digo de usu�rio: ";
                cin >> codigo;

                cout << "Voc� �:\n1 - Passageiro\n2 - Tripulante\nEscolha: ";
                int tipo;
                cin >> tipo;

                if (tipo == 1) {
                    tipoPessoa = "Passageiro";
                } else if (tipo == 2) {
                    cout << "Qual � seu cargo?\n1 - Piloto\n2 - Copiloto\n3 - Comiss�rio\nEscolha: ";
                    int opcaoCargo;
                    cin >> opcaoCargo;

                    switch (opcaoCargo) {
                        case 1: cargo = "Piloto"; break;
                        case 2: cargo = "Copiloto"; break;
                        case 3: cargo = "Comiss�rio"; break;
                        default:
                            cout << "Op��o inv�lida! Reserva cancelada.\n";
                            return;
                    }
                    tipoPessoa = cargo;
                } else {
                    cout << "Op��o inv�lida! Reserva cancelada.\n";
                    return;
                }

                // Atualiza o assento com as novas informa��es
                assento.setStatus("ocupado");
                assento.setNome(nome);
                assento.setCodigo(codigo);
                assento.setTipoPessoa(tipoPessoa);

                // Salvar os dados no arquivo
                Assento::salvarAssentos("assentos.txt", assentos);

                // Atualizar fidelidade apenas para passageiros
                if (tipoPessoa == "Passageiro") {
                    atualizarPontosFidelidade(codigo, nome);
                }

                cout << "Reserva feita com sucesso!" << endl;
                return;
            } else {
                cout << "Erro: Assento j� est� ocupado." << endl;
                return;
            }
        }
    }

    cout << "Erro: Assento ou voo n�o encontrado." << endl;
}



//Fun��o para baixa em reserva
void cancelarReserva() {
    string numero, voo;
    int codigo;

    cout << "Digite o n�mero do assento: ";
    cin >> numero;
    cout << "Digite o c�digo do voo: ";
    cin >> voo;
    cout << "Digite seu c�digo de usu�rio: ";
    cin >> codigo;

    vector<Assento> assentos = Assento::carregarAssentos("assentos.txt");

    for (auto& assento : assentos) {
        if (assento.getNumero() == numero && assento.getVoo() == voo) {
            if (assento.getStatus() == "ocupado" && assento.getCodigo() == codigo) {
                assento.setStatus("livre");
                assento.setNome("");
                assento.setCodigo(0);
                Assento::salvarAssentos("assentos.txt", assentos);

                cout << "Reserva cancelada com sucesso!" << endl;
                return;
            } else {
                cout << "Erro: Assento n�o pertence a este usu�rio." << endl;
                return;
            }
        }
    }

    cout << "Erro: Assento ou voo n�o encontrado." << endl;
}

    // Fun��o para cadastrar um novo assento
void cadastrarAssento() {
    string numero, voo;
    cout << "Digite o n�mero do assento: ";
    cin >> numero;
    cout << "Digite o c�digo do voo: ";
    cin >> voo;

    vector<Assento> assentos = Assento::carregarAssentos("assentos.txt");

    // Verificar se o assento j� existe
    for (const auto& assento : assentos) {
        if (assento.getNumero() == numero && assento.getVoo() == voo) {
            cout << "Erro: Assento j� cadastrado." << endl;
            return;
        }
    }

    // Criar e adicionar novo assento
    Assento novoAssento;
    novoAssento.setNumero(numero);
    novoAssento.setVoo(voo);
    novoAssento.setStatus("livre");
    assentos.push_back(novoAssento);

    Assento::salvarAssentos("assentos.txt", assentos);
    cout << "Assento cadastrado com sucesso!" << endl;
}

    // Carregar e exibir todos os assentos
    static void carregarAssentos(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo de assentos.\n";
            return;
        }

        std::string linha;
        std::cout << "Assentos cadastrados:\n";
        while (std::getline(arquivo, linha)) {
            std::cout << linha << "\n";
        }
        arquivo.close();
    };



class Reserva {
public:
    Reserva(const string& codigoVoo = "", const string& numeroAssento = "", int codigoPassageiro = 0)
        : codigoVoo(codigoVoo), numeroAssento(numeroAssento), codigoPassageiro(codigoPassageiro) {}

    string getCodigoVoo() const { return codigoVoo; }
    string getNumeroAssento() const { return numeroAssento; }
    int getCodigoPassageiro() const { return codigoPassageiro; }

private:
    string codigoVoo;
    string numeroAssento;
    int codigoPassageiro;
};

void BaixarReserva(string codigoVoo, string numeroAssento) {
    ifstream arquivoLeitura("reservas.dat", ios::binary);
    ofstream arquivoTemporario("reservas_temp.dat", ios::binary);

    if (!arquivoLeitura.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return;
    }

    Reserva reserva;
    bool reservaEncontrada = false; // Declara��o e inicializa��o da vari�vel

    while (arquivoLeitura.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        if (reserva.getCodigoVoo() == codigoVoo && reserva.getNumeroAssento() == numeroAssento) {
            reservaEncontrada = true;
            // ... (l�gica para remover a reserva)
        } else {
            arquivoTemporario.write(reinterpret_cast<const char*>(&reserva), sizeof(Reserva));
        }
    }

    arquivoLeitura.close();
    arquivoTemporario.close();

    if (reservaEncontrada) {
        remove("reservas.dat");
        rename("reservas_temp.dat", "reservas.dat");
        cout << "Reserva cancelada com sucesso.\n";
    } else {
        remove("reservar_temp.dat");
        cout << "Reserva n�o encontrada para este assento e voo.\n";
    }
}

void liberarAssento(const string& numeroAssento) {
    ifstream arquivoLeitura("assentos.txt");
    ofstream arquivoEscrita("assentos_temp.txt");

    if (!arquivoLeitura.is_open() || !arquivoEscrita.is_open()) {
        cerr << "Erro ao abrir os arquivos de assentos." << endl;
        return;
    }

    string linha;
    while (getline(arquivoLeitura, linha)) {
        istringstream ss(linha);
        string numero, voo, status;
        getline(ss, numero, ',');
        getline(ss, voo, ',');
        getline(ss, status, ',');

        if (numero == numeroAssento) {
            status = "livre"; // Atualiza o status para livre
        }

        arquivoEscrita << numero << "," << voo << "," << status << endl;
    }

    arquivoLeitura.close();
    arquivoEscrita.close();

    remove("assentos.txt");
    rename("assentos_temp.txt", "assentos.txt");

    cout << "Assento liberado com sucesso." << endl;
}

void pesquisarPessoa() {
    string termoBusca;
    cout << "Digite o nome ou c�digo da pessoa que deseja buscar: ";
    cin.ignore();
    getline(cin, termoBusca);

    // Vari�veis para armazenar detalhes da pessoa encontrada
    string nome, tipo, telefone;
    bool encontrado = false;

    // Abrir arquivo de passageiros
    ifstream arquivoPassageiros("dadosPassageiro.txt");
    if (arquivoPassageiros.is_open()) {
        string linha;
        while (getline(arquivoPassageiros, linha)) {
            if (linha.find(termoBusca) != string::npos) {
                istringstream ss(linha);
                string codigo, nomePassageiro, tipoPessoa, telefonePassageiro;

                getline(ss, codigo, ',');
                getline(ss, nomePassageiro, ',');
                getline(ss, tipoPessoa, ',');
                getline(ss, telefonePassageiro, ',');

                nome = nomePassageiro;
                tipo = tipoPessoa;
                telefone = telefonePassageiro;

                encontrado = true;
                cout << "Passageiro encontrado:\n";
                cout << "C�digo: " << codigo << "\nNome: " << nomePassageiro << "\nTipo: " << tipoPessoa << "\nTelefone: " << telefonePassageiro << "\n";
                break;
            }
        }
        arquivoPassageiros.close();
    }

    // Se n�o encontrado, verificar nos tripulantes
    if (!encontrado) {
        ifstream arquivoTripulacao("dadosTripulacao.txt");
        if (arquivoTripulacao.is_open()) {
            string linha;
            while (getline(arquivoTripulacao, linha)) {
                if (linha.find(termoBusca) != string::npos) {
                    istringstream ss(linha);
                    string codigo, nomeTripulante, cargo, telefoneTripulante;

                    getline(ss, codigo, ',');
                    getline(ss, nomeTripulante, ',');
                    getline(ss, cargo, ',');
                    getline(ss, telefoneTripulante, ',');

                    nome = nomeTripulante;
                    tipo = cargo;
                    telefone = telefoneTripulante;

                    encontrado = true;
                    cout << "Tripulante encontrado:\n";
                    cout << "C�digo: " << codigo << "\nNome: " << nomeTripulante << "\nCargo: " << cargo << "\nTelefone: " << telefoneTripulante << "\n";
                    break;
                }
            }
            arquivoTripulacao.close();
        }
    }

    // Caso n�o encontrado
    if (!encontrado) {
        cout << "Nenhuma pessoa encontrada com o termo '" << termoBusca << "'.\n";
        return;
    }

    // Perguntar se deseja listar voos associados
    cout << "\nDeseja listar os voos dessa pessoa? (1 - Sim, 0 - N�o): ";
    int listarVoos;
    cin >> listarVoos;

    if (listarVoos == 1) {
        ifstream arquivoAssentos("assentos.txt");
        if (!arquivoAssentos.is_open()) {
            cerr << "Erro ao abrir o arquivo de assentos!" << endl;
            return;
        }

        cout << "\nVoos associados:\n";
        string linha;
        bool voosEncontrados = false;

        while (getline(arquivoAssentos, linha)) {
            if (linha.find(nome) != string::npos) {
                cout << linha << "\n";
                voosEncontrados = true;
            }
        }

        if (!voosEncontrados) {
            cout << "Nenhum voo encontrado para esta pessoa.\n";
        }

        arquivoAssentos.close();
    }
}




int escolhaFuncao(int escolha){

  PASSAGEIRO passageiro;
  TRIPULACAO tripulacao;
  Voo voo;
  Assento assento;
  std::string nomeArquivo = "voos.txt";

  switch(escolha){

  case 1: CadastroPassageiro(passageiro); break;
  case 2: CadastroTripulacao(tripulacao); break;
  case 3: voo.criarInformacoes(nomeArquivo); break;
  case 4: cadastrarAssento();break;
  case 5: reservarAssento(); break;
  case 6: cancelarReserva();break;
  case 7: pesquisarPessoa(); break;
  case 8: int codigoConsulta;
  cout << "Digite o c�digo do passageiro: ";
  cin >> codigoConsulta;
  consultarPontosFidelidade(codigoConsulta);
  break;
  case 0: cout << "Saindo...\nTe vejo em breve..." << endl; return -1;
  default: cout <<"Op��o invalida, escolha uma op��o de 1 a 7"<<endl; return escolha;

  }

  return 0;
};

// ************  --------------  VOID   --------------  ************//

void exibirmenu(){
        int opcao = 0;

  do {
      cout << "\nBem-vindo(a) ao Voe Tranquilo!\n"
           << "------------------------------------\n"
           << "O que voc� deseja?\n"
           << "1 - Cadastrar Passageiro\n"
           << "2 - Cadastrar Tripula��o\n"
           << "3 - Cadastrar Voos\n"
           << "4 - Cadastrar Assento\n"
           << "5 - Fazer Reserva\n"
           << "6 - Baixar Reserva\n"
           << "7 - Pesquisa de Pessoa\n"
           << "0 - Encerrar o Programa\n"
           << "Escolha o que deseja: ";
      cin >> opcao;

  if (escolhaFuncao(opcao) == -1) {
            break;
        }
    } while(true);

}

// ************  --------------  MAIN   --------------  ************//

int main(){
    setlocale(LC_ALL, "portuguese");
    exibirmenu();
    return 0;
}

