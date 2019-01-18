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

static char *nombre = "mundo";        // An example Linux Kernel Module argument -- default value is "world"
module_param(nombre, charp, S_IRUGO); //module_param(name, type, permissions) charp = char ptr, S_IRUGO can be read/not changed
MODULE_PARM_DESC(nombre, "El nombre a mostrar en /var/log/kern.log");  // parameter description

/** @brief The LKM initialization function
 *  The static keyword restricts the visibility of the function to within this C file. The __init
 *  macro means that for a built-in driver (not a LKM) the function is only used at initialization
 *  time and that it can be discarded and its memory freed up after that point.
 *  @return returns 0 if successful
 */
static int __init hola_init(void){
   printk(KERN_INFO "Hola %s desde el kernel a traves de un modulo cargado!\n", nombre);
   return 0;
}

/** @brief The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required.
 */
static void __exit hola_exit(void){
   printk(KERN_INFO "Adios %s desde el kernel a traves de un modulo cargado!\n", nombre);
}

/** @brief A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(hola_init);
module_exit(hola_exit);
