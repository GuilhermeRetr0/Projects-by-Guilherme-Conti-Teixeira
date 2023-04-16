import math

def calculator():
    print("Selecione a operação:")
    print("1. Soma")
    print("2. Subtração")
    print("3. Multiplicação")
    print("4. Divisão")
    print("5. Seno")
    print("6. Cosseno")
    print("7. Tangente")
    print("8. Raiz quadrada")
    print("9. Potência")
    
    choice = input("Digite sua escolha (1/2/3/4/5/6/7/8/9): ")
    
    if choice in ('1', '2', '3', '4', '9'):
        num1 = float(input("Digite o primeiro número: "))
        num2 = float(input("Digite o segundo número: "))
        
        if choice == '1':
            print(num1, "+", num2, "=", num1 + num2)
        
        elif choice == '2':
            print(num1, "-", num2, "=", num1 - num2)
        
        elif choice == '3':
            print(num1, "*", num2, "=", num1 * num2)
        
        elif choice == '4':
            print(num1, "/", num2, "=", num1 / num2)
            
        elif choice == '9':
            print(num1, "^", num2, "=", num1 ** num2)
    
    elif choice in ('5', '6', '7', '8'):
        num = float(input("Digite um número: "))
        
        if choice == '5':
            print("Seno de", num, "é", math.sin(num))
        
        elif choice == '6':
            print("Cosseno de", num, "é", math.cos(num))
        
        elif choice == '7':
            print("Tangente de", num, "é", math.tan(num))
        
        elif choice == '8':
            print("Raiz quadrada de", num, "é", math.sqrt(num))
    
    else:
        print("Opção inválida!")
    
    novamente()

def novamente():
    calc_again = input("Deseja fazer outra operação? (Sim / Não): ")
    if calc_again.upper() == 'SIM':
        calculator()
    elif calc_again.upper() == 'NÃO':
        print("Até logo!")
    else:
        novamente()

calculator()
