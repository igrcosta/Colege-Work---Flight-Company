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
        cout << "Digite o nome do país: ";
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

    // Adicionar novo passageiro se não encontrado
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
        cout << "Passageiro não encontrado no sistema de fidelidade." << endl;
    } else {
        cerr << "Erro ao abrir o arquivo de fidelidade." << endl;
    }
}

int CadastroPassageiro(class PASSAGEIRO &passageiro) { /// MODIFICOU

    static int contadorCodigoPassageiro = 1000;
    int ficarOuSair;

    ifstream arquivoLeitura("contadorCodigoPassageiro.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoPassageiro;
        arquivoLeitura.close();
    } else {contadorCodigoPassageiro = 1000;}

    ofstream arquivo("dadosPassageiro.txt", ios::app); // CASO O ARQUIVO N ABRE NO TEU PC, BASTA TROCAR O ENDEREÇO OU NOME
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os passageiros!" << endl;
        return -1;
    }

    cout<<"---------- Cadastro de Passageiros Selecionado ----------\n"<<endl;
    do{
    ///---------- nome do passageiro ----------
    string nomePassageiro;
            cout<< "Digite o nome do passageiro: ";
            cin.ignore();
            getline(cin, nomePassageiro);
            passageiro.setNomePassageiro(nomePassageiro);

    ///---------- endereco do passageiro ----------

    ENDERECOPASSAGEIRO enderecoPassageiro;
    enderecoPassageiro.InserirEnderecoPassageiro();


    ///---------- telefone do Passageiro ----------

    string telefonePassageiro;
    cout << "Digite o número de telefone do passageiro: ";
    cin >> telefonePassageiro;

    while (telefonePassageiro.length() > 14 || !isdigit(telefonePassageiro[0])) {
    cout << "Digite um numero valido: ";
    cin >> telefonePassageiro;
    }

    passageiro.setTelefonePassageiro(telefonePassageiro);

    ///---------- codigo do passageiro ----------


    passageiro.setCodigoPassageiro(contadorCodigoPassageiro++);
    cout << "Código do Passageiro: PG - " << passageiro.getCodigoPassageiro() << "\n";

    /// ---------- salvar em arquivo ----------

    arquivo << "Nome do Passageiro: " << nomePassageiro << endl;
    arquivo << "Endereco: "<< endl;
    arquivo << "Pais: " << enderecoPassageiro.getPaisPassageiro()
            << "\nEstado: " << enderecoPassageiro.getEstadoPassageiro()
            << "\nCidade: " << enderecoPassageiro.getCidadePassageiro() << endl;
    arquivo << "Telefone do Passageiro: " << telefonePassageiro << endl;
    arquivo << "Código: " << "PG - " << passageiro.getCodigoPassageiro() << endl;
    //arquivo << "Pontos de Fidelidade do Passageiro: " << pontosFidelidade << endl; IGOR, COMANDO PARA SALVAR NO ARQUIVO TXT
    arquivo << " " << endl;

    cout << "\nPassageiro cadastrado com sucesso!\n";

    cout << "Deseja continuar o cadastro um novo passageiro?\n"
         << "Continuar.................Digite 1\n"
         << "Voltar Para o Menu........Digite 0\n"
         << "Digite: ";
    cin >> ficarOuSair;

    if(ficarOuSair == 1){
        continue;
    }else if(ficarOuSair == 0){
        break;
    }else{
        cout << "\nValor invalido\n";
    };
    }while(true);

    arquivo.close();

    ofstream arquivoContador("contadorCodigoPassageiro.txt");
    if (arquivoContador.is_open()) {
        arquivoContador << contadorCodigoPassageiro;
        arquivoContador.close();
    } else {
        cerr << "Erro ao atualizar o contador de códigos!" << endl;
        return -1;
    }

    return 0;
};

