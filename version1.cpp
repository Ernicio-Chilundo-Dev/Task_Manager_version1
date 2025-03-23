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
vector<Tarefa> tarefas;

// Funcao para salvarTarefa
void salvarTarefa()
{
    ofstream arquivo("tarefa.txt");

    for (const auto &tarefa : tarefas)
    {
        cout << tarefa.descrricao << endl
             << tarefa.prazo << endl
             << tarefa.concluida << endl;
    }
    arquivo.close();
}

// Funcao para carregar tarefa
void carregarTarefa()
{
    ifstream arquivo("tarefa.txt");
    if (!arquivo)
        return;

    Tarefa tarefa;
    while (getline(arquivo, tarefa.descrricao))
    {
        getline(arquivo, tarefa.descrricao);
        arquivo >> tarefa.concluida;
        arquivo.ignore();
        tarefas.push_back(tarefa);
    }
    arquivo.close();
}

// Funcao para adicionar uma nove tarefa
void adicionarTarefa()
{
    Tarefa novaTarefa;
    cin.ignore();
    cout << "Digite a descricao da tarefa: ";
    getline(cin, novaTarefa.descrricao);
    cout << "Digite o prazo da tarefa tarefa: ";
    getline(cin, novaTarefa.prazo);
    novaTarefa.concluida = false;
    tarefas.push_back(novaTarefa);
    salvarTarefa();
    cout << "Tarefa adicionada com sucesso!\n";
}

// Funcao para listar uma tarefa
void listarTarefa()
{
    if (tarefas.empty()){
        cout << "Nenhuma tarefa encontrada\n";
    }
    for (size_t i = 0; i < tarefas.size(); i++)
    {
        cout << i + 1 << ". [" << (tarefas[i].concluida ? 'C' : 'X') << "] " << tarefas[i].descrricao << " (Prazo: " << tarefas[i].prazo << ")" << endl;
    }
}

//Funcao para marcar tarefa concluida
void marcarTarefa(){
    listarTarefa();
    if(tarefas.empty())return;
    int index;
    cout << "Digite o numero da tarefa concluida: ";
    cin >> index;

    if(index > 0 && index <= static_cast <int> (tarefas.size())){
        tarefas[index - 1].concluida = true;
        salvarTarefa();
        cout << "Tarefa marcada como cooncluida\n";
    }else{
        cout << "Alternativa nula\n";
    }
}

// Funcao para remover uma tarefa
void removerTarefa(){
    listarTarefa();
    if(tarefas.empty())return;

    int index;
    cout << "Digite o numero da tarefa a excluir: ";
    cin >> index;

    if(index > 0 && index <= static_cast<int>(tarefas.size())){
        tarefas.erase(tarefas.begin() + index - 1);
        salvarTarefa();
        cout << "Tarefa removida com sucesso\n";
    }else{
        cout << "Alternativa nula\n";
    }
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
        cin >> alternativa;

        switch(alternativa){
            case 1: adicionarTarefa();break;
            case 2: listarTarefa();break;
            case 3: marcarTarefa();break;
            case 4: removerTarefa();break;
            case 5: cout << "Saindo do progama...\n";break;
            default: cout << "Alternativa nula\n";
        }
    } while (alternativa != 5);
    return 0;
}