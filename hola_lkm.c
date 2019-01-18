/**
    2016/09/26
    loadable kernel module (LKM)
    modulo cargable del nucleo
    muestra un mensaje en /var/log/kern.log cuando el modulo es cargado y removido
    El modulo puede aceptar un argumento cuando es cargado
    codigo original en http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
*/

#include <linux/init.h>             // Macros used to mark up functions e.g., __init __exit
#include <linux/module.h>           // Core header for loading LKMs into the kernel
#include <linux/kernel.h>           // Contains types, macros, functions for the kernel

MODULE_LICENSE("GPL");              // The license type -- puede producir un "tainted" en el kernel
MODULE_AUTHOR("Rene Hernandez");      // The author -- visible when you use modinfo
MODULE_DESCRIPTION("Practica de sistemas operativos: compilar y cargar un modulo al kernel");  //< The description -- see modinfo
MODULE_VERSION("0.1");              // The version of the module


static int __init hola_init(void){
   printk(KERN_INFO "Hola Mundo desde el kernel a traves de un modulo cargado!\n");
   return 0;
}


static void __exit hola_exit(void){
   printk(KERN_INFO "Adios Mundo desde el kernel a traves de un modulo cargado!\n");
}

module_init(hola_init);
module_exit(hola_exit);