int CadastroTripulacao(TRIPULACAO& tripulacao) { /// MODIFICOU

    int ficarOuSair, opcao;
    string nomeComissario, telefoneComissario;
    string nomeCopiloto, telefoneCopiloto;
    string nomePiloto, telefonePiloto;
    static int contadorCodigoTripulacao = 1000;

    ifstream arquivoLeitura("contadorCodigoTripulacao.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoTripulacao;
        arquivoLeitura.close();
    } else {contadorCodigoTripulacao = 1000;}

    ofstream arquivo("dadosTripulacao.txt", ios::app); // CASO O ARQUIVO N ABRE NO TEU PC, BASTA TROCAR O ENDEREÇO OU NOME
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os passageiros!" << endl;
        return -1;
    }

    cout<<"---------- Cadastro de Tripulacao Selecionado ----------\n"<<endl;

    do{
        cout <<"Voce deseja fazer o cadastro de qual cargo?\n"
             <<"1 - Piloto\n"
             <<"2 - Copiloto\n"
             <<"3 - Comissario\n"
             <<"Digite: \n";
         cin >> opcao;

        switch(opcao){
            case 1:{

                cout << "Digite o nome do Piloto"<<endl;
                cin.ignore();
                getline(cin, nomePiloto);
                tripulacao.getCargo().setNomePiloto(nomePiloto);

                cout << "Digite o número de telefone do piloto: ";
                cin >> telefonePiloto;

                while (telefonePiloto.length() > 14 || !isdigit(telefonePiloto[0])) {
                cout << "Digite um numero valido: ";
                cin >> telefonePiloto;
                }

                tripulacao.getCargo().setTelefonePiloto(telefonePiloto);
                tripulacao.getCargo().setCodigoPiloto(contadorCodigoTripulacao++);
                cout << "Código do Piloto: " << tripulacao.getCargo().codigoPiloto << "\n";

                cout <<"\nPiloto Cadastrado\n";
                arquivo << "Piloto: " << nomePiloto << endl;
                arquivo << "Telefone: " << telefonePiloto << endl;
                arquivo << "Código: " << "PI - " << tripulacao.getCargo().codigoPiloto << endl;
                arquivo << " " << endl;

                ofstream arquivoContador("contadorCodigoTripulacao.txt");
                if (arquivoContador.is_open()) {
                    arquivoContador << contadorCodigoTripulacao;
                    arquivoContador.close();
                }

                break;
            }
            case 2:{
                cout << "Digite o nome do Copiloto: ";
                cin.ignore();
                getline(cin, nomeCopiloto);
                tripulacao.getCargo().setNomeCopiloto(nomeCopiloto);

                cout << "Digite o número de telefone do copiloto: ";
                cin >> telefoneCopiloto;

                while (telefoneCopiloto.length() > 14 || !isdigit(telefoneCopiloto[0])) {
                    cout << "Digite um numero valido: ";
                    cin >> telefoneCopiloto;
                }

                tripulacao.getCargo().setTelefoneCopiloto(telefoneCopiloto);
                tripulacao.getCargo().setCodigoCopiloto(contadorCodigoTripulacao++);
                cout << "Código do Copiloto: " << tripulacao.getCargo().codigoCopiloto << "\n";

                cout << "\nCopiloto Cadastrado\n";
                arquivo << "Copiloto: " << nomeCopiloto << endl;
                arquivo << "Telefone: " << telefoneCopiloto << endl;
                arquivo << "Código: " << "CO - " << tripulacao.getCargo().codigoCopiloto << endl;
                arquivo << " " << endl;
                break;
            }
            case 3:{

                cout << "Digite o nome do Comissário: ";
                cin.ignore();
                getline(cin, nomeComissario);
                tripulacao.getCargo().setNomeComissario(nomeComissario);

                cout << "Digite o número de telefone do comissário: ";
                cin >> telefoneComissario;

                while (telefoneComissario.length() > 14 || !isdigit(telefoneComissario[0])) {
                    cout << "Digite um numero valido: ";
                    cin >> telefoneComissario;
                }

                tripulacao.getCargo().setTelefoneComissario(telefoneComissario);
                tripulacao.getCargo().setCodigoComissario(contadorCodigoTripulacao++);
                cout << "Código do Comissario: " << tripulacao.getCargo().codigoComissario << "\n";

                cout << "\nComissário Cadastrado\n";
                arquivo << "Comissário: " << nomeComissario << endl;
                arquivo << "Telefone: " <<telefoneComissario << endl;
                arquivo << "Código: " << "CM - " << tripulacao.getCargo().codigoComissario << endl;
                arquivo << " " << endl;

                ofstream arquivoContador("arquivosTripulacaoDados\\contadorCodigoTripulacao.txt");
                if (arquivoContador.is_open()) {
                    arquivoContador << contadorCodigoTripulacao;
                    arquivoContador.close();
                }
                break;
            }
            case 0:
                cout << "Voltando para o menu...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }





        cout << "Deseja continuar o cadastro um novo passageiro?\n"
         << "Continuar.................Digite 1\n"
         << "Voltar Para o Menu........Digite 0\n"
         << "Digite: ";
    cin >> ficarOuSair;

    if(ficarOuSair == 1){
        continue;
    }else if(ficarOuSair == 0){
        break;
    }else{
        cout << "\nValor invalido\n";
    };
    }while(true);

    arquivo.close();

    ofstream arquivoContador("contadorCodigoTripulacao.txt");
    if (arquivoContador.is_open()) {
        arquivoContador << contadorCodigoTripulacao;
        arquivoContador.close();
    } else {
        cerr << "Erro ao atualizar o contador de códigos!" << endl;
        return -1;
    }

    return 0;
}

