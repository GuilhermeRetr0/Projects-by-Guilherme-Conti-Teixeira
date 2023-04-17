import random
perguntas = ['Olá', 'Como você está?', 'Qual é o seu nome?', 'Qual é a sua idade?']
respostas = ['Olá!', 'Estou bem, obrigado!', 'Meu nome é ChatBot.', 'Eu sou um programa de computador, não tenho idade.']
while True:
    pergunta = input('Você: ')
    resposta = random.choice(respostas)
    print('ChatBot:', resposta)
