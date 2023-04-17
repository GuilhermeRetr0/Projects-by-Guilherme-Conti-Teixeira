import hashlib

def hash_password(password):

    salt = "s4lT_v4luE"  
    return hashlib.sha256((password + salt).encode()).hexdigest()

class PasswordManager:
    def __init__(self, filename):
        self.filename = filename
        self.passwords = {}
        self.load_passwords()

    def load_passwords(self):
    
        with open(self.filename, "r") as f:
            for line in f:
                site, username, password = line.strip().split(",")
                self.passwords[site] = (username, password)

    def save_passwords(self):
    
        with open(self.filename, "w") as f:
            for site, (username, password) in self.passwords.items():
                f.write(f"{site},{username},{password}\n")

    def add_password(self, site, username, password):
    
        hashed_password = hash_password(password)
        self.passwords[site] = (username, hashed_password)
        self.save_passwords()

    def remove_password(self, site):
    
        if site in self.passwords:
            del self.passwords[site]
            self.save_passwords()

    def get_password(self, site):
    
        if site in self.passwords:
            username, hashed_password = self.passwords[site]
            return username, hashed_password
        else:
            return None

if __name__ == "__main__":
    filename = "passwords.txt"
    password_manager = PasswordManager(filename)

    while True:
        print("\nEscolha uma opção:")
        print("1. Adicionar senha")
        print("2. Remover senha")
        print("3. Obter senha")
        print("4. Sair")
        choice = input("> ")

        if choice == "1":
            site = input("Digite o nome do site: ")
            username = input("Digite o nome de usuário: ")
            password = input("Digite a senha: ")
            password_manager.add_password(site, username, password)
            print("Senha adicionada com sucesso.")
        elif choice == "2":
            site = input("Digite o nome do site para remover: ")
            password_manager.remove_password(site)
            print("Senha removida com sucesso.")
        elif choice == "3":
            site = input("Digite o nome do site para obter a senha: ")
            result = password_manager.get_password(site)
            if result:
                username, hashed_password = result
                password = input("Digite a senha mestre: ")
                if hash_password(password) == hashed_password:
                    print(f"A senha para {site} é: {username}, {hashed_password}")
                else:
                    print("Senha incorreta.")
            else:
                print(f"Senha para {site} não encontrada.")
        elif choice == "4":
            break
        else:
            print("Opção inválida.")