class Voo {
private:
    std::string codigoVoo, data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario;
    bool status;  // true = ativo, false = inativo
    double tarifa;

public:
    void criarInformacoes(const std::string& nomeArquivo) {
        std::cout << "Digite o código do voo: ";
        std::cin >> codigoVoo;

        std::cout << "Digite a data (DD-MM-AAAA): ";
        std::cin >> data;

        std::cout << "Digite a hora (HH:MM): ";
        std::cin >> hora;

        std::cout << "Digite a origem: ";
        std::cin >> origem;

        std::cout << "Digite o destino: ";
        std::cin >> destino;

        std::cout << "Digite o código do avião: ";
        std::cin >> codigoAviao;

        std::cout << "Digite o código do piloto (digite 0 se não houver piloto): ";
        std::cin >> codigoPiloto;

        if (codigoPiloto == "0") {
            codigoPiloto.clear();  // Se o código do piloto for 0, considera que não há piloto
        }

        std::cout << "Digite o código do copiloto (digite 0 se não houver copiloto): ";
        std::cin >> codigoCopiloto;

        if (codigoCopiloto == "0") {
            codigoCopiloto.clear();  // Se o código do copiloto for 0, considera que não há copiloto
        }

        std::cout << "Digite o código do comissário: ";
        std::cin >> codigoComissario;

        status = (!codigoPiloto.empty() && !codigoCopiloto.empty());

        std::cout << "Status do voo definido como: " << (status ? "Ativo" : "Inativo") << std::endl;

        std::cout << "Digite a tarifa: ";
        std::cin >> tarifa;

        cadastrarVoo(nomeArquivo);

    }

    //Método para ver o status do voo, utilizamos isso para reservar o voo
    bool getstatus () const {
    return status;
    }

    // Método para cadastrar voo em um arquivo
    void cadastrarVoo(const std::string& nomeArquivo) {
        std::ifstream arquivoVerificar(nomeArquivo);
        bool arquivoExiste = arquivoVerificar.is_open();
        arquivoVerificar.close();

        std::ofstream arquivo(nomeArquivo, std::ios::app); /* flags, escrever ao final do arquivo sem sobrescrever */
        if (arquivo.is_open()) {
            if (!arquivoExiste) {
                arquivo << "Código do Voo,Data,Hora,Origem,Destino,Código do Avião,Código do Piloto,"
                        << "Código do Copiloto,Código do Comissário,Status, Tarifa\n";
            }
            arquivo << codigoVoo << "," << data << "," << hora << "," << origem << "," << destino << ","
                    << codigoAviao << "," << (codigoPiloto.empty() ? "Nenhum" : codigoPiloto) << ","
                    << (codigoCopiloto.empty() ? "Nenhum" : codigoCopiloto) << "," << codigoComissario << ","
                    << (status ? "Ativo" : "Inativo") << "," << tarifa << "\n";
            std::cout << "Voo cadastrado com sucesso no arquivo.\n";

            /* se o copiloto ou piloto estiverem vazios, escreve nenhum */
            /* status ? true : false */
        } else {
            std::cerr << "Erro ao abrir o arquivo para cadastro.\n";
        }
    }

