#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>   // provides struct anf func for handling char device

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("first character device");

static const char *my_device = "my_cdev";

static struct file_operations fops = {

};
static int major;

static int my_init(void){
    major = register_chrdev(0,my_device,&fops);
    if(major < 0){
        pr_err("%s:charatcter device reg failed\n",my_device);
        return major;
    }
    pr_info("%s: character device registered , Major number: %d\n",my_device,major);
    return 0;
}

static void my_exit(void){
    unregister_chrdev(major,my_device);
    pr_info("%s: Good Bye Kernel!!\n",my_device);
}

module_init(my_init);
module_exit(my_exit);
