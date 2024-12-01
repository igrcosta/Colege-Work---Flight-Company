#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;
// ************  --------------  CLASSES   --------------  ************//

class Padroes
{
protected:
    int codigo;
    string nome;
};

class PASSAGEIRO : protected Padroes
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

class CARGO
{
public:
    int codigoPiloto, codigoCopiloto, codigoComissario;
    string nomePiloto, nomeCopiloto, nomeComissario;

    void setCodigoPiloto(int codigo)
    {
        if (codigo > 0)
        {
            codigoPiloto = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomePiloto(const string nome) { nomePiloto = nome; }
    string getNomePiloto() const { return nomePiloto; }

    void setCodigoCopiloto(int codigo)
    {
        if (codigo > 0)
        {
            codigoCopiloto = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomeCopiloto(const string nome) { nomeCopiloto = nome; }
    string getNomeCopiloto() const { return nomeCopiloto; }

    void setCodigoComissario(int codigo)
    {
        if (codigo > 0)
        {
            codigoComissario = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomeComissario(string nome) { nomeComissario = nome; }
    string getNomeComissario() const { return nomeComissario; }
};

class TRIPULACAO : protected Padroes
{
private:
    int telefone;
    string nome;
    class CARGO cargo;

public:
    void setCodigo(int codigoTripulacao)
    {
        if (codigoTripulacao > 0)
        {
            codigo = codigoTripulacao;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigo() const { return codigo; }

    void setTelefone(int telefoneTripulacao)
    {
        if (telefoneTripulacao > 0)
        {
            telefone = telefoneTripulacao;
        }
        else
        {
            throw invalid_argument("Digite um telefone maior que 0");
        }
    }

    int getTelefone() const { return telefone; }

    void setNomeTripulacao(string nomeTripulacao) { nome = nomeTripulacao; }
    string getNomeTripulacao() const { return nome; }

    CARGO getCargo() { return cargo; }
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

class VOO : protected Padroes
{
public:
    int codigoVoo, codigoAviao;
    class DATA dataVoo;
    string origem, destino;
    class CARGO cargo;
    bool status;
    float tarifa;

public:
    void setCodigoVoo(int codigo)
    {
        if (codigo > 0)
        {
            codigoVoo = codigo;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigoVoo() const { return codigoVoo; }

    void setCodigoAviao(int codigo)
    {
        if (codigo > 0)
        {
            codigoAviao = codigo;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigoAviao() const { return codigoAviao; }

    void setOrigem(string origem) { this->origem = origem; }
    string getOrigem() const { return origem; }

    void setDestino(string destino) { this->destino = destino; }
    string getDestino() const { return destino; }

    void setStatus(bool status) { this->status = status; }
    bool getStatus() const { return status; }

    void setTarifa(float tarifa)
    {
        if (tarifa >= 0)
        {
            this->tarifa = tarifa;
        }
        else
        {
            throw invalid_argument("Digite um valor que seja R$ 0");
        }
    }

    float getTarifa() const { return tarifa; }

    void setDataVoo(const DATA &data) { dataVoo = data; }
    DATA getDataVoo() const { return dataVoo; }

    CARGO &getCargo() { return cargo; }
};

class ASSENTO
{
public:
    int numeroAssento;
    class VOO voo;
    bool status;

    void setVoo(const VOO &voo) { this->voo = voo; }
    VOO getVoo() const { return voo; }

    void setNumeroAssento(int numAssento)
    {
        if (numAssento > 0)
        {
            numeroAssento = numAssento;
        }
        else
        {
            throw invalid_argument("Digite um numero maior que 0");
        }
    }

    int getNumeroAssento() const { return numeroAssento; }

    void setStatus(bool status) { this->status = status; }
    bool getStatus() const { return status; }
};

class RESERVA
{
public:
    class VOO voo;
    class ASSENTO assento;
    class PASSAGEIRO passageiro;

    void setVoo(const VOO &voo) { this->voo = voo; }
    VOO getVoo() const { return voo; }

    void setAssento(const ASSENTO &assento) { this->assento = assento; }
    ASSENTO getAssento() const { return assento; }

    void setPassageiro(const PASSAGEIRO &passageiro) { this->passageiro = passageiro; }
    PASSAGEIRO getPassageiro() const { return passageiro; }
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


// ************  --------------  FUNCOES   --------------  ************//

int CadastroPassageiro(class PASSAGEIRO &passageiro) {

    setlocale(LC_ALL, "portuguese");
    static int contadorCodigoPassageiro = 1000;
    int ficarOuSair;

    ifstream arquivoLeitura("arquivosPassageirosDados\\contadorCodigoPassageiro.txt");
    if (arquivoLeitura.is_open()) {
        arquivoLeitura >> contadorCodigoPassageiro;
        arquivoLeitura.close();
    } else {
        contadorCodigoPassageiro = 1000;
    }

    ofstream arquivo("arquivosPassageirosDados\\dadosPassageiro.txt", ios::app); // CASO O ARQUIVO N ABRE NO TEU PC, BASTA TROCAR O ENDEREÇO OU NOME
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

    ///---------- Fidelidade ----------

        /*---------- so remover aqui igor ----------

            bool fidelidade;
            int resposta;

        cout << "O usuário tem pontos de fidelidade? (sim/nao): ";
        cin >> resposta;

        if (resposta == "sim" || resposta == "SIM") { // IGOR AQUI É SO PARA SABER SE TEM FIDELIDADE, AQUI VC N PRECISA MEXER
        fidelidade = true;
    } else if (resposta == "nao" || resposta == "NAO") {
        fidelidade = false;
    } else {
        cout << "Digite 'sim' ou 'nao'.";
        return -1;
    }

        if (fidelidade) {
            // IGOR VC VAI COMEÇAR POR AQUI, CHAMA A SUA FUNCAO, METODO, CLASSE, SEI LA O QUE VC VAI FAZER, QLQR COISA OU DUVIDA SO CHAMAR
    } else {
        cout << "Sem pontos de fidelidade, faça o seu primeiro voo para recebe-lo !!!" << endl;
    }

    ---------- so remover aqui igor ---------- */

    ///---------- codigo do passageiro ----------


        passageiro.setCodigoPassageiro(contadorCodigoPassageiro++);
        cout << "Código do Passageiro: " << passageiro.getCodigoPassageiro() << "\n";

    /// ---------- salvar em arquivo ----------

    arquivo << "Nome do Passageiro: " << nomePassageiro << endl;
    arquivo << "Endereco: "<< endl;
    arquivo << "Pais: " << enderecoPassageiro.getPaisPassageiro()
            << "\nEstado: " << enderecoPassageiro.getEstadoPassageiro()
            << "\nCidade: " << enderecoPassageiro.getCidadePassageiro() << endl;
    arquivo << "Telefone do Passageiro: " << telefonePassageiro << endl;
    arquivo << "Código: " << passageiro.getCodigoPassageiro() << endl;
    // arquivo << "Pontos de Fidelidade do Passageiro: " << pontosFidelidade << endl; IGOR, COMANDO PARA SALVAR NO ARQUIVO TXT
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

    ofstream arquivoContador("arquivosPassageirosDados\\contadorCodigoPassageiro.txt");
    if (arquivoContador.is_open()) {
        arquivoContador << contadorCodigoPassageiro;
        arquivoContador.close();
    } else {
        cerr << "Erro ao atualizar o contador de códigos!" << endl;
        return -1;
    }

    return 0;
};

int CadastroTripulacao(class TRIPULACAO &tripulacao) {
  cout<<"---------- Cadastro de Tripulação Selecionado ----------\n"<<endl;
    return 0;
};

int CadastroVoo(class VOO &voo) {
  cout<<"---------- Cadastro de Voo Selecionado ----------\n"<<endl;
    return 0;
};

int CadastroAssento(class ASSENTO &assento) {
  cout<<"---------- Cadastro de Assento Selecionado ----------\n"<<endl;
    return 0;
};

struct ReservaInfo {
    int codigoVoo;
    int numeroAssento;
    int codigoPassageiro;
};

void CadastrarReserva(const VOO &voo, ASSENTO &assento, const PASSAGEIRO &passageiro){
    if(!voo.getStatus()){
        cout<<"Reserva falhou. O voo não está ativo.\n";
        return;
    }

    if(!assento.getStatus()){
        cout<<"Reserva falhou: O assento já está ocupado.\n";
        return;
    }

    ReservaInfo novaReserva = {voo.getCodigoVoo(), assento.getNumeroAssento(), passageiro.getCodigoPassageiro()};

    ifstream arquivoLeitura("reservas.dat", ios::binary);
    ReservaInfo reservaExistente;

    while(arquivoLeitura.read((char*)&reservaExistente, sizeof(ReservaInfo))) {
        if(reservaExistente.codigoVoo == novaReserva.codigoVoo && reservaExistente.numeroAssento == novaReserva.numeroAssento){
            cout<<"Reserva falhou: Duplicidade de assento no mesmo voo.\n";
            arquivoLeitura.close();
            return;
        }
    }
    arquivoLeitura.close();

    // atualizar o status do assento e salvar a reserva
    ofstream arquivoEscrita("reservas.dat", ios::binary | ios::app);
    arquivoEscrita.write((char*)&novaReserva, sizeof(ReservaInfo));
    assento.setStatus(false);
    cout << "Reserva realizada com sucesso!\n";
}

void BaixarReserva(int codigoVoo, int numeroAssento){
    ifstream arquivoLeitura("reservas.dat", ios::binary);
    ofstream arquivoTemporario("reservas_temp.dat", ios::binary);
    ReservaInfo reserva;
    bool reservaEncontrada = false;

    // procurar a reserva e copiar todas as outras para o arquivo temporário
    while(arquivoLeitura.read((char*)&reserva, sizeof(ReservaInfo))){
        if(reserva.codigoVoo == codigoVoo && reserva.numeroAssento == numeroAssento){
            reservaEncontrada = true;

            ASSENTO assento;
            assento.setNumeroAssento(numeroAssento);
            assento.setStatus(true);
            cout<<"Reserva cancelada. Assento liberado\n";
        } else {
            arquivoTemporario.write((char*)&reserva, sizeof(ReservaInfo));
        }
    }
    arquivoLeitura.close();
    arquivoTemporario.close();

    if(reservaEncontrada){
        remove("reservas.dat");
        rename("reservas_temp.dat", "reservas.dat");

        VOO voo;
        voo.setCodigoVoo(codigoVoo);
        float valorPagamento = voo.getTarifa();
        cout<<"Valor total a ser pago: R$ "<<valorPagamento<<endl;
    } else {
        remove("reservar_temp.dat");
        cout<<"Reserva não encontrada para este assento e voo.\n";
    }
}

void VerificarReserva(int codigoVoo, int numeroAssento){
    ifstream arquivoLeitura("reservas.dat", ios::binary);
    ReservaInfo reserva;
    bool reservaEncontrada = false;

    while(arquivoLeitura.read((char*)&reserva, sizeof(ReservaInfo))){
        if(reserva.codigoVoo == codigoVoo && reserva.numeroAssento == numeroAssento){
            cout<<"Reserva encontrada! Código do Passageiro: "<<reserva.codigoPassageiro<<endl;
            reservaEncontrada = true;
            break;
        }
    }
    arquivoLeitura.close();

    if(!reservaEncontrada){
        cout<<"Nenhuma reserva encontrada para este assento e voo\n";
    }
}

int VerificarReserva(class RESERVA &reserva) {
  cout<<"---------- Verificação de Reservas Selecionado ----------\n"<<endl;
    return 0;
};

int BaixarReserva(class RESERVA &reserva) {
  cout<<"---------- Baixar Reservas Selecionado ----------\n"<<endl;
    return 0;
};

int PesquisarPessoa(class PASSAGEIRO &passageiro, class TRIPULACAO &tripulacao) {
  cout<<"---------- Pesquisa de Pessoa Selecionado ----------\n"<<endl;
    return 0;
};

int escolhaFuncao(int escolha){

  PASSAGEIRO passageiro;
  TRIPULACAO tripulacao;
  VOO voo;
  ASSENTO assento;
  RESERVA reserva;

  switch(escolha){

  case 1: CadastroPassageiro(passageiro); break;
  case 2: CadastroTripulacao(tripulacao); break;
  case 3: CadastroVoo(voo); break;
  case 4: CadastroAssento(assento); break;
  case 5:
    cout<<"Digite o código do voo: ";
    cin>>voo.codigoVoo;
    cout<<"Digite o número do assento: ";
    cin>>assento.numeroAssento;
    // cout<<"Digite o código do passageiro: ";
    // cin>>passageiro.codigo;
    CadastrarReserva(voo, assento, passageiro);
    break;
    //VerificarReserva(reserva); break;
  case 6:
    cout<<"Digite o código do voo para cancelar a reserva: ";
    cin>>voo.codigoVoo;
    cout<<"Digite o número do assento a ser liberado: ";
    cin>>assento.numeroAssento;
    BaixarReserva(voo.codigoVoo, assento.numeroAssento);
    break;
  case 7: PesquisarPessoa(passageiro,tripulacao); break;
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