    // Método criado para verificar se estava funcionando
    void abrirArquivo(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            std::string linha;
            std::cout << "Voos cadastrados no arquivo:\n";
            while (std::getline(arquivo, linha)) {
                std::cout << linha << std::endl;
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para leitura.\n";
        }
    }

};

class Assento {
private:
    string numero;
    string voo;
    string status; // "livre" ou "ocupado"
    string nome;
    int codigo;

    public:
    Assento() : status("livre"), codigo(0) {}

    // Getters e Setters
    string getNumero() const { return numero; }
    void setNumero(const string& numero) { this->numero = numero; }

    string getVoo() const { return voo; }
    void setVoo(const string& voo) { this->voo = voo; }

    string getStatus() const { return status; }
    void setStatus(const string& status) { this->status = status; }

    string getNome() const { return nome; }
    void setNome(const string& nome) { this->nome = nome; }

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
            if (assento.status == "ocupado") {
                arquivo << assento.nome << "," << assento.codigo;
            }
            arquivo << endl;
        }

        arquivo.close();
    }
    };

    // Função para reservar um assento
void reservarAssento() {
    string numero, voo, nome;
    int codigo;

    cout << "Digite o número do assento: ";
    cin >> numero;
    cout << "Digite o código do voo: ";
    cin >> voo;

    vector<Assento> assentos = Assento::carregarAssentos("assentos.txt");

    for (auto& assento : assentos) {
        if (assento.getNumero() == numero && assento.getVoo() == voo) {
            if (assento.getStatus() == "livre") {
                cout << "Digite seu nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite seu código de usuário: ";
                cin >> codigo;

                assento.setStatus("ocupado");
                assento.setNome(nome);
                assento.setCodigo(codigo);
                Assento::salvarAssentos("assentos.txt", assentos);

                 // Atualizar pontos de fidelidade
                atualizarPontosFidelidade(codigo, nome);

                cout << "Reserva feita com sucesso!" << endl;
                return;
            } else {
                cout << "Erro: Assento já está ocupado." << endl;
                return;
            }
        }
    }

    cout << "Erro: Assento ou voo não encontrado." << endl;
}

//Função para baixa em reserva
void cancelarReserva() {
    string numero, voo;
    int codigo;

    cout << "Digite o número do assento: ";
    cin >> numero;
    cout << "Digite o código do voo: ";
    cin >> voo;
    cout << "Digite seu código de usuário: ";
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
                cout << "Erro: Assento não pertence a este usuário." << endl;
                return;
            }
        }
    }

    cout << "Erro: Assento ou voo não encontrado." << endl;
}

    // Função para cadastrar um novo assento
