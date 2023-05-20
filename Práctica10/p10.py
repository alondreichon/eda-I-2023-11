import sys

libros = []

def menu(intOption):
    global libros

    if intOption == 1:
        insertarLibro()
    elif intOption == 2:
        eliminarLibro()
    elif intOption == 3:
        ordenarLibros()
    elif intOption == 4:
        mostrarLibros()
    elif intOption == 5:
        sys.exit()
    else:
        print("Opcion no valida.\n")

def insertarLibro():
    global libros
    
    while True:
        libro = {} 
        
        libro["titulo"] = input("Ingrese el título del libro (o escriba 'salir' para terminar): \n")
        if libro["titulo"].lower() == "salir":
            break
        
        libros.append(libro)

def eliminarLibro():
    global libros
    
    titulo = input("¿Qué libro desea eliminar?\n")
    encontrado = False

    for libro in libros:
        if libro["titulo"].lower() == titulo.lower():
            libros.remove(libro)
            encontrado = True
            break

    if encontrado:
        print("El libro se ha eliminado correctamente.\n")
    else:
        print("No se encontró un libro con ese título.\n")

def ordenarLibros():
    global libros
    
    libros.sort(key=lambda x: x["titulo"].lower())
    print("Los libros se han ordenado alfabéticamente.\n")


def mostrarLibros():
    print("Estos son los libros en orden:\n")
    if len(libros) == 0:
        print("No hay libros registrados.")
    else:
        for libro in libros:
            print(libro["titulo"])
    print()


print("\n")
print("Bienvenido a la biblioteca, puede realizar las siguientes operaciones: \n")

while True:
    print("\t1) Agregar libro\n")
    print("\t2) Eliminar Libro\n")
    print("\t3) Ordenar biblioteca\n")
    print("\t4) Ver biblioteca\n")
    print("\t5) Salir\n")
    option = int(input("Ingrese una opción: "))
    menu(option)