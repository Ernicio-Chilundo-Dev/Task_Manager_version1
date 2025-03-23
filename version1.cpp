#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

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