#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>   // provides struct anf func for handling char device

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("first character device");

#define MY_MAJOR 64

static const char *my_device = "cdev";

static struct file_operations fops = {

};
//static int major;

static int my_init(void){
    int status;
    status = register_chrdev(MY_MAJOR,my_device,&fops);
    if(status){
        pr_err("%s:charatcter device reg failed\n",my_device);
        return status;
    }
    pr_info("%s: character device registered , Major number: %d\n",my_device,MY_MAJOR);
    return 0;
}

static void my_exit(void){
    unregister_chrdev(MY_MAJOR,my_device);
    pr_info("%s: Good Bye Kernel!!\n",my_device);
}

module_init(my_init);
module_exit(my_exit);
