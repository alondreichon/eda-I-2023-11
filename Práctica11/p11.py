import sys

def menu(intOption):
    if intOption == 1:
        conversionBases()
    elif intOption == 2:
        nterms = int(input("Ingrese el número de términos de la serie de Fibonacci:\n"))
        if nterms <= 0:
            print("Ingrese un entero positivo\n")
        else:
            print("Serie de Fibonacci (en orden inverso):\n")
            fibo_list = []
            for i in range(nterms-1, -1, -1):  # Generar valores en orden inverso
                fibo_list.append(recur_fibo(i))
            print(*fibo_list)  # Imprimir la lista sin corchetes ni comas
    elif intOption == 3:
        sys.exit()
    else:
        print("Opcion no valida.\n")

def conversionBases():
    numero = int(input("Ingrese un numero a convertir en binario: \n"))
    numero_binario = 0
    multiplicador = 1

    while numero != 0:
        numero_binario = numero_binario + numero % 2 * multiplicador
        numero //= 2
        multiplicador *= 10

    print("El numero en binario es:\n", numero_binario)

def recur_fibo(n):
    if n <= 1:
        return n
    else:
        return recur_fibo(n - 1) + recur_fibo(n - 2)

print("\n")
print("Bienvenido, puede realizar las siguientes operaciones: \n")

while True:
    print("\t1) Conversion de bases\n")
    print("\t2) Serie de Fibonacci\n")
    print("\t3) Salir\n")

    option = int(input("Ingrese una opción: \n"))
    menu(option)
