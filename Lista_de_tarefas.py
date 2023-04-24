lista_de_tarefas = []

def adicionar_tarefa():
    tarefa = input("Digite a nova tarefa: ")
    lista_de_tarefas.append(tarefa)
    print("Tarefa adicionada com sucesso!")

def visualizar_tarefas():
    print("Lista de Tarefas:")
    if len(lista_de_tarefas) == 0:
        print("Nenhuma tarefa na lista.")
    else:
        for i, tarefa in enumerate(lista_de_tarefas, 1):
            print(f"{i}. {tarefa}")

def marcar_tarefa_concluida():
    visualizar_tarefas()
    tarefa_concluida = int(input("Digite o número da tarefa concluída: "))
    if tarefa_concluida <= len(lista_de_tarefas):
        lista_de_tarefas.pop(tarefa_concluida - 1)
        print("Tarefa marcada como concluída e removida da lista.")
    else:
        print("Tarefa não encontrada.")

while True:
    print("\nMenu:")
    print("1. Adicionar tarefa")
    print("2. Visualizar tarefas")
    print("3. Marcar tarefa como concluída")
    print("4. Sair")
    opcao = input("Digite o número da opção desejada: ")

    if opcao == "1":
        adicionar_tarefa()
    elif opcao == "2":
        visualizar_tarefas()
    elif opcao == "3":
        marcar_tarefa_concluida()
    elif opcao == "4":
        print("Saindo...")
        break
    else:
        print("Opção inválida. Tente novamente.")
