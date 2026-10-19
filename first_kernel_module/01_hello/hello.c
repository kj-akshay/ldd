#include<linux/module.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple hello kernel module");

static int my_init(void){
    printk("hello: Hello Kernel!!\n");
    return 0;
}

static void my_exit(void){
    printk("hello: Good Bye Kernel!!\n");
}

module_init(my_init);
module_exit(my_exit);
