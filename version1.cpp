#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Estrutura a para reprresentar uma tarefa
struct Tarefa
{
    string descrricao;
    string prazo;
    bool concluida;
};

// Vector para armanezar as tarefas
vector<Tarefa>tarefas;

// Funcao para salvarTarefa
void salvarTarefa(){
    ofstream arquivo("tarefa.txt");

    for(const auto& tarefa:tarefas){
        cout << tarefa.descrricao<<endl<<tarefa.prazo<<endl<<tarefa.concluida<<endl;
    }
    arquivo.close();
}

// Funcao para carregar tarefa
void carregarTarefa(){
    ifstream arquivo("tarefa.txt");
    if(!arquivo)return;

    Tarefa tarefa;
    while (getline(arquivo,tarefa.descrricao))
    {
        getline(arquivo,tarefa.descrricao);
        arquivo>>tarefa.concluida;
        arquivo.ignore();
        tarefas.push_back(tarefa);
    }
    arquivo.close();
}

// Funcao para adicionar uma nove tarefa
void adicionarTarefa(){
    Tarefa novaTarefa;
    cin.ignore();
    cout << "Digite a descricao da tarefa: ";
    getline(cin,novaTarefa.descrricao);
    cout << "Digite o prazo da tarefa tarefa: ";
    getline(cin,novaTarefa.prazo);
    novaTarefa.concluida = false;
    tarefas.push_back(novaTarefa);
    salvarTarefa();
    cout << "Tarefa adicionada com sucesso!\n";
}

// Funcao principal
int main()
{
    carregarTarefa();
    int alternativa;
    do
    {
        cout << "######################## Gerenciador de Tarefas ###########################\n";
        cout << "1. Adicionar Tarefas\n";
        cout << "2. Listar todas as tarefas\n";
        cout << "3. Marcar a tarefa concluida\n";
        cout << "4. Remover Tarefa\n";
        cout << "5. Sair\n";
        cout << "Informe a sua alternsativa: ";
    } while (alternativa != 5);
    return 0;
}