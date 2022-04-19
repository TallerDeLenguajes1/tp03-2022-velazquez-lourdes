#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/*
i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
clientes.
ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
*/
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct
{
    int ProductoID; // Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algun valor del arreglo TipoProductos
    float PrecioUnitario; // entre 10 -100
} Producto;
typedef struct 
{
    int ClienteID; //Numerado en ciclo iterativo
    char *NombreCliente; // Ingresado por el usuario
    int CantidadProductosAPedir;// aleatorio entre 1 y 5
    Producto *Productos; // el tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}Cliente;
/*                                 DECLARACION DE FUNCIONES                              */
void funcion_Cliente (int aux);
void funcion_producto (int a);
/*                                                                                      */
int main ()
{
    srand((int)time(NULL));
    srand((float)time(NULL));
    int CantCliente;
    Cliente **CargarCliente;
    printf("Ingrese el numero de Clientes: ");
    scanf("%d", &CantCliente);
    funcion_Cliente(CantCliente);

    return 0;
}
/*                                    FUNCIONES                                         */
/*                           FUNCION PARA CARGAR CLIENTE                                */
void funcion_Cliente (int CantCliente)
{
    char *nombre[CantCliente];
    Cliente *buff;
    int aux;
    buff=(Cliente*)malloc(sizeof(Cliente));
    buff->NombreCliente=(char*)malloc(100*sizeof(char));

    for ( int i = 0; i < CantCliente; i++)
    {
        printf("ingrese el nombre del Cliente N° %d : \n", i+1);
        gets(buff->NombreCliente);
        nombre[i]=(char*)malloc((strlen(buff->NombreCliente)+1)*sizeof(char));
        strcpy(nombre[i], buff->NombreCliente);
    }

    printf("------------------PEDIDOS-----------------------\n");
    
    for ( int i =0; i < CantCliente; i++)
    {
        buff->ClienteID=i+1;
        printf("Cliente Numero N°: %d \n", buff->ClienteID);
        printf("Nombre del cliente: %s \n", nombre[i]);
        buff->CantidadProductosAPedir= 1+rand()%10;
        printf("Cantidad de produtos: %d \n", buff->CantidadProductosAPedir);
      //  funcion_producto(buff->CantidadProductosAPedir);
        printf("________________________________________________________________________\n");
       
    }
     free(buff);
}
/*                          FUNCION PARA CARGAR PRODUCTO                               */
void funcion_producto(int a)
{
    printf("------------------------------------------------------------------------------\n");
    Producto *buff_productos;
    for ( int i =0; i<a; i++)
    {
        buff_productos->ProductoID=i+1;
        printf("Producto Numero N°: %d \n", buff_productos->ProductoID);
        buff_productos->Cantidad = 1+ rand()%10;
        printf("Cantidad de Productos: %d \n", buff_productos->Cantidad);
        buff_productos->PrecioUnitario=1+rand()%110;
        printf("Precio por unidad: $ %f \n", buff_productos->PrecioUnitario);
        free(buff_productos);
    }
    
}