void cadastrarAssento() {
    string numero, voo;
    cout << "Digite o número do assento: ";
    cin >> numero;
    cout << "Digite o código do voo: ";
    cin >> voo;

    vector<Assento> assentos = Assento::carregarAssentos("assentos.txt");

    // Verificar se o assento já existe
    for (const auto& assento : assentos) {
        if (assento.getNumero() == numero && assento.getVoo() == voo) {
            cout << "Erro: Assento já cadastrado." << endl;
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
    bool reservaEncontrada = false; // Declaração e inicialização da variável

    while (arquivoLeitura.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        if (reserva.getCodigoVoo() == codigoVoo && reserva.getNumeroAssento() == numeroAssento) {
            reservaEncontrada = true;
            // ... (lógica para remover a reserva)
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
        cout << "Reserva não encontrada para este assento e voo.\n";
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

int PesquisarPessoa() {
    cout << "---------- Pesquisa de Pessoa ----------\n" << endl;

    int escolha;
    cout << "Selecione o tipo de pessoa que deseja pesquisar:\n"
         << "1 - Passageiro\n"
         << "2 - Tripulante\n"
         << "Escolha: ";
    cin >> escolha;

    if (escolha == 1) {
        // Pesquisa de Passageiros
        string termoBusca;
        cout << "Digite o nome ou código do passageiro (ex.: 1234): ";
        cin.ignore();
        getline(cin, termoBusca);

        ifstream arquivo("dadosPassageiro.txt");
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de passageiros!" << endl;
            return -1;
        }

        string linha, nome, codigo;
        bool encontrado = false;

        while (getline(arquivo, linha)) {
            if (linha.find("Nome do Passageiro: ") != string::npos) {
                nome = linha.substr(20);
            } else if (linha.find("Código: ") != string::npos) {
                codigo = linha.substr(8);

                if (nome.find(termoBusca) != string::npos || codigo.find(termoBusca) != string::npos) {
                    encontrado = true;
                    cout << "Nome: " << nome << " | Código: " << codigo << endl;
                }
            }
        }

        if (!encontrado) {
            cout << "Passageiro não encontrado." << endl;
            arquivo.close();
            return 0;
        }

        arquivo.close();

        // Listar voos do passageiro
        cout << "\nDeseja listar os voos do passageiro? (1 - Sim, 0 - Não): ";
        int listarVoos;
        cin >> listarVoos;

        if (listarVoos == 1) {
            ifstream arquivoVoos("voos.txt");
            if (!arquivoVoos.is_open()) {
                cerr << "Erro ao abrir o arquivo de voos!" << endl;
                return -1;
            }

            cout << "\nVoos associados ao passageiro:\n";
            while (getline(arquivoVoos, linha)) {
                if (linha.find(codigo) != string::npos) {
                    cout << linha << endl;
                }
            }
            arquivoVoos.close();
        }

    } else if (escolha == 2) {
        // Pesquisa de Tripulantes
        string termoBusca;
        cout << "Digite o nome ou código do tripulante (ex.: 1234): ";
        cin.ignore();
        getline(cin, termoBusca);

        ifstream arquivo("dadosTripulacao.txt");
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de tripulantes!" << endl;
            return -1;
        }

        string linha, nome, codigo;
        bool encontrado = false;

        while (getline(arquivo, linha)) {
            if (linha.find("Piloto: ") != string::npos || linha.find("Copiloto: ") != string::npos || linha.find("Comissário: ") != string::npos) {
                nome = linha.substr(linha.find(": ") + 2); 
            } else if (linha.find("Código: ") != string::npos) {
                codigo = linha.substr(8); 

                if (nome.find(termoBusca) != string::npos || codigo.find(termoBusca) != string::npos) {
                    encontrado = true;
                    cout << "Nome: " << nome << " | Código: " << codigo << endl;
                }
            }
        }

        if (!encontrado) {
            cout << "Tripulante não encontrado." << endl;
        }

        arquivo.close();

    } else {
        cout << "Opção inválida!" << endl;
    }

    return 0;
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
  case 7: PesquisarPessoa(); break;
  case 8: int codigoConsulta;
  cout << "Digite o código do passageiro: ";
  cin >> codigoConsulta;
  consultarPontosFidelidade(codigoConsulta);
  break;
  case 0: cout << "Saindo...\nTe vejo em breve..." << endl; return -1;
  default: cout <<"Opção invalida, escolha uma opção de 1 a 7"<<endl; return escolha;

  }

  return 0;
};

// ************  --------------  VOID   --------------  ************//

void exibirmenu(){
        int opcao = 0;

  do {
      cout << "\nBem-vindo(a) ao Voe Tranquilo!\n"
           << "------------------------------------\n"
           << "O que você deseja?\n"
           << "1 - Cadastrar Passageiro\n"
           << "2 - Cadastrar Tripulação\n"
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
