# Practica-modulo-driver-linux
Hola mundo version driver de linux

## Instrucciones
### Compilar

1. Instalar compilador y librerías esenciales (gcc, gcc, make, dpkg-dev, libc6-dev)<br>
    ```sudo apt-get update```<br>
    ```sudo apt-get install build-essential checkinstall```<br>

2. Instalar cabecera del kernel
    1. Buscar la version del kernel
        ```apt-cache search linux-headers-$(uname -r)```<br>
    2. Instalar la cabecera
        ```sudo apt-get install linux-headers-$(uname -r)```<br>
    * Para revisar sus archivos
        ```cd /usr/src/linux-headers-4.2.0-16-generic```<br>

3. Compilar
    ```make```<br>
    
### Instalar

1. Instalar <br>
    ```sudo insmod hola_lkm.ko```<br>

2. Verlo en ejecucion dentro del sistema <br>
```lsmod ```<br>
```modinfo hola_lkm.ko``` <br>
```cd /proc``` <br>
```cat modules|grep hola_lkm``` <br>

3. Para ver los mensajes <br>
```sudo su -```<br>
```cd /var/log```<br>
```tail -f kern.log```<br>

### Remover

```sudo rmmod hola_lkm.ko```
    
# Notas
Con parámetro<br>
    ```sudo insmod driver.ko nombre=Rene```<br>

Ver más detalles<br>
    ```cd /sys/module```<br>
    ```ls -l|grep hola_lkm```<br>

# Referencias
[Help Ubuntu - CompilingSoftware](https://help.ubuntu.com/community/CompilingSoftware)<br>
[nixCraft - Debian / Ubuntu Linux Install Kernel Headers Package](http://www.cyberciti.biz/faq/howto-install-kernel-headers-package/)<br>
[derekmolloy.ie Molloy - Writing a Linux Kernel Module](http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/)<br>
[The Linux Kernel Module Programming Guide](http://www.tldp.org/LDP/lkmpg/2.6/html/lkmpg.html)<br>
